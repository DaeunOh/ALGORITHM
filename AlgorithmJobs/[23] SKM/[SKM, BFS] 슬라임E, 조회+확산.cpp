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

오늘 밤 합쳐진 슬라임이 2일 뒤 나눠갖게 되는 무게는 합쳐진 그룹별로 어떻게 될까요?

입력
첫 번째 줄에 들판의 크기 N, M이 주어집니다. 
두 번째 줄부터 N 개의 줄, M 개의 행에 걸쳐 NxM 마리의 슬라임 질량 K가 공백을 통해 구분하여 주어집니다. 
마지막 줄에 질량 크기 차이 범위값 X, Y가 주어집니다. 
(1 ≤ N, M ≤ 50, 1 ≤ K ≤ 100, 1 ≤ X ≤ Y ≤ 100)

출력
합쳐진 슬라임이 나눠갖게 되는 무게는 합쳐진 그룹별 한 줄에 하나씩 출력합니다. 
이때 무게는 내림차순으로 출력합니다. 
만약 합쳐지는 슬라임이 없다면 "-1"을 출력합니다.


입력 예제 1
2 2
40 20
20 30
20 50
출력 예제 1
-1

입력 예제 2
2 2
40 20
20 40
20 50
출력 예제 2
-1

입력 예제 3
3 3
15 22 78 
58 43 8 
7 52 6 
29 55
출력 예제 3
51

입력 예제 4
5 8
40 46 12 44 41 50 36 3 
66 52 18 1 36 96 78 23 
23 28 37 3 43 86 43 17 
95 31 3 91 82 43 82 32 
65 5 80 3 89 94 9 17 
15 24
출력 예제 4
32
29
24
20

*/

/*

추가된 내용
1) 합쳐진 슬라임의 좌표를 저장해놔야 한다.
2) 합쳐진 슬라임이 있다면, 다음날 분리된 질량을 맵에 다시 기록해야 한다.
3) 마지막 날에만 결과에 집어 넣는다.

*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXNM = 50 + 10;

int N, M;
int map[MAXNM][MAXNM] = {0, };
int X, Y;
vector<int> res;

int sum, cnt;
vector<pair<int, int>> g;
int visited[MAXNM][MAXNM] = {0, };

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int getAbs(int x) {
  if(x >= 0) return x;
  else return -x;
}

void BFS(int y, int x) {
  g.clear();
  queue<pair<int, int>> q;
  sum = 0, cnt = 0;
  visited[y][x] = 1;
  q.push(make_pair(y, x));
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    sum += map[front.first][front.second];
    g.push_back(make_pair(front.first, front.second));
    cnt++;
    
    for(int i=0; i<4; i++) {
      int nextY = front.first + dy[i];
      int nextX = front.second + dx[i];
      
      if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > M-1) continue;
      
      int gap = getAbs(map[nextY][nextX] - map[front.first][front.second]);
      
      if(!visited[nextY][nextX] && X <= gap && gap <= Y) {
        visited[nextY][nextX] = 1;

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
  
  scanf("%d %d", &X, &Y);
  
  int day = 2;
  
  while(day--) {
    memset(visited, 0, sizeof(visited));
    
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        if(!visited[i][j]) {
          BFS(i, j);
          
          if(cnt > 1) {
            if(day != 0) {
              for(int k=0; k<g.size(); k++) map[g[k].first][g[k].second] = sum / cnt;
            }
            else res.push_back(-sum / cnt);
          }
        }
      }
    }
  }
  
  sort(res.begin(), res.end());
  
  if(res.size() != 0) for(int i=0; i<res.size(); i++) printf("%d\n", -res[i]);
  else printf("-1\n");
  
  return 0;
}