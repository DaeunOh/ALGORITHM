/*

문제
비행기에서 뛰어내려 특정 좌표에 도착해 전투를 시작한다. 
전투 투시경을 통해 현재 위치에서 모든 적의 위치가 보인다. 
일단 전투를 시작하기 전 현재 위치에서 
각각의 적의 위치까지 도착하는데에 걸리는 시간을 미리 구해놓을려고 한다. 
거리는 현재 위치 (a, b)와 적의 위치 (c, d)를 알면 |a-c| + |b-d| 로 구할 수 있다. 
이동하는데에 소요되는 시간은 격자판 기준 1칸 이동시 1분이 소요된다.

이동은 상하좌우로만 할 수 있으며, 대각선으로는 이동할 수 없다. 
또한, 자신의 레벨보다 높은 레벨의 적을 뚫고 지나갈 수 없다. 
자신의 레벨과 같은 레벨의 적은 잡을 수는 없으나, 지나갈 수 있다. 
만약 거리가 같은 적이 2명 이상일 경우 y 좌표가 작은 적에게 우선 이동한다. 
거리가 같고, y 좌표가 동일한 적이 2명 이상일 경우 x 좌표가 작은 적을 향해 이동한다.

battle_ground-C
전장의 정보와 낙하 지점이 주어졌을때, 낙하 지점에서 각 적까지의 시간을 구하여 출력해보자.

입력
첫 번째 줄에 전장의 크기 N, 현재 레벨 K가 주어진다.

두 번째 줄부터 N개의 줄에 걸쳐 전장의 정보가 주어진다. 
각 줄은 N개의 숫자로 이루어져 있으며, 각 숫자는 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중에 하나이다. 
0은 아무것도 없음, 1 ~ 8은 적, 9는 낙하 지점을 의미한다. 9는 하나만 주어진다.

왼쪽 최상단의 좌표는 (1, 1)이다.
(2 ≤ N ≤ 20, 2 ≤ K ≤ 9)

출력
주어진 전장의 정보에서 현재 레벨보다 낮은 적의 위치 칸은 낙하 지점에서의 시간을 출력한다. 
낙하 지점에서 출발하여 도착할 수 없는 칸은 '-1'을 출력한다. 
같은 레벨일 경우 '.'을 출력하고, 높은 레벨일 경우 'X'를 출력한다. 
낙하 지점은 '*'로 출력한다. 
나머지 칸의 경우 '0'을 출력한다.

입력의 예 1
5 2
0 1 0 1 0 
0 0 0 0 2 
0 2 0 2 0 
3 3 9 0 0 
1 3 0 0 0
출력의 예 1
0 4 0 4 0
0 0 0 0 .
0 . 0 . 0
X X * 0 0
-1 X 0 0 0

입력의 예 2
6 4
3 2 5 0 9 0
0 3 0 0 4 0
2 0 0 2 5 4
7 0 0 1 3 2
2 2 0 1 7 1
4 3 2 3 8 2 
출력의 예 2
6 5 X 0 * 0
0 4 0 0 . 0
6 0 0 3 X .
X 0 0 4 5 4
8 7 0 5 X 5
. 8 7 6 X 6

*/

/*

전장속으로B 문제를 풀면서, BFS로 구현하지 않아도 되는 문제를
BFS 형식으로 구현했다고 썼는데,

다행히도 거리를 구하는 방식에서 장애물이 존재하기 때문에
BFS 방식을 사용하면 쉽게 구할 수 있다는 장점이 있었다.

역시 코딩은 정해진 답이 있는게 아니었다.ㅎㅎ 이래서 코딩이 좋다^^

*/

#include <stdio.h>
#include <queue>

using namespace std;

const int MAXN = 20 + 10;

int N, K;
int map[MAXN][MAXN] = {0, };
int visited[MAXN][MAXN] = {0, };

int y, x;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS() {
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
        if(map[nextY][nextX] <= K) q.push(make_pair(nextY, nextX));
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &K);
  
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      scanf("%d", &map[i][j]);
      
      if(map[i][j] == 9) {
        y = i;
        x = j;
      }
    }
  }
  
  BFS();
  
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      if(map[i][j] == 0) printf("0 ");
      else if(map[i][j] == 9) printf("* ");
      else {
        if(map[i][j] > K) printf("X ");
        else if(map[i][j] == K) printf(". ");
        else printf("%d ", visited[i][j] - 1);
      }
    }
    printf("\n");
  }
  
  return 0;
}