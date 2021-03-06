// 소요시간: 1시간 12분
// 실행시간: 20ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB		3216	1731	1069		52.376%

문제
재현시의 시장 구재현은 지난 몇 년간 게리맨더링을 통해서 자신의 당에게 유리하게 선거구를 획정했다. 
견제할 권력이 없어진 구재현은 권력을 매우 부당하게 행사했고, 심지어는 시의 이름도 재현시로 변경했다. 
이번 선거에서는 최대한 공평하게 선거구를 획정하려고 한다.

재현시는 크기가 N×N인 격자로 나타낼 수 있다. 격자의 각 칸은 구역을 의미하고, r행 c열에 있는 구역은 (r, c)로 나타낼 수 있다. 
구역을 다섯 개의 선거구로 나눠야 하고, 각 구역은 다섯 선거구 중 하나에 포함되어야 한다. 
선거구는 구역을 적어도 하나 포함해야 하고, 한 선거구에 포함되어 있는 구역은 모두 연결되어 있어야 한다. 
구역 A에서 인접한 구역을 통해서 구역 B로 갈 수 있을 때, 두 구역은 연결되어 있다고 한다. 
중간에 통하는 인접한 구역은 0개 이상이어야 하고, 모두 같은 선거구에 포함된 구역이어야 한다.

