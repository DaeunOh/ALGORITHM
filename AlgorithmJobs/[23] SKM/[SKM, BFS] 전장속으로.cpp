/*

시간제한 1초

문제
비행기에서 뛰어내려 특정 좌표에 도착해 전투를 시작한다. 
현재 레벨에 따라 잡을 수 있는 적의 레벨이 다르다. 
예를 들어, 현재 레벨이 5일 경우 5 보다 작은 숫자인 레벨 1, 2, 3, 4 에 해당하는 적을 잡을 수 있다. 
현재 레벨과 동일한 수의 적을 잡을 경우 레벨업을 한다. 이때 증가한 레벨은 1이다. 
만약 현재 레벨이 2라면 2명의 적을 잡아야한다. 
2명을 잡았을 경우 레벨업하여 레벨 3이 된다.

battle_ground1
[그림 1]

비행기에서 내려 땅에 도착했을 때의 레벨은 2이며, 
도착한 순간부터 현재 위치에서 가장 가깝고 사살할 수 있는 적부터 찾아 나선다. 
사살할 수 있는 적이 많다면 가장 위쪽을 우선으로 타겟을 잡는다. 
만약 위쪽에서도 적이 많다면 그 중에서도 가장 왼쪽에 있는 적으로 아동한다. 
좌표 이동을 한 칸하는데에 1분이 소요되며, 현재 좌표의 인접한 4방향(상하좌우)으로만 이동이 가능하다. 
만약 이동하고자하는 위치에 현재 레벨보다 높은 레벨의 적이 있다면 이동할 수 없다. 
같은 레벨의 적이 있는 경우 지나갈 수는 있지만 사살할 수는 없다. 
낮은 레벨의 적이 있다면 해당 위치에 도착함과 동시에 적을 섬멸한다. 
적을 섬멸하는데에 소요되는 시간은 따로 없다.

전장의 정보가 주어졌을때, 사살할 수 있는 적을 모두 섬멸하는데에 걸리는 시간은 몇 분인가? 
위 그림의 예에서 이어서 상황을 그려본다면 다음과 같은 절차를 통해 적을 섬멸한다. 
총 걸리는 시간은 15분이다.

battle_ground2
[그림 2]

battle_ground3
[그림 3]

battle_ground4
[그림 4]

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다. 
각각의 테스트 케이스의 첫 번째 줄에 전장의 크기 N이 주어진다. 
두 번째 줄부터 N개의 줄에 걸쳐 전장의 정보가 주어진다. 
각 숫자는 0부터 9까지의 자연수이며, 0은 아무것도 없음, 1부터 8까지의 수는 적의 레벨을 뜻한다. 
9의 경우 비행기에서 내려 도착한 위치를 뜻한다. (2 ≤ N ≤ 20)

 

출력
각 테스트 케이스에 대해 최대한 적을 섬멸하는데에 걸리는 시간을 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. 
r은 문제에 대한 결과값을 뜻한다.

 

예제 입력
5
5
0 1 0 1 0 
0 0 0 0 2 
0 2 0 2 0 
0 3 9 0 0 
1 3 0 0 0 
4
0 4 5 0 
1 1 9 1 
4 5 2 5 
6 0 3 6
4
5 4 3 1 
5 1 2 7 
3 2 3 0 
0 0 9 1 
5
3 2 5 0 9 
0 3 0 0 2 
2 0 0 2 5 
7 0 0 1 3 
2 2 0 1 7 
7
1 1 0 5 9 1 3 
5 2 3 1 6 2 2 
7 0 5 1 1 4 1 
4 0 0 3 1 2 1 
0 0 1 6 7 0 1 
3 8 1 2 6 1 8 
7 6 1 0 5 0 8 
예제 출력
#1 15
#2 7
#3 17
#4 27
#5 70

*/

/*

분할해서 풀었을 때는 조건이 나누어져 있어 복잡하지 않았는데,
조건을 다 합치고 나서는 꽤 복잡한 문제였다.

조건이 많아지면서 문제 이해를 제대로 하지 못하고 넘어간 부분이나 애매한 부분이 존재했다.

1) 레벨업을 위해 잡은 적의 수를 계속해서 세게 되는데, 
레벨업을 하고 나서는 그 적의 수를 다시 0으로 초기화 해줘야 한다.
즉, 누적되는 방식이 아니다.

2) "사살할 수 있는 적을 모두 섬멸하는데에 걸리는 시간" 을 구하는 것이기 때문에
모두 사살하지 못하는 테스트 케이스도 존재한다.
따라서 사살할 수 있는 적이 없다면 반복문을 빠져나가야 한다.

*/

#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 20 + 10;

int T;
int N;
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
int userLevel;

int Y, X;
int enemyNum;
int cnt, exp;
int myMin;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(int y, int x) {
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  q.push(make_pair(y, x));
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    for(int i=0; i<4; i++) {
      int nextY = front.first + dy[i];
      int nextX = front.second + dx[i];
      
      if(nextY < 1 || nextY > N || nextX < 1 || nextX > N) continue;
      
      // 방문하지 않은 곳 중에 자신의 레벨보다 같거나 작은 지역, 또는 도착 지점만 queue에 추가한다.
      // 자신의 레벨보다 크다면 방문 처리만 하고 queue에는 넣지 않는다.
      if(!visited[nextY][nextX]) {
        visited[nextY][nextX] = visited[front.first][front.second] + 1;
        if(map[nextY][nextX] <= userLevel) q.push(make_pair(nextY, nextX));
      }
    }
  }
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    enemyNum = 0;
    userLevel = 2;
    scanf("%d", &N);
    
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
        scanf("%d", &map[i][j]);
        
        if(map[i][j] == 9) {
          Y = i;
          X = j;
        }
        else if(map[i][j] != 0) enemyNum++;
      }
    }
    
    cnt = 0, exp = 0;
    while(enemyNum != 0) {
      memset(visited, 0, sizeof(visited));
      BFS(Y, X);
      
      // 가장 가까운 적 찾기
      myMin = 987987987;
      int minY, minX;
      for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
          if(map[i][j] == 0 || map[i][j] == 9) continue;
          
          // 방문한 곳 중에서 자신의 레벨보다 작은 지점 중 가장 가까운 곳을 찾는다.
          if(visited[i][j] != 0 && map[i][j] < userLevel && myMin > visited[i][j] - 1) {
            myMin = visited[i][j] - 1;
            minY = i;
            minX = j;
          }
        }
      }
      
      // 사살할 수 있는 적이 없다면 반복문을 빠져나간다.
      if(myMin == 987987987) break;
      
      // 사살하기 위해 걸린 일수를 cnt에 더해주고, 후보에 포함시키지 않게 하기 위해 map을 0으로 바꿔준다.
      cnt += myMin;
      
      map[Y][X] = 0;
      Y = minY;
      X = minX;
      map[Y][X] = 9;
      
      enemyNum--;
      exp++;
      
      // 사살한 적의 수가 유저의 레벨만큼 된다면 레벨업을 한다.
      // 레벨업을 하고 나서는 사살한 적의 수를 다시 0으로 초기화해준다.
      if(exp == userLevel) {
        userLevel++;
        exp = 0;
      }
    }
    
    printf("#%d %d\n", t, cnt);
  }
  
  return 0;
}