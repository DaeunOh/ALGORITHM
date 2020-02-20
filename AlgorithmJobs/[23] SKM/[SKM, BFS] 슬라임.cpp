/*

문제
들판에 NxM 마리의 슬라임이 옹기종기 모여있습니다. 
슬라임은 서로의 존재를 보호하기 위해 서로 합쳐지는 것을 원하지않는 편입니다. 
하지만 성장기에 있는 슬라임은 상태가 불안정하여 달이 뜬 밤 서로가 근접해 있다면 합체가 일어납니다. 
근접해 있는 슬라임의 질량의 차가 만약 X이상 Y이하라면 서로 합쳐집니다. 
밤이 되었을때 성장기 슬라임의 위치에서 상, 하, 좌, 우에 존재하는 성장기 슬라임과 서로 합쳐졌다가, 
다음날 아침이 되면 평균값으로 질량 크기를 나눠 가져서 다시 분리됩니다. 
합체는 성장기에 있는 슬라임 모두에게 일순간 동시에 일어납니다.

slime1
[그림 1]

위와 같은 예시에서 만약 X가 20이고, Y가 50이라고 가정합니다. 
그렇다면 첫 날 밤 A, B, C 슬라임이 서로 연결되어 합쳐져서 
40 + 20 + 20 = 80 인 무게를 가진 하나의 슬라임이 됩니다. 
다음날 아침 슬라임의 수인 3으로 나눈 값, 26의 질량을 서로 나눠 가진 상태로 분리됩니다.
(나머지는 버립니다.)

slime2
[그림 2]

다음 상황에서는 아무리 많은 밤이 찾아와도 슬라임은 더 이상 합쳐질 수 없는 상태에 놓입니다.
 NxM 마리의 성장기에 있는 슬라임이 주어졌을 때 몇 일이 지나야 
더 이상 합체가 일어나지 않는지 알아내는 프로그램을 작성해주세요.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어집니다.(1 ≤ T ≤ 50) 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어집니다. 
각각의 테스트 케이스의 첫째 줄에 들판의 크기 N, M이 주어집니다. 
둘째 줄부터 N 개의 줄, M 개의 행에 걸쳐 NxM 마리의 슬라임 질량 K가 공백을 통해 구분하여 주어집니다. 
마지막 줄에 질량 크기 차이 범위값 X, Y가 주어집니다. 
(1 ≤ N, M ≤ 50, 1 ≤ K ≤ 100, 1 ≤ X ≤ Y ≤ 100)

 

출력
각 테스트 케이스에 대해 몇 일이 지나야 더 이상 합체가 일어나지 않는지 출력합니다. 
각 테스트 케이스의 출력 양식은 "#t r"입니다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다.
r은 문제에 대한 결과값을 뜻합니다.

 

예제 입력
5
2 2
40 20
20 30
20 50
2 2
40 20
20 40
20 50
3 3
15 22 73 
58 43 8 
7 52 6 
29 55
3 3
5 91 69 
66 2 93 
73 83 78 
43 50
20 14
4 3 4 85 33 96 88 4 4 3 4 95 75 3 
4 25 52 95 58 4 3 48 3 28 4 3 20 28 
4 25 49 55 73 3 75 19 41 4 3 4 17 3 
63 58 33 98 3 58 44 36 48 90 50 3 3 36 
79 44 43 17 20 19 53 35 35 24 27 4 95 49 
4 4 70 31 36 4 3 14 4 3 92 69 4 46 
4 65 3 69 13 90 84 26 74 18 84 3 58 67 
12 4 98 11 3 41 3 4 4 4 4 57 53 24 
96 13 23 3 3 24 85 4 48 4 83 3 7 4 
63 26 61 60 3 4 47 37 27 4 42 3 61 14 
4 3 3 37 92 52 26 4 4 91 4 4 3 85 
10 4 3 3 43 61 4 4 3 26 3 4 4 83 
4 4 3 56 32 3 3 3 36 4 4 4 46 74 
22 4 48 3 61 7 35 75 58 8 14 98 9 78 
70 3 3 3 34 4 72 14 33 47 56 3 9 4 
91 61 4 4 72 48 3 3 3 46 93 3 60 69 
4 84 65 64 51 4 86 4 4 86 4 3 45 4 
67 15 3 4 4 93 75 56 40 76 3 35 77 53 
34 27 88 8 3 3 4 4 62 3 4 13 31 7 
11 22 35 42 3 92 51 89 66 59 60 23 3 41 
7 99
예제 출력
#1 1
#2 1
#3 1
#4 0
#5 5

*/

/*

합쳐지는 슬라임이 있다면 분리시킨 후 업데이트하고 다시 BFS 돌리기.
없다면 while문 종료(BFS 종료)

최종적으로는 며칠이 걸렸는지 day를 출력한다.

*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXNM = 50 + 10;

int T;
int N, M;
int map[MAXNM][MAXNM] = {0, };
int X, Y;

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
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        scanf("%d", &map[i][j]);
      }
    }
    
    scanf("%d %d", &X, &Y);
    
    int day = 0;
    while(1) {
      memset(visited, 0, sizeof(visited));
      
      bool flag = false;
      for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
          if(!visited[i][j]) {
            BFS(i, j);
            
            if(cnt > 1) {
              flag = true;
              for(int k=0; k<g.size(); k++) map[g[k].first][g[k].second] = sum / cnt;
            }
          }
        }
      }
      
      if(flag) day++;
      else break;
    }
    
    printf("#%d %d\n", t, day);
  }

  return 0;
}