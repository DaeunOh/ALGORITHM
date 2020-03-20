// 소요시간: 1시간 51분
// 실행시간: 4ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB		31661	8815	4722	25.251%

문제
스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 제품은 구슬 탈출이다. 
구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.

보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다. 
가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 
빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다. 
게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안 된다.

이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 
왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.

각각의 동작에서 공은 동시에 움직인다. 
빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 
빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 
또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 
기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.

보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다. 
다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다. 이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다. 
'.'은 빈 칸을 의미하고, '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다. 
'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.

입력되는 모든 보드의 가장자리에는 모두 '#'이 있다. 구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.

출력
최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 
만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.

예제 입력 1 
5 5
#####
#..B#
#.#.#
#RO.#
#####
예제 출력 1 
1

예제 입력 2 
7 7
#######
#...RB#
#.#####
#.....#
#####.#
#O....#
#######
예제 출력 2 
5

예제 입력 3 
7 7
#######
#..R#B#
#.#####
#.....#
#####.#
#O....#
#######
예제 출력 3 
5

예제 입력 4 
10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.#.#..#
#...#.O#.#
##########
예제 출력 4 
-1

예제 입력 5 
3 7
#######
#R.O.B#
#######
예제 출력 5 
1

예제 입력 6 
10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.##...#
#O..#....#
##########
예제 출력 6 
7

예제 입력 7 
3 10
##########
#.O....RB#
##########
예제 출력 7 
-1

*/

