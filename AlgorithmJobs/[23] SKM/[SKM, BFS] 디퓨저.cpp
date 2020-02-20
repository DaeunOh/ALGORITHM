/*

시간제한 1초

문제
향에 민감한 선웅은 강의실 곳곳에 디퓨저를 놓아뒀다. 
코칭을 시작하기 전 향기로운 냄새로 강의실을 채우기 위해 뚜껑을 닫아둔 디퓨저 병을 K개 정도 열어두려고 한다. 
강의실 내부를 N * M 격자판으로 표현했을때, 
뚜껑이 열린 디퓨저 병에서 향이 나와 1초에 상하좌우로 벽이 아닌 모든 칸에 한 칸씩 퍼진다. 
뚜껑이 닫혀있는 상태는 향이 퍼져나가지 않을뿐, 디퓨저 병이 있는 칸은 이미 향기롭다.

예를 들어, 2개의 디퓨저 뚜껑을 열어둘 예정이고, 6 * 8 의 강의실 정보가 다음과 같이 주어졌다고 하자.

diffuser1
[그림 1]

[그림 1]의 상황에서 나올 수 있는 모든 가짓수를 행동에 옮겼을 경우 다음과 같이 향이 퍼진다.

diffuser2
[그림 2]

따라서, [그림 1]의 상황에서 강의실 전체에 디퓨저 향이 퍼지는데에 걸리는 최소 시간은 7초이다.

강의실 정보와 뚜껑을 열어둘 디퓨저 병의 개수가 주어졌을때, 
디퓨저 향이 강의실 전체에 퍼지는데 필요한 최소 시간을 알아내보자.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다. 
각각의 테스트 케이스의 첫 번째 줄에 강의실의 크기 N, M과 
열어둘 디퓨저 병의 개수 K가 공백을 통해 구분하여 주어진다. 
두 번째 줄부터 N개의 줄에 걸쳐 강의실 각 격자칸의 정보가 공백을 통해 구분하여 주어진다. 
각 칸에 올 수 있는 숫자는 0, 1, 2이며, 0은 아무것도 없음, 1은 벽, 2는 디퓨저 병을 의미한다. 
강의실 내부에 있는 디퓨저 병 갯수는 최소 K개, 최대 10개이다. (3 ≤ N, M ≤ 100, 1 ≤ K ≤ 10)

 

출력
각 테스트 케이스에 대해 디퓨저 향이 강의실 전체에 퍼지는데 필요한 최소 시간을 출력한다. 
만약 어떠한 디퓨저 조합을 골라도 강의실 전체에 향을 퍼뜨릴 수 없을 경우 -1을 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. 
r은 문제에 대한 결과값을 뜻한다.

 

예제 입력
5
6 8 2
1 0 1 0 0 2 0 0 
0 0 0 1 0 1 1 0 
1 0 1 0 0 0 0 0 
0 2 0 0 0 1 0 0 
0 0 0 0 0 2 0 0 
0 0 1 0 0 1 0 0
4 6 2
0 0 2 1 2 0 
0 0 0 1 2 0 
1 1 0 0 1 1 
0 2 2 0 0 2 
4 6 2
0 0 1 1 0 0 
0 0 2 2 1 0 
2 2 0 2 2 0 
0 0 0 2 0 2 
7 6 2
1 0 0 2 1 2 
2 1 0 1 0 0 
0 1 1 0 0 0 
0 0 1 0 1 1 
1 0 1 0 0 0 
0 0 1 0 0 1 
0 1 0 1 2 0 
3 3 1
1 1 1
2 1 1
2 2 1
예제 출력
#1 7
#2 5
#3 4
#4 -1
#5 0

*/

/*

전형적인 BFS 문제.

가능한 조합을 중복되지 않게 짠 후에, 
그 조합을 통해 얻은 시작 지점을 queue에 넣는다.

그리고 모든 map이 0이 아닌 수가 될 때까지 BFS를 진행한다.

한 번의 BFS가 끝나면, visited에 기록된 숫자중 최댓값을 구하고,
다양한 경우를 통해 나온 최댓값들 중 최솟값을 출력하면 된다.

*/

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXNM = 100 + 10;
const int MAXK = 10 + 10;

int T;
int N, M, K;
int map[MAXNM][MAXNM];
int visited[MAXNM][MAXNM];
int zeroNum;
vector<pair<int, int>> dif;

int comb[MAXK];
queue<pair<int, int>> q;
int myMin;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void getMin() {
  int myMax = -987987987;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      myMax = max(myMax, visited[i][j]);
    }
  }
  
  if(myMin > myMax) myMin = myMax;
}

bool BFS() {
  int cnt = 0;
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    if(cnt == zeroNum) return true;
    
    for(int i=0; i<4; i++) {
      int nextY = front.first + dy[i];
      int nextX = front.second + dx[i];
      
      if(nextY < 1 || nextY > N || nextX < 1 || nextX > M) continue;
      
      if(!visited[nextY][nextX] && map[nextY][nextX] != 1) {
        if(map[nextY][nextX] == 0) cnt++;
        
        visited[nextY][nextX] = visited[front.first][front.second] + 1;
        q.push(make_pair(nextY, nextX));
      }
    }
  }
  
  return cnt == zeroNum ? true : false;
}

void getComb(int x) {
  if(x >= K) {
    // queue와 visited 비우기
    while(!q.empty()) q.pop();
    memset(visited, 0, sizeof(visited));
    
    // queue에 넣기
    for(int i=0; i<K; i++) {
      int y = dif[comb[i]-1].first;
      int x = dif[comb[i]-1].second;
      
      visited[y][x] = 1;
      q.push(make_pair(y, x));
    }
    
    if(BFS()) getMin();
  }
  else {
    for(int i=1; i<=dif.size(); i++) {
      if(x == 0 || comb[x-1] < i) {
        comb[x] = i;
        getComb(x+1);
      }
    }
  }
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    zeroNum = 0;
    dif.clear();
    myMin = 987987987;
    
    scanf("%d %d %d", &N, &M, &K);
    
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=M; j++) {
        scanf("%d", &map[i][j]);
        
        if(map[i][j] == 0) zeroNum++;
        else if(map[i][j] == 2) dif.push_back(make_pair(i, j));
      }
    }
    
    // 조합 구하기
    getComb(0);
    
    if(myMin != 987987987) printf("#%d %d\n", t, myMin-1);
    else printf("#%d -1\n", t);
  }

  return 0;
}