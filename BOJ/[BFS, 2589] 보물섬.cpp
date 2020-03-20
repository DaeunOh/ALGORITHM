/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB		14656	5084	3651	38.729%

문제
보물섬 지도를 발견한 후크 선장은 보물을 찾아나섰다. 
보물섬 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 
각 칸은 육지(L)나 바다(W)로 표시되어 있다. 
이 지도에서 이동은 상하좌우로 이웃한 육지로만 가능하며, 한 칸 이동하는데 한 시간이 걸린다. 
보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다. 
육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면 같은 곳을 두 번 이상 지나가거나, 멀리 돌아가서는 안 된다.

예를 들어 위와 같이 지도가 주어졌다면 보물은 아래 표시된 두 곳에 묻혀 있게 되고, 
이 둘 사이의 최단 거리로 이동하는 시간은 8시간이 된다.

보물 지도가 주어질 때, 보물이 묻혀 있는 두 곳 간의 최단 거리로 이동하는 시간을 구하는 프로그램을 작성하시오.


입력
첫째 줄에는 보물 지도의 세로의 크기와 가로의 크기가 빈칸을 사이에 두고 주어진다. 
이어 L과 W로 표시된 보물 지도가 아래의 예와 같이 주어지며, 각 문자 사이에는 빈 칸이 없다. 
보물 지도의 가로, 세로의 크기는 각각 50이하이다.

출력
첫째 줄에 보물이 묻혀 있는 두 곳 사이를 최단 거리로 이동하는 시간을 출력한다.


예제 입력 1 
5 7
WLLWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLWLWW
예제 출력 1 
8

*/

/*

보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있으므로,
모든 육지를 BFS의 시작 지점으로 하여 해당 육지와 다른 육지 간의 거리를 구하고,
그 중 가장 긴 거리를 다른 지점을 시작 지점으로 했을 때의 거리와 비교하여 최댓값을 찾는 문제이다.

1) 후크 선장은 육지로만 이동할 수 있으므로, BFS의 시작이 되는 지점은 'L'인 지점이다.
    따라서 (0, 0)부터 시작해서 (N-1, M-1)까지 스캔하면서, 'L'인 지점을 찾고,
    해당 지점을 시작으로 queue가 빌 때까지 BFS를 돌린다.
2) 큐에 쌓이는 모든 거리 중 가장 최댓값을 구한다.
3) 다른 지점을 시작 지점으로 했을 때의 거리와 비교하여 최댓값을 갱신한다.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 50 + 10;

int N, M;
char map[MAX][MAX];
int visited[MAX][MAX];

int myMax = -1;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    int subMax = -1;
    visited[y][x] = 1;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        // 해당 BFS의 최댓값을 찾는다.
        if (subMax < visited[front.first][front.second] - 1)
            subMax = visited[front.first][front.second] - 1;

        for (int i = 0; i < 4; i++) {
            int ny = front.first + dy[i];
            int nx = front.second + dx[i];

            if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1) continue;

            // 방문하지 않은 육지라면
            if (!visited[ny][nx] && map[ny][nx] == 'L') {
                visited[ny][nx] = visited[front.first][front.second] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }

    // 이 문제의 최댓값을 구한다.
    if (myMax < subMax) myMax = subMax;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'L') { // 맵 안에 존재하는 모든 육지를 시작점으로 BFS를 돌린다.
                memset(visited, 0, sizeof(visited));
                BFS(i, j);
            }
        }
    }

    printf("%d\n", myMax);

    return 0;
}