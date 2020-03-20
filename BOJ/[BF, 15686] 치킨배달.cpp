/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB		21150	9307	5221	39.643%

문제
크기가 N×N인 도시가 있다. 도시는 1×1크기의 칸으로 나누어져 있다. 도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다. 
도시의 칸은 (r, c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다. 
r과 c는 1부터 시작한다.

이 도시에 사는 사람들은 치킨을 매우 좋아한다. 따라서, 사람들은 "치킨 거리"라는 말을 주로 사용한다. 
치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다. 
즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 치킨 거리를 가지고 있다. 
도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.

임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다.
예를 들어, 아래와 같은 지도를 갖는 도시를 살펴보자.

0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 2

0은 빈 칸, 1은 집, 2는 치킨집이다.

(2, 1)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |2-1| + |1-2| = 2, (5, 5)에 있는 치킨집과의 거리는 |2-5| + |1-5| = 7이다. 
따라서, (2, 1)에 있는 집의 치킨 거리는 2이다.
(5, 4)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |5-1| + |4-2| = 6, (5, 5)에 있는 치킨집과의 거리는 |5-5| + |4-5| = 1이다. 
따라서, (5, 4)에 있는 집의 치킨 거리는 1이다.

이 도시에 있는 치킨집은 모두 같은 프랜차이즈이다. 
프렌차이즈 본사에서는 수익을 증가시키기 위해 일부 치킨집을 폐업시키려고 한다. 
오랜 연구 끝에 이 도시에서 가장 수익을 많이 낼 수 있는  치킨집의 개수는 최대 M개라는 사실을 알아내었다.
도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 
어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.
둘째 줄부터 N개의 줄에는 도시의 정보가 주어진다.
도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다. 
집의 개수는 2N개를 넘지 않으며, 적어도 1개는 존재한다. 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.

출력
첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력한다.

예제 입력 1 
5 3
0 0 1 0 0
0 0 2 0 1
0 1 2 0 0
0 0 1 0 0
0 0 0 0 2
예제 출력 1 
5

예제 입력 2 
5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2
예제 출력 2 
10

예제 입력 3 
5 1
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
예제 출력 3 
11

예제 입력 4 
5 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
예제 출력 4 
32

*/

/*

N개의 치킨집 중 도시의 치킨 거리를 가장 작게 만드는 M개의 치킨집을 고르는 문제.
중복되지 않도록 M개의 치킨집을 고르는 모든 조합을 생각한 후
그 M개의 치킨집들과 집과의 거리 중 가장 작은 값을 해당 조합에서의 치킨 거리로 확정하면 된다.

처음에 아무 생각 없이 중복이 되도록 (M개 모두 치킨집 0번이 되는 경우;;;) 조합을 짰다가
시간초과가 나서 굉장히 당황했다...ㅎ;;
이후 선택(1)/미선택(0) 방식으로 다시 풀긴 했지만(주석 처리한 코드 참고) 나는 바로 아래 코드의 방식이 더 좋다!

M개를 고를 때 중복 없이 골라야 함을 잊지말자!!!

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 50 + 10;

int N, M;
int map[MAX][MAX];
vector<pair<int, int>> home, chicken;

int comb[20];
int myMin = 987987987;

int getAbs(int x) {
    if (x > 0) return x;
    else return -x;
}

void getMinDist() {
    int sum = 0;
    for (int i = 0; i < home.size(); i++) {
        int minDist = 987987987;
        for (int j = 0; j < M; j++) {
            int idx = comb[j];
            int dist = getAbs(chicken[idx].first - home[i].first) + getAbs(chicken[idx].second - home[i].second);

            if (dist < minDist) minDist = dist;
        }

        sum += minDist;
    }

    if (sum < myMin) myMin = sum;
}

void getComb(int x) {
    if (x >= M) {
        getMinDist();
    }
    else {
        for (int i = 0; i < chicken.size(); i++) {
            if (x == 0 || comb[x - 1] < i) {
                comb[x] = i;
                getComb(x + 1);
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == 1) home.push_back(make_pair(i, j));
            else if (map[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }

    getComb(0);

    printf("%d\n", myMin);

    return 0;
}

/*
// 선택(1) / 미선택(0) 으로 조합을 짜는 방법
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 50 + 10;
const int MAXH = 100 + 10;

int N, M;
int map[MAX][MAX];
vector<pair<int, int>> home, chicken;

int comb[20];
int myMin = 987987987;

int getAbs(int x) {
    if (x > 0) return x;
    else return -x;
}

void getMinDist() {
    int dist[MAXH];
    for (int i = 0; i < home.size(); i++) dist[i] = 987987987;

    for (int i = 0; i < chicken.size(); i++) {
        if (comb[i]) {
            for (int j = 0; j < home.size(); j++) {
                int d = getAbs(chicken[i].first - home[j].first) + getAbs(chicken[i].second - home[j].second);

                if (d < dist[j]) dist[j] = d;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < home.size(); i++) sum += dist[i];

    if (sum < myMin) myMin = sum;
}

void getComb(int x, int cnt) {
    if (x >= chicken.size()) {
        if (cnt == 0) getMinDist();
    }
    else {
        if (cnt > 0) {
            comb[x] = 1;
            getComb(x + 1, cnt - 1);
        }
        comb[x] = 0;
        getComb(x + 1, cnt);
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == 1) home.push_back(make_pair(i, j));
            else if (map[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }

    getComb(0, M);

    printf("%d\n", myMin);

    return 0;
}
*/