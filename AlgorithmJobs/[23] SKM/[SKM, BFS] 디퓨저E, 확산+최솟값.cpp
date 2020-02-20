/*

문제
N * M 격자판에 K 개의 디퓨저 병이 놓여져있다. 
그 중 하나의 디퓨저 병의 뚜껑을 열었을때, 
격자판 전체에 향이 퍼지는데 걸리는 시간이 최소로 걸리는 시간을 알아보자.

디퓨저에서 나오는 향기는 1초에 한 칸씩 퍼진다. 퍼지는 방향은 상, 하, 좌, 우 4방향이다. 
만약 퍼지는 방향에 장애물이 있을 경우 향기는 퍼지지 않는다. 
디퓨저 병의 뚜껑이 닫혀있는 상태에서는 향이 퍼져나가지 않을뿐, 디퓨저가 있는 칸은 이미 향기롭다.

diffuser-E-1
diffuser-E-2
diffuser-E-3
diffuser-E-4
위의 예에서 최소로 걸리는 시간은 3번째 디퓨저 병을 여는 경우로 8초이다.

입력
첫 번째 줄에 격자판의 크기 N, M이 공백을 통해 구분하여 주어진다.

두 번째 줄부터 N개의 줄에 걸쳐 격자판 정보가 주어진다. 
각 줄은 M개의 숫자로 구성되어 있으며, 각 숫자는 0, 1, 2 중 하나이다. 
0은 아무것도 없음, 1은 장애물, 2는 디퓨저 병을 의미한다.
(3 ≤ N, M ≤ 100, 1 ≤ K ≤ 10)

출력
향이 격자판 전체에 퍼지는데 걸리는 최소 시간을 출력한다. 
만약 모든 디퓨저 병에 대해서 뚜껑을 열어봤지만 어느 디퓨저 병을 열더라도 격자판 전체에 퍼질 수 없는 경우 “-1”을 출력한다.


입력 예제 1
6 8
1 0 1 0 0 2 0 0 
0 0 0 1 0 1 1 0 
1 0 1 0 0 0 0 0 
0 2 0 0 0 1 0 0 
0 0 0 0 0 2 0 0 
0 0 1 0 0 1 0 0
출력 예제 1
8

입력 예제 2
4 6
0 0 2 1 2 0 
0 0 0 0 2 0 
1 1 0 0 1 1 
0 2 2 0 0 2
출력 예제 2
5

입력 예제 3
4 6
0 0 2 1 2 0 
0 0 0 1 2 0 
1 1 0 0 1 1 
0 2 2 0 0 2
출력 예제 3
-1

입력 예제 4
3 3
1 2 1
2 1 1
1 2 2
출력 예제 4
0

*/

/*

각각을 열어봤을 때 최소 일수를 구하는 문제.

주의해야 할 점
1) BFS 함수에서 cnt를 셀 때, map이 0인 경우에만 cnt를 증가시켜야 한다.
2) 이미 디퓨저가 있는 곳은 queue에는 넣어지지만, 향기가 머물러 있기 때문에 일수에는 영향을 주면 안된다.
    따라서 BFS 도중 cnt와 map에 있는 0의 개수가 같아지면, queue가 비어있지 않더라도 함수를 종료해야 한다.
3) BFS 시작 전마다 visited배열을 초기화해줘야 한다.
4) -1이 출력되는 조건을 잘 고려해야 한다.

*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAXNM = 100 + 10;

int N, M;
int map[MAXNM][MAXNM] = {0, };

int Y, X;
int visited[MAXNM][MAXNM] = {0, };

vector<pair<int, int>> dif;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int num = 0;

int BFS(int y, int x) {
  queue<pair<int, int>> q;
  int cnt = 0;
  
  visited[y][x] = 1;
  q.push(make_pair(y, x));
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    if(num == cnt) return cnt;
    
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
  
  return cnt;
}

int main() {
  scanf("%d %d", &N, &M);
  
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      scanf("%d", &map[i][j]);
      
      if(map[i][j] == 0) num++;
      
      if(map[i][j] == 2) dif.push_back(make_pair(i, j));
    }
  }
  
  int cnt;
  int min = 987987987;
  for(int d=0; d<dif.size(); d++) {
    memset(visited, 0, sizeof(visited));
    cnt = BFS(dif[d].first, dif[d].second);
    
    int max = -987987987;
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=M; j++) {
        if(visited[i][j] > max) max = visited[i][j];
      }
    }

    if(num == cnt && min > max) min = max;
  }
  
  if(min != 987987987) printf("%d\n", min-1);
  else printf("-1\n");
  
  return 0;
}