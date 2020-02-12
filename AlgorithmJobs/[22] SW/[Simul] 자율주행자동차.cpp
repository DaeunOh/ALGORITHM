/*

시간제한 3초

문제
5G 네트워크가 상용화 됨에 따라 자율주행자동차 또한 상용화될 기미가 보이기 시작했다. 
네트워크 연구실에서 근무하고 있는 수형은 자율주행 시뮬레이터를 만들려고 한다. 
시뮬레이터의 좌표평면의 크기는 2000 * 2000 으로 고정되어있다. 
x, y 좌표의 최댓값과 최솟값은 각각 1000, -1000으로 설정되었다. 
시뮬레이터에서 자동차의 위치는 (x, y)로 설정되며, 각 차들마다 정해진 방향으로 직진한다. 
자동차는 화면에서 1초에 1칸씩 움직이고, 모든 자동차는 최초 위치에서 동시에 이동한다. 
만약 2개 이상의 자동차끼리 충돌하거나 정해진 맵 바깥으로 벗어나면 자동차는 사라진다.

self-driving[그림 1]

[그림 1]의 예처럼 자동차들이 배치되어있고, 각각의 이동방향이 그림처럼 설정되어있다고 가정하자. 
충돌한 좌표를 (x, y)로 표현한다면, 1초가 지났을때 (-1, -1)와 (1, 1)에서 충돌이 일어나 자동차 6대가 사라진다. 
다음으로 2.5초가 경과했을때, (0.5, 1)에서 충돌이 일어나 자동차 2대가 사라진다.

수형은 시뮬레이터를 통해 최대한 충돌 없는 자동차 배치를 알고싶다. 
자동차의 초기 위치 및 방향 (x, y, r) 이 주어졌을때, 
자동차가 좌표평면에서 모두 사라질때까지 자동차끼리 충돌한 횟수를 구해보자. 
(단, 맵을 벗어난 경우는 충돌한 것으로 보지 않는다.)

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다. 
각각의 테스트 케이스의 첫 번째 줄에 자동차의 개수 S가 주어진다. 
두 번째 줄부터 S개의 줄에 걸쳐 자동차 정보가 주어진다. 
자동차 정보는 초기 위치 x, y 와 현재 바라보고 있는 방향 r 이 공백을 통해 구분하여 주어진다. 
r 은 0, 1, 2, 3 중 하나이며, 각각은 상, 하, 좌, 우를 뜻한다. 
자동차의 초기 위치는 모두 다르다. (1 ≤ S ≤ 1,000, -1000 ≤ y, x ≤ 1000)

 

출력
각 테스트 케이스에 대해 자동차가 모두 사라질때까지 자동차끼리 충돌 횟수를 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. r은 문제에 대한 결과값을 뜻한다.

 

예제 입력
5
8
-2 1 3
0 1 3
3 1 2
-1 0 1
1 0 0
-2 -1 3
0 -1 2
-1 -2 0
9
-9 -3 1
-5 7 3
-3 -4 1
10 6 0
7 10 2
-4 7 2
-3 9 0
-2 8 0
-3 -6 0
4
7 -2 1
-9 -10 2
-8 1 0
-10 8 2
7
-10 4 3
5 -2 1
-6 -2 1
-2 6 1
8 -4 2
5 3 3
9 -9 0
5
-4 2 0
-6 4 2
-3 10 3
1 10 2
-7 -8 2
예제 출력
#1 3
#2 2
#3 0
#4 1
#5 1

*/

/*

좌표를 벗어나는 범위를 잘못 계산하고 풀었던 문제.

그동안 풀었던 문제와는 달리 좌표평면에서의 이동이기 때문에 
최대 4001개의 행과 열이 채워질 수 있다(4000개가 아님)

*/

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXCAR = 1000 + 10;
const int MAX = 4000 + 10;

int T;
int S;
int map[MAX][MAX];

// 상하좌우
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct CAR {
  int x, y, r;
  
  void createCAR(int X, int Y, int R) {
    x = X;
    y = Y;
    r = R;
  }
};

vector<CAR> car(MAXCAR);

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    memset(map, 0, sizeof(map));
    scanf("%d", &S);
    int carNum = S;
    
    int x, y, r;
    for(int i=1; i<=S; i++) {
      scanf("%d %d %d", &x, &y, &r);
      CAR c;
      c.createCAR(x*2+2000, y*2+2000, r);
      car[i] = c;
      map[x*2+2000][y*2+2000] = i;
    }
    
    vector<pair<int, int>> removeIdx;
    int cnt = 0;
    while(carNum != 0) {
      removeIdx.clear();
      for(int i=1; i<=S; i++) {
        if(car[i].r != -1) {
          int nextY = car[i].y + dy[car[i].r];
          int nextX = car[i].x + dx[car[i].r];
          
          map[car[i].x][car[i].y] = 0;
          
          if(nextY < 0 || nextY > MAX-10 || nextX < 0 || nextX > MAX-10) {
            carNum--;
            car[i].r = -1;
            continue;
          }
          
          if(map[nextX][nextY] == 0) {
            map[nextX][nextY] = i;
            car[i].y = nextY;
            car[i].x = nextX;
          }
          else {
            carNum--;
            car[i].r = -1;
            
            bool flag = false;
            for(int j=0; j<removeIdx.size(); j++) {
              if(removeIdx[j].first == nextX && removeIdx[j].second == nextY) flag = true;
            }
            if(!flag) removeIdx.push_back(make_pair(nextX, nextY));
          }
        }
      }
      
      for(int i=0; i<removeIdx.size(); i++) {
        cnt++;
        carNum--;
        car[map[removeIdx[i].first][removeIdx[i].second]].r = -1;
        map[removeIdx[i].first][removeIdx[i].second] = 0;
      }
    }
    
    printf("#%d %d\n", t, cnt);
  }
  
  

  return 0;
}