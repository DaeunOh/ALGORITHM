#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 1010;

int N, M;
bool map[MAX][MAX] = {0, };
int visited[MAX][MAX] = {0, };
int dist = 1;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS() {
  visited[N-1][0] = 1;
  queue<pair<int, int>> q;
  q.push(make_pair(N-1, 0));
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    if(front.first == 0 && front.second == M-1) return;
    q.pop();
      
    for(int i=0; i<4; i++) {
      int nextY = front.first + dy[i];
      int nextX = front.second + dx[i];
      
      if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > M-1) continue;
      
      if(!visited[nextY][nextX] && map[nextY][nextX] == 0) {
        visited[nextY][nextX] = visited[front.first][front.second] + 1;
        q.push(make_pair(nextY, nextX));
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
  
  BFS();
  
  printf("%d\n", visited[0][M-1] - 1);
  
  return 0;
}