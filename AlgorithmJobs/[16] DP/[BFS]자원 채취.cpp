/*

문제
N x M의 지도가 주어지며, 이 지도의 각 칸에는 자원이 존재한다. 
자원의 양은 정수로 나타난다. 
다음 그림은 5 x 6 의 지도에 존재하는 자원을 나타낸다.

scv1

철수는 자원을 채취하는 로봇을 갖고 있으며, 
이 로봇은 (0, 0) 에서 출발하여 (N-1, M-1) 에서 자원 채취를 마친다. 
로봇은 한가지 제약이 있는데, 오른쪽과 아랫쪽으로밖에 움직일 수 없다는 것이다. 
이 로봇을 이용하여 가장 많이 채취할 수 있는 자원의 양을 출력하는 프로그램을 작성하시오. 
위의 예제의 경우 다음과 같이 채취하는 것이 최대이며, 그 양은 49이다.

scv2

 

입력
첫 번째 줄에 N, M이 주어진다. ( 1 ≤ N, M ≤ 1,000 ) 
두 번째 줄부터 N x M 의 지도에 존재하는 자원의 양이 주어진다.

 

출력
로봇을 이용하여 채취할 수 있는 자원의 양의 최댓값을 출력한다.

 

예제 입력
5 6
1 7 3 2 8 0
9 2 3 4 5 4
3 4 7 8 2 2
1 4 3 1 4 1
3 2 5 5 3 8
예제 출력
49

*/

/*

BFS로 푸는 것이 익숙해서, BFS로 풀어봤는데 답은 나왔으나
이 구현의 단점은 T[i][j]의 값이 최대 2번 바뀐다는 것이다.
모든 BFS를 끝나고 (N-1, M-1)의 값은 정확하게 업데이트 되지만,
필요없는 부분까지 계산하게 되는 경우도 있다.
따라서 다른 방법으로도 구현해볼 필요가 있는 것 같다..ㅎ


## 1. T[i][j] = (0, 0)에서 (i, j)까지의 자원의 합 최댓값

그 좌표까지의 합을 기준으로 테이블을 구성해야 하므로 테이블은 2차원 배열이여야 한다.
0, 0을 시작으로 오른쪽과 아래쪽으로 이동하며, 특정 조건을 만족할 때마다 큐에 넣는다.


## 2. T[i][j] = max(T[i][j], T[front.first][front.second] + map[i][j])

BFS 방식으로 구현했기 때문에, T[i][j]에 값이 있을 시 그 값과 새로 덮어씌워질 수 있는 값 두개를 비교한다.
그리고 그 중 최댓값을 T[i][j]에 넣게 되면 그 값이 최종 T[i][j]가 된다.


점화식을 세우긴 세웠으나, 큐를 사용했기 때문에 식에 front도 들어가 있고...
깔끔하지 않은 점화식이 세워졌다...
다른 방법도 생각해봐야겠다...!

*/

#include <stdio.h>
#include <queue>

using namespace std;

const int MAX = 1000 + 10;

int N, M;
int map[MAX][MAX];
int T[MAX][MAX] = {0, };

int dy[2] = {1, 0};
int dx[2] = {0, 1};

void BFS(int y, int x) {
  queue<pair<int, int>> q;
  T[y][x] = map[y][x];
  q.push(make_pair(y, x));
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    for(int i=0; i<2; i++) {
      int nextY = front.first + dy[i];
      int nextX = front.second + dx[i];
      
      if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > M-1) continue;
      
      if(!T[nextY][nextX]) {
        T[nextY][nextX] = T[front.first][front.second] + map[nextY][nextX];
        q.push(make_pair(nextY, nextX));
      }
      else {
        if(T[nextY][nextX] < T[front.first][front.second] + map[nextY][nextX]) {
          T[nextY][nextX] = T[front.first][front.second] + map[nextY][nextX];
          q.push(make_pair(nextY, nextX));
        }
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
  
  BFS(0, 0);
  
  printf("%d\n", T[N-1][M-1]);

  return 0;
}