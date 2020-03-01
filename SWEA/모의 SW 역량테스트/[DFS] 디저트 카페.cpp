// 총 소요시간 : 59분

/*

시간 : 50개 테스트케이스를 합쳐서 C의 경우 3초 / C++의 경우 3초 / Java의 경우 3초 / Python의 경우 15초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


친구들과 디저트 카페 투어를 할 계획이다.
[Fig. 1]과 같이 한 변의 길이가 N인 정사각형 모양을 가진 지역에 디저트 카페가 모여 있다.

[Fig. 1]

원 안의 숫자는 해당 디저트 카페에서 팔고 있는 디저트의 종류를 의미하고
카페들 사이에는 대각선 방향으로 움직일 수 있는 길들이 있다.
디저트 카페 투어는 어느 한 카페에서 출발하여
[Fig. 2]와 같이 대각선 방향으로 움직이고 사각형 모양을 그리며 출발한 카페로 돌아와야 한다.

[Fig. 2]

디저트 카페 투어를 하는 도중 해당 지역을 벗어나면 안 된다.
또한, 친구들은 같은 종류의 디저트를 다시 먹는 것을 싫어한다.
즉, [Fig. 3]과 같이 카페 투어 중에 같은 숫자의 디저트를 팔고 있는 카페가 있으면 안 된다.

[Fig. 3]

[Fig. 4]와 같이 하나의 카페에서 디저트를 먹는 것도 안 된다.

[Fig. 4]

[Fig. 5]와 같이 왔던 길을 다시 돌아가는 것도 안 된다.
 
[Fig. 5]
 
친구들과 디저트를 되도록 많이 먹으려고 한다.
디저트 가게가 모여있는 지역의 한 변의 길이 N과 디저트 카페의 디저트 종류가 입력으로 주어질 때,
임의의 한 카페에서 출발하여 대각선 방향으로 움직이고
서로 다른 디저트를 먹으면서 사각형 모양을 그리며 다시 출발점으로 돌아오는 경우,
디저트를 가장 많이 먹을 수 있는 경로를 찾고, 그 때의 디저트 수를 정답으로 출력하는 프로그램을 작성하라.
만약, 디저트를 먹을 수 없는 경우 -1을 출력한다.


[예시]

한 변의 길이 N이 4인 지역에 디저트 카페가 [Fig. 6]과 같이 있다고 생각하자.
 
[Fig. 6]

디저트 카페 투어가 가능한 경우는 [Fig. 7]과 같이 5가지로 나눌 수 있다.
(출발한 곳과 도는 방향은 다를 수 있지만, 디저트 카페 투어의 경로가 그리는 사각형 모양은 5가지 중 하나이다.)

[Fig. 7]

이 중에 디저트를 가장 많이 먹을 수 있는 경우는 ⑤인 경우로 디저트의 종류는 6개이다.
따라서, 정답은 6이 된다.


[제약사항]

1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는 데 C/C++/Java 모두 3초
2. 디저트 카페가 모여있는 지역의 한 변의 길이 N은 4 이상 20 이하의 정수이다. (4 ≤ N ≤ 20)
3. 디저트 종류를 나타나는 수는 1 이상 100 이하의 정수이다.


[입력]

입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 디저트 카페가 모여있는 지역의 한 변의 길이 N이 주어진다.
그 다음 N 줄에는 N * N 크기의 디저트 카페에서 팔고 있는 디저트 종류에 대한 정보가 주어진다.


[출력]

테스트 케이스 개수만큼 T개의 줄에 각각의 테스트 케이스에 대한 답을 출력한다.
각 줄은 "#t"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (t는 1부터 시작하는 테스트 케이스의 번호이다)
출력해야 할 정답은 가능한 경우 중 디저트를 가장 많이 먹을 때의 디저트 수 이다.
만약, 디저트를 먹을 수 없는 경우 정답은 -1이다.


입력
10             // 총 테스트 케이스 개수 T = 10   
4               // 첫 번째 테스트 케이스, N = 4, 본문 예제
9 8 9 8
4 6 9 4
8 7 7 8
4 5 3 5
5               // 두 번째 테스트 케이스, N = 5
8 2 9 6 6
1 9 3 3 4
8 2 3 3 6
4 3 4 4 9
7 4 6 3 5
…              // 나머지는 sample_input.txt 참조

출력
#1 6
#2 -1
#3 4
#4 4
#5 8
#6 6
#7 14
#8 12
#9 18
#10 30

*/

