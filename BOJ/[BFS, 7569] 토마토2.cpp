/*

문제
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 
토마토는 아래의 그림과 같이 격자모양 상자의 칸에 하나씩 넣은 다음, 상자들을 수직으로 쌓아 올려서 창고에 보관한다.

[그림]

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 
보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다. 
대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 
철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 
며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 
단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H가 주어진다. 
M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 
단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다. 
둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다. 
즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다. 
각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다. 
정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 
이러한 N개의 줄이 H번 반복하여 주어진다.

출력
여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다. 
만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 
토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.


예제 입력 1 
5 3 1
0 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1
예제 출력 1 
-1

예제 입력 2 
5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
예제 출력 2 
4

예제 입력 3 
4 3 2
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
-1 -1 -1 -1
1 1 1 -1
예제 출력 3 
0

예제 입력 4
4 3 2
1 1 1 1
-1 -1 1 1
0 0 -1 1
1 1 1 1
-1 -1 -1 -1
0 0 1 -1
예제 출력 4
3

*/

/*

기본 BFS 문제에서 3차원으로 확장해주기만 하면 되는 문제이다.
즉, 상하좌우뿐만이 아니라 위아래까지 보면 되는 것이다.
그리고 입력을 N, M, H 순으로 받게 되는데, 이때 N이 열의 수, M이 행의 수임에 유의하자!

초기에 익지 않은 토마토의 개수를 세어 놓고 BFS가 끝난 이후 익게 된 토마토의 개수와 비교하여
둘의 개수가 같으면 최소일수를 출력하고, 그렇지 않으면 -1을 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100 + 10;

int N, M, H;
int tomato[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];

int zeroNum = 0;
int maxDay = 0;

int dh[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dx[6] = { 0, 0, 0, 0, -1, 1 };

struct TOMATO {
    int h, y, x;

    TOMATO(int _h, int _y, int _x) {
        h = _h;
        y = _y;
        x = _x;
    }
};

queue <TOMATO> q;

int BFS() {
    int cnt = 0;

    while (!q.empty()) {
        TOMATO front = q.front();
        q.pop();

        if (visited[front.h][front.y][front.x] > maxDay)
            maxDay = visited[front.h][front.y][front.x];

        for (int i = 0; i < 6; i++) {
            int nh = front.h + dh[i];
            int ny = front.y + dy[i];
            int nx = front.x + dx[i];

            if (nh < 0 || nh > H - 1 || ny < 0 || ny > M - 1 || nx < 0 || nx > N - 1) continue;

            if (!visited[nh][ny][nx] && !tomato[nh][ny][nx]) {
                visited[nh][ny][nx] = visited[front.h][front.y][front.x] + 1;
                q.push(TOMATO(nh, ny, nx));
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    memset(visited, 0, sizeof(visited));

    scanf("%d %d %d", &N, &M, &H);

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &tomato[h][i][j]);

                if (tomato[h][i][j] == 0) zeroNum++;
                else if (tomato[h][i][j] == 1) {
                    q.push(TOMATO(h, i, j));
                    visited[h][i][j] = 1;
                }
            }
        }
    }

    int cnt = BFS();
    if (cnt != zeroNum) printf("-1\n");
    else printf("%d\n", maxDay - 1);

    return 0;
}