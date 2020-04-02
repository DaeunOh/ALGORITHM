// 소요시간: 30분

/*

문제
유니와 거니는 간단한 게임을 하나 만들었다. 
세로, 가로가 각각 N , M 인 직사각형 놀이터에서 한 명은 보물을 숨기고 다른 한 명은 보물을 찾는 게임이다. 
각 위치는 ( 세로 좌표 , 가로 좌표 ) 로 표현할 수 있다.

유니가 술래일 때, 시작 지점인 ( 0 , 0 ) 에서 눈을 감고 있는 사이 거니는 아무 칸에 가서 보물을 숨긴다. 
거니는 보물을 한 번 숨기면 다시 보물을 옮기지 않는다. 
이때 거니는 놀이터 밖에도 보물을 숨길 수 있는데, 놀이터 밖에 보물을 숨긴다면 유니는 보물 찾기를 포기한다. 
거니가 ( 0 , 0 ) 에 보물을 숨긴다면 게임을 시작할 수 없다.

유니는 눈을 뜨고 보물 찾기를 시작한다. 유니가 상, 하, 좌, 우 한 칸을 움직이는 데 1초가 걸린다. 
유니는 항상 놀이터의 맨 왼쪽 위 ( 0 , 0 ) 부터 출발한다.

유니가 보물을 찾을 수 있는 최단 시간과 최단 시간으로 찾을 수 있는 경우의 수를 구하는 프로그램을 만드시오.

입력
첫 번째 줄에는 보물찾기 게임을 할 놀이터 공간이 세로 N 과 가로 M 으로 공백으로 구분하여 주어진다.
두 번째 줄에는 거니가 물건을 숨긴 세로, 가로 좌표 ( a , b ) 가 공백으로 구분하여 주어진다.
( 1 ≤ N, M ≤ 25, 0 ≤ a , b ≤ 30 )

출력
유니가 보물을 찾을 수 있을 때, 첫 번째 줄에는 유니가 보물을 찾는 최단시간, 두 번째 줄에는 그 경우의 수를 정수로 출력한다.
만약 유니가 보물을 찾을 수 없거나 게임을 시작할 수 없는 경우 fail 을 출력한다.

예제 입력 1
9 9
2 1
예제 출력 1
3
3
 

예제 입력 2
3 3
0 7
예제 출력 2
fail

*/

/*

BFS를 통해 보물의 위치까지 도달하는 최단시간 및 최단시간으로 보물을 찾을 수 있는 경우의 수를 구하는 문제.

최단시간을 구하는 방법은 전형적인 BFS 문제이기 때문에 구현이 어렵지 않다.
하지만, 그 최단시간으로 보물을 찾을 수 있는 경우의 수는 조금 더 고민이 필요하다.

처음에는 BFS를 통해 최단시간을 구함과 동시에, 같은 시간으로 보물에 도달한다면 cnt를 증가시키는 방식을 사용했다.
하지만, 그렇게 구현하면 중간에 path가 살짝 달랐으나 이미 방문돼서 진행하지 못한 경우는 고려가 되지 않는다.

그 이후에는 최단시간은 BFS를 통해 찾고, 경우의 수는 DFS를 통해 찾으려 했다.
DFS는 맵의 크기가 큰 경우에는 적합하지 않다는 건 알고 있었는데,
그동안 너무 큰 배열들을 많이 봐와서 최대 25 x 25라는 배열 크기는 작은 편이라 생각했다.
하지만.. 25 x 25도 DFS에서는 굉장히 큰 크기였다 ㄷㄷㄷ

DFS는 답이 아닌 것 같아, 최대한 BFS로 풀어보는 방식을 생각해보았다.
어떻게 하면 중간에 합쳐지는 지점에서 카운트를 제대로 할 수 있을까.....

그 답은 이미 방문된 지점에서의 시간이 현재 자신의 시간과 같다면 그 카운트를 누적시키는 것이었다!
그렇게 구현하면 같은 시간대에 해당 위치에 온 경로들의 수가 모두 누적이 되므로
최종적으로 보물 위치에서의 카운트가 바로 최단시간으로 보물을 찾을 수 있는 경우의 수가 된다! ㅎㅎ

왠지 비슷한 종류의 문제가 조금 많을 것 같은데, 실제로는 처음 접하는 문제라 조금 당황스럽다 ㅎㅎㅎㅎ...
그래도 코딩테스트 전에 알게 되어서 다행이라고 생각한다!

*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 25 + 10;

int N, M;
int a, b;

int visited[MAX][MAX];
int cnt[MAX][MAX];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(int y, int x) {
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  cnt[y][x] = 1;
  q.push(make_pair(y, x));
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    for(int i=0; i<4; i++) {
      int ny = front.first + dy[i];
      int nx = front.second + dx[i];
      
      if(ny < 0 || ny > N-1 || nx < 0 || nx > M-1) continue;
      
      if(!visited[ny][nx]) {
        visited[ny][nx] = visited[front.first][front.second] + 1;
        cnt[ny][nx] = cnt[front.first][front.second];
        q.push(make_pair(ny, nx));
      }
      else if(visited[ny][nx] == visited[front.first][front.second] + 1) {
        cnt[ny][nx] += cnt[front.first][front.second];
      }
    }
  }
  
  cout << visited[a][b] - 1 << "\n";
  cout << cnt[a][b];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  cin >> a >> b;
  
  if((a == 0 && b == 0) || a >= N || b >= M) cout << "fail";
  else {
    memset(visited, 0, sizeof(visited));
    memset(cnt, 0, sizeof(cnt));
    BFS(0, 0);
  }

  return 0;
}