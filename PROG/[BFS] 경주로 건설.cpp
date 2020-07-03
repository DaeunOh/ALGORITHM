/*

▶ 소요시간 및 실행시간
38분, 0ms

▶ 문제
도면의 상태(0은 비어 있음, 1은 벽)을 나타내는 2차원 배열이 주어질 때, 경주로를 건설하는데 필요한 최소 비용을 구하시오.

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/67259

▶ 풀이
경주로를 건설하는데 필요한 최소 비용을 구하는 BFS 문제.
해당 문제에서는 직선 도로를 건설하는 데 드는 비용이 100원이고,
그 경주로에 코너가 존재한다면 코너 하나 당 비용이 500원이므로 최대한 코너의 개수를 적게 하는 경주로를 건설하면 된다.

직선 도로가 건설되는 경우는 이전 도로의 방향과 세울 도로의 방향이 같은 경우이고,
코너가 건설되는 경우는 그 방향이 다른 경우이다.
(사실 이전 도로의 방향과 반대 방향인 경우에도 직선 도로가 건설되지만, 이는 되돌아가는 경우이기에 고려하지 않는다.)

여기서 핵심은 코너가 건설될지 말지는 도로를 세우는 시점에 결정되는 것이 아니라,
도로를 세우고 나서 그 이후에 결정되는 것이기 때문에 2차원의 visited 배열만으로는 해결할 수 없게 된다.
(그 당시에는 최솟값일지 몰라도 이후에 코너가 건설되면 최솟값이 아니게 될 수 있기 때문에!)

따라서 2차원이 아닌 3차원으로 visited 배열을 만들어 놓은 후에,
현재 방향에 따라 그 지점까지 도로가 건설되는 데 들었던 최소 비용을 계속 업데이트하는 방식을 활용해야 한다.
이렇게 구현하면 어차피 어느 곳에서 그 지점에 왔든 현재 방향이 일치하게 되므로
이후에 코너가 건설되든 말든 해당 방향에서는 visited에 적힌 값이 최솟값이 되는 것이다.

또한, 현재 방향과 이전 방향을 비교하기 위해 좌표, 방향을 저장할 수 있는 CAR라는 구조체를 이용한다.
그리고 경주로 건설을 시작할 때에는 방향이 정해져 있지 않으므로 4가지 방향을 다 큐에 넣고 시작하는 방식을 활용한다.

비용을 계산하는 부분과 관련해서는
방문되지 않은 지점이라면 현재 방향과 이전 방향을 비교하면서 그에 알맞는 비용을 계산하여 visited 배열에 넣어 주고,
방문된 지점이라면 이미 들어 있는 비용보다 새로 업데이트 될 비용이 더 적은 경우에만 다시 덮어씌우도록 구현하면 된다.

최종적으로는 N-1, N-1에 적혀 있는 4개의 비용 중에 방문이 된 방향 중 가장 최소 비용이 정답이 된다.

▶ 후기
실제로 코딩 테스트때 해당 문제를 풀 당시에 나는 3차원의 visited 배열을 이용해야 한다는 것을 캐치하지 못했다.

2차원의 BFS로는 풀이에 적어놨던 것처럼 그 당시에는 최솟값일지 몰라도
이후에 최솟값이 아니게 될 수 있다는 것 때문에 절대로 해결할 수 없었다.
하지만 그렇다고 해서 DFS를 사용하면, 최대 25x25의 맵이 작은 맵이 아니기 때문에 시간초과가 날 수밖에 없었다.

결국 제출할 때는 일단 BFS로 대충 최솟값에 근접한 수를 구한 후에
DFS를 돌릴 때 그 값을 넘어가는 경우는 계산하지 않도록 해서 최대한 시간을 줄여보려고 했는데,
내 기억상 3문제 정도는 시간초과 때문에 해결할 수 없어서 결국 문제를 해결하지 못했었다..!

나중에 3차원 배열이 핵심이라는 것을 알게 되었을 때는 하하... 많이 허무했지만.. ㅎㅎ
그래도 당시 BFS 문제에 많이 소홀했던 것이 사실이기에 결국은 열심히 하지 않았던 내 잘못이라고 생각하고 넘어갔었다..ㅎ
(BFS 문제의 대부분은 2차원 배열로 풀이가 가능하지만, 가끔 문제 중에 3차원 배열이 필요한 경우가 꽤 있다.
만약 BFS 문제를 많이 풀었다면 3차원 배열로 해결하는 문제라는 것을 빨리 캐치할 수 있었을 듯!)

역시 노력이 답이다!!! 화이팅!!! :)
아 그리고, 최근에 뭐 면접 준비한다고 알고리즘에 너무 소홀했던 것 같다..
아무리 바쁘더라도 하루에 1문제 씩은 푸는 습관을 계속해서 들여야 겠다. 이것두 화이팅!!

*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 25 + 10;

int N;
int visited[MAX][MAX][4] = {0, };

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct CAR {
    int y, x, d;
};

void BFS(int y, int x, vector<vector<int>> &board) {
    queue<CAR> q;
    
    for(int i=0; i<4; i++) {
        visited[y][x][i] = 1;
        q.push({y, x, i});
    }
    
    while(!q.empty()) {
        CAR front = q.front();
        q.pop();
        
        for(int i=0; i<4; i++) {
            int ny = front.y + dy[i];
            int nx = front.x + dx[i];
            
            if(ny < 0 || ny > N-1 || nx < 0 || nx > N-1 || board[ny][nx]) continue;
            
            if(!visited[ny][nx][i]) {
                if(front.d == i) 
                    visited[ny][nx][i] = visited[front.y][front.x][front.d] + 100;
                else
                    visited[ny][nx][i] = visited[front.y][front.x][front.d] + 100 + 500;
                
                q.push({ny, nx, i});
            }
            else {
                if(front.d == i && visited[ny][nx][i] > visited[front.y][front.x][front.d] + 100) {
                    visited[ny][nx][i] = visited[front.y][front.x][front.d] + 100;
                    q.push({ny, nx, i});
                }
                else if(front.d != i && visited[ny][nx][i] > visited[front.y][front.x][front.d] + 100 + 500) {
                    visited[ny][nx][i] = visited[front.y][front.x][front.d] + 100 + 500;
                    q.push({ny, nx, i});
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 987987987;
    N = board.size();
    
    BFS(0, 0, board);
    
    for(int i=0; i<4; i++) {
        if(visited[N-1][N-1][i] && answer > visited[N-1][N-1][i] - 1)
            answer = visited[N-1][N-1][i] - 1;
    }
    
    return answer;
}