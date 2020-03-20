// 소요시간: 45분
// 실행시간: 0ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB		6440	2221	1653	34.019%

문제
송도에 사는 상근이와 친구들은 송도에서 열리는 펜타포트 락 페스티벌에 가려고 한다. 
올해는 맥주를 마시면서 걸어가기로 했다. 출발은 상근이네 집에서 하고, 맥주 한 박스를 들고 출발한다. 
맥주 한 박스에는 맥주가 20개 들어있다. 목이 마르면 안되기 때문에 50미터에 한 병씩 마시려고 한다.

상근이의 집에서 페스티벌이 열리는 곳은 매우 먼 거리이다. 따라서, 맥주를 더 구매해야 할 수도 있다. 
미리 인터넷으로 조사를 해보니 다행히도 맥주를 파는 편의점이 있다. 
편의점에 들렸을 때, 빈 병은 버리고 새 맥주 병을 살 수 있다. 하지만, 박스에 들어있는 맥주는 20병을 넘을 수 없다.

편의점, 상근이네 집, 펜타포트 락 페스티벌의 좌표가 주어진다. 
상근이와 친구들이 행복하게 페스티벌에 도착할 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 t가 주어진다. (t ≤ 50)
각 테스트 케이스의 첫째 줄에는 맥주를 파는 편의점의 개수 n이 주어진다. (0 ≤ n ≤ 100).
다음 n+2개 줄에는 상근이네 집, 편의점, 펜타포트 락 페스티벌 좌표가 주어진다. 
각 좌표는 두 정수 x와 y로 이루어져 있다. (두 값 모두 미터, -32768 ≤ x, y ≤ 32767)
송도는 직사각형 모양으로 생긴 도시이다. 두 좌표 사이의 거리는 x 좌표의 차이 + y 좌표의 차이 이다. (맨해튼 거리)

출력
각 테스트 케이스에 대해서 상근이와 친구들이 행복하게 페스티벌에 갈 수 있으면 "happy", 중간에 맥주가 바닥나면 "sad"를 출력한다. 

예제 입력 1 
2
2
0 0
1000 0
1000 1000
2000 1000
2
0 0
1000 0
2000 1000
2000 2000
예제 출력 1 
happy
sad

*/

/*

일반적인 BFS와는 달리 visited 배열을 따로 사용하지 않고 구현 가능한 BFS문제.

좌표의 범위가 넓고, 음수도 존재하기 때문에 일반적인 BFS처럼 map과 visited배열을 사용하면 안된다고 판단하여,
CVS라는 구조체를 만들고, 그 안에 편의점의 좌표와 방문여부를 체크하는 변수인 visited를 담을 수 있도록 했다.
(초기 CVS의 visited는 false이다)

처음 이 문제를 접했을 때는 어떻게 구현해야 할지 빠르게 떠올리지 못했다.
맥주 한 병당 50m를 갈 수 있기 때문에, 50m씩 더해주면서 페스티벌 까지 가야하나 생각했는데,
50m를 더하거나 뺄 필요 없이 "자신이 있는 위치"에서 "편의점 또는 페스티벌 위치"를 갈 수 있는지의 여부만
빠르게 판단해서 큐에 넣어주거나 반복문을 종료시키면 되는 것이었다. ㅎㅎㅎ


코드 설명은 다음과 같다.

모든 입력을 받은 후에는 상근이의 위치를 시작으로 BFS를 돌리는데,
상근이는 편의점에 가서 맥주를 리필할 수 있지만, 편의점에 가야만 하는 것은 아니다.
따라서 현재 자신의 위치에서 바로 페스티벌에 갈 수 있다면 그 즉시 true를 리턴하도록 구현했다.

만약 페스티벌에 갈 수 없는 위치라면, 들리지 않은 편의점 중 자신이 갈 수 있는 범위 내에 있는 편의점을 찾아
해당 편의점의 visited를 true로 바꾸고, 큐에 넣는다.
(자신이 갈 수 있는 편의점인지는 맥주 1개로 50m를 갈 수 있으므로 거리를 계산했을 때 1000 이하면 된다.
또한, 이미 방문한 편의점이라면 이미 큐에 누적이 되어 있을 것이므로 굳이 그 편의점은 갈 필요가 없다.)

자신이 갈 수 있는 모든 지점을 다 갔음에도 페스티벌에 도착하지 못한다면(큐가 다 비워졌을 경우) false를 리턴한다.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int T;
int N;
int Y, X;
int dstY, dstX;
vector<bool> res;

struct CVS {
    int y, x;
    bool visited = false;

    void create(int _y, int _x) {
        y = _y;
        x = _x;
    }
};

vector<CVS> cvs;

int getAbs(int x) {
    if (x > 0) return x;
    else return -x;
}

bool BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        // 만약 현재 위치에서 페스티벌에 갈 수 있다면 true를 리턴한다.
        int distance = getAbs(front.first - dstY) + getAbs(front.second - dstX);
        if (distance <= 1000) return true;

        for (int i = 0; i < N; i++) {
            if (cvs[i].visited) continue; // 이미 방문한 편의점이라면 건너뛴다.

            int dist = getAbs(front.first - cvs[i].y) + getAbs(front.second - cvs[i].x);

            if (dist <= 1000) { // 갈 수 있는 편의점이라면 간다.
                cvs[i].visited = true;
                q.push(make_pair(cvs[i].y, cvs[i].x));
            }
        }
    }

    return false;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        cvs.clear();
        scanf("%d", &N);
        scanf("%d %d", &Y, &X);

        for (int i = 0; i < N; i++) {
            int y, x;
            scanf("%d %d", &y, &x);

            CVS c;
            c.create(y, x);
            cvs.push_back(c);
        }

        scanf("%d %d", &dstY, &dstX);

        if (BFS(Y, X)) res.push_back(true);
        else res.push_back(false);
    }

    for (int i = 0; i < res.size(); i++) {
        if (res[i]) printf("happy\n");
        else printf("sad\n");
    }

    return 0;
}