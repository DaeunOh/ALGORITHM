/*

시간제한 1초

문제
N * N 크기의 산을 최대한 훼손하지 않고 스키장을 건설하려 한다. 
현재 임의의 위치 한 곳의 땅 높이를 최대 K 만큼 깎을 수 있는 상태다. 
예를 들어, (a, b) 위치를 깎기로 했다면 (a, b) 를 제외한 위치는 깎을 수 없다. 
(a, b) 위치를 0, 1, 2, ..., K 만큼 높이를 낮출 수 있다.

슬로프를 최대한 다이나믹하게 만들어야 고객 만족도가 높다. 
따라서, 구간을 발견함에 있어 꺾임이 많은 구간을 찾아야한다. 
또한, 가장 높은 곳에서부터 낮은 곳으로 내려가는 것이 가장 스릴이 넘치므로, 
구간의 시작 지점은 높이가 가장 높은 곳, 산의 꼭대기에서부터 시작한다.

슬로프 구간은 상하좌우로 연결되어 있어야하며, 대각선으로 연결되어서는 안된다. 
슬로프는 높은 곳에서 낮은 곳으로 내려가는 구성이여야한다. 
즉, 구간내에 같은 높이는 있을 수 없다. 
산의 높이를 깎는 대상 중 산 꼭대기는 포함되지않음에 주의하도록 한다. 
지상의 높이는 0으로 정의하며, 지하 밑으로 까지 깎을 수 없다. 
산의 크기 N 과 최대 깎을 수 있는 높이 K 가 주어졌을때, 
고객 만족도가 가장 클 구간의 꺾임 횟수를 알아내보자.

만약, 최대 3 만큼 산의 높이를 깎을 수 있고, N이 5인 산의 정보가 주어졌다고 하자.

ski1
[그림 1]

산 꼭대기의 경우 3곳, (0, 1), (1, 3), (3, 2)에 위치한다. 
산을 깎지않은 상태에서 가장 많은 꺾임이 있는 구간은 (3, 2)에서 시작하여 2번 꺾이는 슬로프 구간이다.

ski2
[그림 2]

기존에 (0,1)의 위치에서 시작하면 최대 1번의 꺾임이 일어났지만, 
(1,0)의 높이를 2만큼 깎을 경우, 최대 4번의 꺾임이 일어나는 슬로프를 만들 수 있다.

ski3
[그림 3]

따라서, 해당 예제의 최대 꺾임 횟수는 4회이다.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다. 
각각의 테스트 케이스의 첫 번째 줄에 산의 크기 N 과 최대로 깎을 수 있는 높이 K 가 공백을 통해 구분하여 주어진다. 
두 번째 줄부터 N 개의 줄에 걸쳐 높이 정보가 주어진다. 
한 줄에 N개의 숫자가 공백을 통해 주어진다. 산의 높이는 최대 20이며, 
산 꼭대기의 개수는 최소 3개, 최대 5개이다. (3 ≤ N ≤ 10, 1 ≤ K ≤ 5)

 

출력
각 테스트 케이스에 대해 만족도가 가장 클 구간의 꺾임 횟수를 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. r은 문제에 대한 결과값을 뜻한다.

 

예제 입력
5
5 3
2 9 8 3 8
6 5 1 9 7
3 2 6 3 2
6 1 9 5 7
8 1 7 5 7
4 3
5 4 9 3 
1 3 5 9 
9 1 2 0 
8 9 7 3
5 1
7 1 2 2 5 
4 5 7 6 6 
1 2 6 4 5 
5 4 1 4 4 
7 6 2 3 5 
6 3
4 5 0 0 0 4 
0 2 1 2 4 3 
5 0 1 2 0 3 
4 4 0 0 0 3 
5 0 2 3 4 3 
3 1 1 5 4 4 
6 1
4 4 2 4 0 3 
2 1 1 0 3 3 
3 0 5 5 4 4 
4 4 1 1 0 5 
4 3 0 0 0 0 
2 4 3 0 4 0 
예제 출력
#1 4
#2 3
#3 3
#4 3
#5 2

*/

/*

"산의 높이를 깎는 대상 중 산 꼭대기는 포함되지않음에 주의하도록 한다."
라는 문장을 잘못 생각해서 시간을 소모했던 문제.

높이를 깎을 때 처음에만 고려하면 되는 줄 알았는데,
알고보니 중간에 깎으면서도 꼭대기가 깎이는 경우가 있을 수도 있었다.

따라서 중간 지점에서도 산 꼭대기는 깎지 않도록 조건문이 필요했다.

또한, 산을 깎을 수 있는 기회는 총 1번이다.
즉, 한 번에 K만큼 깎을 수는 있지만, 한 번이라도 깎고 나면 다음에는 깎지 못한다.

*/

#include <cstdio>
#include <cstring>

const int MAX = 20;

int T;
int N, K;
int map[MAX][MAX];
int visited[MAX][MAX];
int max;
int top;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void DFS(int y, int x, int d, int c, int k) {
  for(int i=0; i<4; i++) {
    int nextY = y + dy[i];
    int nextX = x + dx[i];
    
    if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > N-1 || map[nextY][nextX] < 0) continue;
    
    if(!visited[nextY][nextX]) {
      if(map[y][x] > map[nextY][nextX]) {
        visited[nextY][nextX] = 1;
        
        if(d != -1 && d != i) DFS(nextY, nextX, i, c+1, k);
        else DFS(nextY, nextX, i, c, k);
        
        visited[nextY][nextX] = 0;
      }
      else if(k == K && map[y][x] > map[nextY][nextX]-k && map[nextY][nextX] != top) {
        for(int j=1; j<=k; j++) {
          if(map[nextY][nextX]-j >= 0 && map[y][x] > map[nextY][nextX]-j) {
            visited[nextY][nextX] = 1;
            map[nextY][nextX] -= j;
            
            if(d != -1 && d != i) DFS(nextY, nextX, i, c+1, k-j);
            else DFS(nextY, nextX, i, c, k-j);
            
            map[nextY][nextX] += j;
            visited[nextY][nextX] = 0;
            break;
          }
        }
      }
    }
  }
  
  if(max < c) max = c;
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    // 초기화
    memset(map, 0, sizeof(map));
    max = -987987987;
    scanf("%d %d", &N, &K);
    
    top = -1;
    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        scanf("%d", &map[i][j]);
        if(map[i][j] > top) top = map[i][j];
      }
    }
    
    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        if(map[i][j] == top) { // 시작지점
          memset(visited, 0, sizeof(visited));
          visited[i][j] = 1;
          DFS(i, j, -1, 0, K);
        }
      }
    }
    
    printf("#%d %d\n", t, max);
  }
  
  return 0;
}