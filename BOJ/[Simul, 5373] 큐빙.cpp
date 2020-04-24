// 소요시간: 2시간 23분
// 실행시간: 4ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초		128 MB		5537	1950	1338		35.500%

문제
루빅스 큐브는 삼차원 퍼즐이다. 보통 루빅스 큐브는 3×3×3개의 작은 정육면체로 이루어져 있다. 
퍼즐을 풀려면 각 면에 있는 아홉 개의 작은 정육면체의 색이 동일해야 한다.

큐브는 각 면을 양방향으로 90도 만큼 돌릴 수 있도록 만들어져 있다. 
회전이 마친 이후에는, 다른 면을 돌릴 수 있다. 이렇게 큐브의 서로 다른 면을 돌리다 보면, 색을 섞을 수 있다.

이 문제에서는 루빅스 큐브가 모두 풀린 상태에서 시작한다. 
윗 면은 흰색, 아랫 면은 노란색, 앞 면은 빨간색, 뒷 면은 오렌지색, 왼쪽 면은 초록색, 오른쪽 면은 파란색이다.

루빅스 큐브를 돌린 방법이 순서대로 주어진다. 이때, 모두 돌린 다음에 가장 윗 면의 색상을 구하는 프로그램을 작성하시오.

[그림1]

위의 그림은 루빅스 큐브를 푼 그림이다. 왼쪽 면은 시계방향으로 조금 돌려져 있는 상태이다.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개이다. 
각 테스트 케이스는 다음과 같이 구성되어져 있다.
- 첫째 줄에 큐브를 돌린 횟수 n이 주어진다. (1 ≤ n ≤ 1000)
- 둘째 줄에는 큐브를 돌린 방법이 주어진다. 각 방법은 공백으로 구분되어져 있으며, 첫 번째 문자는 돌린 면이다. 
  U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면이다. 
  두 번째 문자는 돌린 방향이다. +인 경우에는 시계 방향 (그 면을 바라봤을 때가 기준), -인 경우에는 반시계 방향이다.

출력
각 테스트 케이스에 대해서 큐브를 모두 돌린 후의 윗 면의 색상을 출력한다. 
첫 번째 줄에는 뒷 면과 접하는 칸의 색을 출력하고, 두 번째, 세 번째 줄은 순서대로 출력하면 된다. 
흰색은 w, 노란색은 y, 빨간색은 r, 오렌지색은 o, 초록색은 g, 파란색은 b.

예제 입력 1 
4
1
L-
2
F+ B+
4
U- D- L+ R+
10
L- U- L+ U- L- U- U- L+ U+ U+
예제 출력 1 
rww
rww
rww
bbb
www
ggg
gwg
owr
bwb
gwo
www
rww

*/

