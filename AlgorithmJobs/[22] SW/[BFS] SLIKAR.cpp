/*

문제
사악한 암흑의 군주 임정택은 드디어 원하던 마법 구슬을 손에 넣었고, 알랩숲에 홍수를 일으켰다!
이 숲에 살고 있는 고슴도치는 지금 당장 비버의 굴로 가능한 빨리 돌아가 홍수를 피하려고 한다.
알랩숲의 지도는 R행 C열로 구성되어 있다.
비어있는 곳은 '.'로 나타나 있고, 물이 차있는 지역은 '*', 돌은 'X'로 표현되어 있다.
추가적으로, 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 표시되어 있다.
매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. (위, 아래, 오른쪽, 왼쪽)
물은 매 분마다 물이 있는 칸과 적어도 한 변을 공유하는 비어있는 모든 칸에 물이 차게 된다.
물과 고슴도치는 돌을 통과할 수 없다.
또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물은 비버의 소굴로 이동할 수 없다.
알랩숲의 지도가 주어졌을 때,
고슴도치가 안전하게 비버의 굴로 도달하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.
고슴도치는 물이 찰 예정인 칸으로 이동할 수 없음에 주의한다.

입력
첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.
다음 R개 줄에 걸쳐 C개의 문자가 주어진다.('.', '*', 'X', 'D' or 'S')
'D'와 'S'는 하나씩만 주어진다.

출력
첫째 줄에 고슴도치가 비버의 굴로 도달할 수 있는 가장 빠른 시간을 출력한다.
만약, 안전하게 비버의 굴로 이동할 수 없을 경우, "KAKTUS"를 출력한다.

*/

/*

visitedW의 초기값을 0으로 해놓고,
조건문에
visitedW[nextY][nextX] > visited[front.first][front.second] + 1
라고 썼기 때문에 물이 퍼지지 않아도 고슴도치는 물이 퍼졌다고 생각할 수 있다.

따라서 조건문에 visitedW[nextY][nextX] == 0 을 새로 추가하거나, 
visitedW의 초기값을 매우 큰 값으로 설정하면 된다.

*/

#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 60;

int R, C;
char map[MAX][MAX];
int visitedS[MAX][MAX] = {0, }, visitedW[MAX][MAX] = {0, };
int Y, X, destY, destX;
bool isFinished = false;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(queue<pair<int, int>> q, int visited[MAX][MAX], bool flag) {
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    if(flag && front.first == destY && front.second == destX) {
      isFinished = true;
      return;
    }
    
    for(int i=0; i<4; i++) {
      int nextY = front.first + dy[i];
      int nextX = front.second + dx[i];
      
      if(nextY < 0 || nextY > R-1 || nextX < 0 || nextX > C-1) continue;
      
      if(map[nextY][nextX] == 'X') continue;
      if(!flag && map[nextY][nextX] == 'D') continue;
      
      if(!flag && !visited[nextY][nextX]) {
        visited[nextY][nextX] = visited[front.first][front.second] + 1;
        q.push(make_pair(nextY, nextX));
      }
      
      if(flag && !visited[nextY][nextX] && (visitedW[nextY][nextX] > visited[front.first][front.second] + 1 || map[nextY][nextX] == 'D' || visitedW[nextY][nextX] == 0)) {
        visited[nextY][nextX] = visited[front.first][front.second] + 1;
        q.push(make_pair(nextY, nextX));
      }
    }
  }
}

int main() {
  scanf("%d %d", &R, &C);
  
  queue<pair<int, int>> waterQ;
  queue<pair<int, int>> myQ;
  
  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      scanf(" %c", &map[i][j]);
      
      if(map[i][j] == '*') {
        visitedW[i][j] = 1;
        waterQ.push(make_pair(i, j));
      }
      else if(map[i][j] == 'S') {
        visitedS[i][j] = 1;
        myQ.push(make_pair(i, j));
        Y = i;
        X = j;
      }
      else if(map[i][j] == 'D') {
        destY = i;
        destX = j;
      }
    }
  }
  
  // 물 BFS
  BFS(waterQ, visitedW, false); // false면 물
  
  // 고슴도치 BFS
  BFS(myQ, visitedS, true);
    
  if(isFinished) printf("%d\n", visitedS[destY][destX]-1);
  else printf("KAKTUS\n");
  
  return 0;
}

/*

3 3
D.*
...
.S.
-----
3

3 3
D.*
...
..S
-----
KAKTUS

3 6
D...*.
.X.X..
....S.
-----
6

5 4
.D.*
....
..X.
S.*.
....
-----
4

*/