/*

제한시간 5초

문제
알고리즘랩스에서 인공지능 엔진 개발을 담당하고 있는 원석은 
수강생의 문제별 GR 지수 예측 프로그램을 완성했다. 
해당 프로그램을 통해 어떤 문제에서 막히게 될지 미리 알 수 있게 되었다. 
이때 각 수강생 별로 연속으로 최소 K 개의 문제를 통해 
성장하는 기쁨을 느끼게 하기 위해 적절한 문제를 골라 특강으로 진행하려고 한다.

GR 지수는 알파벳으로 표현되며, 내림차순으로 적게되면 S A B C D F 와 같다. 
성장하는 기쁨을 위한 연속된 GR 지수 흐름은 예를 들어 C → B → A 혹은 D → A → S 가 있다. 
지표를 떨어뜨리지 않고 유지하는 것도 매우 중요하기때문에 
D → B → B 와 같은 사례에서도 성장하는 기쁨을 줄 수 있다고 정의한다.

특강을 통해 모두 같은 GR 지수로 통일 시킬 수 있다. 
통일할 GR 지수는 기쁨을 선사하는데 적절한 정도로만 맞춰주는 것이 이상적이다. 
통일할 GR 지수는 S ~ D 의 범위를 갖는다.

예를 들어, 수강생이 6명이고 진행될 문제가 5개라고 가정하여 
GR 지수 예측 프로그램을 실행시켰을때 다음과 같이 표로 받아볼 수 있다. 
Row 가 문제의 번호, Col 이 수강생의 이름이다. 각 칸에는 예측된 GR 지수가 표기 되어있다.

gr1[그림 1]

만약 K 가 3이라고 했을때, 나, 라, 바 수강생분이 성장하는 기쁨을 느낄 수 없다고 볼 수 있다. 
이때, 3번 문제와 4번 문제를 특강을 통해 지표를 S로 맞추면 모두가 성장하는 기쁨을 누릴 수 있게 된다.

gr2[그림 2]

모든 문제를 특강을 통해 높히기엔 시간제약이 있는 상황이다. 
제한된 시간으로 인해 최소한의 특강 횟수로 모든 수강생분의 만족을 이끌어내려고 한다. 
수강생의 문제별 GR 지수 예측 표와 기쁨을 선사할 수 있는 최소 연속 성장 문제 수 K 가 주어졌을때, 
모두에게 만족감을 줄 수 있는 최소 특강 횟수를 구해보자.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다.

각각의 테스트 케이스의 첫 번째 줄에 
문제의 수 P, 수강생의 수 N, 기쁨을 위한 문제수 K 가 공백을 통해 구분하여 주어진다.

다음 줄부터 P 줄에 걸쳐 한 줄당 N 개의 GR 지수가 공백을 통해 구분하여 주어진다. 
각 지수는 알파벳으로 주어지며, S A B C D F 중 하나이다.

(1 ≤ T ≤ 50, 3 ≤ P ≤ 8, 1 ≤ N ≤ 15, 1 ≤ K ≤ P)

 

출력
각 테스트 케이스에 대해 최소 특강 횟수를 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. t는 테스트 케이스의 번호이며, 1부터 시작한다. 
r은 문제에 대한 결과값을 뜻한다.

 

예제 입력
3
5 6 3
D F C D B B
A S S S C D
S F S D B S
S S D A S B
S A S B B C
5 3 3
B D D 
B S S 
C F A 
F C B 
C F C 
8 12 5
D D A F S D D C S F F C 
F F A B C D F S A C B D 
A S C C B D D F C C F S 
F D B S D D F D B D F F 
F D F S A D S C S B B S 
D F C B S A S D A C B S 
A D S A F F S B F F F A 
D B A F A D S F S F D S 
예제 출력
#1 2
#2 1
#3 4

*/

