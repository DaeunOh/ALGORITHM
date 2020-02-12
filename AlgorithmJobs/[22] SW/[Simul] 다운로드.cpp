/*

시간제한 1초

문제
와이파이를 통해 다운로드 받을 시, 
현재 위치에서 최적의 와이파이를 연결하여 최대한 많은 용량을 다운받을 수 있는 알고리즘을 개발하려고한다. 
다음과 같이 8*10 지도와 함께 각 공유기의 위치가 주어진다.

download1
[그림 1]

AP 범위가 3이라고 했을시, AP가 설치되어있는 위치에서 거리가 3 내에 들어올 경우 와이파이 신호를 잡을 수 있다. 
이때, 거리 계산은 사용자의 위치가 y, x 이고, AP의 위치가 a, b일 경우, |(y-a)|+|(x-b)| 로 한다. 
와이파이 신호는 공유기와의 거리와 관계없이 일정하며 모든 영역에서 동일하다고 가정한다. 
사용자는 오직 하나의 AP에만 접속할 수 있다. 
현재 위치가 여러 공유기에 걸쳐있고, 각 공유기마다 다운로드 속도가 다르다면 
가장 다운로드 속도가 빠른 공유기의 신호를 잡는 것이 좋다. 
[그림 1]에서 (5, 4)에 위치할 경우 AP1 혹은 AP2의 신호를 잡을 수 있다. 
만약 AP1의 속도가 500 MB/s 이고, AP2의 속도가 300 MB/s 의 경우 AP1 의 신호를 잡는 것이 더 좋다.

download2
[그림 2]

[그림 2]에서 두 사람의 초당 이동 경로를 나타내었다. 
각각의 공유기의 다운로드 속도는 AP1 부터 차례대로 500 MB/s, 300 MB/s, 700MB/s 이다. 
몇몇 시간에서 하나의 네트워크 범위에 두 사람이 동시에 접속할 수 있는 것을 확인할 수 있다. 
만약 두 사람이 같은 공유기에 접속할 경우 해당 공유기의 다운로드 속도는 절반이 된다.

T가 8일 경우를 보면, A는 AP1 혹은 AP2 중 하나의 네트워크를 선택하는 것이 가능하고, B는 AP1 에 접속이 가능하다. 
경우의 수를 나눠보면 다음과 같이 표현된다.

만약 A가 AP1에 접속할 경우, A와 B가 모두 AP1에 접속했으므로 AP1의 다운로드 속도가 절반이 된다. 
따라서, A와 B는 250 MB 를 다운받을 수 있다.
만약 A가 AP2에 접속할 경우, A와 B가 다른 AP에 접속했으므로, 
A는 300 MB를 다운받을 수 있고, B는 500 MB를 다운 받을 수 있다.
만약 위와 같은 상황이 존재할때, 두 사람 모두가 이득보는 방향으로 선택하는 것은 쉽지않으므로 
일단은 간단히 두 사람의 다운로드 용량 합이 최대가 되도록 결정을 한다. 
합이 최대가 되는 조합이 하나가 아닌 경우 
두 사람 중 다운로드 용량이 더 많이 남은 사람이 더 많은 용량을 다운받을 수 있도록 한다.

각 시간별 다운로드 용량을 알아보면 아래와 같이 적을 수 있다.
T=0s, A: 0 MB 6000 MB / B: 0 MB 5500 MB
T=1s, A: 0 MB 6000 MB / B: 0 MB 5500 MB
T=2s, A: 0 MB 6000 MB / B: 500 MB 5000 MB
T=3s, A: 0 MB 6000 MB / B: 500 MB 4500 MB
T=4s, A: 0 MB 6000 MB / B: 500 MB 4000 MB
T=5s, A: 0 MB 6000 MB / B: 0 MB 4000 MB
T=6s, A: 0 MB 6000 MB / B: 500 MB 3500 MB
T=7s, A: 0 MB 6000 MB / B: 500 MB 3000 MB
T=8s, A: 300 MB 5700 MB / B: 500 MB 2500 MB
T=9s, A: 300 MB 5400 MB / B: 500 MB 2000 MB
T=10s, A: 300 MB 5100 MB / B: 500 MB 1500 MB
T=11s, A: 300 MB 4800 MB / B: 0 MB 1500 MB
T=12s, A: 150 MB 4650 MB / B: 150 MB 1350 MB
T=13s, A: 150 MB 4500 MB / B: 150 MB 1200 MB
T=14s, A: 150 MB 4350 MB / B: 150 MB 1050 MB
T=15s, A: 700 MB 3650 MB / B: 300 MB 750 MB
T=16s, A: 700 MB 2950 MB / B: 300 MB 450 MB
T=17s, A: 700 MB 2250 MB / B: 0 MB 450 MB
T=18s, A: 700 MB 1550 MB / B: 0 MB 450 MB
T=19s, A: 700 MB 850 MB / B: 0 MB 450 MB
T=20s, A: 0 MB 850 MB / B: 0 MB 450 MB

두 사람이 각각 다운로드 받아야하는 용량 D1, D2 와 이동경로가 N * M 지도와 함께 주어졌을때, 
공유기를 위 규칙대로 선택하여 이동한 결과 두 사람의 남은 다운로드 용량을 알아내는 프로그램을 작성해보자.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다. 
각각의 테스트 케이스의 첫 번째 줄에 지도의 크기 N, M 과 공유기의 개수 K가 공백을 통개 구분하여 주어진다. 
지도의 최상단 좌측의 자표는 (1, 1)이다.

다음 K개 줄에 걸쳐 공유기 정보가 주어진다. 
각 줄에 공유기의 위치 Y, X와 함께 공유기의 범위 R, 해당 공유기의 다운로드 속도 D가 공백을 통해 구분하여 주어진다. 
D는 10의 배수로 주어진다. 같은 위치에 설치되는 공유기는 없다.

다음으로 A와 B의 이동 길이 S가 주어지고, 
바로 다음 두 줄에 걸쳐 A, B가 어떻게 이동하는지 공백을 통해 구분하여 주어진다. 
해당 정보는 숫자로 주어지며, 0부터 4까지의 정수로 구성된다. 
0은 이동하지 않았다는 것을 의미하고 1은 위쪽, 2는 오른쪽, 3은 아래쪽, 4는 왼쪽으로 이동했다는 것을 의미한다. 
이동 중 지도 바깥으로 나가는 경우는 없다.

바로 다음 두 줄이 입력되는데, 
첫 번째 줄에는 A의 시작 좌표 ay, ax와 A가 다운받아야하는 용량의 크기 ad가 공백을 통해 구분하여 주어지고, 
두 번째 줄에는 B의 시작 좌표 by, bx와 B가 다운받아야하는 용량의 크기 bd가 공백을 통해 구분하여 주어진다. 
A와 B의 시작 위치는 공유기의 위치가 될 수 있으며, 서로 같은 시작점을 가질수도 있다. 
시작점이 만약 공유기 범위 내부라면 이동 시작과 동시에 공유기 용량만큼 다운로드를 받을 수 있다.

(1 ≤ N, M, X, Y, ay, ax, by, bx ≤ 10, 1 ≤ K, R ≤ 5, 10 ≤ D ≤ 1,000, 10 ≤ S ≤ 100, 10,000 ≤ ad, bd ≤ 1,000,000)

 

출력
각 테스트 케이스에 대해 A와 B의 남은 다운로드 용량을 공백을 통해 구분하여 출력한다. 
만약 남은 용량이 없을 경우 0을 출력한다. 
각 테스트 케이스의 출력 양식은 "#t ra rb"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. 
ra, rb은 문제에 대한 결과값을 뜻한다.

 

예제 입력
5
8 10 3
2 9 3 700
5 6 2 300
6 3 2 500
20
0 2 2 3 2 3 3 3 2 3 2 1 1 1 2 2 3 2 3 2
0 2 2 3 2 1 1 4 1 1 2 2 2 2 3 3 3 2 2 3
1 1 6000
7 1 5500
6 6 1
2 2 4 910
10
4 1 0 3 4 1 0 2 0 2 
2 3 0 4 3 2 1 3 0 3 
6 5 5800
2 5 9400
9 2 5
6 2 2 560
9 2 3 700
5 2 3 480
7 1 1 940
6 4 3 470
10
2 3 1 3 1 0 0 0 4 2 
4 2 4 1 3 3 2 4 0 1 
1 1 4300
3 2 9500
4 5 4
2 1 2 990
3 1 2 680
2 2 4 50
1 5 3 500
13
4 0 0 4 0 0 2 1 1 4 2 2 3 
3 4 2 4 0 1 1 2 4 2 1 4 3 
4 5 5600
3 2 2500
10 9 5
3 8 5 920
8 6 4 820
4 2 4 780
9 9 2 520
2 7 3 890
10
2 1 4 2 1 1 2 4 2 3 
1 1 3 3 4 1 1 0 0 4 
9 1 5900
3 7 300
예제 출력
#1 850 450
#2 3980 6670
#3 3580 4860
#4 1260 0
#5 0 0

*/

