// 소요시간: 1번째 시도(2시간 이상), 2번째 시도(51분)
// 실행시간: 0ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
0.5 초		512 MB		3137	1404	870		43.873%

문제
재현이는 주변을 살펴보던 중 체스판과 말을 이용해서 새로운 게임을 만들기로 했다. 
새로운 게임은 크기가 N×N인 체스판에서 진행되고, 사용하는 말의 개수는 K개이다. 
말은 원판모양이고, 하나의 말 위에 다른 말을 올릴 수 있다. 체스판의 각 칸은 흰색, 빨간색, 파란색 중 하나로 색칠되어있다.

게임은 체스판 위에 말 K개를 놓고 시작한다. 말은 1번부터 K번까지 번호가 매겨져 있고, 이동 방향도 미리 정해져 있다. 
이동 방향은 위, 아래, 왼쪽, 오른쪽 4가지 중 하나이다.

턴 한 번은 1번 말부터 K번 말까지 순서대로 이동시키는 것이다. 한 말이 이동할 때 위에 올려져 있는 말도 함께 이동한다. 
말의 이동 방향에 있는 칸에 따라서 말의 이동이 다르며 아래와 같다. 
턴이 진행되던 중에 말이 4개 이상 쌓이는 순간 게임이 종료된다.

- A번 말이 이동하려는 칸이
  - 흰색인 경우에는 그 칸으로 이동한다. 이동하려는 칸에 말이 이미 있는 경우에는 가장 위에 A번 말을 올려놓는다.
    - A번 말의 위에 다른 말이 있는 경우에는 A번 말과 위에 있는 모든 말이 이동한다.
    - 예를 들어, A, B, C로 쌓여있고, 이동하려는 칸에 D, E가 있는 경우에는 A번 말이 이동한 후에는 D, E, A, B, C가 된다.
  - 빨간색인 경우에는 이동한 후에 A번 말과 그 위에 있는 모든 말의 쌓여있는 순서를 반대로 바꾼다.
    - A, B, C가 이동하고, 이동하려는 칸에 말이 없는 경우에는 C, B, A가 된다.
    - A, D, F, G가 이동하고, 이동하려는 칸에 말이 E, C, B로 있는 경우에는 E, C, B, G, F, D, A가 된다.
  - 파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다. 방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히 있는다.
  - 체스판을 벗어나는 경우에는 파란색과 같은 경우이다.

다음은 크기가 4×4인 체스판 위에 말이 4개 있는 경우이다.

[그림 1-1]

첫 번째 턴은 다음과 같이 진행된다.

[그림 1-2]
			
두 번째 턴은 다음과 같이 진행된다.

[그림 1-3]
			
체스판의 크기와 말의 위치, 이동 방향이 모두 주어졌을 때, 게임이 종료되는 턴의 번호를 구해보자.

입력
첫째 줄에 체스판의 크기 N, 말의 개수 K가 주어진다. 둘째 줄부터 N개의 줄에 체스판의 정보가 주어진다. 
체스판의 정보는 정수로 이루어져 있고, 각 정수는 칸의 색을 의미한다. 0은 흰색, 1은 빨간색, 2는 파란색이다.

다음 K개의 줄에 말의 정보가 1번 말부터 순서대로 주어진다. 
말의 정보는 세 개의 정수로 이루어져 있고, 순서대로 행, 열의 번호, 이동 방향이다. 
행과 열의 번호는 1부터 시작하고, 이동 방향은 4보다 작거나 같은 자연수이고 1부터 순서대로 →, ←, ↑, ↓의 의미를 갖는다.

같은 칸에 말이 두 개 이상 있는 경우는 입력으로 주어지지 않는다.

출력
게임이 종료되는 턴의 번호를 출력한다. 그 값이 1,000보다 크거나 절대로 게임이 종료되지 않는 경우에는 -1을 출력한다.

제한
4 ≤ N ≤ 12
4 ≤ K ≤ 10

*/

