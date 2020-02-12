/*

시간제한 7초

문제
민건이는 원룸 청소하기 너무 귀찮아서 로봇청소기를 하나 구매했다. 
로봇 청소기는 원룸 바닥을 돌아다니며, 열심히 바닥에 있는 먼지를 청소한다. 
돈이 없는 민건이는 값싼 로봇 청소기를 구매하였다. 
해당 로봇 청소기는 원룸 구조를 파악하여 똑똑하게 이동하는 것이 아닌 
그냥 벽에 부딪히면 튕겨나온 방향으로 움직이는 무식한(?) 청소기이다. 
벽이나 구조물을 만나기 전까지 계속해서 직진만 하며, 
벽이나 구조물에 부딪히는 순간 방향을 틀어서 움직인다. 
예를 들어, 벽이나 구조물에 부딪히면 다음과 같이 직각 혹은 반대 방향으로 움직인다.

robot_1[그림 1]

구조물은 회전이 가능하며, 현재 [그림 1]의 왼편에 나오는 구조물의 번호는 1번이다. 
해당 구조물을 시계 방향으로 90° 회전시킬시 2번, 
180° - 3번, 270° - 4번, 360° 는 구조물 1번과 동일하므로 1번이다. 
[그림 1]의 오른편에 나오는 구조물은 5번으로 붙혔다. 그림으로 표현하면 다음과 같다.

robot_2[그림 2]

무식한(?) 청소기답게 현재 높이보다 낮은 턱에 빠지면 더 이상 움직일 수 없어서 꺼내줘야한다. 
낮은 턱의 경우 집 구조 상 어디든 존재하고 원룸 구조도에 “-1”로 표기한다. 
또한 특이하게 다른 원룸과 달리 바닥에 최대 5쌍의 워프 장치가 있는데, 
워프 장치 한 쪽으로 갈 경우 다른 한 쪽으로 이동하게 된다.
(그래서 바닥에 물건을 떨어뜨리면 찾기가 쉽지않다.) 
이때 워프 장치를 통과한 후 진행방향은 워프 진입 직전의 진행 방향과 동일하다. 
워프 장치는 번호는 6번부터 10번까지 존재하고, 원룸 구조도에 무조건 한 쌍으로 표기되어있다.

robot_3[그림 3]

robot_4[그림 4]

robot_5[그림 5]robot_6[그림 6]robot_7[그림 7]

[그림 4] 와 같은 원룸 구조도가 주어졌을 때, 로봇청소기의 이동 사례를 살펴보면 다음과 같다. 
[그림 5] 의 경우 시작지점으로 다시 돌아와서 이동이 종료되었고, 
[그림 6] 의 경우 낮은 턱에 빠져버려서 이동이 종료되었다. 
[그림 7] 의 경우 벽에 부딪혀 튕겨져나와, [그림 5] 와 동일하게 시작지점으로 돌아와서 이동이 종료되었다. 
[그림 5] 의 이동한 칸의 수는 6 이고, [그림 6] 의 이동한 칸의 수는 9 이다. 
[그림 7] 의 이동한 칸의 수는 4 이다. 시작 위치는 구조물, 워프 장치, 낮은 턱이 될 수 없다. 
그 이외의 모든 공간에서는 청소를 시작할 수 있다.

원룸 구조는 N x N m2 이며, 로봇 청소기는 한 번에 한 칸씩 움직일 수 있다. 
다시 말하면, 1m2 씩 움직일 수 있다. 로봇 청소기가 출발한 위치로 다시 돌아오고, 
시작한 방향과 동일한 방향을 보고 있을때 작동을 멈춘다. 
혹은 청소 진행 도중에 낮은 턱에 빠져버릴 경우 그대로 작동을 중지한다. 
현재 민건이는 로봇청소기가 얼마나 열심히 일하는지 알고싶다. 
원룸 구조도가 주어지고, 로봇 청소기가 임의의 위치에서 임의의 방향을 보고 이동을 시작하여, 
끝나기까지 한 번이라도 지나간 칸의 수를 D 라고 하였을 때, D 의 최댓값을 구해보자! 
(단, D의 경로에는 낮은 턱이 포함되지 않는다.)

 

입력
첫 번째 줄에 테스트 케이스의 개수 T(5 ≤ T ≤ 50) 가 주어진다. 
각 테스트 케이스의 첫째 줄에 N(5 ≤ N ≤ 100) 이 주어지고, 
N 개의 줄에 걸쳐 N 개의 숫자가 공백을 통해 구분하여 입력된다. 
각각의 입력되는 숫자는 -1 부터 10까지의 정수이다. 
워프 장치는 최대 5쌍 존재한다. 낮은 턱은 최대 5개 존재할 수 있으며, 최소 1개 존재한다.

 

출력
각 테스트 케이스에 해당하는 결과값을 “#t result” 포맷으로 출력한다. (t는 1부터 T까지의 정수이다)

 

예제 입력
4
5
0 4 0 0 0
0 0 3 6 0
0 2 0 0 5
0 0 -1 0 0
0 6 0 1 0
8
0 0 1 1 0 0 0 4
0 0 0 0 0 0 5 0
0 0 0 3 0 0 0 0
2 0 0 4 3 4 0 0
0 0 0 0 0 0 0 0
0 0 2 0 0 5 0 0
0 0 5 0 3 0 0 0
0 0 4 0 0 3 1 0
4
1 1 1 1
1 1 -1 1
1 -1 0 -1
1 1 -1 1
4
0 0 0 4
0 0 4 0
2 -1 5 0
6 1 5 6
예제 출력
#1 9
#2 11
#3 1
#4 8

*/