/*

조건 중에 하나를 빠뜨려서 고생했던 문제.
조건이 많을 때는 설계를 처음부터 끝까지 꼼꼼하게 해야한다!

*/

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 10 + 10;
const int MAXK = 5 + 10;
const int MAXS = 100 + 10;

int T;
int N, M, K;
vector<int> map[MAX][MAX];
int AP[MAXK];

int S;
int A[MAXS], B[MAXS];

int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, 1, 0, -1};

int ay, ax, ad;
int by, bx, bd;

void download(int x) {
  ay += dy[A[x]];
  ax += dx[A[x]];
  
  by += dy[B[x]];
  bx += dx[B[x]];
  
  // 속도 빠른 공유기 선택
  int maxD_A = -1, maxIdx_A = -1;
  for(int i=0; i<map[ay][ax].size(); i++) {
    if(maxD_A < AP[map[ay][ax][i]]) {
      maxD_A = AP[map[ay][ax][i]];
      maxIdx_A = map[ay][ax][i];
    }
  }
  
  int maxD_B = -1, maxIdx_B = -1;
  for(int i=0; i<map[by][bx].size(); i++) {
    if(maxD_B < AP[map[by][bx][i]]) {
      maxD_B = AP[map[by][bx][i]];
      maxIdx_B = map[by][bx][i];
    }
  }
  
  if((maxIdx_A != -1 || maxIdx_B != -1) && maxIdx_A != maxIdx_B) {
    if(maxIdx_A != -1) ad -= maxD_A;
    if(maxIdx_B != -1) bd -= maxD_B;
  }
  else if(maxIdx_A != -1 && maxIdx_B != -1 && maxIdx_A == maxIdx_B){
    int maxSum = -987987987, maxCnt = 0;
    for(int i=0; i<map[ay][ax].size(); i++) {
      for(int j=0; j<map[by][bx].size(); j++) {
        if(map[ay][ax][i] == map[by][bx][j]) {
          if(AP[map[ay][ax][i]] > maxSum) {
            maxSum = AP[map[ay][ax][i]];
            maxD_A = maxSum / 2;
            maxD_B = maxSum / 2;
            
            maxCnt = 1;
          }
          else if(AP[map[ay][ax][i]] == maxSum) maxCnt++;
        }
        else {
          if(AP[map[ay][ax][i]] + AP[map[by][bx][j]] > maxSum) {
            maxSum = AP[map[ay][ax][i]] + AP[map[by][bx][j]];
            maxD_A = AP[map[ay][ax][i]];
            maxD_B = AP[map[by][bx][j]];
            
            maxCnt = 1;
          }
          else if(AP[map[ay][ax][i]] + AP[map[by][bx][j]] == maxSum) maxCnt++;
        }
      }
    }
    
    if(maxCnt == 1) {
      ad -= maxD_A;
      bd -= maxD_B;
    }
    else {
      maxD_A = -987987987, maxD_B = -987987987;
      for(int i=0; i<map[ay][ax].size(); i++) {
        for(int j=0; j<map[by][bx].size(); j++) {
          if(map[ay][ax][i] == map[by][bx][j]) {
            if(AP[map[ay][ax][i]] == maxSum) {
              if(ad >= bd && maxD_A < maxSum / 2
                  || ad < bd && maxD_B < maxSum / 2) {
                maxD_A = maxSum / 2;
                maxD_B = maxSum / 2;
              }
            }
          }
          else {
            if(AP[map[ay][ax][i]] + AP[map[by][bx][j]] == maxSum) {
              if(ad >= bd && maxD_A < AP[map[ay][ax][i]] 
                  || ad < bd && maxD_B < AP[map[by][bx][j]]) {
                maxD_A = AP[map[ay][ax][i]];
                maxD_B = AP[map[by][bx][j]];
              }
            }
          }
        }
      }
      
      ad -= maxD_A;
      bd -= maxD_B;
    }
  }
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    memset(map, 0, sizeof(map));
    memset(AP, 0, sizeof(AP));
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    scanf("%d %d %d", &N, &M, &K);
    
    int Y, X, R, D;
    for(int k=1; k<=K; k++) {
      scanf("%d %d %d %d", &Y, &X, &R, &D);
      
      AP[k] = D;
      
      for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
          int distY = i - Y >= 0 ? i - Y : Y - i;
          int distX = j - X >= 0 ? j - X : X - j;
          
          if(distY + distX <= R) {
            map[i][j].push_back(k);
          }
        }
      }
    }
    
    scanf("%d", &S);
    
    for(int i=1; i<=S; i++) scanf("%d", &A[i]);
    for(int i=1; i<=S; i++) scanf("%d", &B[i]);
    
    scanf("%d %d %d", &ay, &ax, &ad);
    scanf("%d %d %d", &by, &bx, &bd);
    
    for(int i=0; i<=S; i++) {
      download(i);
    }
    
    printf("#%d %d %d\n", t, ad >= 0 ? ad : 0, bd >= 0 ? bd : 0);
  }

  return 0;
}