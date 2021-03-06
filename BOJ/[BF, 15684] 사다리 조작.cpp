// 소요시간: 1시간 50분
// 실행시간: 492ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초		512 MB		25617	6702	2931		20.632%

문제
사다리 게임은 N개의 세로선과 M개의 가로선으로 이루어져 있다. 
인접한 세로선 사이에는 가로선을 놓을 수 있는데, 각각의 세로선마다 가로선을 놓을 수 있는 위치의 개수는 H이고, 
모든 세로선이 같은 위치를 갖는다. 아래 그림은 N = 5, H = 6 인 경우의 그림이고, 가로선은 없다.

[그림1-1]

초록선은 세로선을 나타내고, 초록선과 점선이 교차하는 점은 가로선을 놓을 수 있는 점이다. 
가로선은 인접한 두 세로선을 연결해야 한다. 단, 두 가로선이 연속하거나 서로 접하면 안 된다. 
또, 가로선은 점선 위에 있어야 한다.

[그림1-2]

위의 그림에는 가로선이 총 5개 있다. 
가로선은 위의 그림과 같이 인접한 두 세로선을 연결해야 하고, 가로선을 놓을 수 있는 위치를 연결해야 한다.

사다리 게임은 각각의 세로선마다 게임을 진행하고, 세로선의 가장 위에서부터 아래 방향으로 내려가야 한다. 
이때, 가로선을 만나면 가로선을 이용해 옆 세로선으로 이동한 다음, 이동한 세로선에서 아래 방향으로 이동해야 한다.

위의 그림에서 1번은 3번으로, 2번은 2번으로, 3번은 5번으로, 4번은 1번으로, 5번은 4번으로 도착하게 된다. 
아래 두 그림은 1번과 2번이 어떻게 이동했는지 나타내는 그림이다.
	
[그림2-1, 1번 세로선]	[그림2-2, 2번 세로선]

사다리에 가로선을 추가해서, 사다리 게임의 결과를 조작하려고 한다. 이때, i번 세로선의 결과가 i번이 나와야 한다. 
그렇게 하기 위해서 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 세로선의 개수 N, 가로선의 개수 M, 세로선마다 가로선을 놓을 수 있는 위치의 개수 H가 주어진다. 
(2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H)
둘째 줄부터 M개의 줄에는 가로선의 정보가 한 줄에 하나씩 주어진다.
가로선의 정보는 두 정수 a과 b로 나타낸다. (1 ≤ a ≤ H, 1 ≤ b ≤ N-1) 
b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미이다.
가장 위에 있는 점선의 번호는 1번이고, 아래로 내려갈 때마다 1이 증가한다. 
세로선은 가장 왼쪽에 있는 것의 번호가 1번이고, 오른쪽으로 갈 때마다 1이 증가한다.
입력으로 주어지는 가로선이 서로 연속하는 경우는 없다.

출력
i번 세로선의 결과가 i번이 나오도록 사다리 게임을 조작하려면, 추가해야 하는 가로선 개수의 최솟값을 출력한다. 
만약, 정답이 3보다 큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다.

예제 입력 1 
2 0 3
예제 출력 1 
0

예제 입력 2 
2 1 3
1 1
예제 출력 2 
1

예제 입력 3 
5 5 6
1 1
3 2
2 3
5 1
5 4
예제 출력 3 
3

예제 입력 4 
6 5 6
1 1
3 2
1 3
2 5
5 5
예제 출력 4 
3

예제 입력 5 
5 8 6
1 1
2 2
3 3
4 4
3 1
4 2
5 3
6 4
예제 출력 5 
-1

예제 입력 6 
5 12 6
1 1
1 3
2 2
2 4
3 1
3 3
4 2
4 4
5 1
5 3
6 2
6 4
예제 출력 6 
-1

예제 입력 7 
5 6 6
1 1
3 1
5 2
4 3
2 3
1 4
예제 출력 7 
2

힌트 [그림3]
예제 3	예제 3 정답	
예제 7	예제 7 정답

*/