/*

색깔이 다른 두 개의 구슬을 중력을 이용해서 이동시키고,
최종적으로는 빨간 구슬만을 구멍에 넣을 수 있는 최소 횟수를 구하는 시뮬레이션 문제.

구슬이 한 개가 아니라 두 개기 때문에, 어떤 구슬을 먼저 이동시킬지에 대한 flag와
각 방향마다 어떻게 이동시켜줘야 할지를 따로 구현하고자 했기 때문에 코드가 굉장히 길어지고, 시간도 오래 걸렸다.
코드가 길어지다 보니(하드코딩에 가까움) 하나를 바꿀 때마다 바꿔줘야 할 요소가 너무 많아서 정말 힘들었다.. ㅠ

문제는 해결했지만, 코드의 길이를 줄이고, 조금 더 간결하게 짜기 위해서 다른 사람의 코드를 참고해보고 싶었다.
참고한 결과, 다음에 문제를 복습할 때 고려해야 할 점을 다음과 같이 정리해봤다.

1) 방향 별로 이동하는 부분을 따로 만들지 않고, 하나의 함수로 만들어 보자.
2) 어떤 구슬이 먼저 이동해야 할지를 고려하지 말고, 해당 구슬이 이동한 칸수를 이용해보자.
3) visited 함수를 이용해서 이미 왔던 자리라면 다시 큐에 넣지 않도록 하자.

화이팅!!!!

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 15;

int N, M;
char map[MAX][MAX];

int RY, RX, BY, BX;
int dstY, dstX;

struct RB {
    int ry, rx, by, bx;
};

queue<RB> q;

void moveRB(int ry, int rx, int by, int bx, int d, bool isRed) {
    RB rb;
    int nry, nrx, nby, nbx;

    switch (d)
    {
    case 0:
        if (isRed) {
            for (int i = ry; i >= 1; i--) {
                if (map[i - 1][rx] == '.') continue;
                else if (map[i - 1][rx] == 'O') {
                    nry = i - 1;
                    break;
                }
                else {
                    nry = i;
                    break;
                }
            }

            for (int i = by; i >= 1; i--) {
                if ((nry != i - 1 || rx != bx) && map[i - 1][bx] == '.') continue;
                else if (map[i - 1][bx] == 'O') {
                    nby = i - 1;
                    break;
                }
                else {
                    nby = i;
                    break;
                }
            }
        }
        else {
            for (int i = by; i >= 1; i--) {
                if (map[i - 1][bx] == '.') continue;
                else if (map[i - 1][bx] == 'O') {
                    nby = i - 1;
                    break;
                }
                else {
                    nby = i;
                    break;
                }
            }

            for (int i = ry; i >= 1; i--) {
                if ((nby != i - 1 || bx != rx) && map[i - 1][rx] == '.') continue;
                else if (map[i - 1][rx] == 'O') {
                    nry = i - 1;
                    break;
                }
                else {
                    nry = i;
                    break;
                }
            }

        }

        if((nby != dstY || bx != dstX) && (nry != ry || nby != by)) {
            rb = { nry, rx, nby, bx };
            q.push(rb);
        }

        break;
    case 1:
        if (isRed) {
            for (int i = ry; i <= N - 2; i++) {
                if (map[i + 1][rx] == '.') continue;
                else if (map[i + 1][rx] == 'O') {
                    nry = i + 1;
                    break;
                }
                else {
                    nry = i;
                    break;
                }
            }

            for (int i = by; i <= N - 2; i++) {
                if ((nry != i + 1 || rx != bx) && map[i + 1][bx] == '.') continue;
                else if (map[i + 1][bx] == 'O') {
                    nby = i + 1;
                    break;
                }
                else {
                    nby = i;
                    break;
                }
            }
        }
        else {
            for (int i = by; i <= N - 2; i++) {
                if (map[i + 1][bx] == '.') continue;
                else if (map[i + 1][bx] == 'O') {
                    nby = i + 1;
                    break;
                }
                else {
                    nby = i;
                    break;
                }
            }

            for (int i = ry; i <= N - 2; i++) {
                if ((nby != i + 1 || bx != rx) && map[i + 1][rx] == '.') continue;
                else if (map[i + 1][rx] == 'O') {
                    nry = i + 1;
                    break;
                }
                else {
                    nry = i;
                    break;
                }
            }
        }

        if ((nby != dstY || bx != dstX) && (nry != ry || nby != by)) {
            rb = { nry, rx, nby, bx };
            q.push(rb);
        }

        break;
    case 2:
        if (isRed) {
            for (int i = rx; i >= 1; i--) {
                if (map[ry][i - 1] == '.') continue;
                else if (map[ry][i - 1] == 'O') {
                    nrx = i - 1;
                    break;
                }
                else {
                    nrx = i;
                    break;
                }
            }

            for (int i = bx; i >= 1; i--) {
                if ((nrx != i - 1 || ry != by) && map[by][i - 1] == '.') continue;
                else if (map[by][i - 1] == 'O') {
                    nbx = i - 1;
                    break;
                }
                else {
                    nbx = i;
                    break;
                }
            }
        }
        else {
            for (int i = bx; i >= 1; i--) {
                if (map[by][i - 1] == '.') continue;
                else if (map[by][i - 1] == 'O') {
                    nbx = i - 1;
                    break;
                }
                else {
                    nbx = i;
                    break;
                }
            }

            for (int i = rx; i >= 1; i--) {
                if ((nbx != i - 1 || ry != by) && map[ry][i - 1] == '.') continue;
                else if (map[ry][i - 1] == 'O') {
                    nrx = i - 1;
                    break;
                }
                else {
                    nrx = i;
                    break;
                }
            }
        }

        if ((by != dstY || nbx != dstX) && (nrx != rx || nbx != bx)) {
            rb = { ry, nrx, by, nbx };
            q.push(rb);
        }

        break;
    case 3:
        if (isRed) {
            for (int i = rx; i <= M - 2; i++) {
                if (map[ry][i + 1] == '.') continue;
                else if (map[ry][i + 1] == 'O') {
                    nrx = i + 1;
                    break;
                }
                else {
                    nrx = i;
                    break;
                }
            }

            for (int i = bx; i <= M- 2; i++) {
                if ((nrx != i + 1 || ry != by) && map[by][i + 1] == '.') continue;
                else if (map[by][i + 1] == 'O') {
                    nbx = i + 1;
                    break;
                }
                else {
                    nbx = i;
                    break;
                }
            }
        }
        else {
            for (int i = bx; i <= M - 2; i++) {
                if (map[by][i + 1] == '.') continue;
                else if (map[by][i + 1] == 'O') {
                    nbx = i + 1;
                    break;
                }
                else {
                    nbx = i;
                    break;
                }
            }

            for (int i = rx; i <= M - 2; i++) {
                if ((nbx != i + 1 || ry != by) && map[ry][i + 1] == '.') continue;
                else if (map[ry][i + 1] == 'O') {
                    nrx = i + 1;
                    break;
                }
                else {
                    nrx = i;
                    break;
                }
            }
        }

        if ((by != dstY || nbx != dstX) && (nrx != rx || nbx != bx)) {
            rb = { ry, nrx, by, nbx };
            q.push(rb);
        }

        break;
    }
}

void playGame() {
    RB rb = { RY, RX, BY, BX };
    q.push(rb);

    int t = 0;

    while (1) {
        int qSize = q.size();

        if (t > 10) {
            printf("-1");
            break;
        }

        while (qSize--) {
            RB front = q.front();
            q.pop();
            if ((front.ry == dstY && front.rx == dstX) && (front.by != dstY || front.bx != dstX)) {
                printf("%d", t);
                return;
            }

            if (front.ry < front.by) moveRB(front.ry, front.rx, front.by, front.bx, 0, 1);
            else moveRB(front.ry, front.rx, front.by, front.bx, 0, 0);

            if (front.ry >= front.by) moveRB(front.ry, front.rx, front.by, front.bx, 1, 1);
            else moveRB(front.ry, front.rx, front.by, front.bx, 1, 0);

            if (front.rx < front.bx) moveRB(front.ry, front.rx, front.by, front.bx, 2, 1);
            else moveRB(front.ry, front.rx, front.by, front.bx, 2, 0);

            if (front.rx >= front.bx) moveRB(front.ry, front.rx, front.by, front.bx, 3, 1);
            else moveRB(front.ry, front.rx, front.by, front.bx, 3, 0);
        }

        t++;
    }
    
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &map[i][j]);

            if (map[i][j] == 'R') {
                RY = i;
                RX = j;

                map[i][j] = '.';
            }
            else if (map[i][j] == 'B') {
                BY = i;
                BX = j;

                map[i][j] = '.';
            }
            else if (map[i][j] == 'O') {
                dstY = i;
                dstX = j;
            }
        }
    }

    playGame();

    return 0;
}