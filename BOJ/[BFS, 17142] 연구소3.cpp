// 소요시간: 29분
// 실행시간: 16ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
0.25 초		512 MB	12459	3367	1964	25.563%

문제
인체에 치명적인 바이러스를 연구하던 연구소에 승원이가 침입했고, 바이러스를 유출하려고 한다. 
바이러스는 활성 상태와 비활성 상태가 있다. 가장 처음에 모든 바이러스는 비활성 상태이고, 
활성 상태인 바이러스는 상하좌우로 인접한 모든 빈 칸으로 동시에 복제되며, 1초가 걸린다. 
승원이는 연구소의 바이러스 M개를 활성 상태로 변경하려고 한다.

연구소는 크기가 N×N인 정사각형으로 나타낼 수 있으며, 정사각형은 1×1 크기의 정사각형으로 나누어져 있다. 
연구소는 빈 칸, 벽, 바이러스로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 
활성 바이러스가 비활성 바이러스가 있는 칸으로 가면 비활성 바이러스가 활성으로 변한다.

예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자. 0은 빈 칸, 1은 벽, 2는 바이러스의 위치이다.

2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 0 0 2

M = 3이고, 바이러스를 아래와 같이 활성 상태로 변경한 경우 6초면 모든 칸에 바이러스를 퍼뜨릴 수 있다. 
벽은 -, 비활성 바이러스는 *, 활성 바이러스는 0, 빈 칸은 바이러스가 퍼지는 시간으로 표시했다.

* 6 5 4 - - 2
5 6 - 3 - 0 1
4 - - 2 - 1 2
3 - 2 1 2 2 3
2 2 1 0 1 - -
1 - 2 1 2 3 4
0 - 3 2 3 4 *

시간이 최소가 되는 방법은 아래와 같고, 4초만에 모든 칸에 바이러스를 퍼뜨릴 수 있다.

0 1 2 3 - - 2
1 2 - 3 - 0 1
2 - - 2 - 1 2
3 - 2 1 2 2 3
3 2 1 0 1 - -
4 - 2 1 2 3 4
* - 3 2 3 4 *

연구소의 상태가 주어졌을 때, 모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간을 구해보자.

입력
첫째 줄에 연구소의 크기 N(4 ≤ N ≤ 50), 놓을 수 있는 바이러스의 개수 M(1 ≤ M ≤ 10)이 주어진다.
둘째 줄부터 N개의 줄에 연구소의 상태가 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 있는 위치이다. 
2의 개수는 M보다 크거나 같고, 10보다 작거나 같은 자연수이다.

출력
연구소의 모든 빈 칸에 바이러스가 있게 되는 최소 시간을 출력한다. 
바이러스를 어떻게 놓아도 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우에는 -1을 출력한다.

예제 입력 1 
7 3
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 0 0 2
예제 출력 1 
4

예제 입력 2 
7 3
2 0 2 0 1 1 0
0 0 1 0 1 2 0
0 1 1 2 1 0 0
2 1 0 0 0 0 2
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2
예제 출력 2 
4

예제 입력 3 
7 4
2 0 2 0 1 1 0
0 0 1 0 1 2 0
0 1 1 2 1 0 0
2 1 0 0 0 0 2
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2
예제 출력 3 
4

예제 입력 4 
7 5
2 0 2 0 1 1 0
0 0 1 0 1 2 0
0 1 1 2 1 0 0
2 1 0 0 0 0 2
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2
예제 출력 4 
3

예제 입력 5 
7 3
2 0 2 0 1 1 0
0 0 1 0 1 0 0
0 1 1 1 1 0 0
2 1 0 0 0 0 2
1 0 0 0 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2
예제 출력 5 
7

예제 입력 6 
7 2
2 0 2 0 1 1 0
0 0 1 0 1 0 0
0 1 1 1 1 0 0
2 1 0 0 0 0 2
1 0 0 0 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2
예제 출력 6 
-1

예제 입력 7 
5 1
2 2 2 1 1
2 1 1 1 1
2 1 1 1 1
2 1 1 1 1
2 2 2 1 1
예제 출력 7 
0

*/

/*

연구소2 문제에서 바이러스의 활성, 비활성 여부만 추가되었을 뿐 거의 똑같은 BFS문제이다.
따라서 연구소2 문제에서 언급했던 수행과정 중, 1) 2) 3) 과정은 이 문제에서도 똑같이 진행된다.

1) map이 2(바이러스가 존재 가능한 위치)인 위치를 벡터에 저장한다.
2) 벡터의 번호를 이용하여 조합을 구한다. (조합의 길이는 M이고, 중복되지 않아야 한다.)
3) 바이러스를 복제한다.

다만, 4)번 과정의 최소 시간을 업데이트 할 때, 연구소2와는 다르게
이 문제에서는 맵의 2에 해당하는 부분이 "비활성"되어 있을 뿐, 바이러스는 존재한다는 것을 고려해줘야 한다.
즉, 최소 시간을 구하는 과정에서 맵의 2에 해당하는 부분은 관여해서는 안되며, 오직 0에 해당하는 부분만 관여해야 한다.

또한, 연구소 2에서는 myMax의 초기값을 -1로 해주었는데,
-1으로 그대로 세팅할 경우 맵에 1(벽)과 2(바이러스)만 존재하는 상황에서 0이 출력되어야 하는데 -2가 출력된다.
(맵이 2인 부분은 건너 뛰므로 myMax가 -1로 고정되고, 마지막에 -1을 한 값이 출력되므로 -2가 출력되는 것)

바이러스가 퍼질 필요가 없을 때를 따로 고려해줘도 상관 없지만,
나는 myMax의 값을 업데이트 할 때 사용되는 visited의 값도 최솟값이 1이기 때문에 myMax의 초기값을 그냥 1로 바꿔주었다.
그러면 1과 2만 존재하는 상황에서도 -2가 아닌 0이 제대로 출력된다.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 50 + 10;

int N, M;
int map[MAX][MAX];
vector<pair<int, int>> virus;

int visited[MAX][MAX];
int comb[20];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int myMin = 987987987;

void spread() {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    
    for (int i = 0; i < M; i++) {
        visited[virus[comb[i]].first][virus[comb[i]].second] = 1;
        q.push(make_pair(virus[comb[i]].first, virus[comb[i]].second));
    }

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = front.first + dy[i];
            int nx = front.second + dx[i];

            if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1) continue;
            if (visited[ny][nx] || map[ny][nx] == 1) continue;

            visited[ny][nx] = visited[front.first][front.second] + 1;
            q.push(make_pair(ny, nx));
        }
    }

    int myMax = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) continue;
            if (!visited[i][j]) return;

            if (map[i][j] == 0) myMax = max(myMax, visited[i][j]);
        }
    }

    myMin = min(myMin, myMax);
}

void getComb(int x) {
    if (x >= M) {
        spread();
    }
    else {
        for (int i = 0; i < virus.size(); i++) {
            if (x == 0 || comb[x - 1] < i) {
                comb[x] = i;
                getComb(x + 1);
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    getComb(0);
    
    if (myMin == 987987987) printf("-1\n");
    else printf("%d\n", myMin - 1);

    return 0;
}