/*

완전탐색을 이용해서 i번 세로선의 결과가 i번이 나오도록 사다리를 조작하는 문제.
추가해야 하는 가로선의 개수는 최소 0개부터 최대 3개이며, 3개를 넘어가거나 사다리 조작이 불가능한 경우에는 -1을 출력해야 한다.

따라서 나는 놓을 수 있는 가로선을 0개부터 3개까지 늘려가면서
모든 세로선의 결과가 자기 자신의 번호가 나올 때 그 즉시 사다리를 놓는 것을 중단하도록 구현했다.

처음에는 사다리의 상태를 표시하기 위해 하나의 배열만 사용했는데,
그러다 보니 해당 위치에서 왼쪽으로 가는 사다리인지 오른쪽으로 가는 사다리인지 구별할 수가 없게 되어서
왼쪽으로 가는 사다리, 오른쪽으로 가는 사다리를 따로 만들어줬다.
(또는 하나의 사다리를 사용해서 해당 위치에서 몇 번째 사다리로 가는지 사다리의 번호를 써줘도 된다.)

가로선을 놓을 위치를 구하기 위해서는 1차원의 수를 2차원의 수로 바꿔주는 방법을 사용했다.
예를 들어 i가 2일 때 이를 2차원의 수로 바꿔주면 (a=(i/N)+1, b=(i%N))이 된다.
그리고 b가 0인 경우에는 오른쪽에 가로선을 놓을 수 없으므로 그 경우는 고려하지 않았다.

이렇게 구한 (a, b)를 가지고 가로선을 놓을 수 있을지 말지도 결정해야 하는데,
이를 확인하기 위해서는 (a, b)의 왼쪽, 오른쪽에 가로선이 있는지, (a, b+1)의 오른쪽에 가로선이 있는지를 확인해야 한다.
(만약 이를 확인하지 않으면 연속되는 가로선이 생기게 된다. 경험담;;)

또한, 가로선을 놓을 때 조합을 이용했는데,
중복된 조합은 필요 없고, 가로선은 서로 연속하는 경우가 없도록 해야하기 때문에
다음 가로선을 놓을 수 있는 위치는 (가로선을 놓은 지점 + 2)부터 가능하다.
(만약 이렇게 구현하지 않는다면 시간초과가 난다. 경험담;;)

이렇게 모든 경우를 탐색하면서 사다리 타기를 해봤는데도 답이 나오지 않으면 -1을 출력하고,
중간에 답이 나오면 추가한 사다리의 개수를 출력하면 된다!!

코드를 설명하는 데에도 살짝씩 언급했지만, 내가 이 문제를 풀면서 오래 걸렸던 점은
1) (a, b)의 왼쪽, 오른쪽은 확인했지만 (a, b+1)의 오른쪽은 확인하지 않았다는 점
2) 중복된 조합을 고려하지 않은 점
때문이었다...

조합 문제를 오랜만에 풀어서 그런지는 모르겠지만 해결 방법이라던지 틀린 점을 생각해 내기가 매우 힘들었다 ㅎㅎㅎ;;;
요즘에 자소서 쓰느라 문제를 많이 못 풀었는데.... 적어도 하루에 한개씩은 꼭 풀도록 하장 ㅠㅠ!!!

*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXH = 30 + 10;
const int MAXN = 10 + 10;

int N, M, H;
bool L[MAXH][MAXN] = { false, };
bool R[MAXH][MAXN] = { false, };

bool isFinished = false;

bool playGame() {
    for (int i = 1; i <= N; i++) { // 1번부터 N번까지 사다리 시작
        int a = 1, b = i, dst = i;
        while (a <= H) {
            if (L[a][b]) { // 왼쪽으로 가는 길이 있다면 도착지점을 한 칸 왼쪽으로
                dst--;
                b--;
            }
            else if (R[a][b]) { // 오른쪽으로 가는 길이 있다면 도착지점을 한 칸 오른쪽으로
                dst++;
                b++;
            }

            a++; // 사다리 내려가기
        }

        if (dst != i) return false; // i번 사다리가 i번에 도착하지 않는 경우
    }

    return true;
}

void getComb(int x, int k, int next) {
    if (isFinished) return;

    if (x >= k) {
        if (playGame()) {
            isFinished = true;
            cout << k;
        }
    }
    else {
        for (int i = next; i <= N * H; i++) { // 1부터가 아닌 그 다음 칸부터 봐야함에 유의한다.
            if (i % N == 0) continue;
            
            // 1차원 수를 2차원으로 변환하고, 해당 자리에 사다리를 놓을 수 있는지 확인한다.
            int a = (i / N) + 1;
            int b = i % N;
            if (L[a][b] || R[a][b]) continue;
            if (R[a][b + 1]) continue;

            // 사다리를 놓은 후 다시 원래대로 돌려 놓는다.
            R[a][b] = true;
            L[a][b + 1] = true;
            getComb(x + 1, k, i + 2);
            R[a][b] = false;
            L[a][b + 1] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        R[a][b] = true; // (a, b)에서 오른쪽으로 가는 사다리가 있다.
        L[a][b + 1] = true; // (a, b+1)에서 왼쪽으로 가는 사다리가 있다.
    }

    for (int i = 0; i <= 3; i++) {
        getComb(0, i, 1);
        if (isFinished) return 0;
    }

    cout << "-1";

    return 0;
}