/*

어제 도전했던 문제였지만, 조금 정리가 되지 않은 상태에서 문제를 풀어서 그런지 어제는 풀지 못했던 문제이다.
오늘 다시 도전할 때는 설계를 조금 더 명확하게 하고, 최대한 함수를 만들어서 사용했다!

또한, 여기서 이동하려는 칸이 파란색(또는 범위 넘어가는 경우)인 경우에
방향을 바꾸고 다음 위치를 다시 계산하는 부분이 있는데,
처음 풀었을 때는 위치를 계산해서 파란색이나 범위를 넘어가지 않기만 하면 그냥 해당 위치로 이동했더니 틀렸던 경험이 있었다.
오늘 풀 때는 그 부분에 대해서 이동하려는 부분이 빨간색인지, 하얀색인지 까지 체크해줬고, 그에 따라 이동하도록 구현했다.

이 부분에 대해서는 문제의 조건을 추가해줬으면 좋겠다. ㅠㅠ
실제로 시뮬레이션 해가면서 해당 부분이 틀린 것을 알아냈기에.. 이 부분에서는 굉장히 오랜 시간이 걸렸었다..!
오늘은 그 부분을 인지하고 넘어가서 덜 헷갈린 것 같다!

그리고 벡터의 특정 구간을 지워주는 부분이 있는데,
처음 구현할 때는 어차피 맨 끝까지 지워지니까 카운트를 세서 pop_back을 하는 방식을 활용했다.
하지만 그렇게 구현하면 나중에 중간에 있는 요소들을 지울 때는 굉장히 복잡한 방식을 거쳐야 한다는 단점이 있었다.
이 점을 해결하기 위해 평소에는 잘 사용하지 않았던 erase를 사용했고, 그 결과 코드가 더 깔끔해지고 확장성도 좋아졌다!

사용 방법은 다음과 같다.
v.erase(a, b); // [a, b) 구간을 지운다.
v.erase(v.begin() + a, v.begin() + b) // a가 0이고 b가 2라면, 인덱스 0번부터 1번까지 지워진다.

나중에 써야할 일이 있을 수도 있으니 까먹지 말고 기억해두자!
코드에 대한 설명은 주석으로 자세히 달아놓았다. 나중에 볼 일이 있으면 참고하자!

*/

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 12 + 10;

int N, K;
int board[MAX][MAX];
bool isFinished = false;

struct CHESS {
    int y, x, d, idx;
};

vector<int> map[MAX][MAX]; // 보드에 존재하는 말
CHESS chess[MAX]; // 게임에 참여하는 말

int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

int changeDir(int d) {
    if (d == 1) return 2;
    else if (d == 2) return 1;
    else if (d == 3) return 4;
    else return 3;
}

void moveToWhite(int y, int x, int ny, int nx, int s) {
    int e = map[y][x].size();

    for (int i = s; i < e; i++) {
        int idx = map[y][x][i];
        
        chess[idx].y = ny;
        chess[idx].x = nx;
        chess[idx].idx = map[ny][nx].size();

        map[ny][nx].push_back(idx);
    }

    // 말이 4개 이상 쌓이면 종료한다.
    if (map[ny][nx].size() >= 4) isFinished = true;

    // 해당 말의 인덱스부터 맨 끝까지 지운다.
    map[y][x].erase(map[y][x].begin() + s, map[y][x].begin() + e);
}

void moveToRed(int y, int x, int ny, int nx, int e) {
    int s = map[y][x].size() - 1;

    for (int i = s; i >= e; i--) {
        int idx = map[y][x][i];

        chess[idx].y = ny;
        chess[idx].x = nx;
        chess[idx].idx = map[ny][nx].size();

        map[ny][nx].push_back(idx);
    }

    if (map[ny][nx].size() >= 4) isFinished = true;

    map[y][x].erase(map[y][x].begin() + e, map[y][x].begin() + s + 1);
}

void solution() {
    // 최대 1000번의 턴을 시행한다.
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= K; j++) {
            int y = chess[j].y;
            int x = chess[j].x;
            int d = chess[j].d;
            int idx = chess[j].idx;

            int ny = y + dy[d];
            int nx = x + dx[d];

            // 1) 범위를 넘어가거나, 파란색인 경우
            // 2) 흰색인 경우
            // 3) 빨간색인 경우
            if (ny < 1 || ny > N || nx < 1 || nx > N || board[ny][nx] == 2) {
                chess[j].d = changeDir(d);
                ny = y + dy[chess[j].d];
                nx = x + dx[chess[j].d];

                // 방향을 바꿨음에도 범위를 넘어가거나, 파란색이라면 아무 것도 하지 않는다.
                if (ny < 1 || ny > N || nx < 1 || nx > N || board[ny][nx] == 2);
                else if (board[ny][nx] == 0) moveToWhite(y, x, ny, nx, idx);
                else if (board[ny][nx] == 1) moveToRed(y, x, ny, nx, idx);
            }
            else if (board[ny][nx] == 0) moveToWhite(y, x, ny, nx, idx);
            else if (board[ny][nx] == 1) moveToRed(y, x, ny, nx, idx);

            // 말이 4개 이상 쌓인 경우에는 그 즉시 종료한다.
            if (isFinished) {
                cout << i;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= K; i++) {
        int y, x, d;
        cin >> y >> x >> d;
        chess[i] = { y, x, d, 0 };

        map[y][x].push_back(i);
    }

    solution();

    if (!isFinished) cout << "-1";

    return 0;
}