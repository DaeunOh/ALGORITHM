/*

시간 : 50개 테스트케이스를 합쳐서 C의 경우 3초 / C++의 경우 3초 / Java의 경우 3초 / Python의 경우 15초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


등산로를 조성하려고 한다.

등산로를 만들기 위한 부지는 N * N 크기를 가지고 있으며, 이곳에 최대한 긴 등산로를 만들 계획이다.

등산로 부지는 아래 [Fig. 1]과 같이 숫자가 표시된 지도로 주어지며, 각 숫자는 지형의 높이를 나타낸다.
 
[Fig. 1]
 

등산로를 만드는 규칙은 다음과 같다.

   ① 등산로는 가장 높은 봉우리에서 시작해야 한다.

   ② 등산로는 산으로 올라갈 수 있도록 반드시 높은 지형에서 낮은 지형으로 가로 또는 세로 방향으로 연결이 되어야 한다.
       즉, 높이가 같은 곳 혹은 낮은 지형이나, 대각선 방향의 연결은 불가능하다.

   ③ 긴 등산로를 만들기 위해 딱 한 곳을 정해서 최대 K 깊이만큼 지형을 깎는 공사를 할 수 있다.

N * N 크기의 지도가 주어지고, 최대 공사 가능 깊이 K가 주어진다.

이때 만들 수 있는 가장 긴 등산로를 찾아 그 길이를 출력하는 프로그램을 작성하라.


[예시]

위 [Fig. 1]과 같이 N = 5인 지도가 주어진 경우를 살펴보자.

가장 높은 봉우리는 높이가 9로 표시된 세 군데이다.

이 세 곳에서 출발하는 가장 긴 등산로 중 하나는 아래 [Fig. 2]와 같고, 이 때 길이는 5가 된다.
 
[Fig. 2]
 

만약 최대 공사 가능 깊이 K = 1로 주어질 경우,

아래 [Fig. 3]과 같이 빨간색 부분의 높이를 9에서 8로 깎으면 길이가 6인 등산로를 만들 수 있다.
 
[Fig. 3]


이 예에서 만들 수 있는 가장 긴 등산로는 위와 같으며, 출력할 정답은 6이 된다.


[제약 사항]

1. 시간 제한 : 최대 50개 테스트 케이스를 모두 통과하는 데 C/C++/Java 모두 3초

2. 지도의 한 변의 길이 N은 3 이상 8 이하의 정수이다. (3 ≤ N ≤ 8)

3. 최대 공사 가능 깊이 K는 1 이상 5 이하의 정수이다. (1 ≤ K ≤ 5)

4. 지도에 나타나는 지형의 높이는 1 이상 20 이하의 정수이다.

5. 지도에서 가장 높은 봉우리는 최대 5개이다.

6. 지형은 정수 단위로만 깎을 수 있다.

7. 필요한 경우 지형을 깎아 높이를 1보다 작게 만드는 것도 가능하다.

[입력]

입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 지도의 한 변의 길이 N, 최대 공사 가능 깊이 K가 차례로 주어진다.

그 다음 N개의 줄에는 N * N 크기의 지도 정보가 주어진다.

[출력]

테스트 케이스 개수만큼 T개의 줄에 각각의 테스트 케이스에 대한 답을 출력한다.

각 줄은 "#t"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (t는 1부터 시작하는 테스트 케이스의 번호이다)

출력해야 할 정답은 만들 수 있는 가장 긴 등산로의 길이이다.


입력
10            // 총 테스트 케이스 개수 T = 10
5 1           // 첫 번째 테스트 케이스, N = 5, K = 1, 본문 예제
9 3 2 3 2   // 지도 정보
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
3 2           // 두 번째 테스트 케이스, N = 3, K = 2
1 2 1        // 지도 정보
2 1 2
1 2 1
…             // 나머지는 등산로 조성.txt 참조


출력
#1 6
#2 3
#3 7
#4 4
#5 2
#6 12
#7 6
#8 7
#9 10
#10 19

*/

/*

처음에는 BFS로 구현을 시도했는데, BFS로 구현하니 중복 방문하는 경우가 있어도
길이가 달라지는 부분이 있어서 구현하기가 어려웠다.

이후 DFS로 바꿔 구현을 시도했는데, 50개의 테스트 케이스 중 48개만 정답처리가 되었다.
어느 부분이 틀렸나 싶어 문제를 다시 읽어보니 "최대 K 깊이만큼 지형을 깎는 공사를 할 수 있다."를 간과하고 있었다.
나는 항상 깎을 수 있는 지형이 있다면 K만큼 깎았는데,
K만큼 깎아버리면 길이가 더 길어질 수 있음에도 길게 못 만드는 경우가 있을 수 있다.

최대 K 깊이만큼 깎을 수 있는 것이므로, 최대 K이지만 최소로 깎는 것이 길이 증가에 도움이 된다.
이 부분을 바꿔 주었더니 모든 테스트 케이스를 통과할 수 있었다.

*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 8 + 10;

int N, K;
int map[MAX][MAX] = {0, };
bool visited[MAX][MAX];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int maxLen;

void DFS(int y, int x, bool k, int len) {
    if(maxLen < len) maxLen = len;
    
    for(int i=0; i<4; i++) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        
        if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > N-1) continue;
        
        if(!visited[nextY][nextX] && map[y][x] > map[nextY][nextX]) {
            visited[nextY][nextX] = 1;
            DFS(nextY, nextX, k, len+1);
            visited[nextY][nextX] = 0;
        }
        else if(!visited[nextY][nextX] && k && map[y][x] > map[nextY][nextX] - K) {
            visited[nextY][nextX] = 1;
            
            for(int j=1; j<=K; j++) {
                if(map[y][x] > map[nextY][nextX] - j) {
                    map[nextY][nextX] -= j;
                    DFS(nextY, nextX, 0, len+1);
                    map[nextY][nextX] += j;
                    visited[nextY][nextX] = 0;
                    
                    break;
                }
            }
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
        maxLen = -987987987;
        scanf("%d %d", &N, &K);
        
        int maxH = -987987987;
        for(int i=0; i<N; i++) {
        	for(int j=0; j<N; j++) {
                scanf("%d", &map[i][j]);
                
                if(maxH < map[i][j]) maxH = map[i][j];
            }
        }
        
        int myMax = -987987987;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(map[i][j] == maxH) {
                    memset(visited, false, sizeof(visited));
                    visited[i][j] = 1;
                    DFS(i, j, 1, 1);
                    visited[i][j] = 0;
                }
            }
        }
        
        printf("#%d %d\n", test_case, maxLen);
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}