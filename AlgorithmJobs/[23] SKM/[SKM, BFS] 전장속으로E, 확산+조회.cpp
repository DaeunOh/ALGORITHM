/*

문제
비행기에서 뛰어내려 특정 좌표에 도착해 전투를 시작한다. 
낙하한 위치에서 가장 가까운 적을 우선으로 섬멸한다. 
적을 모두 사살하면 게임이 종료된다. 
게임이 종료되기까지 걸리는 시간을 알고 싶다.

이동은 상하좌우로만 할 수 있으며, 대각선으로는 이동할 수 없다. 
이동하는데에 소요되는 시간은 격자판 기준 1칸 이동시 1분이 소요된다. 
만약 거리가 같은 적이 2명 이상일 경우 y 좌표가 작은 적에게 우선 이동한다. 
거리가 같고, y 좌표가 동일한 적이 2명 이상일 경우 x 좌표가 작은 적을 향해 이동한다. 
적의 위치에 도착하자마자 적은 사살되며, 적을 사살하는데에 걸리는 시간은 없다고 본다.

battle_ground-E-1
그림의 왼쪽과 같이 적이 주어지고, (4, 3)의 위치에 낙하했다고 생각해보자. 
그렇다면 오른쪽과 같이 각 적에 대한 이동 소요시간을 알 수 있다.
가장 가까운 위치에 존재하는 (4, 2)에 존재하는 적에게 이동한다.

battle_ground-E-2
(4, 2)로 이동을 한 뒤 다시 각 적에 대한 이동 소요시간을 계산하면 위의 오른쪽 그림과 동일하다. 
가장 가까운 적 중에서 위에 있는 적에게 가야되므로 (3, 2)로 이동한다. 
위 예시에서 적을 모두 섬멸하는데에 걸리는 시간은 15 이다.

위와 같은 절차를 적이 모두 없어질때까지 반복한다고 했을때, 
주어진 전장의 정보에서 적을 모두 없애기까지 이동한 거리를 구해보자.

입력
첫 번째 줄에 전장의 크기 N이 주어진다.

두 번째 줄부터 N개의 줄에 걸쳐 전장의 정보가 주어진다. 
각 줄은 N개의 숫자로 이루어져 있으며, 각 숫자는 0, 1, 9 중에 하나이다. 
0은 아무것도 없음, 1은 적, 9는 낙하 지점을 의미한다. 9는 하나만 주어진다.

왼쪽 최상단의 좌표는 (1, 1)이다.
(2 ≤ N ≤ 20)

출력
주어진 전장의 정보에서 적을 모두 없애기까지 이동한 거리를 출력한다.


입력의 예 1
5
0 1 0 1 0 
0 0 0 0 1 
0 1 0 1 0 
0 1 9 0 0 
1 1 0 0 0
출력의 예 1
15

입력의 예 2
7
1 1 0 1 9 1 1 
1 1 1 1 1 1 1 
1 0 1 1 1 1 1 
1 0 0 1 1 1 1 
0 0 1 1 1 0 1 
1 1 1 1 1 1 1 
1 1 1 0 1 0 1
출력의 예 2
46

*/

#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 20 + 10;

int N, K;
int map[MAXN][MAXN] = {0, };
int visited[MAXN][MAXN] = {0, };
int Y, X;
int enemyNum;
int myMin;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(int y, int x) {
  queue<pair<int, int>> q;
  
  visited[y][x] = 1;
  q.push(make_pair(y, x));
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    for(int i=0; i<4; i++) {
      int nextY = front.first + dy[i];
      int nextX = front.second + dx[i];
      
      if(nextY < 1 || nextY > N || nextX < 1 || nextX > N) continue;
      
      if(!visited[nextY][nextX]) {
        visited[nextY][nextX] = visited[front.first][front.second] + 1;
        q.push(make_pair(nextY, nextX));
      }
    }
  }
}

int main() {
  enemyNum = 0;
  scanf("%d", &N);
  
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      scanf("%d", &map[i][j]);
      
      if(map[i][j] == 1) enemyNum++;
      else if(map[i][j] == 9) {
        Y = i;
        X = j;
      }
    }
  }
  
  int cnt = 0;
  while(enemyNum != 0) {
    memset(visited, 0, sizeof(visited));
    BFS(Y, X);
    
    myMin = 987987987;
    
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
        if(map[i][j] == 0 || map[i][j] == 9) continue;
        
        if(visited[i][j] != 0) {
          if(myMin > visited[i][j] - 1) {
            myMin = visited[i][j] - 1;
            Y = i;
            X = j;
          }
        }
      }
    }
    
    cnt += visited[Y][X] - 1;
    map[Y][X] = 0;
    enemyNum--;
  }

  printf("%d\n", cnt);
  
  return 0;
}