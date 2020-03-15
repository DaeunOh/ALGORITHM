// 소요시간: 3시간 (MAX의 범위................)
// 실행시간: 96ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	6597	1507	1047	21.785%

문제
지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!
미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 
그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.

지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다) 이동한다. 
불은 각 지점에서 네 방향으로 확산된다. 
지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다. 
지훈이와 불은 벽이 있는 공간은 통과하지 못한다.


입력
입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1000 이다. 
R은 미로 행의 개수, C는 열의 개수이다.

다음 입력으로 R줄동안 각각의 미로 행이 주어진다.
 각각의 문자들은 다음을 뜻한다.

#: 벽
.: 지나갈 수 있는 공간
J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
F: 불이난 공간
J는 입력에서 하나만 주어진다.

출력
지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는경우 IMPOSSIBLE 을 출력한다.
지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다. 


예제 입력 1 
4 4
####
#JF#
#..#
#..#
예제 출력 1 
3

*/

/*

지훈이는 불이 있는 곳에는 가지 못하므로, 불을 먼저 퍼뜨리고 난 후
지훈이가 이동하면서 자신의 시간보다 불이 늦게 오거나, 불이 아예 없는 경우 이동이 가능하도록 구현하는 시뮬레이션 문제.

BFS로 시간을 체크하면서 벽이 아닌 곳만 옮겨 다니면 되는 문제라 구현에는 어려움이 없었는데
문제를 풀면서......... 약 2시간이라는 시간을 잡아먹은 두 개의 문제점이 있었다...

1) 처음에는 map을 char로 선언한 후에, scanf(" %c", &map[i][j]); 로 맵에 바로 받았다.
    그리고 map[i][j]가 불인 경우에는 불queue에 넣어주고 방문 처리를 하고,
    사람인 경우에는 사람queue에 넣어주고 방문처리를 했다.

    하지만 백준에서는 왠지 모르게... 위처럼 인풋을 받아오는 과정을 인식하지(?) 못한다..
    계속 시간 초과가 뜨길래 이동 부분의 문제인가 했는데, 확인해 본 결과 인풋을 받아오는 과정에서 생긴 시간초과였다..
    그래서 char 변수로 인풋을 받고, 그 변수에 따라 map을 특정 정수로 바꿔서 저장했더니
    위와 같은 문제는 해결될 수 있었다. ㅜㅜ

    헐!!!!!!! 혹시나 해서.. 방금 시간초과의 이유가 scanf로 원하는 숫자를 다 받아오지 못해 생긴 건 아닐까 해서
    초기 코드 100이었던 MAX를 1000으로 바꿔 주었더니 ㅠㅠㅠㅠ 정답이 떴다... ㅠㅠㅠ...
    이 모든건... 2번에 나올 MAX 범위 문제 때문이었다...
    다음에는 시간 초과가 날 때 최대 범위를 잘못 잡은건 아닌지 먼저 생각해봐야겠다 ㅠㅠ...

2) R과 C의 범위가 최대 1000인데.... MAX를 100으로 잡아버렸다...
    이 문제 때문에 3시간을 날렸다니... 매우 허무하지만.. 내 실수니까 ㅠㅠㅠ...
    그래도 다음에는 더이상 이 실수는 안할 것 같다.. 아니 못할 것 같다..ㅎ;;;

    아까 말했듯이 시간초과 이슈는 R과 C의 인풋을 다 받아오지 못해서 생긴거였고,
    계속 틀렸던 이유는... R과 C를 역시 다 못받아와서 map에 다 들어가지 못한 채로 진행됐기 때문이다 ㅠㅠ..
    그래도 지금이라도 알게된 게 다행이라고 생각한다....

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 10;

int R, C;
int map[MAX][MAX];
int visitedF[MAX][MAX] = { 0, };
int visitedJ[MAX][MAX] = { 0, };

queue < pair<int, int> > qF;
queue < pair<int, int> > qJ;

bool isFinished = false;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int visited[MAX][MAX], queue < pair<int, int> > &q, bool isF) {
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        if (!isF && (front.first == 0 || front.first == R - 1 || front.second == 0 || front.second == C - 1)) {
            isFinished = true;
            printf("%d\n", visited[front.first][front.second]);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = front.first + dy[i];
            int nx = front.second + dx[i];

            if (ny < 0 || ny > R-1 || nx < 0 || nx > C-1) continue;
            if (map[ny][nx] == 4) continue;

            if (isF && !visited[ny][nx]) {
                visited[ny][nx] = visited[front.first][front.second] + 1;
                q.push(make_pair(ny, nx));
            }

            if (!isF && !visited[ny][nx]
                && (visitedF[ny][nx] > visited[front.first][front.second] + 1 || visitedF[ny][nx] == 0)) {
                visited[ny][nx] = visited[front.first][front.second] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main()
{
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char temp;
            scanf(" %c", &temp);

            if (temp == 'F') {
                map[i][j] = 1;
                visitedF[i][j] = 1;
                qF.push(make_pair(i, j));
            }
            else if (temp == 'J') {
                map[i][j] = 2;
                visitedJ[i][j] = 1;
                qJ.push(make_pair(i, j));
            }
            else if (temp == '.') map[i][j] = 3;
            else if (temp == '#') map[i][j] = 4;
        }
    }

    BFS(visitedF, qF, 1);
    BFS(visitedJ, qJ, 0);

    if (!isFinished) printf("IMPOSSIBLE\n");
}