/*

문제
비행기에서 뛰어내려 특정 좌표에 도착해 전투를 시작한다. 
전투 투시경을 통해 현재 위치에서 모든 적의 위치가 보인다. 
일단 전투를 시작하기 전 현재 위치에서 각각의 적의 위치까지 
도착하는데에 걸리는 시간을 미리 구해놓을려고 한다. 
거리는 현재 위치 (a, b)와 적의 위치 (c, d)를 알면 |a-c| + |b-d| 로 구할 수 있다. 
이동하는데에 소요되는 시간은 격자판 기준 1칸 이동시 1분이 소요된다.

battle_ground-B
위 그림과 같이 적들이 존재하는 경우를 예로 들어보자. (4, 3)에 낙하했다면 
오른쪽 그림과 같이 각 적들까지의 거리가 계산된다. 
이동은 상하좌우로만 할 수 있으며, 대각선으로는 이동할 수 없다.

전장의 정보와 낙하 지점이 주어졌을때, 낙하 지점에서 각 적까지의 시간을 구하여 출력해보자.

입력
첫 번째 줄에 전장의 크기 N이 주어진다.

두 번째 줄부터 N개의 줄에 걸쳐 전장의 정보가 주어진다. 
각 줄은 N개의 숫자로 이루어져 있으며, 각 숫자는 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중에 하나이다. 
0은 아무것도 없음, 1 ~ 8은 적, 9는 낙하 지점을 의미한다. 9는 하나만 주어진다.

왼쪽 최상단의 좌표는 (1, 1)이다.
(2 ≤ N ≤ 20)

출력
주어진 전장의 정보에서 적의 위치 칸은 낙하 지점에서의 시간을 출력한다. 
낙하 지점은 '*'로 출력한다. 나머지 칸의 경우 0을 출력한다.


입력의 예 1
5
0 1 0 1 0 
0 0 0 0 2 
0 2 0 2 0 
0 3 9 0 0 
1 3 0 0 0
출력의 예 1
0 4 0 4 0 
0 0 0 0 4 
0 2 0 2 0 
0 1 * 0 0 
3 2 0 0 0

입력의 예 2
7
1 1 0 5 9 1 3 
5 2 3 1 6 2 2 
7 0 5 1 1 4 1 
4 0 0 3 1 2 1 
0 0 1 6 7 0 1 
3 8 1 2 6 1 8 
0 6 1 0 5 0 8
출력의 예 2
4 3 0 1 * 1 2 
5 4 3 2 1 2 3 
6 0 4 3 2 3 4 
7 0 0 4 3 4 5 
0 0 6 5 4 0 6 
9 8 7 6 5 6 7 
0 9 8 0 6 0 8

*/

/*

맵 형태의 그림이 나오길래 당연히 BFS 구나 라고 생각을 하고 BFS 형식으로 구현했는데,
사실 이 문제는 단순 반복문과 조건문으로 해결할 수 있는 문제다.

어려운 쪽으로만 구현을 생각하기 보다, 최대한 쉽게 해결하는 방법을 찾는 연습도 틈틈이!

*/

#include <stdio.h>
#include <queue>

using namespace std;

const int MAXN = 20 + 10;

int N;
int map[MAXN][MAXN] = {0, };
int visited[MAXN][MAXN] = {0, };

queue<pair<int, int>> q;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(int y, int x) {
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
        int distY = y - nextY >= 0 ? y - nextY : nextY - y;
        int distX = x - nextX >= 0 ? x - nextX : nextX - x;
        visited[nextY][nextX] = distY + distX;
        q.push(make_pair(nextY, nextX));
      }
    }
  }
}

int main() {
  scanf("%d", &N);
  
  int Y, X;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      scanf("%d", &map[i][j]);
      
      if(map[i][j] == 9) {
        Y = i;
        X = j;
      }
    }
  }
  
  BFS(Y, X);
  
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      if(map[i][j] == 0) printf("0 ");
      else if(map[i][j] == 9) printf("* ");
      else printf("%d ", visited[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}