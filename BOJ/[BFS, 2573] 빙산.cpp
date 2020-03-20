// 소요시간: 31분
// 실행시간: 64ms, 44ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB		19266	5414	3617	26.256%

문제
지구 온난화로 인하여 북극의 빙산이 녹고 있다. 빙산을 그림 1과 같이 2차원 배열에 표시한다고 하자. 
빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다. 빙산 이외의 바다에 해당되는 칸에는 0이 저장된다. 
그림 1에서 빈칸은 모두 0으로 채워져 있다고 생각한다.

<그림 1. 행의 개수가 5이고 열의 개수가 7인 2차원 배열에 저장된 빙산의 높이 정보>

빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에, 
배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 
일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다. 
단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 
바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다. 따라서 그림 1의 빙산은 일년후에 그림 2와 같이 변형된다.

그림 3은 그림 1의 빙산이 2년 후에 변한 모습을 보여준다. 
2차원 배열에서 동서남북 방향으로 붙어있는 칸들은 서로 연결되어 있다고 말한다. 
따라서 그림 2의 빙산은 한 덩어리이지만, 그림 3의 빙산은 세 덩어리로 분리되어 있다.

<그림 2> <그림 3>

한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오. 
그림 1의 빙산에 대해서는 2가 답이다. 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.

입력
첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다. 
N과 M은 3 이상 300 이하이다. 
그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다. 
각 칸에 들어가는 값은 0 이상 10 이하이다. 
배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다. 
배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.

출력
첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다. 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.

예제 입력 1 
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0
예제 출력 1 
2

*/

/*

빙산이 두 덩어리 이상으로 분리되는 최초의 시간을 찾는 BFS 문제.
코드 맨 아래 주석처리한 코드는 문제를 해결했으나, 조금 복잡한 방식으로 해결한 것 같아 아쉬운 마음이 들었던 코드이다.
조금 더 쉽고 직관적으로 코드를 바꾸고 싶었기에
다음과 같은 내용을 새로 적용하여 첫 번째 코드 -> 두 번째 코드가 완성 되었다.

첫 번째 코드 설계
1) 초기 빙산의 개수를 total의 저장한다.
2) BFS 시작 전 temp에다가 map의 정보를 저장한다.
3) 양수인 지점을 시작 지점으로 BFS를 시작한다. (BFS는 마지막에 빙산의 개수를 반환한다)
    3-1) total != BFS의 반환 값인 경우? 빙산이 두 덩어리 이상으로 나뉘어진 경우이므로 t를 출력한 후 프로그램을 종료한다.
    3-2) total == BFS의 반환 값인 경우? 빙산이 아직 한 덩어리 이므로 temp를 map에 옮긴 후,
           BFS를 통해 제거된 빙산의 개수만큼 total을 감소시킨다.
4) 빙산이 남아있지 않은 경우에는 0을 출력한다.

두 번째 코드 설계
1) 양수이면서 방문하지 않은 지점을 찾는다.
2) BFS를 돌리기 전 증가시킨 bfsCnt를 확인한다.
    2-1) bfsCnt가 1보다 크다면 빙산이 두 덩어리 이상이라는 의미이므로 t를 출력하고 프로그램을 종료시킨다.
    2-2) 1보다 작거나 같다면 해당 지점을 시작 지점으로 BFS를 돌린다.
3) 방문하지 않은 지점을 찾는다.
    3-1) 인접 지점이 바다라면 0이상이 유지되도록 자신의 높이를 깎는다.
           (자신은 방문처리가 된 지점이므로 다른 지점에서 바다라고 인식하지 않는다.)
    3-2) 인접 지점이 빙산이라면 방문 처리를 하고 queue에 넣는다.
4) 시간을 증가시키기 전 bfsCnt가 0이라면 빙산이 다 녹았다는 의미이므로 0을 출력하고 프로그램을 종료한다.


첫 번째 코드보다 두 번째 코드가 실행시간도 짧고, 훨씬 더 간단하고 직관적이다.
맵의 크기가 크다면 map을 복사하는데 소요되는 시간이 크게 되므로 웬만하면 복사는 생각에서 뒤로 미루도록 하자!ㅎㅎ;

*/

// 두 번째 코드
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 300 + 10;

int N, M;
int map[MAX][MAX];

bool visited[MAX][MAX];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = front.first + dy[i];
            int nx = front.second + dx[i];

            if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1) continue;

            // 1) 방문하지 않은 지점이면서 빙산이 바다와 인접해있다면 자신의 높이를 깎는다.
            //    (0 이상은 유지하도록)
            // 2) 방문하지 않은 지점이면서 빙산이라면 방문처리하고 큐에 넣는다.
            if (!visited[ny][nx]) {
                if (!map[ny][nx] && map[front.first][front.second] > 0) {
                    map[front.first][front.second]--;
                }
                else if (map[ny][nx] > 0) {
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int t = 0;
    while (1) {
        memset(visited, 0, sizeof(visited));
        int bfsCnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > 0 && !visited[i][j]) {
                    bfsCnt++;

                    if (bfsCnt > 1) {
                        printf("%d\n", t);
                        return 0;
                    }
                    
                    BFS(i, j);
                }
            }
        }

        if (bfsCnt == 0) { // 빙산이 전부 다 녹은 경우
            printf("0\n");
            return 0;
        }

        t++;
    }
}

/*
// 첫 번째 코드
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 300 + 10;

int N, M;
int map[MAX][MAX];
int temp[MAX][MAX];
int total = 0;

bool visited[MAX][MAX];
int zeroNum;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS(int y, int x) {
    queue<pair<int, int>> q;
    int cnt = 0;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int ny = front.first + dy[i];
            int nx = front.second + dx[i];

            if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1) continue;

            // 1) 빙산이 바다와 인접해있다면 자신의 높이를 깎는다(0 이상은 유지하도록)
            // 2) 방문하지 않은 지점이면서 빙산이라면
            if (!map[ny][nx] && temp[front.first][front.second] > 0) {
                temp[front.first][front.second]--;
                if (temp[front.first][front.second] == 0) zeroNum++; // 없어진 빙산의 개수 저장
            }
            else if (!visited[ny][nx] && map[ny][nx] > 0) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }

    return cnt;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] != 0) total++;
        }
    }

    int t = 0;
    while (1) {
        // BFS 시작 전 map의 정보를 저장해둔다.
        memcpy(temp, map, sizeof(temp));

        bool isAlive = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > 0) {
                    isAlive = true;
                    memset(visited, 0, sizeof(visited));
                    zeroNum = 0;

                    int cnt = BFS(i, j);

                    if (total != cnt) { // 빙산이 두 덩어리 이상으로 분리됐다면
                        printf("%d\n", t);
                        return 0;
                    }
                    else { // 빙산이 한 덩어리라면
                        memcpy(map, temp, sizeof(map));
                        total -= zeroNum; // 없어진 빙산만큼 전체 빙산 개수를 조정해준다.
                    }

                    break;
                }
            }
            if (isAlive) break;
        }

        if (!isAlive) { // 빙산이 전부 다 녹은 경우
            printf("0\n");
            return 0;
        }

        t++;
    }
}
*/