// 소요시간: 13분
// 실행시간: 4ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB		14175	4414	3374	34.330%

문제
강호는 코딩 교육을 하는 스타트업 스타트링크에 지원했다. 오늘은 강호의 면접날이다. 
하지만, 늦잠을 잔 강호는 스타트링크가 있는 건물에 늦게 도착하고 말았다.

스타트링크는 총 F층으로 이루어진 고층 건물에 사무실이 있고, 스타트링크가 있는 곳의 위치는 G층이다. 
강호가 지금 있는 곳은 S층이고, 이제 엘리베이터를 타고 G층으로 이동하려고 한다.

보통 엘리베이터에는 어떤 층으로 이동할 수 있는 버튼이 있지만, 강호가 탄 엘리베이터는 버튼이 2개밖에 없다. 
U버튼은 위로 U층을 가는 버튼, D버튼은 아래로 D층을 가는 버튼이다. 
(만약, U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다)

강호가 G층에 도착하려면, 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램을 작성하시오. 
만약, 엘리베이터를 이용해서 G층에 갈 수 없다면, "use the stairs"를 출력한다.

입력
첫째 줄에 F, S, G, U, D가 주어진다. (1 ≤ S, G ≤ F ≤ 1000000, 0 ≤ U, D ≤ 1000000) 
건물은 1층부터 시작하고, 가장 높은 층은 F층이다.

출력
첫째 줄에 강호가 S층에서 G층으로 가기 위해 눌러야 하는 버튼의 수의 최솟값을 출력한다. 
만약, 엘리베이터로 이동할 수 없을 때는 "use the stairs"를 출력한다.

예제 입력 1 
10 1 10 2 1
예제 출력 1 
6

예제 입력 2 
100 2 1 1 0
예제 출력 2 
use the stairs

*/

/*

S층에 있는 강호가 G층에 도착하기 위해 눌러야 하는 버튼 수의 "최솟값"을 구하는 것이므로,
DFS보다는 BFS방식을 활용하는게 좋다고 판단했다.
(DFS는 최악의 경우 답이 아님에도 굉장히 깊게 탐색할 수도 있기 때문이다.)

해당 문제는 건물 안에 해당 층이 존재하는지 확인 하고, 방문 처리만 잘 해주면 쉽게 정답을 구할 수 있는 문제이다.

어떤 층에서 강호가 엘레베이터를 타고 갈 수 있는 층은 자신의 위치 + U, 자신의 위치 - D밖에 존재하지 않으므로,
해당 건물에 자신의 위치 + U 또는 자신의 위치 - D 층이 존재하면서 방문하지 않은 층이라면
해당 층을 방문처리 한 후 큐에 push한다.

큐에 쌓이는 층들 중, G층이 있다면 visited에 저장해놓은 횟수를 출력하며 true를 return하고,
큐를 다 스캔해도 G층이 없다면 false를 return하고 use the stairs을 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 1000000 + 10;

int F, S, G, U, D;
int visited[MAX] = { 0, };

bool BFS(int start) {
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == G) {
            printf("%d\n", visited[front] - 1);
            return true;
        }

        if (front + U <= F && !visited[front + U]) {
            visited[front + U] = visited[front] + 1;
            q.push(front + U);
        }

        if (front - D >= 1 && !visited[front - D]) {
            visited[front - D] = visited[front] + 1;
            q.push(front - D);
        }
    }

    return false;
}

int main() {
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    
    if(!BFS(S)) printf("use the stairs\n");

    return 0;
}