#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 110;
const int dirMAX = 4;
const int warpMAX = 20;

int T;
int N;
int map[MAX][MAX];
int visited[MAX][MAX];
pair<int, int> warp[MAX][MAX][warpMAX];
vector<pair<int, int>> temp[warpMAX];


int dy[dirMAX] = {-1, 1, 0, 0};
int dx[dirMAX] = {0, 0, -1, 1};

struct ROBOT{
  int y;
  int x;
  int d;
  
  ROBOT(int Y, int X, int D){
    y = Y;
    x = X;
    d = D;
  }
};

pair<bool, int> rotate(int m, int d) {
  // bool이 0이면 90도, 1이면 180도
  
  if(m == 1) {
    if(d == 1) return make_pair(0, 2);
    else if(d == 3) return make_pair(0, 0);
    else if(d == 0) return make_pair(1, 1);
    else if(d == 2) return make_pair(1, 3);
  }
  else if(m == 2) {
    if(d == 1) return make_pair(0, 3);
    else if(d == 2) return make_pair(0, 0);
    else if(d == 0) return make_pair(1, 1);
    else if(d == 3) return make_pair(1, 2);
  }
  else if(m == 3) {
    if(d == 2) return make_pair(0, 1);
    else if(d == 0) return make_pair(0, 3);
    else if(d == 3) return make_pair(1, 2);
    else if(d == 1) return make_pair(1, 0);
  }
  else if(m == 4) {
    if(d == 3) return make_pair(0, 1);
    else if(d == 0) return make_pair(0, 2);
    else if(d == 1) return make_pair(1, 0);
    else if(d == 2) return make_pair(1, 3);
  }
  else if(m == 5) {
    if(d == 0) return make_pair(1, 1);
    else if(d == 1) return make_pair(1, 0);
    else if(d == 2) return make_pair(1, 3);
    else if(d == 3) return make_pair(1, 2);
  }
}

int BFS(int y, int x, int d) {
  queue <ROBOT> q;
  int cnt = 0;
  int total_cnt = 0;
  
  visited[y][x] = true;
  cnt++;
  q.push(ROBOT(y, x, d));
  
  while(!q.empty()) {
    ROBOT front = q.front();
    q.pop();
    total_cnt++;
    
    if(total_cnt != 1 && front.y == y && front.x == x && front.d == d) return cnt;
    
    int nextY = front.y + dy[front.d];
    int nextX = front.x + dx[front.d];
    
    if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > N-1) {
      int dir;
      
      if(nextY < 0) dir = 1;
      else if(nextY > N-1) dir = 0;
      else if(nextX < 0) dir = 3;
      else if(nextX > N-1) dir = 2;
      
      if(map[front.y][front.x] >= 6 && map[front.y][front.x] <= 10) {
        nextY = warp[front.y][front.x][map[front.y][front.x]].first;
        nextX = warp[front.y][front.x][map[front.y][front.x]].second;
      }
        
      q.push(ROBOT(nextY, nextX, dir));
    }
    else if(map[nextY][nextX] == -1) {
      return cnt;
    }
    else if(map[nextY][nextX] == 0) {
      if(!visited[nextY][nextX]) {
        visited[nextY][nextX] = true;
        cnt++;
      }
      
      q.push(ROBOT(nextY, nextX, front.d));
    }
    else if(map[nextY][nextX] >= 1 && map[nextY][nextX] <= 5) {
      pair<bool, int> temp = rotate(map[nextY][nextX], front.d);
      
      if(temp.first == 0) {
        if(!visited[nextY][nextX]) {
          visited[nextY][nextX] = true;
          cnt++;
        }
      }
      
      q.push(ROBOT(nextY, nextX, temp.second));
    }
    else if(map[nextY][nextX] >= 6 && map[nextY][nextX] <= 10) {
      if(!visited[nextY][nextX]) {
        visited[nextY][nextX] = true;
        cnt++;
      }
      
      int nextY2 = warp[nextY][nextX][map[nextY][nextX]].first;
      int nextX2 = warp[nextY][nextX][map[nextY][nextX]].second;
      
      if(!visited[nextY2][nextX2]) {
        visited[nextY2][nextX2] = true;
        cnt++;
      }
      
      q.push(ROBOT(nextY2, nextX2, front.d));
    }
  }
  
  return cnt;
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    scanf("%d", &N);
    memset(warp, 0, sizeof(warp));
    temp[6].clear();
    temp[7].clear();
    temp[8].clear();
    temp[9].clear();
    temp[10].clear();
    
    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        scanf("%d", &map[i][j]);
        
        if(map[i][j] >= 6 && map[i][j] <= 10) {
          temp[map[i][j]].push_back(make_pair(i, j));
        }
      }
    }
    
    for(int i=6; i<=10; i++) {
      if(temp[i].size() != 0) {
        warp[temp[i][0].first][temp[i][0].second][i].first = temp[i][1].first;
        warp[temp[i][0].first][temp[i][0].second][i].second = temp[i][1].second;
        
        warp[temp[i][1].first][temp[i][1].second][i].first = temp[i][0].first;
        warp[temp[i][1].first][temp[i][1].second][i].second = temp[i][0].second;
      }
    }
    
    int max = -987987987;
    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        if(map[i][j] == 0) {
          for(int k=0; k<4; k++) {
            int temp = BFS(i, j, k);
            if(max < temp) max = temp;
          
            memset(visited, 0, sizeof(visited));
          }
        }
      }
    }
    
    printf("#%d %d\n", t, max);
  }
  
  return 0;
}