/*

최근에 푼 문제들 중에 가장 극한의 난이도였던 시뮬레이션 문제이다..

이게 시험에 나왔다니 ㅜㅜ.. 풀다가 중간에 긴장감때문에 더 안 풀리고, 현타까지 와서 못 풀었을 것 같은 문제..ㅋㅋ..
지금은 집에서 편하게 코딩하니까 그~~~나마 정말 그~~~나마 나았던 것 같은데...
만약 현장에서 직접 풀었으면 ㅠㅠ 생각만해도 끔찍하다..

그리고 사실 이 문제도 다른 분들이 올려 준 반례를 이용해서 잘못 구현한 점을 찾은 것이기 때문에..
내 스스로 풀었다고 말할 수도 없다..ㅎㅎ;;

풀면서 "아~ 찾아 보면 이보다 훨씬 좋은 최적화된 코드가 있을 것 같은데...."라고 생각했는데,
다 풀고나서 진짜 그걸 보니 .. 큐브가 너무 싫어져서 일단 나중에 보기로 했다 ㅋㅋㅋㅋㅋㅋ ㅜㅜ
근데 진짜 완전.. 코드도 깔끔하고 조건문이 많지 않아서 길이도 내꺼에 비해 완전 짧았던 코드였다 ㄷㄷ..
그런 사람들은 진짜 어떻게 그런 생각을 하는지.. 대단..
나도 언젠가 그런 사람이 됐으면 좋겠다 ㅎㅎㅎㅎㅎㅎㅎㅎ

뭐.... 여튼,... 나는 처음에 큐브를 전개도처럼 이용해서 풀려고 했는데,
공간 지각 능력이 조금 부족한건지... 뭔지... 머리로 잘 그려지지가 않고... 더 헷갈리는 것 같아서
전개도가 아닌 큐브 각각의 면을 따로 생각했다 ㅎㅎ.. (사실 이렇게 푸는 게 맞을 수도 있다 ㅎㅋㅋㅋ)

그리고, 돌려야 할 면과 방향에 따라 문제에서 주어진 그대로 큐브를 돌렸다!
즉, 설계 노트에 각 전개도를 그려서 윗면이 시계 또는 반시계 방향으로 돌아가면 이동될 다른 면들을 찾고,
그 면들을 방향에 맞게 그대로 이동시키는 방법을 사용했다!

어떤 곳은 위치가 반대로 들어가고, 어떤 곳은 그대로 들어가고 하는 것때문에 조금 시간이 많이 걸렸고,
하드코딩 방식을 사용하다 보니 인덱스 같은게 하나라도 틀리면 제대로 돌아가지 않았다 ㅠㅠ..

또, 내가 풀면서 아무리 봐도 맞는 것 같은데 예제 출력이 제대로 나오지 않았을 때의 문제는....
바로 큐브를 돌릴 때 상하좌우에 있는 면만 돌리고 자기 자신은 안 돌렸기 때문이었다ㅜㅜ..
(이 부분은 아무리 생각해도 모르겠어서, 다른 분이 올린 반례를 보고 깨달았다 ㅜㅜ)

처음에 주어진 큐브가 이미 맞춰져 있는 큐브라, 돌릴 때 자기 자신도 돌아간다는 점을 깜빡했던 것 같다 ㅜㅜ
코드 리뷰를 하면서 ㅜㅜ를 많이 쓴 적이 없는데..ㅋㅋㅋㅋ 대충 보기만 해도 ..이랑 ㅜㅜ가 너무 많다 ㅋㅋㅋㅋㅋ

다 풀었는데도 뭔가 제대로 푼 것 같지가 않고.. 찝찝한 마음이 들어서 더 그런 것 같다 ㅋㅋㅋ
다음에 이 문제를 다시 풀게 된다면.. 그때는 조금 코드를 최적화해서 다시 풀어봐야겠다.
(일단 오늘은 아니다... 오늘 다시 풀면 머리가 터질 것 같다 하하하하하)

*/

#include <iostream>
#include <string>

using namespace std;

int T;
int n;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int U[3][3], D[3][3], F[3][3], B[3][3], L[3][3], R[3][3];
char color[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };

