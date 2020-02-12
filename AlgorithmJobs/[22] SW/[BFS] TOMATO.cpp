/*

문제
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다.
토마토는 아래의 그림과 같이 격자모양 상자의 칸에 하나씩 넣은 다음,
상자들을 수직으로 쌓아 올려서 창고에 보관한다.

<그림>

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다.
보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.
하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다.
대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다.
철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.
토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때,
며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라.
단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H 가 주어진다.
M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다.
단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다.
둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다.
즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다.
각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다.
정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
이러한 N개의 줄이 H 번 반복하여 주어진다.

출력
여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다.
만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고,
토마토가 모두 익지는 못하는 상황이면 -1 을 출력해야 한다.

*/

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 110;

int M, N, H; // M: 가로, N: 세로, H: 높이
int tomato[MAX][MAX][MAX];
int visited[MAX][MAX][MAX] = {0, };
int tomatoNum = 0;
int maxDay = -987987987;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct TOMATO {
  int h, y, x;
  TOMATO(int H, int Y, int X) {
    h = H;
    y = Y;
    x = X;
  }
};

queue <TOMATO> q;

void BFS() {
  while(!q.empty()) {
    TOMATO front = q.front();
    q.pop();
    
    if(maxDay < visited[front.h][front.y][front.x]) {
      maxDay = visited[front.h][front.y][front.x];
    }
    
    for(int i=0; i<4; i++) {
      int nextY = front.y + dy[i];
      int nextX = front.x + dx[i];
      
      if(nextY < 1 || nextY > N || nextX < 1 || nextY > M) continue;
      
      if(tomato[front.h][nextY][nextX] == 0 && !visited[front.h][nextY][nextX]) {
        visited[front.h][nextY][nextX] = visited[front.h][front.y][front.x] + 1;
        tomatoNum--;
        tomato[front.h][nextY][nextX] = 1;
        q.push(TOMATO(front.h, nextY, nextX));
      }
    }
    
    // 위
    if(tomato[front.h+1][front.y][front.x] == 0 && !visited[front.h+1][front.y][front.x]) {
      visited[front.h+1][front.y][front.x] = visited[front.h][front.y][front.x] + 1;
      tomato[front.h+1][front.y][front.x] = 1;
      tomatoNum--;
      q.push(TOMATO(front.h+1, front.y, front.x));
    }
    
    // 아래
    if(tomato[front.h-1][front.y][front.x] == 0 && !visited[front.h-1][front.y][front.x]) {
      visited[front.h-1][front.y][front.x] = visited[front.h][front.y][front.x] + 1;
      tomato[front.h-1][front.y][front.x] = 1;
      tomatoNum--;
      q.push(TOMATO(front.h-1, front.y, front.x));
    }
  }
} 

int main() {
  scanf("%d %d %d", &M, &N, &H);
  
  memset(tomato, -1, sizeof(tomato));
  
  for(int h=1; h<=H; h++) {
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=M; j++) {
        scanf("%d", &tomato[h][i][j]);
        if(tomato[h][i][j] == 0) tomatoNum++;
      }
    }
  }
  
  if(tomatoNum == 0) {
    printf("0\n");
    return 0;
  }
  
  for(int h=1; h<=H; h++) {
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=M; j++) {
        if(tomato[h][i][j] == 1 && !visited[h][i][j]) {
          visited[h][i][j] = 1;
          q.push(TOMATO(h, i, j));
        }
      }
    }
  }
  
  BFS();
  
  if(tomatoNum == 0) printf("%d\n", maxDay-1);
  else printf("-1\n");

  return 0;
}

/*

5 3 1
0 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1
-------------
-1

5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
------------
4

4 3 2
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
-1 -1 -1 -1
1 1 1 -1
--------------
0

*/