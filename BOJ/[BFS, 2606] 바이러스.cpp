// 소요시간: 11분
// 실행시간: 0ms

/*

문제
신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 
한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 
1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 
2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 
하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.

<그림 1>

어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 
컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 
1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 
둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 
이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

출력
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.


예제 입력 1 
7
6
1 2
2 3
1 5
5 2
5 6
4 7
예제 출력 1 
4

*/

/*

컴퓨터의 연결을 담고 있는 그래프를 통해 주변 컴퓨터로 이동하면서 바이러스를 전파시키는 기본적인 BFS 문제.
단방향 그래프가 아니므로 입력되는 노드들을 양방향으로 연결해줘야 함을 잊지 말자!

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 100 + 10;

int N, M;
vector <int> myGraph[MAX];
bool visited[MAX] = { false, };

int BFS() {
    queue <int> q;
    int cnt = 0;
    visited[1] = true;
    q.push(1);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int i = 0; i < myGraph[front].size(); i++) {
            int adj = myGraph[front][i];

            if (!visited[adj]) {
                visited[adj] = true;
                q.push(adj);
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }

    printf("%d\n", BFS());
}