void cw(int arr[3][3]) {
    int temp[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = arr[2 - j][i];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

void ccw(int arr[3][3]) {
    int temp[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = arr[j][2 - i];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

void rotate(char plane, char dir) {
    int tmp[3];
    int arr[3][3];
    if (plane == 'U') {
        for (int i = 0; i < 3; i++) tmp[i] = B[2][i];
        if (dir == '+') {
            cw(U);
            for (int i = 0; i < 3; i++) B[2][i] = L[2-i][2];
            for (int i = 0; i < 3; i++) L[i][2] = F[0][i];
            for (int i = 0; i < 3; i++) F[0][i] = R[2-i][0];
            for (int i = 0; i < 3; i++) R[i][0] = tmp[i];
        }
        else {
            ccw(U);
            for (int i = 0; i < 3; i++) B[2][i] = R[i][0];
            for (int i = 0; i < 3; i++) R[2-i][0] = F[0][i];
            for (int i = 0; i < 3; i++) F[0][i] = L[i][2];
            for (int i = 0; i < 3; i++) L[2-i][2] = tmp[i];
        }
    }
    else if (plane == 'D') {
        for (int i = 0; i < 3; i++) tmp[i] = F[2][i];
        if (dir == '+') {
            cw(D);
            for (int i = 0; i < 3; i++) F[2][i] = L[i][0];
            for (int i = 0; i < 3; i++) L[i][0] = B[0][2-i];
            for (int i = 0; i < 3; i++) B[0][i] = R[i][2];
            for (int i = 0; i < 3; i++) R[2-i][2] = tmp[i];
        }
        else {
            ccw(D);
            for (int i = 0; i < 3; i++) F[2][i] = R[2-i][2];
            for (int i = 0; i < 3; i++) R[i][2] = B[0][i];
            for (int i = 0; i < 3; i++) B[0][2-i] = L[i][0];
            for (int i = 0; i < 3; i++) L[i][0] = tmp[i];
        }
    }
    else if (plane == 'F') {
        for (int i = 0; i < 3; i++) tmp[i] = U[2][i];
        if (dir == '+') {
            cw(F);
            for (int i = 0; i < 3; i++) U[2][i] = L[2][i];
            for (int i = 0; i < 3; i++) L[2][i] = D[0][2-i];
            for (int i = 0; i < 3; i++) D[0][2-i] = R[2][i];
            for (int i = 0; i < 3; i++) R[2][i] = tmp[i];
        }
        else {
            ccw(F);
            for (int i = 0; i < 3; i++) U[2][i] = R[2][i];
            for (int i = 0; i < 3; i++) R[2][i] = D[0][2-i];
            for (int i = 0; i < 3; i++) D[0][2-i] = L[2][i];
            for (int i = 0; i < 3; i++) L[2][i] = tmp[i];
        }
    }
    else if (plane == 'B') {
        for (int i = 0; i < 3; i++) tmp[i] = D[2][2-i];
        if (dir == '+') {
            cw(B);
            for (int i = 0; i < 3; i++) D[2][2-i] = L[0][i];
            for (int i = 0; i < 3; i++) L[0][i] = U[0][i];
            for (int i = 0; i < 3; i++) U[0][i] = R[0][i];
            for (int i = 0; i < 3; i++) R[0][i] = tmp[i];
        }
        else {
            ccw(B);
            for (int i = 0; i < 3; i++) D[2][2-i] = R[0][i];
            for (int i = 0; i < 3; i++) R[0][i] = U[0][i];
            for (int i = 0; i < 3; i++) U[0][i] = L[0][i];
            for (int i = 0; i < 3; i++) L[0][i] = tmp[i];
        }
    }
    else if (plane == 'L') {
        for (int i = 0; i < 3; i++) tmp[i] = D[i][0];
        if (dir == '+') {
            cw(L);
            for (int i = 0; i < 3; i++) D[i][0] = F[i][0];
            for (int i = 0; i < 3; i++) F[i][0] = U[i][0];
            for (int i = 0; i < 3; i++) U[i][0] = B[i][0];
            for (int i = 0; i < 3; i++) B[i][0] = tmp[i];
        }
        else {
            ccw(L);
            for (int i = 0; i < 3; i++) D[i][0] = B[i][0];
            for (int i = 0; i < 3; i++) B[i][0] = U[i][0];
            for (int i = 0; i < 3; i++) U[i][0] = F[i][0];
            for (int i = 0; i < 3; i++) F[i][0] = tmp[i];
        }
    }
    else if (plane == 'R') {
        for (int i = 0; i < 3; i++) tmp[i] = D[i][2];
        if (dir == '+') {
            cw(R);
            for (int i = 0; i < 3; i++) D[i][2] = B[i][2];
            for (int i = 0; i < 3; i++) B[i][2] = U[i][2];
            for (int i = 0; i < 3; i++) U[i][2] = F[i][2];
            for (int i = 0; i < 3; i++) F[i][2] = tmp[i];
        }
        else {
            ccw(R);
            for (int i = 0; i < 3; i++) D[i][2] = F[i][2];
            for (int i = 0; i < 3; i++) F[i][2] = U[i][2];
            for (int i = 0; i < 3; i++) U[i][2] = B[i][2];
            for (int i = 0; i < 3; i++) B[i][2] = tmp[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                U[i][j] = 1;
                D[i][j] = 2;
                F[i][j] = 3;
                B[i][j] = 4;
                L[i][j] = 5;
                R[i][j] = 6;
            }
        }
        
        cin >> n;

        for (int f = 0; f < n; f++) {
            string info;
            cin >> info;

            rotate(info[0], info[1]);     
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << color[U[i][j] - 1];
            }
            cout << "\n";
        }
    }

    return 0;
}