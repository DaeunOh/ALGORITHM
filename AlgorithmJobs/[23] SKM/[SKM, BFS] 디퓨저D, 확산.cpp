/*

문제
N * M 격자판에 K 개의 디퓨저 병이 놓여져있다. 
모든 디퓨저 병의 뚜껑을 열었을때, 격자판 전체에 향이 퍼지는데 걸리는 시간을 알아보자.

디퓨저에서 나오는 향기는 1초에 한 칸씩 퍼진다. 
퍼지는 방향은 상, 하, 좌, 우 4방향이다. 만약 퍼지는 방향에 장애물이 있을 경우 향기는 퍼지지 않는다. 
디퓨저 병의 뚜껑이 닫혀있는 상태에서는 향이 퍼져나가지 않을뿐, 디퓨저가 있는 칸은 이미 향기롭다.

diffuser-D
위의 예에서 걸리는 시간은 4초이다.

입력
첫 번째 줄에 격자판의 크기 N, M이 공백을 통해 구분하여 주어진다.

두 번째 줄부터 N개의 줄에 걸쳐 격자판 정보가 주어진다. 
각 줄은 M개의 숫자로 구성되어 있으며, 각 숫자는 0, 1, 2 중 하나이다. 
0은 아무것도 없음, 1은 장애물, 2는 디퓨저 병을 의미한다.

(3 ≤ N, M ≤ 100, 1 ≤ K ≤ 10)

출력
향이 격자판 전체에 퍼지는데 걸리는 시간을 출력한다. 
만약 격자판 전체에 퍼질 수 없는 경우 “-1”을 출력한다.


입력 예제 1
6 8
1 0 1 0 0 2 0 0 
0 0 0 1 0 1 1 0 
1 0 1 0 0 0 0 0 
0 2 0 0 0 1 0 0 
0 0 0 0 0 2 0 0 
0 0 1 0 0 1 0 0
출력 예제 1
4

입력 예제 2
4 6
0 0 2 1 2 0 
0 0 0 1 2 0 
1 1 0 0 1 1 
0 2 2 0 0 2
출력 예제 2
3

입력 예제 3
7 6 2 // 뭐지?
1 0 0 2 1 2 
2 1 0 1 0 0 
0 1 1 0 0 0 
0 0 1 0 1 1 
1 0 1 0 0 0 
0 0 1 0 0 1 
0 1 0 1 2 0
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

C의 연장 문제. 디퓨저가 2개가 아니라 K개!
하지만 C에서 "2개"라는 개수를 고정하지 않고 구현을 했기에
D문제와 C문제가 코드가 같다!^^

<<디퓨저의 좌표를 처음부터 visited 표시를 하며 queue에 넣고,
이후 그 queue를 가지고 BFS를 돌리는 방식을 활용했다.>>

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

queue<pair<int, int>> q;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int cnt = 0;

void BFS() {
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    for(int i=0; i<4; i++) {
      int nextY = front.first + dy[i];
      int nextX = front.second + dx[i];
      
      if(nextY < 1 || nextY > N || nextX < 1 || nextX > M) continue;
      
      if(!visited[nextY][nextX] && map[nextY][nextX] == 0) {
        cnt++;
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
      
      if(map[i][j] == 0) num++;
      
      if(map[i][j] == 2) {
        visited[i][j] = 1;
        q.push(make_pair(i, j));
      }
    }
  }
  
  BFS();

  int max = -987987987;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      if(visited[i][j] > max) max = visited[i][j];
    }
  }
  
  if(num == cnt) printf("%d\n", max-1);
  else printf("-1\n");
  
  return 0;
}