/*

DFS를 통해 시작지점으로 다시 되돌아 온 경우를 찾아 가능한 디저트 종류의 최댓값을 구하는 문제.
처음에는 갈 수 있는 방향이 대각선 방향이긴 하지만, 최대 4방향이기 때문에 BFS로 시도하고자 했다.

하지만, "항상 사각형 모양을 그리며 출발한 카페로 돌아와야 한다"라는 조건이 있었기에
BFS로 모든 경우를 탐색하는 방법은 비효율적이라고 생각했다.

그래서 시작지점을 기준으로 시계방향으로 도는 사각형을 만든 후 다시 시작지점으로 돌아올 수 있도록
dy dx를 {오른쪽 아래, 왼쪽 아래, 왼쪽 위, 오른쪽 위}로 설정해두고,
1) 방향을 유지하며 가는 것과 2) 방향을 꺾는 것 두 가지로 나눠보았다.

시작지점은 항상 오른쪽 아래(0)로만 갈 수 있기에 꺾을 수 없도록 조건문을 걸었고,
마지막에 시작지점으로 돌아올 때에도 항상 오른쪽 위로(3)만 가능하기에 꺾을 수 없도록 조건문을 걸었다.

그 외 나머지 지점에서는 디저트의 종류가 겹치지 않는 한(방문된 번호를 true로 만드는 visited 배열을 사용했다)
방향을 유지하며 제일 깊게 가고, 깊게 가는게 다 끝나면 방향을 꺾기도 하며 반복문을 구성하였다.

그리고 반복문 안에서 다음 지점이 시작지점이 된다면, 반복문을 빠져나오는 형식으로 로직을 설계했다.

사실 이런류의 DFS는 풀어본 경험이 몇 번 되지 않아 설계를 하면서도 이게 맞는건가? 싶었다..ㅋㅋ
그래서 Pass를 받은 이후에 내가 푼 방법이 맞는 건지 인터넷에 검색을 해보았다.
(코딩에 정답은 없지만 최대한 효율적인 방법으로 짜고 싶었다 ㅎㅎ;;)

근데 내가 짠 설계가 일반적인 풀이랑 거의 유사해서 ... 오늘도 또 행복을 느꼈다 ㅋㅋㅎㅎ
요즘은 코딩하면서 행복한 일이 많은 것 같다!!! 앞으로도 화이팅!

*/

#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 20 + 10;
const int MAX = 100 + 10;

int N;
int map[MAXN][MAXN];

int destY, destX;

int dy[4] = {1, 1, -1, -1};
int dx[4] = {1, -1, -1, 1};

int visited[MAX];
int myMax;

void initialize() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    myMax = -987987987;
}

void DFS(int y, int x, int idx, int cnt) {
    if(idx == 3 && y == destY && x == destX) {
        if(myMax < cnt) myMax = cnt;
        return;
    }
    
    visited[map[y][x]] = true;
    
    for(int i=0; i<=1; i++) {
        int nextY = y + dy[idx + i];
        int nextX = x + dx[idx + i];
        
        if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > N-1) continue;
        
        if(i == 0) {
            if(!visited[map[nextY][nextX]]) DFS(nextY, nextX, idx, cnt+1);
        }
        else {
            if(cnt != 0 && idx != 3 && !visited[map[nextY][nextX]]) DFS(nextY, nextX, idx+1, cnt+1);
        }
        
        if(nextY == destY && nextX == destX) {
            DFS(nextY, nextX, idx+i, cnt+1);
            break;
        }
    }
    
    visited[map[y][x]] = false;
}

void solution() {
    for(int i=0; i<N-2; i++) {
        for(int j=1; j<N-1; j++) {
            destY = i, destX = j;
            DFS(i, j, 0, 0);
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        initialize();
        solution();
        
        if(myMax == -987987987) printf("#%d -1\n", test_case);
        else printf("#%d %d\n", test_case, myMax);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}