/*

모든 조합을 다 고려해서 문제를 해결하는 것이 핵심이다.
조합짜는 방법만 잘 알고 있고, 조건을 빠뜨리지 않는다면 쉽게 해결 가능하다.

제한시간을 고려해서 모든 카운트를 세지 않고,
최소 조건만 만족하면 반복문을 빠져나가는 형식으로 짰는데,
이건 잘 짠 것 같다. 덕분에 시간이 매우 줄어들었다.

## 실수한 점

1. 여러 조건을 걸면서 최대한 조합을 짜는 것을 피하는 방식으로 접근했던 것.
--> 제한시간이 5초로 여유롭고, 각 변수의 MAX도 크지 않기 때문에
모든 조합을 생각해도 반복문을 빠져나가는 시점만 잘 찾아낸다면
제한시간보다 훨씬 더 작은 시간 안에서도 해결이 가능하다.

2. 문제가 애매하게 쓰여있기도 했고, 문제에 주어진 조건을 제대로 보지 못했다.
--> 특강은 성적을 높일 수도, 낮출 수도 있다. (이 점을 제대로 파악하지 못했다)
또한, 통일할 GR지수는 S~F가 아니라 S~D임을 유의해야 한다.

3. 이미 반복문이 앞에서부터 진행되기 때문에 이전의 GR지수는 확인할 필요가 없었다.
--> 따라서 현 인덱스와 그 다음 인덱스의 GR지수만 서로 비교해주면 된다.

*/

#include <cstdio>
#include <cstring>

const int MAX = 20;
const int MAXP = 8 + 10;

int T;
int P, N, K;

int GR[MAX][MAX];
int GR2[MAX][MAX];

int comb[MAXP] = {0, };
bool isFinished = false;

void getComb(int x, int cnt) {
  if(isFinished) return; // 답을 찾았다면
  
  if(x >= P) {
    if(cnt == 0) {
      for(int i=0; i<P; i++) {
        if(comb[i] == 0) {
          for(int j=0; j<N; j++) GR2[i][j] = GR[i][j];
        }
        else {
          for(int j=0; j<N; j++) GR2[i][j] = comb[i];
        }
      }

      for(int i=0; i<N; i++) {
        int check = 1;
        bool flag = false;
        for(int j=0; j<P-1; j++) {
          if(GR2[j][i] <= GR2[j+1][i]) check++; // 이전과는 비교할 필요 없이, 다음만 비교하면 된다
          else check = 1;

          if(check >= K) { // 최소 조건만 만족하면 되므로
            flag = true;
            break;
          }
        }
        
        if(!flag) return;
      }
      
      isFinished = true;
    }
  }
  else {
    if(cnt != 0) {
      for(int i=2; i<=6; i++) { // 통일할 수 있는 지수의 범위는 S~D이다.
        comb[x] = i;
        getComb(x+1, cnt-1);
      }
    }
    
    comb[x] = 0;
    getComb(x+1, cnt);
  }
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    memset(GR, 0, sizeof(GR));
    memset(GR2, 0, sizeof(GR2));
    memset(comb, 0, sizeof(comb));
    isFinished = false;
    
    scanf("%d %d %d", &P, &N, &K); // P: 문제 수, N: 수강생 수, K: 기쁨을 위한 문제 수
    
    for(int i=0; i<P; i++) {
      for(int j=0; j<N; j++) {
        char gr;
        scanf(" %c", &gr);
        
        if(gr == 'S') GR[i][j] = 6;
        else if(gr == 'A') GR[i][j] = 5;
        else if(gr == 'B') GR[i][j] = 4;
        else if(gr == 'C') GR[i][j] = 3;
        else if(gr == 'D') GR[i][j] = 2;
        else if(gr == 'F') GR[i][j] = 1;
      }
    }
    
    for(int i=0; i<=P; i++) {
      getComb(0, i);
      
      if(isFinished) {
        printf("#%d %d\n", t, i);
        break;
      }
    }
  }
  
  return 0;
}