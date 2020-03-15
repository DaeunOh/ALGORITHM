// 소요시간: 1시간 18분
// 실행시간: 0ms

/*

문제
소수를 유난히도 좋아하는 창영이는 게임 아이디 비밀번호를 4자리 ‘소수’로 정해놓았다. 
어느 날 창영이는 친한 친구와 대화를 나누었는데:

“이제 슬슬 비번 바꿀 때도 됐잖아”
“응 지금은 1033으로 해놨는데... 다음 소수를 무엇으로 할지 고민중이야"
“그럼 8179로 해”
“흠... 생각 좀 해볼게. 이 게임은 좀 이상해서 비밀번호를 한 번에 한 자리 밖에 못 바꾼단 말이야. 
예를 들어 내가 첫 자리만 바꾸면 8033이 되니까 소수가 아니잖아. 
여러 단계를 거쳐야 만들 수 있을 것 같은데... 예를 들면... 1033 1733 3733 3739 3779 8779 8179처럼 말이야.”
“흠...역시 소수에 미쳤군. 그럼 아예 프로그램을 짜지 그래. 
네 자리 소수 두 개를 입력받아서 바꾸는데 몇 단계나 필요한지 계산하게 말야.”
“귀찮아”

그렇다. 그래서 여러분이 이 문제를 풀게 되었다. 
입력은 항상 네 자리 소수만(1000 이상) 주어진다고 가정하자. 
주어진 두 소수 A에서 B로 바꾸는 과정에서도 항상 네 자리 소수임을 유지해야 하고, 
‘네 자리 수’라 하였기 때문에 0039 와 같은 1000 미만의 비밀번호는 허용되지 않는다.


입력
첫 줄에 test case의 수 T가 주어진다. 다음 T줄에 걸쳐 각 줄에 1쌍씩 네 자리 소수가 주어진다.

출력
각 test case에 대해 두 소수 사이의 변환에 필요한 최소 회수를 출력한다. 불가능한 경우 Impossible을 출력한다.

예제 입력 1 
3
1033 8179
1373 8017
1033 1033
예제 출력 1 
6
7
0

*/

/*

에라토스테네스의 체를 이용하여 소수를 먼저 구하고,
A를 queue의 첫 시작으로 하여 네자리수의 각 자리를 0~9까지 바꿔가면서 방문하지 않았으면서 소수이면 큐에 넣는다.

이후 단계를 업데이트 시켜 나가다가 front가 B가 되는 경우가 있으면 true를 return하고,
큐가 비워질 때까지 B가 되는 경우가 없으면 false를 return하여
단계수를 출력할지 Impossible을 출력할지 결정한다.

어떻게 구현해야 할지는 금방 떠올릴 수 있었으나,
1) 에라토스테네스의 체에서 배수를 체크할 때 반복문의 시작(i+i)과 증가정도(j+=i)를 한 번에 떠올리기가 힘들었다.
2) abcd라는 네자리 수의 각 자리수를 바꿔줄 때, 정수를 빼고 더하지 않고 한 번에 바꿔주기 위해
    string 또는 char배열을 사용하려고 했으나, 사용법이 익숙하지 않아 시간이 오래 걸렸다.
    (결국은 정수를 빼고 더해서 계산함.. 근데 이것도 헷갈렸다 ㅠㅠㅠ...)

    ++ string을 이용하는 방법
    string str = to_string(num);
    str[i] = j + '0'; // 정수를 문자로 변환해주기 위해 '0'을 더해준다.
    return stoi(str); // 반환할 때는 다시 정수로 변환해준다.

    ++ abcd(네자리 수)에서 각 자리 찾기
    a = num % 10000 / 1000; // a 앞을 다 지워주고(%10000), a 뒤도 다 지워준다(/1000)
    b = num % 1000 / 100;
    c = num % 100 / 10;
    d = num % 10;

*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 10000 + 10;

int T;
int A, B;
bool isNotPrime[MAX];

int visited[MAX];
int myMax;

int getNum(int i, int j, int num) {
    if (i == 0) {
        int temp = num % 10000 / 1000;
        num -= temp * 1000;
        num += j * 1000;
    }
    else if (i == 1) {
        int temp = num % 1000 / 100;
        num -= temp * 100;
        num += j * 100;
    }
    else if (i == 2) {
        int temp = num % 100 / 10;
        num -= temp * 10;
        num += j * 10;
    }
    else {
        int temp = num % 10;
        num -= temp;
        num += j;
    }

    return num;
}

bool changeAtoB() {
    queue <int> q;
    visited[A] = 1;
    q.push(A);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (myMax < visited[front]) myMax = visited[front];
        if (front == B) return true;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <= 9; j++) {
                if (i == 0 && j == 0) continue;

                int num = getNum(i, j, front);

                if (!visited[num] && !isNotPrime[num]) {
                    visited[num] = visited[front] + 1;
                    q.push(num);
                }
            }
        }
    }

    return false;
}

int main()
{
    // 10000 미만의 소수를 구한다.
    // isNotPrime[i] == false : i는 소수.
    for (int i = 2; i < 10000; i++) {
        if (!isNotPrime[i]) {
            int start = 2;
            for (int j = i + i; j < 10000; j += i) {
                isNotPrime[j] = true;
            }
        }
    }

    scanf("%d", &T);

    vector<int> res;
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &A, &B);

        myMax = 0;
        memset(visited, 0, sizeof(visited));

        if (changeAtoB()) res.push_back(myMax - 1);
        else res.push_back(-1);
    }

    for (int i = 0; i < res.size(); i++) {
        if (res[i] != -1) printf("%d\n", res[i]);
        else printf("Impossible\n");
    }

    return 0;
}