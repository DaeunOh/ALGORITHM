/*

시간제한 1초

문제
폭파 작전에 투입된 태경은 폭탄 설치를 모두 마쳤다. 
이제 폭탄을 한꺼번에 터뜨리기 위해 폭탄을 모두 연결시키는 작업만 남았다. 
폭탄을 서로 연결하는 방법은 폭탄이 서로 전선으로 연결되면 된다. 
폭탄이 설치된 모습을 격자판에 옮겨 표현하면 다음과 같다.

install_bomb1
[그림 1]

현재 들고 있는 전선은 너무 빳빳해서 구부릴 수 없는 상황이다. 
전선은 직선 형태로만 사용할 수 있다. 
폭탄이 전선에 의해 연결되려면 전선의 양 끝에 폭탄이 붙어있어야한다. 
[그림 2]에서 녹색칸에 해당하는 부분에 전선이 연결된다. 
또한, [그림 2]에서 볼 수 있듯 전선은 교차될 수 있다.

install_bomb2
[그림 2] 전선 특징

위 전선 특징에 따라 [그림 1]에 존재하는 폭발물을 전선으로 모두 연결하면 최소 길이 4 의 전선이 필요하다.

install_bomb3
[그림 3]

현재 작전을 명령한 승훈은 태경이 작전에 들고간 전선을 최대한 적게 쓰고 복귀했으면 한다. 
폭탄이 설치된 상황이 주어졌을때, 폭발물을 모두 연결하는데에 필요한 전선의 최소 길이를 알아내보자.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다. 
각각의 테스트 케이스의 첫 번째 줄에 
폭탄이 설치된 상황을 격자판으로 나타내었을때의 크기 R, C 가 공백을 통해 구분하여 주어진다. 
두 번째 줄부터 R 개의 줄에 걸쳐 격자판 형태로 현재 폭탄이 설치된 상황이 주어진다. 
각 줄은 C 개의 숫자를 가지고 있고, 각 숫자는 0 혹은 1이다. 
1은 폭탄이 존재한다는 의미다. 
하나의 폭탄은 서로 상하좌우로 연결되어있다. 
(5 ≤ R, C ≤ 10, 2 ≤ 폭탄의 개수 ≤ 6)

 

출력
각 테스트 케이스에 대해 폭탄을 설치하고 남은 전선의 길이를 출력한다. 
만약 폭발물을 모두 연결할 수 없다면 -1을 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. 
r은 문제에 대한 결과값을 뜻한다.

 

예제 입력
copy4
5 7
0 0 0 0 0 1 1 
1 1 1 0 0 1 1 
1 1 1 0 0 0 0 
1 1 0 0 0 0 0 
1 0 0 0 1 1 1 
3 5
1 0 0 1 0 
0 0 0 1 0 
1 0 1 0 0
5 4
1 0 0 1 
0 0 0 1 
0 0 0 0 
0 0 1 0 
1 1 0 0 
9 7
0 0 0 0 0 0 1 
1 1 1 1 1 1 1 
1 1 1 0 1 0 1 
1 0 0 1 0 0 0 
1 0 0 0 0 0 0 
1 1 0 0 0 1 0 
0 0 1 0 0 0 0 
0 1 1 1 0 0 0 
1 1 0 1 0 0 0
예제 출력
#1 4
#2 4
#3 -1
#4 5

*/

#include <stdio.h>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 10 + 10;

int T;
int R, C;
int map[MAX][MAX];
int group[MAX][MAX], groupCnt = 1;
int myMin;
int finished[MAX] = {0, };

int comb[MAX];
bool visited[MAX] = {0, };

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool getDistance() {
  int minDist = 987987987;
  
  for(int x=1; x<=groupCnt-1; x++) {
    if(finished[x]) continue;
    
    int minDist = 987987987, minGroup = -1;
    for(int i=0; i<R; i++) {
      for(int j=0; j<C; j++) {
        if(group[i][j] == x) {
          for(int k=0; k<4; k++) {
            int dist = 0;
            int g = 0;
            int nextY = i + dy[k];
            int nextX = j + dx[k];
            
            if(nextY < 0 || nextY > R-1 || nextX < 0 || nextX > C-1) continue;
            
            if(!group[nextY][nextX]) {
              while(nextY >= 0 && nextY <= R-1 && nextX >= 0 && nextX <= C-1) {
                if(group[nextY][nextX] == 0) {
                  dist++;
                }
                else if(group[nextY][nextX] != x){
                  g = group[nextY][nextX];
                  break;
                }
                else if(group[nextY][nextX] == x) {
                  break;
                }
                
                nextY += dy[k];
                nextX += dx[k];
              }
                
              if(g != 0) {
                if(minDist > dist) {
                  minDist = dist;
                  minGroup = g;
                }
              }
            }
          }
        }
        
      }
    }
    
    if(minDist != 987987987) {
      finished[x] = true;
      finished[minGroup] = true;
      myMin += minDist;
    }
  }
  
  for(int i=1; i<=groupCnt-1; i++) {
    if(!finished[i]) return false;
  }
  
  return true;
}

void setGroup(int y, int x) {
  queue < pair<int, int> > q;
  group[y][x] = groupCnt;
  q.push(make_pair(y, x));
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    for(int i=0; i<4; i++) {
      int nextY = front.first + dy[i];
      int nextX = front.second + dx[i];
      
      if(nextY < 0 || nextY > R-1 || nextX < 0 || nextX > C-1) continue;
      
      if(!group[nextY][nextX] && map[nextY][nextX] == 1) {
        group[nextY][nextX] = groupCnt;
        q.push(make_pair(nextY, nextX));
      }
    }
  }
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    myMin = 0;
    memset(group, 0, sizeof(group));
    memset(finished, 0, sizeof(finished));
    groupCnt = 1;
    
    scanf("%d %d", &R, &C);
    
    for(int i=0; i<R; i++) {
      for(int j=0; j<C; j++) {
        scanf("%d", &map[i][j]);
      }
    }
    
    for(int i=0; i<R; i++) {
      for(int j=0; j<C; j++) {
        if(!group[i][j] && map[i][j] == 1) {
          setGroup(i, j);
          groupCnt++;
        }
      }
    }
    
    if(getDistance()) printf("#%d %d\n", t, myMin);
    else printf("#%d -1\n", t);
  }

  return 0;
}