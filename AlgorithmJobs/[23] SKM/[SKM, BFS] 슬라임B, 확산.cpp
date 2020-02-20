/*

문제
들판에 N x M 마리의 슬라임이 옹기종기 모여있습니다. 
슬라임은 서로의 존재를 보호하기 위해 서로 합쳐지는 것을 원하지않는 편입니다. 
하지만 성장기에 있는 슬라임은 상태가 불안정하여 달이 뜬 밤 서로가 근접해 있다면 합체가 일어납니다. 
근접해 있는 슬라임의 질량의 차가 만약 X이상 Y이하라면 서로 합쳐집니다.

밤이 되었을때 성장기 슬라임의 위치에서 상, 하, 좌, 우에 존재하는 성장기 슬라임과 서로 합쳐졌다가, 
다음날 아침이 되면 평균값으로 질량 크기를 나눠 가져서 다시 분리됩니다. 
(구한 평균값에서 나머지는 버립니다) 
합체는 성장기에 있는 슬라임 모두에게 일순간 동시에 일어납니다.

(0, 0)의 위치에 있는 슬라임은 몇 마리의 슬라임과 합쳐질까요?

입력
첫 번째 줄에 들판의 크기 N, M이 주어집니다. 
두 번째 줄부터 N 개의 줄, M 개의 행에 걸쳐 NxM 마리의 슬라임 질량 K가 공백을 통해 구분하여 주어집니다. 
마지막 줄에 질량 크기 차이 범위값 X, Y가 주어집니다. (1 ≤ N, M ≤ 50, 1 ≤ K ≤ 100, 1 ≤ X ≤ Y ≤ 100)

출력
(0, 0)의 위치에 있는 슬라임과 합쳐지는 슬라임의 수를 출력합니다.


입력 예제 1
2 2
40 20
20 30
20 50
출력 예제 1
2

입력 예제 2
2 2
40 20
20 40
20 50
출력 예제 2
3

입력 예제 3
3 3
15 22 78 
58 43 8 
7 52 6 
29 55
출력 예제 3
4

*/

/*

0, 0을 시작 지점으로 DFS 또는 BFS 를 돌리고,
0, 0에 위치한 슬라임과 합체되는 슬라임의 개수를 구하는 문제.

여기서 주의할 점은 다음 지점이 방문이 안 된 지점이라고 해서
방문 처리를 하면 안 된다는 것이다.
(그 지점은 다른 지점에 의해 방문 처리가 되어야 제대로 계산이 될 수도 있기 때문)

따라서 방문 유무를 확인 후, 연이어 X이상 Y이하인지 확인해야 한다.

*/

#include <stdio.h>
#include <queue>

using namespace std;

const int MAXNM = 50 + 10;

int N, M;
int map[MAXNM][MAXNM] = {0, };
int X, Y;

int visited[MAXNM][MAXNM] = {0, };

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int getAbs(int x) {
  if(x >= 0) return x;
  else return -x;
}

void BFS(int y, int x) {
  queue<pair<int, int>> q;
  int sum = 0, cnt = 0;
  visited[y][x] = 1;
  q.push(make_pair(y, x));
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    for(int i=0; i<4; i++) {
      int nextY = front.first + dy[i];
      int nextX = front.second + dx[i];
      
      if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > M-1) continue;
      
      int gap = getAbs(map[nextY][nextX] - map[front.first][front.second]);
      
      if(!visited[nextY][nextX] && X <= gap && gap <= Y) {
        visited[nextY][nextX] = 1;
        
        sum += map[nextY][nextX];
        cnt++;
        q.push(make_pair(nextY, nextX));
      }
    }
  }
  
  printf("%d", cnt);
}

int main() {
  scanf("%d %d", &N, &M);
  
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  
  scanf("%d %d", &X, &Y);
  
  BFS(0, 0);
  
  return 0;
}