선거구를 나누는 방법은 다음과 같다.
1. 기준점 (x, y)와 경계의 길이 d1, d2를 정한다. (d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N)
2. 다음 칸은 경계선이다.
  2-1. (x, y), (x+1, y-1), ..., (x+d1, y-d1)
  2-2. (x, y), (x+1, y+1), ..., (x+d2, y+d2)
  2-3. (x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
  2-4. (x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
3. 경계선과 경계선의 안에 포함되어있는 곳은 5번 선거구이다.
4. 5번 선거구에 포함되지 않은 구역 (r, c)의 선거구 번호는 다음 기준을 따른다.
  4-1. 1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
  4-2. 2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
  4-3. 3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
  4-4. 4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N

아래는 크기가 7×7인 재현시를 다섯 개의 선거구로 나눈 방법의 예시이다.

[그림1]

구역 (r, c)의 인구는 A[r][c]이고, 선거구의 인구는 선거구에 포함된 구역의 인구를 모두 합한 값이다. 
선거구를 나누는 방법 중에서, 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값을 구해보자.

입력
첫째 줄에 재현시의 크기 N이 주어진다. (5 ≤ N ≤ 20)
둘째 줄부터 N개의 줄에 N개의 정수가 주어진다. r행 c열의 정수는 A[r][c]를 의미한다. (1 ≤ A[r][c] ≤ 100)

출력
첫째 줄에 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값을 출력한다.

*/

/*

◆ 풀이

주어진 조건에 따라 기준점 (x, y)를 구하고, 그 기준점에서 가능한 경계의 길이 d1, d2를 정한 후에
경계선을 계산하여 경계선에 따라 5개의 선거구로 나누는 시뮬레이션 문제이다.

기준점, 경계의 길이뿐만 아니라 경계선이나 각 선거구에 대한 조건까지 모두 까다롭지만,
반대로 생각하면 그 조건만 코드에 잘 녹여낼 수 있으면 쉬운 문제가 될 수 있다. (나는 어려웠다 ^^;;)

코드의 전체적인 진행 과정은 다음과 같다.

1) 기준점 (x, y)를 구한다.
    여기서의 기준점은 조건에 따라 계산해보면 (1, 2) ~ (N-2, N-1) 사이의 값이 될 수 있음을 캐치해야 한다.

2) 경계의 길이 d1, d2를 정한다.
    경계의 길이는 기준점에 따라 최소 1부터 최대 N-2까지 설정될 수 있다.
    어떤 길이가 가능한가는 d1과 기준점에 달려 있으므로 문제에서 주어진 조건을 활용해보도록 하자.

3) 5번 선거구의 위치를 찾는다.
    5번 선거구는 기준점과 경계의 길이에 의해 정해진 경계선과 그 경계선 안에 존재하는 구역이 된다.
    경계선은 조건에 의해 쉽게 구할 수 있고, 그 안에 존재하는 구역들은 한 행에서 두 경계선 사이의 구역이 되므로
    이를 활용해서 경계선 안에 존재하는 구역을 5번 선거구로 지정할 수 있다.
    5번 선거구가 된 지점은 isFive라는 2차원 배열에 true로 설정해놓았다.

4) 주어진 선거구 범위의 조건과 5번 선거구의 지점을 활용하여 각 선거구의 인원을 구한다.
    각 선거구의 범위는 구해져 있지만, 그 범위는 5번 선거구와 일정 부분 겹치는 구간이 존재한다.
    따라서 "5번 선거구가 아니면서" "각 선거구의 범위에 해당하는 구역"이 바로 특정 번호의 선거구가 된다.
    (5번 선거구인지 확인하지 않으면, 직사각형의 범위가 구해지므로 이는 문제에서 원하는 선거구의 범위가 아니다.)

5) 인구가 가장 많은 선거구와 적은 선거구를 찾고, 그 차이를 계산한다.

6) 1) ~ 5)의 과정을 반복하여 구한 차이가 최솟값이 되는 경우를 찾는다.


◆ 후기

예전부터 대각선 방향으로 무언가 탐색하고, 구하는 과정이 조금 어렵게 느껴지는 것 같다.
아마 수학적 지식이 조금 요구돼서 그런 것 같은데... 그래도 오늘은 처음 접했을 때보다는 나았다! 그나마 다행!!

이 문제를 풀 때 겪었던 문제 2가지를 뽑자면,
1) 문제에서 주어진 조건의 범위를 명확하게 인지하고 있지 않았다는 점
2) 문제에서 주어진 조건을 그대로 코드에 녹여내는 과정이 빠르게 이루어지지 않았다는 점이다.

조건이 주어졌으면, 그를 활용하여 제대로 녹여내기만 하면 되는 건데,
왠지 자꾸 예시를 들어보고 싶고, 확인해보고 싶고 그래서 그런 것 같다 ㅋㅋㅋㅋㅋ..ㅎㅎ;;;
아니면 그냥 조건 자체가 생소해서 그런 거일 수도...?

그리고 사실 이 문제는 대각선 개념이 나오고, 여러 조건이 포함되어 있는 것 때문에 매일 미뤘던 문제이다.
오늘은 더이상 미루지 말아야지란 생각에 ...!! ㅎㅎㅎ
그래도 생각보다 오래 걸리지 않아서(?) 그리고 걱정거리가 사라져서 좋다. ㅎㅎㅎ

다음에 비슷한 문제를 보게 되면, 그때는 미루지 말고 바로 풀어봐야겠당!

*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 20 + 10;

int N;
int A[MAX][MAX];
int num[10] = { 0, };
bool isFive[MAX][MAX] = { false, };

int x, y;
int d[2];

int answer = 987987987;

void findFive() {
    memset(isFive, false, sizeof(isFive));

    // 경계선을 5번 선거구로 지정한다.
    for (int i = 0; i <= d[0]; i++) {
        isFive[x + i][y - i] = true;
        isFive[x + d[1] + i][y + d[1] - i] = true;
    }

    for (int j = 0; j <= d[1]; j++) {
        isFive[x + j][y + j] = true;
        isFive[x + d[0] + j][y - d[0] + j] = true;
    }

    // 경계선 안에 존재하는 구역을 5번 선거구로 지정한다.
    for (int i = 1; i <= N; i++) {
        int myFirst = -1, mySecond = -1;
        for (int j = 1; j <= N; j++) {
            if (isFive[i][j]) {
                if (myFirst == -1) myFirst = j;
                else mySecond = j;
            }
        }

        if (myFirst != -1 && mySecond != -1) {
            for (int j = myFirst + 1; j < mySecond; j++) isFive[i][j] = true;
        }
    }
}

int getDiff() {
    // 각 선거구의 범위에 포함되는 지역의 인원을 계산한다.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (isFive[i][j])
                num[5] += A[i][j];
            else if (i < x + d[0] && j <= y)
                num[1] += A[i][j];
            else if (i <= x + d[1] && y < j)
                num[2] += A[i][j];
            else if (x + d[0] <= i && j < y - d[0] + d[1])
                num[3] += A[i][j];
            else if (x + d[1] < i && y - d[0] + d[1] <= j)
                num[4] += A[i][j];
        }
    }

   // 인구가 가장 많은 선거구와 가장 적은 선거구를 찾고 그 차이를 계산한다.
    int myMax = -987987987, myMin = 987987987;
    for (int i = 1; i <= 5; i++) {
        myMax = max(myMax, num[i]);
        myMin = min(myMin, num[i]);
        num[i] = 0;
    }

    return myMax - myMin;
}

void getD(int idx) {
    if (idx >= 2) {
        findFive(); // 5번 선거구의 위치를 찾는다.
        int diff = getDiff();
        answer = min(answer, diff);
    }
    else {
        for (int i = 1; i <= N - 2; i++) {
            if (idx == 0 || (1 <= x && x < x + d[0] + i && x + d[0] + i <= N
                && 1 <= y - d[0] && y - d[0] < y && y < y + i && y + i <= N)) {
                d[idx] = i;
                getD(idx + 1);
            }
        }
    }
}

void solution() {
    // 1) 기준점을 정한다.
    for (int i = 1; i <= N - 2; i++) {
        for (int j = 2; j <= N - 1; j++) {
            x = i;
            y = j;

            // 2) 기준점에 따라 길이를 정한다.
            getD(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    solution();

    cout << answer;

    return 0;
}