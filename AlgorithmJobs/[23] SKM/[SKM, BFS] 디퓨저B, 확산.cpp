/*

문제
N * M 격자판에 1 개의 디퓨저 병이 놓여져있다. 
디퓨저 병의 뚜껑을 열었을때, 격자판 전체에 향이 퍼지는데 걸리는 시간을 알아보자.

디퓨저에서 나오는 향기는 1초에 한 칸씩 퍼진다. 퍼지는 방향은 상, 하, 좌, 우 4방향이다. 
만약 퍼지는 방향에 장애물이 있을 경우 향기는 퍼지지 않는다. 
디퓨저 병의 뚜껑이 닫혀있는 상태에서는 향이 퍼져나가지 않을뿐, 디퓨저가 있는 칸은 이미 향기롭다.

diffuser-B
위의 예에서 걸리는 시간은 9초이다.

입력
첫 번째 줄에 격자판의 크기 N, M이 공백을 통해 구분하여 주어진다.

두 번째 줄부터 N개의 줄에 걸쳐 격자판 정보가 주어진다. 
각 줄은 M개의 숫자로 구성되어 있으며, 각 숫자는 0, 1, 2 중 하나이다. 
0은 아무것도 없음, 1은 장애물, 2는 디퓨저 병을 의미한다. 
디퓨저 병은 격자판에 1개만 존재한다.
(3 ≤ N, M ≤ 100)

출력
향이 격자판 전체에 퍼지는데 걸리는 시간을 출력한다. 
만약 격자판 전체에 퍼질 수 없는 경우 “-1”을 출력한다.



입력 예제 1
6 8
1 0 1 0 0 0 0 0 
0 0 0 1 0 1 1 0 
1 0 1 0 0 0 0 0 
0 2 0 0 0 1 0 0 
0 0 0 0 0 0 0 0 
0 0 1 0 0 1 0 0
출력 예제 1
9

입력 예제 2
4 6
0 0 0 1 0 0 
0 0 0 1 2 0 
1 1 0 0 1 1 
0 0 0 0 0 0
출력 예제 2
-1

*/

/*

BFS로의 상하좌우 탐색이 핵심인 문제.

디퓨저를 시작으로 BFS를 한 후에,
방문된 지점의 개수가 map에서 0또는 2의 개수의 합과 같다면
해당 일수를 출력하면 되고, 그렇지 않으면 -1을 출력한다.

*/

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

const int MAXNM = 100 + 10;

int N, M;
int map[MAXNM][MAXNM] = {0, };

int Y, X;
int visited[MAXNM][MAXNM] = {0, };

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
      
      if(nextY < 1 || nextY > N || nextX < 1 || nextX > M) continue;
      
      if(!visited[nextY][nextX] && map[nextY][nextX] == 0) {
        visited[nextY][nextX] = visited[front.first][front.second] + 1;
        q.push(make_pair(nextY, nextX));
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  
  int num = 0;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      scanf("%d", &map[i][j]);
      
      if(map[i][j] != 1) num++;
      
      if(map[i][j] == 2) {
        Y = i;
        X = j;
      }
    }
  }
  
  BFS(Y, X);
  
  int visitedNum = 0, max = -987987987;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      if(visited[i][j]) {
        visitedNum++;
        if(visited[i][j] > max) max = visited[i][j]; // 또는 algorithm 안에 있는 max사용. res = max(비교값1, 비교값2)
      }
    }
  }
  
  if(num == visitedNum) printf("%d\n", max-1);
  else printf("-1\n");
  
  return 0;
}