// 소요시간: 30분
// 실행시간: 236ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB		25493	14617	8063	54.843%

문제
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 
다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.

연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 
연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 

일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 
새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 
아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.

2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

2 1 0 0 1 1 0
1 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 1 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

2 1 0 0 1 1 2
1 0 1 0 1 2 2
0 1 1 0 1 2 2
0 1 0 0 0 1 2
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.
연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 
2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
빈 칸의 개수는 3개 이상이다.

출력
첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.


예제 입력 1 
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
예제 출력 1 
27

예제 입력 2 
4 6
0 0 0 0 0 0
1 0 0 0 0 2
1 1 1 0 0 2
0 0 0 0 0 2
예제 출력 2 
9

예제 입력 3 
8 8
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
예제 출력 3 
3

*/

/*

완전 탐색 + BFS 를 통해 모든 빈 공간 중 3개의 자리에 벽을 설치하고, 바이러스를 퍼뜨리는 문제.

처음에는 바이러스가 퍼질 위치를 통해 벽을 세울 위치를 구해야 하나? 싶었는데,
N, M의 최댓값(8)을 본 순간... 아!!! 이건 완탐이다!!! 했다 ㅎㅎㅎ
시간 복잡도가 O(N^6)에 이르지만... 8이 최대이므로 모든 칸이 0으로 채워져 있어도 1초가 넘어가지 않는다!

그래서 나는 맵을 처음부터 끝까지 보면서,
빈 공간(0)이고 새로 벽을 세운 지점이 아니라면 그 지점에 벽을 세워 총 3개의 벽을 세운 다음에
바이러스(2)가 갈 수 있는 지점(0)으로 상하좌우로 퍼지도록 구현하였다.

실행시간이 236ms가 나왔는데, 다른 사람들의 실행시간를 보니 40ms도 존재하는 것을 볼 수 있었다.
어떻게 하면 지금 실행시간에서 더 줄일 수 있을까 생각을 해봤더니,
처음에 인풋을 받을 때 빈 공간의 위치를 벡터에 저장시켜 놓고,
처음 인덱스(0)부터 이전 위치는 보지 않도록, 다음 위치로만 인덱스를 이동시킴으로써 3개를 고른 후 BFS를 돌리면
이전 위치는 보지 않고, 0인 위치만 자동으로 보게 됨으로써 반복문을 도는 횟수를 줄일 수 있을 것 같았다!
(어차피 벽을 세우는 위치는 빈 공간만 되므로)

다음에 복습할 때는 위와 같은 방법으로 구현해봐야겠다. ㅎㅎ

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 10;

int N, M;
int map[MAX][MAX];
vector<pair<int, int>> virus;

bool check[MAX][MAX];

bool visited[MAX][MAX];
int zeroNum;
int myMax;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS() {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < virus.size(); i++) {
        visited[virus[i].first][virus[i].second] = true;
        q.push(make_pair(virus[i].first, virus[i].second));
    }

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = front.first + dy[i];
            int nx = front.second + dx[i];

            if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1) continue;

            if (!visited[ny][nx] && map[ny][nx] == 0) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
                cnt++;
            }
        }
    }

    return zeroNum - cnt;
}

void getComb(int x) {
    if (x >= 3) {
        int cnt = BFS();
        if (cnt > myMax) myMax = cnt;
    }
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] != 0 || check[i][j]) continue;

                check[i][j] = true;
                map[i][j] = 1;

                getComb(x + 1);
                
                check[i][j] = false;
                map[i][j] = 0;
            }
        }
    }
}

int main()
{
    zeroNum = 0;
    myMax = -1;
    memset(check, 0, sizeof(check));
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == 0) zeroNum++;
            else if (map[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    getComb(0);

    printf("%d", myMax - 3);

    return 0;
}