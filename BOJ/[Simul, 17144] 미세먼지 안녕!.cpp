// 소요시간: 54분
// 실행시간: 44ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB		7469	4003	2724	53.855%

문제
미세먼지를 제거하기 위해 구사과는 공기청정기를 설치하려고 한다. 
공기청정기의 성능을 테스트하기 위해 구사과는 집을 크기가 R×C인 격자판으로 나타냈고, 1×1 크기의 칸으로 나눴다. 
구사과는 뛰어난 코딩 실력을 이용해 각 칸 (r, c)에 있는 미세먼지의 양을 실시간으로 모니터링하는 시스템을 개발했다. 
(r, c)는 r행 c열을 의미한다.

<그림1>

공기청정기는 항상 1번 열에 설치되어 있고, 크기는 두 행을 차지한다. 
공기청정기가 설치되어 있지 않은 칸에는 미세먼지가 있고, (r, c)에 있는 미세먼지의 양은 Ar,c이다.

1초 동안 아래 적힌 일이 순서대로 일어난다.
1) 미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
    - (r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
    - 인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
    - 확산되는 양은 Ar,c/5이고 소수점은 버린다.
    - (r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
2) 공기청정기가 작동한다.
    - 공기청정기에서는 바람이 나온다.
    - 위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
    - 바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
    - 공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.

다음은 확산의 예시이다.

<그림2>

공기청정기의 바람은 다음과 같은 방향으로 순환한다.

<그림3>

방의 정보가 주어졌을 때, T초가 지난 후 구사과의 방에 남아있는 미세먼지의 양을 구해보자.

입력
첫째 줄에 R, C, T (6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000) 가 주어진다.

둘째 줄부터 R개의 줄에 Ar,c (-1 ≤ Ar,c ≤ 1,000)가 주어진다. 
공기청정기가 설치된 곳은 Ar,c가 -1이고, 나머지 값은 미세먼지의 양이다. 
-1은 2번 위아래로 붙어져 있고, 가장 윗 행, 아랫 행과 두 칸이상 떨어져 있다.

출력
첫째 줄에 T초가 지난 후 구사과 방에 남아있는 미세먼지의 양을 출력한다.


예제 입력 1 
7 8 1
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
예제 출력 1 
188

미세먼지의 확산이 일어나면 다음과 같은 상태가 된다. 

<그림4>

공기청정기가 작동한 이후 상태는 아래와 같다.

<그림4>

예제 입력 2 
7 8 2
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
예제 출력 2 
188

예제 입력 3 
7 8 3
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
예제 출력 3 
186

예제 입력 4 
7 8 4
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
예제 출력 4 
178

예제 입력 5 
7 8 5
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
예제 출력 5 
172

예제 입력 6 
7 8 20
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
예제 출력 6 
71

예제 입력 7 
7 8 30
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
예제 출력 7 
52

예제 입력 8 
7 8 50
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
예제 출력 8 
46

*/

/*

미세먼지를 상하좌우 네 방향에 동시에 확산시키고, 공기청정기를 작동시켜 미세먼지를 정화시키는 시뮬레이션 문제.

모든 미세먼지는 동시에 확산되므로 확산은 맵에 바로 반영이 되도록 하나,
확산된 양이 기존 미세먼지의 양에 영향을 주지 않도록 하기 위해 queue를 사용했다.
또한, 확산되는 양은 5로 나눈 몫이므로 미세먼지의 양이 5이상인 경우에만 queue에 넣도록 했다.
(queue에는 미세먼지의 양이 5이상인 위치와 양이 들어간다.)

이후 확산이 시작되면, 큐에서 하나씩 꺼내면서 상하좌우로 몇 번 퍼졌는지 카운트하여 자신의 미세먼지 양을 감소시켰다.

모든 확산이 끝난 후에는 공기청정기가 작동된다.
공기청정기가 작동되는 부분(미세먼지가 시계 방향, 반시계 방향으로 이동하는 부분)은
13460번 문제 구슬 탈출2에서 다음에 복습 시에 고려해야 할 점을 적용하여 구현했다. (방향에 상관없이 짧은 함수 1개로 구현)
(ㅎㅎㅎㅎㅎㅎㅎㅎㅎ뿌듯!!!!)

행과 열의 크기를 입력받고 나서 맵의 테두리를 -2로 세팅해주었으므로
미세먼지가 이동하는 함수는 -2(벽)를 만나기 전까지 위치를 업데이트 시키며 미세먼지가 이동되는 방식이다.
또한, -2를 만나진 않았지만 공기청정기가 작동하기 시작한 행의 맨 끝 열에 도달하는 경우에도 while문을 종료시키도록 했다.
(이 부분을 추가하지 않으면 그 아래에 있는 것까지 함께 이동이 된다 ㄷㄷ)
모든 미세먼지를 이동시키고 나서 공기가 정화된 부분은 0으로 다시 세팅해줬다!

다른걸 다 떠나서 방향에 상관없이 짧은 함수 1개로 구현한 부분이 ㅎㅎㅎ 제일 뿌듯하다..
만약 구슬 탈출2 문제를 풀지 않았다면 함수에 각 방향별로 많은 반복문이 들어가도록 구현했을 것 같다 ㅠㅠ..
다음에도 비슷한 문제가 나오면 다시 한 번 사용해봐야겠다! ^_^

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 50 + 10;

int R, C, T;
int A[MAX][MAX];
vector<pair<int, int>> cleaner;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct DUST {
    int y, x, a;
};

queue<DUST> q;

void spread() {
    // 큐에 들어있는 미세먼지가 확산되고, 확산된만큼 자신의 미세먼지가 줄어든다.
    while (!q.empty()) {
        DUST front = q.front();
        q.pop();

        int a = front.a / 5;
        int cnt = 0;

        for (int i = 0; i < 4; i++) {
            int ny = front.y + dy[i];
            int nx = front.x + dx[i];

            if (ny < 1 || ny > R || nx < 1 || nx > C) continue; // 범위 벗어나는 경우
            if (A[ny][nx] == -1) continue; // 공기청정기인 경우

            A[ny][nx] += a;
            cnt++;
        }

        A[front.y][front.x] -= a * cnt;
    }
}

void move(int y, int x, int dy, int dx) {
    while (A[y + dy][x + dx] != -2) { // 벽을 만나기 전까지 미세먼지가 이동한다.
        A[y][x] = A[y + dy][x + dx];

        y += dy;
        x += dx;

        if (y == cleaner[0].first && x == C) break; // 벽은 아니지만 이동이 멈춰야 할 구간1
        else if (y == cleaner[1].first && x == C) break; // 구간2
    }
}

void airClean() {
    // 위쪽은 반시계 방향으로 순환한다.
    move(cleaner[0].first - 1, cleaner[0].second, -1, 0);
    move(1, 1, 0, 1);
    move(1, C, 1, 0);
    move(cleaner[0].first, C, 0, -1);
    A[cleaner[0].first][cleaner[0].second + 1] = 0; // 정화된 공기

    // 아래쪽은 시계 방향으로 순환한다.
    move(cleaner[1].first + 1, cleaner[1].second, 1, 0);
    move(R, 1, 0, 1);
    move(R, C, -1, 0);
    move(cleaner[1].first, C, 0, -1);
    A[cleaner[1].first][cleaner[1].second + 1] = 0; // 정화된 공기
}

int main() {
    scanf("%d %d %d", &R, &C, &T);
    for (int i = 0; i <= C + 1; i++) { // 외곽에 벽을 만들어준다.
        A[0][i] = -2;
        A[R + 1][i] = -2;
    }

    for (int i = 0; i <= R + 1; i++) {
        A[i][0] = -2;
        A[i][C + 1] = -2;
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf("%d", &A[i][j]);

            if (A[i][j] == -1) cleaner.push_back(make_pair(i, j));
        }
    }

    while (T--) {
        // 미세먼지의 양이 5이상인 지점의 위치와 양을 큐에 넣는다.
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (A[i][j] >= 5) q.push({ i, j, A[i][j] });
            }
        }

        spread(); // 확산

        airClean(); // 공기청정기 작동
    }

    // 남은 미세먼지의 양을 구한다.
    int sum = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (A[i][j] == -1 || !A[i][j]) continue;
            sum += A[i][j];
        }
    }

    printf("%d\n", sum);

    return 0;
}