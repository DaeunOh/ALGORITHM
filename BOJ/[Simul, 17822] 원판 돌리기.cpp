// 소요시간: 1시간 27분
// 실행시간: 4ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB		3871	1256	844	30.371%


문제
반지름이 1, 2, ..., N인 원판이 크기가 작아지는 순으로 바닥에 놓여있고, 원판의 중심은 모두 같다. 
원판의 반지름이 i이면, 그 원판을 i번째 원판이라고 한다. 
각각의 원판에는 M개의 정수가 적혀있고, i번째 원판에 적힌 j번째 수의 위치는 (i, j)로 표현한다. 수의 위치는 다음을 만족한다.

(i, 1)은 (i, 2), (i, M)과 인접하다.
(i, M)은 (i, M-1), (i, 1)과 인접하다.
(i, j)는 (i, j-1), (i, j+1)과 인접하다. (2 ≤ j ≤ M-1)
(1, j)는 (2, j)와 인접하다.
(N, j)는 (N-1, j)와 인접하다.
(i, j)는 (i-1, j), (i+1, j)와 인접하다. (2 ≤ i ≤ N-1)
아래 그림은 N = 3, M = 4인 경우이다.

<그림1>

원판의 회전은 독립적으로 이루어진다. 2번 원판을 회전했을 때, 나머지 원판은 회전하지 않는다. 
원판을 회전시킬 때는 수의 위치를 기준으로 하며, 회전시킨 후의 수의 위치는 회전시키지 전과 일치해야 한다.
다음 그림은 원판을 회전시킨 예시이다.

<그림2>

원판을 아래와 같은 방법으로 총 T번 회전시키려고 한다. 
원판의 회전 방법은 미리 정해져 있고, i번째 회전할때 사용하는 변수는 xi, di, ki이다.

1. 번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
2. 인접하면서 수가 같은 것을 모두 찾는다.
    2-1. 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
    2-2. 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
원판을 T번 회전시킨 후 원판에 적힌 수의 합을 구해보자.


입력
첫째 줄에 N, M, T이 주어진다. (2 ≤ N, M ≤ 50, 1 ≤ T ≤ 50)
둘째 줄부터 N개의 줄에 원판에 적힌 수가 주어진다.
i번째 줄의 j번째 수는 (i, j)에 적힌 수를 의미한다. (1 ≤ 원판에 적힌 수 ≤ 1,000)
다음 T개의 줄에 xi, di, ki가 주어진다. (2 ≤ xi ≤ N, 0 ≤ di ≤ 1, 1 ≤ ki < M)

출력
원판을 T번 회전시킨 후 원판에 적힌 수의 합을 출력한다.

예제 입력 1 
4 4 1
1 1 2 3
5 2 4 2
3 1 3 5
2 1 3 2
2 0 1
예제 출력 1 
30

원판의 초기 상태는 다음과 같다.

<그림3>

예제 입력 2 
4 4 2
1 1 2 3
5 2 4 2
3 1 3 5
2 1 3 2
2 0 1
3 1 3
예제 출력 2 
22

예제 1에서 이어진다.

<그림4>

예제 입력 3 
4 4 3
1 1 2 3
5 2 4 2
3 1 3 5
2 1 3 2
2 0 1
3 1 3
2 0 2
예제 출력 3 
22

예제 2에서 이어진다.

<그림5>

예제 입력 4 
4 4 4
1 1 2 3
5 2 4 2
3 1 3 5
2 1 3 2
2 0 1
3 1 3
2 0 2
3 1 1
예제 출력 4 
0

예제 3에서 이어진다.

<그림6>	

예제 입력 5 
4 6 3
1 2 3 4 5 6
2 3 4 5 6 7
3 4 5 6 7 8
4 5 6 7 8 9
2 1 4
3 0 1
2 1 2
예제 출력 5 
26

*/

