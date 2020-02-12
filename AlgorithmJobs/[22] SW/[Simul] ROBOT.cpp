/*

문제
많은 공장에서 로봇이 이용되고 있다. 
우리 월드 공장의 로봇은 바라보는 방향으로 궤도를 따라 움직이며, 
움직이는 방향은 동, 서, 남, 북 가운데 하나이다. 
로봇의 이동을 제어하는 명령어는 다음과 같이 두 가지이다.

명령 1. Go k

k는 1, 2 또는 3일 수 있다. 
현재 향하고 있는 방향으로 k칸 만큼 움직인다.
명령 2. Turn dir

dir은 left 또는 right 이며, 각각 왼쪽 또는 오른쪽으로 90° 회전한다.
공장 내 궤도가 설치되어 있는 상태가 아래와 같이 0과 1로 이루어진 직사각형 모양으로 로봇에게 입력된다. 
0은 궤도가 깔려 있어 로봇이 갈 수 있는 지점이고, 
1은 궤도가 없어 로봇이 갈 수 없는 지점이다. 
로봇이 (4, 2) 지점에서 남쪽을 향하고 있을 때, 
이 로봇을 (2, 4) 지점에서 동쪽으로 향하도록 이동시키는 것은 아래와 같이 9번의 명령으로 가능하다.

ROBOT

로봇의 현재 위치와 바라보는 방향이 주어졌을 때, 로봇을 원하는 위치로 이동시키고, 
원하는 방향으로 바라보도록 하는데 최소 몇 번의 명령이 필요한지 구하는 프로그램을 작성하시오.

 

입력
첫째 줄에 공장 내 궤도 설치 상태를 나타내는 
직사각형의 세로 길이 M과 가로 길이 N이 빈칸을 사이에 두고 주어진다. 
이때 M과 N은 둘 다 100이하의 자연수이다. 
이어 M줄에 걸쳐 한 줄에 N개씩 각 지점의 궤도 설치 상태를 나타내는 숫자 0 또는 1이 빈칸을 사이에 두고 주어진다. 
다음 줄에는 로봇의 출발 지점의 위치 (행과 열의 번호)와 바라보는 방향이 빈칸을 사이에 두고 주어진다. 
마지막 줄에는 로봇의 도착 지점의 위치 (행과 열의 번호)와 바라보는 방향이 빈칸을 사이에 두고 주어진다. 
방향은 동쪽이 1, 서쪽이 2, 남쪽이 3, 북쪽이 4로 주어진다. 
출발지점에서 도착지점까지는 항상 이동이 가능하다.

 

출력
첫째 줄에 로봇을 도착 지점에 원하는 방향으로 이동시키는데 필요한 최소 명령 횟수를 출력한다.

 

예제 입력
5 6
0 0 0 0 0 0
0 1 1 0 1 0
0 1 0 0 0 0
0 0 1 1 1 0
1 0 0 0 0 0
4 2 3
2 4 1
예제 출력
9

*/

/*

이전에 풀었던 BFS 문제들과 달리 해당 문제는 좌표뿐만 아니라 
"방향"이 추가적으로 존재하므로 visited의 차원을 아래와 같이 한개 더 늘려주어야 한다.

int visited[MAX][MAX][MAX] = {0, };

또한, 한 번에 갈 수 있는 칸의 수가 최대 3개이며, 
방향을 돌릴 수 있다는 점을 반영해야 하기 때문에 한 level에 할 수 있는 일이 총 3가지가 된다.
1) 방향을 유지하며 최대 3칸까지 전진
2, 3) 왼쪽, 오른쪽으로 90도 회전

마지막으로 방향 별로 if문을 짜는 것보다 
아래와 같이 반복문을 이용해 간결하게 코드를 짜는 것이 훨씬 효율적이다.

    for(int j=1; j<=3; j++) {
      int nextY = front.y + dy[front.d-1] * j;
      int nextX = front.x + dx[front.d-1] * j;
      
      if(nextY < 1 || nextY > M || nextX < 1 || nextX > N) break;
      if(map[nextY][nextX] == 1) break;
      
      if(visited[nextY][nextX][front.d]) continue;
      if(!visited[nextY][nextX][front.d]) {
        visited[nextY][nextX][front.d] = visited[front.y][front.x][front.d] + 1;
        q.push(ROBOT(nextY, nextX, front.d));
      }
    }

조건이 꽤 까다로워서 구현하기가 쉽지만은 않은 문제였다.
하지만 정확하게 조건을 파악하고, 레벨 별로 할 일을 나누면서 구현한다면
큰 문제는 없을 문제이다.

*/

#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 110;

int M, N;
int map[MAX][MAX] = {0, };
int visited[MAX][MAX][MAX] = {0, };

int Y, X, dir;
int destY, destX, destDir;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

struct ROBOT {
  int y;
  int x;
  int d;
  
  ROBOT(int Y, int X, int DIR){
    y = Y;
    x = X;
    d = DIR;
  }
};

void BFS(int y, int x, int d) {
  queue<ROBOT> q;
  int cnt = 0;
  visited[y][x][d] = 1;
  
  q.push(ROBOT(y, x, d));
  
  while(!q.empty()) {
    ROBOT front = q.front();
    q.pop();

    if(front.y == destY && front.x == destX && front.d == destDir) {
      printf("%d", visited[destY][destX][destDir] - 1);
      return;
    }
    
    // 1. 방향 그대로 최대 3칸까지 가보기
    
    for(int j=1; j<=3; j++) {
      int nextY = front.y + dy[front.d-1] * j;
      int nextX = front.x + dx[front.d-1] * j;
      
      if(nextY < 1 || nextY > M || nextX < 1 || nextX > N) break;
      if(map[nextY][nextX] == 1) break;
      
      if(visited[nextY][nextX][front.d]) continue;
      if(!visited[nextY][nextX][front.d]) {
        visited[nextY][nextX][front.d] = visited[front.y][front.x][front.d] + 1;
        q.push(ROBOT(nextY, nextX, front.d));
      }
    }
    
    // 2. 방향 꺾기
    if(front.d == 1 || front.d == 2) {
      if(!visited[front.y][front.x][3]) {
        visited[front.y][front.x][3] = visited[front.y][front.x][front.d] + 1;
        q.push(ROBOT(front.y, front.x, 3));
      }
      if(!visited[front.y][front.x][4]) {
        visited[front.y][front.x][4] = visited[front.y][front.x][front.d] + 1;
        q.push(ROBOT(front.y, front.x, 4));
      }
    }
    else if(front.d == 3 || front.d == 4) {
      if(!visited[front.y][front.x][1]) {
        visited[front.y][front.x][1] = visited[front.y][front.x][front.d] + 1;
        q.push(ROBOT(front.y, front.x, 1));
      }
      if(!visited[front.y][front.x][2]) {
        visited[front.y][front.x][2] = visited[front.y][front.x][front.d] + 1;
        q.push(ROBOT(front.y, front.x, 2));
      }
    }
  }
}

int main() {
  scanf("%d %d", &M, &N);
  
  for(int i=1; i<=M; i++) {
    for(int j=1; j<=N; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  
  scanf("%d %d %d", &Y, &X, &dir);
  scanf("%d %d %d", &destY, &destX, &destDir);
  
  
  BFS(Y, X, dir);
  
  return 0;
}