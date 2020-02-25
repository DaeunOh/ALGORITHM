/*

시간 : 50개 테스트케이스를 합쳐서 C의 경우 3초 / C++의 경우 3초 / Java의 경우 3초 / Python의 경우 15초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


교도소로 이송 중이던 흉악범이 탈출하는 사건이 발생하여 수색에 나섰다.

탈주범은 탈출한 지 한 시간 뒤, 맨홀 뚜껑을 통해 지하터널의 어느 한 지점으로 들어갔으며,

지하 터널 어딘가에서 은신 중인 것으로 추정된다.

터널끼리 연결이 되어 있는 경우 이동이 가능하므로 탈주범이 있을 수 있는 위치의 개수를 계산하여야 한다.

탈주범은 시간당 1의 거리를 움직일 수 있다.

지하 터널은 총 7 종류의 터널 구조물로 구성되어 있으며 각 구조물 별 설명은 [표 1]과 같다.

[표 1]


[그림 1-1] 은 지하 터널 지도의 한 예를 나타낸다.

이 경우 지도의 세로 크기는 5, 가로 크기는 6 이다.

맨홀 뚜껑의 위치가 ( 2, 1 ) 으로 주어질 경우, 이는 세로 위치 2, 가로 위치 1을 의미하며 
[그림 1-2] 에서 붉은 색으로 표기된 구역이다.

탈주범이 탈출 한 시간 뒤 도달할 수 있는 지점은 한 곳이다.

탈주범이 2시간 후 도달할 수 있는 지점은, [그림 1-3] 과 같이 맨홀 뚜껑이 위치한 붉은 색으로 표시된 지하도 와 
파란색으로 표기된 지하도까지 총 3개의 장소에 있을 수 있다.

3시간 후에는 [그림 1-4] 과 같이 총 5개의 지점에 있을 수 있다.
       
                     
[그림 1-1]                                                      [그림 1-2]
       
                    
[그림 1-3]                                                      [그림 1-4]


[그림 2-1] 에서 맨홀뚜껑이 위치한 지점이 ( 2, 2 ) 이고 경과한 시간이 6 으로 주어질 경우,

[그림 2-2] 에서 맨홀뚜껑이 위치한 지점은 붉은 색, 탈주범이 있을 수 있는 장소가 푸른색으로 표기되어 있다.

탈주범이 있을 수 있는 장소는, 맨홀뚜껑이 위치한 지점을 포함하여 총 15 개 이다.
       
                    
[그림 2-1]                                                      [그림 2-2]


지하 터널 지도와 맨홀 뚜껑의 위치, 
경과된 시간이 주어질 때 탈주범이 위치할 수 있는 장소의 개수를 계산하는 프로그램을 작성하라.


[제약 사항]

1. 시간 제한 : 최대 50개 테이트 케이스를 모두 통과하는데, C/C++/Java 모두 1초

2. 지하 터널 지도의 세로 크기 N, 가로 크기 M은 각각 5 이상 50 이하이다. (5 ≤ N, M ≤ 50)

3. 맨홀 뚜껑의 세로 위치 R 은 0 이상 N-1이하이고 가로 위치 C 는 0 이상 M-1이하이다. (0 ≤ R ≤ N-1, 0 ≤ C ≤ M-1)

4. 탈출 후 소요된 시간 L은 1 이상 20 이하이다. (1 ≤ L ≤ 20)

5. 지하 터널 지도에는 반드시 1개 이상의 터널이 있음이 보장된다.

6. 맨홀 뚜껑은 항상 터널이 있는 위치에 존재한다.

[입력]

첫 줄에 총 테스트 케이스의 개수 T가 주어진다.

두 번째 줄부터 T개의 테스트 케이스가 차례대로 주어진다.

각 테스트 케이스의 첫 줄에는 지하 터널 지도의 세로 크기 N, 가로 크기 M, 맨홀 뚜껑이 위치한장소의 세로 위치 R, 가로 위치 C, 그리고 탈출 후 소요된 시간 L 이 주어진다.

그 다음 N 줄에는 지하 터널 지도 정보가 주어지는데, 각 줄마다 M 개의 숫자가 주어진다.

숫자 1 ~ 7은 해당 위치의 터널 구조물 타입을 의미하며 숫자 0 은 터널이 없는 장소를 의미한다.

[출력]

테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.

각 줄은 “#x”로 시작하고 공백을 하나 둔 다음 정답을 기록한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)

출력해야 할 정답은 탈주범이 위치할 수 있는 장소의 개수이다.


입력
5               	// 총 테스트 케이스 개수 T = 5
5 6 2 1 3      	// [그림1-1]과 동일
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0
5 6 2 2 6      	// [그림2-1]과 동일
3 0 0 0 0 3
2 0 0 0 0 6
1 3 1 1 3 1
2 0 2 0 0 2
0 0 4 3 1 1
...            		// 나머지는 탈주범 검거.txt 참조

출력
#1 5
#2 15
#3 29
#4 67
#5 71

*/

