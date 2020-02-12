/*

문제
예전에 당구를 즐겨했던 윤식은 추억삼아 포켓볼 게임을 만들었다. 
아직 베타 버전이라 물리엔진이 현실과 많이 다르다. 
당구공이 잘 움직이는지 확인하기 위해 당구대에 당구공을 X개 두고 테스트를 진행했다.

pocket_ball1
[그림 1] 초기 당구장의 상태

pocket_ball2
[그림 2] 2개 이상의 당구공이 충돌할 경우

pocket_ball3
[그림 3] 벽으로 향하는 공이 다른 공에 부딪힐 경우

현재의 물리엔진으로 구현된 포켓볼 게임은 다음과 같은 특징을 가지고 있다.

[그림 1]을 보면 각각의 당구공은 방향과 힘의 값을 가지고 있다.
당구공은 상하좌우 4방향 중 하나로 움직이며, 1초에 1칸씩 이동한다. 
만약 2개 이상의 당구공이 만날 경우, 힘이 가장 큰 당구공만 남고 나머지 당구공은 사라진다. 
당구공이 가진 힘이 0이 될 경우, 해당 당구공 또한 사라진다. 
벽에 부딪힐 경우에도 마찬가지로 당구공이 가진 힘이 절반이되며 
이동 방향은 벽에 부딪히기 전의 반대 방향이 된다.

[그림 2]에서 보여지는 특징은 2개 이상의 당구공이 한 좌표로 모이면 
가장 힘이 큰 당구공을 제외하고 나머지 당구공은 사라진다는 점이다. 
가장 힘이 큰 당구공의 방향은 유지된 상태로, 힘은 절반으로 떨어진다. 
만약 가장 큰 힘을 가진 당구공이 2개 이상일 경우, 해당 당구공 중 번호가 작은 당구공만 남는다. 
마찬가지로 힘이 가장 크고, 번호가 작은 당구공의 방향을 유지한 상태로, 힘은 절반으로 떨어진다.

[그림 3]의 경우 벽에 부딪히는 상황과 공끼리 충돌하는 상황이 혼합된 상태이다. 
충돌의 절차는 벽에 공이 튕겨 나온 다음, 공끼리 충돌이 일어난다. 
[그림 3]의 왼쪽 그림을 보면 노란 공은 벽에 튕겨 나와 힘이 1이된다. 
이후 공끼리 부딪힐때 가장 힘이 센 파란 공이 남고 나머지 공은 사라진다. 
[그림 3]의 오른쪽 그림은 노란 공이 벽에 튕겨 나와 힘이 5가 된다. 
노란 공이 가장 힘이 크므로 노란 공만 남고 나머지 공은 사라진다.

계속해서 시간이 흐르면 아래와 같이 움직인다.

pocket_ball4
[그림 4]

pocket_ball5
[그림 5]

pocket_ball6
[그림 6]

pocket_ball7
[그림 7]

pocket_ball8
[그림 8]

각 당구공에 번호가 매겨져있을때, 시간 S초가 흐른 뒤 사라진 당구공의 번호를 오름차순으로 구해보자.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다.

각각의 테스트 케이스의 첫 번째 줄에 당구장의 크기 N, M, 시간 S, 당구공 개수 K 가 공백을 통해 구분하여 주어진다.

두 번째 줄부터 K 개의 줄에 걸쳐 당구공의 정보가 주어진다. 
당구공의 정보는 당구공의 위치 y, x, 가지고 있는 힘 f, 이동 방향 d 로 이루어져있고, 공백을 통해 구분되어있다.

당구공의 위치, 가지고 있는 힘은 모두 다르다. 
당구공의 번호는 입력 순서대로 1번부터 매겨진다.

(5 ≤ N, M ≤ 101, 1 ≤ S ≤ 50, 5 ≤ K ≤ 50,
1 ≤ y ≤ N-2, 1 ≤ x ≤ M-2, 1 ≤ f ≤ 50, d = 상: 1, 하: 2, 좌: 3, 우: 4)

 

출력
각 테스트 케이스에 대해 
시간 S초가 흐른 뒤 사라진 당구공의 번호를 오름차순으로 한 줄에 공백을 통해 구분하여 출력한다. 
만약 사라진 당구공이 없다면 "-1"을 출력한다.

각 테스트 케이스의 출력 양식은 "#t r"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. 
r은 문제에 대한 결과값을 뜻한다.



예제 입력
5
9 13 5 8
6 3 2 4 
6 5 9 3 
7 4 5 1 
3 6 9 4
3 2 7 1
3 9 4 3
1 2 1 1
4 11 3 4
9 13 10 5
7 11 5 2
4 8 10 4
2 9 10 2
5 9 42 3
2 4 24 3
15 7 9 6
2 4 14 3
13 5 24 4
6 2 24 4
6 4 46 3
8 3 41 3
8 5 4 3
19 23 6 6
8 12 39 3
16 17 21 2
6 20 13 1
9 14 33 3
8 10 28 4
8 21 50 1
15 15 2 5
6 11 45 4
13 6 12 1
3 13 9 2
10 13 32 1
5 10 40 3
예제 출력
#1 1 3 7 
#2 1 
#3 3 
#4 5
#5 -1

*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 101 + 10;
const int MAXK = 50 + 10;

int T;
int N, M, S, K;
int map[MAX][MAX];

int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};

struct BALL {
  int y, x, f, d;
  
  void createBALL(int Y, int X, int F, int D) {
    y = Y;
    x = X;
    f = F;
    d = D;
  }
};

vector<BALL> ball(MAXK);
vector<int> res;
vector<pair<int, int>> removeIdx;

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    memset(map, 0, sizeof(map));
    ball.clear();
    res.clear();
    scanf("%d %d %d %d", &N, &M, &S, &K);
    
    int y, x, f, d;
    for(int i=1; i<=K; i++) {
      scanf("%d %d %d %d", &y, &x, &f, &d);
      BALL b;
      b.createBALL(y, x, f, d);
      
      ball[i] = b;
      map[y][x] = i;
    }
    
    while(S--) {
      // 공 옮기기
      for(int i=1; i<=K; i++) {
        if(ball[i].d != -1) {
          
          int nextY = ball[i].y + dy[ball[i].d];
          int nextX = ball[i].x + dx[ball[i].d];
          
          // 벽에 부딪히는 경우
          if(nextY < 1 || nextY > N-2 || nextX < 1 || nextX > M-2) {
            ball[i].f /= 2;
            
            if(ball[i].f == 0) { // 힘이 0이 된 당구공 소멸
              ball[i].d = -1;
              res.push_back(i);
              map[ball[i].y][ball[i].x] = 0;
            }
            else { // 방향 전환
              if(ball[i].d == 1) ball[i].d = 2;
              else if(ball[i].d == 2) ball[i].d = 1;
              else if(ball[i].d == 3) ball[i].d = 4;
              else if(ball[i].d == 4) ball[i].d = 3;
            }
            
            continue;
          }
          
          // 벽에 부딪히지 않는 경우에는 y, x 바꿔줌
          ball[i].y = nextY;
          ball[i].x = nextX;
          map[ball[i].y][ball[i].x] = 0;
        }
      }
      
      removeIdx.clear();
      for(int i=1; i<=K; i++) {
        if(ball[i].d != -1) {
          // 자기 자신인 경우. 즉, 벽에 튕긴 경우.
          if(map[ball[i].y][ball[i].x] == i) continue;
          
          if(map[ball[i].y][ball[i].x] == 0) { // 자신이 해당 좌표에 처음 온 경우
            map[ball[i].y][ball[i].x] = i;
          }
          else {
            // 힘이 절반이 되어야 할 좌표 리스트에 해당 좌표를 중복되지 않게 넣음.
            bool flag = false;
            for(int j=0; j<removeIdx.size(); j++) {
              if(removeIdx[j].first == ball[i].y && removeIdx[j].second == ball[i].x) flag = true;
            }
            
            if(!flag) removeIdx.push_back(make_pair(ball[i].y, ball[i].x));

            // 힘 비교
            int curIdx = map[ball[i].y][ball[i].x];
            if(ball[curIdx].f < ball[i].f) {
              ball[curIdx].d = -1;
              res.push_back(curIdx);
              map[ball[i].y][ball[i].x] = i;
            }
            else if(ball[curIdx].f >= ball[i].f) {
              ball[i].d = -1;
              res.push_back(i);
            }
            
          }
        }
      }
      
      // 힘을 절반으로 만들어 줌
      for(int i=0; i<removeIdx.size(); i++) {
        int curIdx = map[removeIdx[i].first][removeIdx[i].second];
        ball[curIdx].f /= 2;
        if(ball[curIdx].f == 0) {
          ball[curIdx].d = -1;
          res.push_back(curIdx);
          map[removeIdx[i].first][removeIdx[i].second] = 0;
        }
      }
    }
    
    // 오름차 순으로 정렬
    sort(res.begin(), res.end());
    
    printf("#%d ", t);
    if(res.size() == 0) printf("-1");
    else {
      for(int i=0; i<res.size(); i++) printf("%d ", res[i]);
    }
    printf("\n");
  }
  
  return 0;
}