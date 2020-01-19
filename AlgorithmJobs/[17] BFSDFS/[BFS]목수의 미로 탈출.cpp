#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 1010;

int N, M;
int map[MAX][MAX] = {0, };
int visitedS[MAX][MAX] = {0, }, visitedE[MAX][MAX] = {0, };

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(int y, int x, int visited[MAX][MAX]) {
  queue <pair <int, int> > q;
  int cnt = 1;
  visited[y][x] = cnt;
  q.push(make_pair(y, x));
  
  while(!q.empty()) {
    pair <int, int> front = q.front();
    q.pop();
    
    for(int i=0; i<4; i++) {
      int nextY = front.first + dy[i];
      int nextX = front.second + dx[i];
      
      if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > M-1) continue;
      
      if(map[nextY][nextX] == 0 && !visited[nextY][nextX]) {
        visited[nextY][nextX] = visited[front.first][front.second] + 1;
        q.push(make_pair(nextY, nextX));
      }
      else if(map[nextY][nextX] == 1 && !visited[nextY][nextX]) {
        visited[nextY][nextX] = visited[front.first][front.second] + 1;
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  
  BFS(N-1, 0, visitedS);
  BFS(0, M-1, visitedE);
  
  int min = 987987987;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(visitedS[i][j] == 0 || visitedE[i][j] == 0) continue;
      
      int dist = visitedS[i][j] + visitedE[i][j] - 2;
      if(min > dist) min = dist;
    }
  }
  
  printf("%d\n", min);
  
  return 0;
}