/*

코딩을 할 때 직접 주어진 수치를 대입하는 방식은 지양하는 편이었는데,
이 문제는 직접 수치를 대입하지 않고는 떠오르는 방법이 없어 수치를 직접 대입하는 부분이 많게 되었다.

그래도, 각 파이프 번호 별로 dy, dx를 미리 저장해둔 덕에 이후에 next를 구하는 과정에서 코드가 많이 줄었으며,
파이프 번호가 많지 않아 갈 수 있는 길인지 확인하는 부분도 나름(?) 깔끔하게 구현 되었다.

전체적인 해결 방법은 BFS이며,
파이프의 모양이 달라 이어진 길인지 또한 확인해야 한다는 점이 다른 BFS 문제와의 차별점이었다.


하지만 오늘도.. 문제를 풀며 작은 실수들이 몇 개 있었다.

1) visited 배열을 다시 한 번 훑는 부분을 또 추가하고 싶지 않아서, if(visited[front.first][front.second] == L) break;
   라는 조건문을 통해 주어진 시간이 다 지나면 while문을 즉시 빠져나오도록 만들었다.
   전역변수인 queue가 다 비워지지 않았을 수도 있으므로 다음 차례에 queue를 비워주는 작업은 추가했지만,
   초기 cnt를 0으로 만들고, cnt를 +해주는 위치를 pop한 다음으로 설정해 주었더니
   카운트가 덜 되는 문제점이 있었다.

   따라서 초기 cnt를 1로 만들고, 이후 next가 확정되는 순간 cnt를 증가시켜 줬더니 카운트 문제는  해결되었다.

2) 평범한 맵이 아닌, 파이프로만 지나다닐 수 있는 길이기 때문에 파이프가 이어져 있는지도 확인해야 한다.
   이를 확인하지 못하고 방문하지 않은 경우만 조건문에 넣었더니 cnt가 더 카운트 되는 경우도 있었다..
   그래서 이어져 있는지 확인하는 부분을 isPossible이라는 함수로 구현했다.

*/

#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 50 + 10;

int N, M, R, C, L;
int map[MAX][MAX];

int cnt;
int visited[MAX][MAX] = {0, };
queue<pair<int, int>> q;

vector<int> dy[10];
vector<int> dx[10];

bool isPossible(int num, int y, int x) {
    if(y == -1 && x == 0 && (num == 1 || num == 2 || num == 5 || num == 6)) return true;
    else if(y == 1 && x == 0 && (num == 1 || num == 2 || num == 4 || num == 7)) return true;
    else if(y == 0 && x == -1 && (num == 1 || num == 3 || num == 4 || num == 5)) return true;
    else if(y == 0 && x == 1 && (num == 1 || num == 3 || num == 6 || num == 7)) return true;
    
    return false;
}

void getNext(int num, int y, int x) {
    for(int i=0; i<dy[num].size(); i++) {
        int nextY = y + dy[num][i];
        int nextX = x + dx[num][i];
        
        if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > M-1) continue;

        if(!visited[nextY][nextX] && isPossible(map[nextY][nextX], dy[num][i], dx[num][i])) {
            cnt++;
            visited[nextY][nextX] = visited[y][x] + 1;
            q.push(make_pair(nextY, nextX));
        }
    }
}

void BFS(int y, int x) {
    cnt = 1;
    visited[y][x] = 1;
    q.push(make_pair(y, x));
    
    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        
        if(visited[front.first][front.second] == L) break;
        
        getNext(map[front.first][front.second], front.first, front.second);
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
	
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(visited, 0, sizeof(visited));
        while(!q.empty()) q.pop();
        scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        
        dy[1].push_back(-1); dy[1].push_back(1); dy[1].push_back(0); dy[1].push_back(0);
        dy[2].push_back(-1); dy[2].push_back(1);
        dy[3].push_back(0); dy[3].push_back(0);
        dy[4].push_back(-1); dy[4].push_back(0);
        dy[5].push_back(1); dy[5].push_back(0);
        dy[6].push_back(1); dy[6].push_back(0);
        dy[7].push_back(-1); dy[7].push_back(0);
        
        dx[1].push_back(0); dx[1].push_back(0); dx[1].push_back(-1); dx[1].push_back(1);
        dx[2].push_back(0); dx[2].push_back(0);
        dx[3].push_back(-1); dx[3].push_back(1);
        dx[4].push_back(0); dx[4].push_back(1);
        dx[5].push_back(0); dx[5].push_back(1);
        dx[6].push_back(0); dx[6].push_back(-1);
        dx[7].push_back(0); dx[7].push_back(-1);
        
        BFS(R, C);
        
        printf("#%d %d\n", test_case, cnt);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}