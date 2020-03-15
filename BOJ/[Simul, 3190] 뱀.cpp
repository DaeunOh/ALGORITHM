// 소요시간: 58분
// 실행시간: 0ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB		21502	7422	5023	33.612%


문제
 'Dummy' 라는 도스게임이 있다. 이 게임에는 뱀이 나와서 기어다니는데, 사과를 먹으면 뱀 길이가 늘어난다. 
뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.

게임은 NxN 정사각 보드위에서 진행되고, 몇몇 칸에는 사과가 놓여져 있다. 
보드의 상하좌우 끝에 벽이 있다. 
게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.

뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.

먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.


입력
첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)
다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다. 
사과의 위치는 모두 다르며, 맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.

다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)
다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데,  정수 X와 문자 C로 이루어져 있으며.
게임 시작 시간으로부터 X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. 
X는 10,000 이하의 양의 정수이며, 방향 전환 정보는 X가 증가하는 순으로 주어진다.

출력
첫째 줄에 게임이 몇 초에 끝나는지 출력한다.


예제 입력 1 
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D
예제 출력 1 
9

예제 입력 2 
10
4
1 2
1 3
1 4
1 5
4
8 D
10 D
11 D
13 L
예제 출력 2 
21

예제 입력 3 
10
5
1 5
1 3
1 2
1 6
1 7
4
8 D
10 D
11 D
13 L
예제 출력 3 
13

*/

/*

뱀의 몸의 길이를 일시적으로 늘렸다가, 사과가 있으면 그대로 두고, 사과가 없으면 꼬리를 비워주는 시뮬레이션 문제.

문제에 게임 종료에 대한 제대로 된 설명이 없어서 나는 문제에서의 꼬리를 가상의 꼬리라고 생각했다.
즉, 내가 가는 지점에 자신의 몸(정확하게는 꼬리)이 있더라도,
뱀이 사과를 못 먹어서 이후 사라질 몸이라면 그 지점에 가도 괜찮다는 방식으로 구현을 했는데,
알고보니 뱀이 사과를 먹든 먹지 않든 내가 가는 지점이 1이라면 게임종료가 되는 단순한 규칙이었다..ㅎㅎㅎ;;

다음에 다시 풀 때는 헷갈리지 않도록 하자!!!

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100 + 10;

int N, K;
int map[MAX][MAX]; // -1: 사과, 0: 빈공간, 1: 자신
int L;
vector<pair<int, char>> D;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct SNAKE {
    int y, x;

    void createSNAKE(int _y, int _x) {
        y = _y;
        x = _x;
    }
};

int changeDir(int d1, char d2) {
    if (d2 == 'L') {
        if (d1 == 0) return 2;
        else if (d1 == 1) return 3;
        else if (d1 == 2) return 1;
        else if(d1 == 3) return 0;
    }
    else {
        if (d1 == 0) return 3;
        else if (d1 == 1) return 2;
        else if (d1 == 2) return 0;
        else if (d1 == 3) return 1;
    }
}

void playGame(int y, int x, int d) {
    queue<SNAKE> q;
    int t = 0;
    int dIdx = 0;

    while (1) {
        SNAKE s;
        s.createSNAKE(y, x);
        q.push(s);
        t++;

        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 1 || ny > N || nx < 1 || nx > N) break;
        if (map[ny][nx] == 1) break;

        if (map[ny][nx] == -1) {
            map[ny][nx] = 1;
        }
        else {
            SNAKE front = q.front();
            q.pop();

            map[front.y][front.x] = 0;
            map[ny][nx] = 1;
        }

        if (dIdx < D.size()) {
            if (D[dIdx].first == t) {
                d = changeDir(d, D[dIdx].second);
                dIdx++;
            }
        }

        y = ny, x = nx;
    }

    printf("%d", t);
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int y, x;
        scanf("%d %d", &y, &x);

        map[y][x] = -1;
    }
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        int X, C;
        scanf("%d %c", &X, &C);

        D.push_back(make_pair(X, C));
    }

    map[1][1] = 1;
    playGame(1, 1, 3);

    return 0;
}