/*

배열을 시계 방향 또는 반시계 방향으로 회전시키고,
DFS 또는 BFS로 인접한 지점을 찾아 원판의 숫자를 바꾸는 시뮬레이션 문제.

1시간을 목표로 잡은 문제인데 1시간 30분이나 걸렸다 ㅠ....ㅠ..
평소에 DFS로는 시도를 많이 안해봤는데, 인접 영역을 찾을 때 DFS를 사용하려고 하니 헷갈리는 부분이 많았다..
(BFS로 접근했으면 조금 빠르지 않았을까... 라고 조심스럽게 예측......)

또한, 원형으로 된 배열에서 인접한 영역을 찾을 때,
BFS에서 사용했던 것과 똑같이 dy, dx를 사용했어도 되는데 (양 끝지점인 1 또는 M, N만 따로 처리해주면 된다.)
문제에 쓰여 있는 그대로 구현을 하려고 하다 보니 하나 하나 조건문을 사용하게 되었다.
(여기서 아마 시간이 조금 더 걸렸던 것 같다.)

또한, 숫자를 지웠다는 것을 표시하기 위한 check라는 배열을 따로 사용했는데,
원판을 돌릴 때마다 같이 돌려야 할 것을 같이 돌리지 않아서 답을 구하는 데 오류가 있었다.
check 배열을 따로 사용하지 않고 원형판 자체를 바꿔주는(지웠다면 0으로 표시) 방식을 사용한다면
조금 더 직관적으로 구현이 가능할 것 같다.

다음에 복습할 때에는 아래의 내용을 추가적으로 고려해보고자 한다.
1) 배열을 복사할 때, 크기가 같다면 memcpy를 사용해보자!
    memcpy(dst, src, sizeof(dst));
    (크기가 같은 경우에는 사이즈 부분에 src를 사용해도 되지만,
    만약 크기가 다르다면 필수적으로 dst의 사이즈를 사용하도록 하자. src의 크기가 더 큰 경우에는 오류가 난다.)
2) 인접 영역을 볼 때 dy, dx를 사용해보자.
3) check 배열을 사용하지 않고, arr 자체를 바꿔주는 형식을 사용해보자.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 50 + 10;

int N, M, T;
int arr[MAX][MAX];

int cnt;

bool visited[MAX][MAX];
bool check[MAX][MAX] = { false, };

void rotateArr(int x, int d, int k) {
    if (d == 0) { // 원판을 시계 방향으로 k번 회전시킨다.
        for (int i = 0; i < k; i++) {
            int temp = arr[x][M];
            int temp2 = check[x][M];
            for (int j = M; j >= 2; j--) {
                arr[x][j] = arr[x][j - 1];
                check[x][j] = check[x][j - 1];
            }
            arr[x][1] = temp;
            check[x][1] = temp2;
        }
    }
    else { // 원판을 반시계 방향으로 k번 회전시킨다.
        for (int i = 0; i < k; i++) {
            int temp = arr[x][1];
            int temp2 = check[x][1];
            for (int j = 1; j <= M - 1; j++) {
                arr[x][j] = arr[x][j + 1];
                check[x][j] = check[x][j + 1];
            }
            arr[x][M] = temp;
            check[x][M] = temp2;
        }
    }
}

void DFS(int y, int x) {
    visited[y][x] = true;

    // 양 옆
    if (x == 1) {
        if (!check[y][2] && !visited[y][2] && (arr[y][2] == arr[y][x])) {
            check[y][2] = true;
            cnt++;

            if (!check[y][x]) {
                check[y][x] = true;
                cnt++;
            }

            DFS(y, 2);
        }
        if (!check[y][M] && !visited[y][M] && (arr[y][M] == arr[y][x])) {
            check[y][M] = true;
            cnt++;

            if (!check[y][x]) {
                check[y][x] = true;
                cnt++;
            }

            DFS(y, M);
        }
    }
    else if (x == M) {
        if (!check[y][M-1] && !visited[y][M-1] && (arr[y][M-1] == arr[y][x])) {
            check[y][M - 1] = true;
            cnt++;

            if (!check[y][x]) {
                check[y][x] = true;
                cnt++;
            }

            DFS(y, M-1);
        }
        if (!check[y][1] && !visited[y][1] && (arr[y][1] == arr[y][x])) {
            check[y][1] = true;
            cnt++;

            if (!check[y][x]) {
                check[y][x] = true;
                cnt++;
            }

            DFS(y, 1);
        }
    }
    else {
        if (!check[y][x - 1] && !visited[y][x - 1] && (arr[y][x - 1] == arr[y][x])) {
            check[y][x - 1] = true;
            cnt++;

            if (!check[y][x]) {
                check[y][x] = true;
                cnt++;
            }

            DFS(y, x - 1);
        }
        if (!check[y][x + 1] && !visited[y][x + 1] && (arr[y][x + 1] == arr[y][x])) {
            check[y][x + 1] = true;
            cnt++;

            if (!check[y][x]) {
                check[y][x] = true;
                cnt++;
            }

            DFS(y, x + 1);
        }
    }

    // 위 아래
    if (y == 1) {
        if (!check[2][x] && !visited[2][x] && (arr[2][x] == arr[y][x])) {
            check[2][x] = true;
            cnt++;

            if (!check[y][x]) {
                check[y][x] = true;
                cnt++;
            }

            DFS(2, x);
        }
    }
    else if (y == N) {
        if (!check[N - 1][x] && !visited[N - 1][x] && (arr[N - 1][x] == arr[y][x])) {
            check[N - 1][x] = true;
            cnt++;

            if (!check[y][x]) {
                check[y][x] = true;
                cnt++;
            }

            DFS(N - 1, x);
        }
    }
    else {
        if (!check[y - 1][x] && !visited[y - 1][x] && (arr[y - 1][x] == arr[y][x])) {
            check[y - 1][x] = true;
            cnt++;

            if (!check[y][x]) {
                check[y][x] = true;
                cnt++;
            }

            DFS(y - 1, x);
        }
        if (!check[y + 1][x] && !visited[y + 1][x] && (arr[y + 1][x] == arr[y][x])) {
            check[y + 1][x] = true;
            cnt++;

            if (!check[y][x]) {
                check[y][x] = true;
                cnt++;
            }

            DFS(y + 1, x);
        }
    }
}

void rotate(int x, int d, int k) {
    for (int t = 1; t <= N; t++) {
        if (t % x != 0) continue;

        rotateArr(t, d, k);
    }

    memset(visited, false, sizeof(visited));
    cnt = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!visited[i][j] && !check[i][j]) {
                DFS(i, j);
            }
        }
    }

    if (cnt == 0) {
        int sum = 0, num = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (!check[i][j]) {
                    sum += arr[i][j];
                    num++;
                }
            }
        }

        float aver = (float)sum / num;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (!check[i][j]) {
                    if (aver < arr[i][j]) arr[i][j]--;
                    else if (aver > arr[i][j]) arr[i][j]++;
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &T);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 1; i <= T; i++) {
        int x, d, k;
        scanf("%d %d %d", &x, &d, &k);

        rotate(x, d, k);
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!check[i][j]) sum += arr[i][j];
        }
    }

    printf("%d", sum);

    return 0;
}