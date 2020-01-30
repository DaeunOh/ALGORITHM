/*

문제
오늘도 열심히 바깥 세상 친구들과 놀아주느라 피곤한 다요는 
힐붐타운에 널브러져 있는 물풍선을 치우기가 정말 귀찮은 상태이다. 
그 모습을 본 버찌는 "너의 진정한 목소리를 들어봐" 라고 다요에게 말했고, 
이를 들은 다요는 생각에 잠긴 뒤 답했다. 
"나는 정말 물풍선을 더 이상 치우고 싶지않아" 
사실은 레이서를 꿈꾸고 있던 다요는 
마지막으로 물풍선 뒷정리를 하고 마을을 떠나기로 마음 먹었다.

빌리지에 아직 처리하지 못한 물풍선들이 많이 남아있다. 
물풍선이 터지게되면 물풍선의 범위에 있는 다른 물풍선들이 연쇄적으로 폭발한다. 
각 물풍선은 상하좌우로 폭발하며, 물풍선에 적혀있는 숫자 만큼 범위를 가진다.

water_balloon1[그림 1]
water_balloon2[그림 2]
water_balloon3[그림 3]
water_balloon4[그림 4]

이제 다요의 주머니에는 바늘이 K개밖에 없어서 
빌리지에 남아있는 물풍선 중 K개만 터뜨릴 수 있다. 
K개의 바늘을 통해, 최대한 많은 물풍선을 제거하고 싶다. 
또한, 남은 물풍선을 제거하기 위해 최소한의 바늘을 구해오려고 한다. 
N * M 빌리지 맵이 주어지고, K개의 바늘을 통해 최대한 많은 물풍선을 터뜨렸을때, 
남아있는 물풍선을 제거하기위해 필요한 추가적인 바늘의 최소 개수를 구해보자.

위 예제에서 물풍선이 계속 터진 다면 다음과 같다.

water_balloon5[그림 5]
water_balloon6[그림 6]
water_balloon7[그림 7]

바늘 하나로 물풍선을 제거했을때, 남아있는 최소 물풍선은 2개이다. 
이때 2의 범위를 갖는 물풍선을 터뜨리면 남아있는 물풍선이 모두 제거되므로, 
추가적인 바늘의 최소 갯수는 1개이다.

입력
첫 번째 줄에 테스트 케이스의 개수를 나타내는 T가 주어진다. 
다음 줄부터 각 테스트 케이스에 대한 값이 주어진다. 
테스트 케이스의 첫 번째 줄에 빌리지의 크기 N, M과 
현재 가지고 있는 바늘의 개수 K가 공백을 통해 구분하여 주어지고, 
다음 줄부터 N 줄에 걸쳐 M 개의 숫자가 공백을 통해 구분하여 주어진다. 
주어진 숫자가 0이라면 물풍선이 없다는 의미이고, 
1~9까지의 숫자가 주어지면 해당 크기의 범위를 가진 물풍선을 의미한다. 
빌리지에 남아있는 물풍선의 최대 개수는 25개이다. 
(1 ≤ T ≤ 50, 1 ≤ N,M ≤ 10, 0 ≤ K ≤ 4)

출력
각 테스트 케이스에 대해 추가적으로 필요한 최소 바늘 갯수를 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. r은 문제에 대한 결과값을 뜻한다.

*/

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 15;
const int bMAX = 30;

int T;
int N, M, K;
int ballonNum;

int map[MAX][MAX];
int visited[MAX][MAX];
int b[bMAX];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(int y, int x, int idx) {
  queue<pair<int, int>> q;
  visited[y][x] = idx;
  q.push(make_pair(y, x));
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    for(int i=0; i<4; i++) {
      for(int j=1; j<=map[front.first][front.second]; j++) {
        int nextY = front.first + dy[i] * j;
        int nextX = front.second + dx[i] * j;
        
        if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > M-1) break;
        
        if(map[nextY][nextX] != 0 && visited[nextY][nextX] != idx) {
          visited[nextY][nextX] = idx;
          q.push(make_pair(nextY, nextX));
        }
      }
    }
  }
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    scanf("%d %d %d", &N, &M, &K);
    memset(map, 0, sizeof(map));
    memset(b, 0, sizeof(b));
    memset(visited, 0, sizeof(visited));
    ballonNum = 0;
    
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        scanf("%d", &map[i][j]);
        if(map[i][j] != 0) ballonNum++;
      }
    }
    
    int idx = 1;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        if(map[i][j] != 0 && !visited[i][j]) {
          BFS(i, j, idx++);
        }
      }
    }
    
    int need = 0;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        if(visited[i][j] != 0) {
          if(b[visited[i][j]] == 0) need++;
          b[visited[i][j]]++;
        }
      }
    }
    
    printf("#%d ", t);
    if(K >= need) printf("0\n");
    else printf("%d\n", need-K);
  }
  
  return 0;
}

/*
 
3
5 5 3
1 0 3 2 0
9 2 0 4 0
0 4 0 0 2
1 0 3 1 0
3 2 0 0 3
4 4 1
1 0 2 0
0 4 0 2
1 0 1 0
3 2 0 3
10 9 2
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 10 4 0 0 1 0 5 3 
0 0 0 0 0 0 0 0 0 
2 0 0 0 0 0 4 0 0 
0 0 3 5 0 1 0 0 0 
10 0 0 0 0 3 0 0 0 
0 0 0 0 4 0 0 0 0 
0 0 1 0 0 10 0 4 0 
0 0 0 0 0 0 3 0 0 
-----------------------
#1 0
#2 1
#3 3

*/