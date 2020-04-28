// 소요시간: 1시간 15분
// 실행시간: 0ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초		512 MB		16849	6809	3877		37.261%

문제
N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 있다. 
공간은 1×1 크기의 정사각형 칸으로 나누어져 있다. 한 칸에는 물고기가 최대 1마리 존재한다.

아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다. 
가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.

아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다. 
아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 
따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.

아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.
- 더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
- 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
- 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
  - 거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
  - 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.

아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정한다. 
즉, 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 이동과 동시에 물고기를 먹는다. 
물고기를 먹으면, 그 칸은 빈 칸이 된다.

아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 
예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.

공간의 상태가 주어졌을 때, 
아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 공간의 크기 N(2 ≤ N ≤ 20)이 주어진다.
둘째 줄부터 N개의 줄에 공간의 상태가 주어진다. 
공간의 상태는 0, 1, 2, 3, 4, 5, 6, 9로 이루어져 있고, 아래와 같은 의미를 가진다.
- 0: 빈 칸
- 1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
- 9: 아기 상어의 위치
아기 상어는 공간에 한 마리 있다.

출력
첫째 줄에 아기 상어가 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간을 출력한다.

예제 입력 1 
3
0 0 0
0 0 0
0 9 0
예제 출력 1 
0
예제 입력 2 
3
0 0 1
0 0 0
0 9 0
예제 출력 2 
3
예제 입력 3 
4
4 3 2 1
0 0 0 0
0 0 9 0
1 2 3 4
예제 출력 3 
14
예제 입력 4 
6
5 4 3 2 3 4
4 3 2 3 4 5
3 2 9 5 6 6
2 1 2 3 4 5
3 2 1 6 5 4
6 6 6 6 6 6
예제 출력 4 
60
예제 입력 5 
6
6 0 6 0 6 1
0 0 0 0 0 2
2 3 4 5 6 6
0 0 0 0 0 2
0 2 0 0 0 0
3 9 3 0 0 1
예제 출력 5 
48
예제 입력 6 
6
1 1 1 1 1 1
2 2 6 2 2 3
2 2 5 2 2 3
2 2 2 4 6 3
0 0 0 0 0 6
0 0 0 0 0 9
예제 출력 6 
39

*/

/*

BFS 문제지만, 일반적인 BFS 문제와 달리 살짝(?) 꼬아서 낸듯한 BFS문제.
그리고 문제에서 주어진 조건을 잘못 이해할 확률이 조금 있는 문제이다..!

해당 문제에서는 M마리의 물고기와 1마리의 아기 상어가 존재하는데,
이 아기 상어는 자신보다 큰 물고기는 먹지도, 지나가지도 못하고, 같은 물고기는 지나가기만 할 수 있으며,
작은 물고기는 지나갈 수도, 먹을 수도 있다.

여기서 "큰 물고기"가 없어서 모든 길을 다 지나갈 수 있다면,
상어와 물고기와의 거리를 구할 때 거리를 구하는 일반적인 공식을 사용해도 되지만,
모든 길을 다 지나갈 수 없기 때문에 그 공식을 사용할 수 없다.

따라서, 상어는 항상 물고기를 먹기 전에 자신의 위치를 시작으로 BFS를 돌리고,
그로 인해 자신의 크기보다 작거나 같은 곳만 지나 다니면서 거리를 계산해야 한다.

그리고 그 계산한 거리 중에 가장 가까운 곳을 찾고,
해당 위치로 넘어가면서 물고기를 먹음과 동시에 이동한 칸 수를 갱신해주는 것이 이 문제의 올바른 접근 방법이다.

또한, 여기서 거리가 같은 경우는 가장 위쪽의 것을 먼저 택하고, 그것마저 같은 경우는 왼쪽의 것을 택하라 했는데,
사실 이 부분은 가장 왼쪽 상단의 거리부터 읽어 나가면서 갱신하는 방식을 취하면 걱정하지 않아도 된다.
(하지만 나는.. 그 가장 위쪽이면서 왼쪽인 지점이, 상어 위치를 기준으로 가장 가까우면서 위쪽, 왼쪽에 있는 거라고 생각했다..
여기서는 상어 기준이 아니라, 거리가 같은 경우 배열에서 가장 위쪽이면서 왼쪽인 물고기를 찾는 것임을 유의해야 한다!)

문제의 조건을 꼼꼼하게 읽어봤음에도 조건 자체를 잘못 해석해버려서 조금 시간이 걸렸던 문제 ㄷㄷ
그리고 사실 미리 거리를 다 구한 후에, 그중의 최선을 찾는 방식도 한 번에 생각나지 않았다..!!

예전에 비슷한 문제를 풀었을 때는 금방 생각났던 것 같은데.... 반성하고 앞으로 더 열심히 하자!!!
근데... 요즘에는 반성을 좀 많이 하게 되는 것 같다 ㅎㅎㅎ하하;;; 이러면 안되는데 ㅠㅠㅠㅠ힝

*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 20 + 10;

int N;
int map[MAX][MAX];
int visited[MAX][MAX];
int Y, X;

int t = 0;
int sSize = 2;
int cnt = 0;

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

void BFS() {
    // 상어가 갈 수 있는 위치의 visited 배열에다가 거리를 찍는다.
    queue<pair<int, int>> q;
    visited[Y][X] = 1;
    q.push(make_pair(Y, X));

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = front.first + dy[i];
            int nx = front.second + dx[i];

            if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1) continue;

            // 상어는 자신보다 크기가 작거나 같은 곳만 이동할 수 있다.
            if (!visited[ny][nx] && map[ny][nx] <= sSize) {
                visited[ny][nx] = visited[front.first][front.second] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                Y = i;
                X = j;
                map[i][j] = 0;
            }
        }
    }

    while (1) {
        memset(visited, 0, sizeof(visited));
        BFS();

        int myMin = 987987987;
        int y, x;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!map[i][j] || !visited[i][j]) continue; // 비어있거나 방문할 수 없는 곳은 넘어간다.

                // 물고기 크기가 상어 크기보다 작으면서 거리가 가장 짧은 곳을 찾는다.
                if (map[i][j] < sSize && visited[i][j] - 1 < myMin) {
                    myMin = visited[i][j] - 1;
                    y = i;
                    x = j;
                }
            }
        }

        if (myMin != 987987987) {
            map[y][x] = 0;
            cnt++;
            t += myMin;

            // 상어 위치를 물고기 위치로 변경한다.
            Y = y;
            X = x;

            if (sSize == cnt) { // 상어의 크기만큼 물고기를 먹었다면 크기를 1 증가시킨다.
                sSize++;
                cnt = 0;
            }
        }
        else break;
    }

    cout << t;

    return 0;
}