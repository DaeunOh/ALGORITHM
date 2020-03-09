// 소요시간: 1시간 25분
// 실행시간: 355ms

/*

시간 : 50개 테스트케이스를 합쳐서 C의 경우 3초 / C++의 경우 3초 / Java의 경우 3초 / Python의 경우 15초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


구슬을 쏘아 벽돌을 깨트리는 게임을 하려고 한다.
구슬은 N번만 쏠 수 있고, 벽돌들의 정보는 아래와 같이 W x H 배열로 주어진다.
( 0 은 빈 공간을 의미하며, 그 외의 숫자는 벽돌을 의미한다. )
 
[Fig. 1]


게임의 규칙은 다음과 같다.
① 구슬은 좌, 우로만 움직일 수 있어서 항상 맨 위에 있는 벽돌만 깨트릴 수 있다.
② 벽돌은 숫자 1 ~ 9 로 표현되며,
   구슬이 명중한 벽돌은 상하좌우로 ( 벽돌에 적힌 숫자 - 1 ) 칸 만큼 같이 제거된다.

아래는 벽돌에 적힌 숫자와, 구술이 명중했을 시 제거되는 범위의 예이다.

[Fig. 2]


③ 제거되는 범위 내에 있는 벽돌은 동시에 제거된다.


예를 들어 아래와 같이 4 번 벽돌에 구술이 명중할 경우,

[Fig. 3]

9번 벽돌은 4 번 벽돌에 반응하여,

[Fig. 4]

동시에 제거된다.

[Fig. 5]
 

④ 빈 공간이 있을 경우 벽돌은 밑으로 떨어지게 된다.

[Fig. 6]
 

N 개의 벽돌을 떨어트려 최대한 많은 벽돌을 제거하려고 한다.
N, W, H, 그리고 벽돌들의 정보가 주어질 때,
▶ 남은 벽돌의 개수를 구하라!

 

※ sample input 1

N = 3, W = 10, K = 10 이고 벽돌들의 정보가 아래와 같을 때,

[Fig. 7]


최대한 많은 벽돌을 깨트리는 방법은 아래와 같으며, 정답은 12 가 된다.
그림의 빨간 색 원은 구술이 명중한 위치이며, 주황색 칸은 폭발의 범위를 의미한다.

 

i) 첫 번째 구슬

[Fig. 8]


ii) 두 번째 구슬

[Fig. 9]
 

iii) 세 번째 구술

[Fig. 10]

 

[제약 사항]

1. 1 ≤ N ≤ 4
2. 2 ≤ W ≤ 12
3. 2 ≤ H ≤ 15

 

[입력]

가장 첫 줄에는 총 테스트 케이스의 개수 T 가 주어지고,
그 다음 줄부터 T 개의 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 N, W, H 가 순서대로 공백을 사이에 두고 주어지고,
다음 H 줄에 걸쳐 벽돌들의 정보가 1 줄에 W 개씩 주어진다.

 
[출력]

출력은 #t 를 찍고 한 칸 띄운 다음 정답을 출력한다.
(t 는 테스트 케이스의 번호를 의미하며 1 부터 시작한다)


입력
5		 // T = 5
3 10 10		// #1, N = 3, W = 10, H = 10
0 0 0 0 0 0 0 0 0 0
1 0 1 0 1 0 0 0 0 0
1 0 3 0 1 1 0 0 0 1
1 1 1 0 1 2 0 0 0 9
1 1 4 0 1 1 0 0 1 1
1 1 4 1 1 1 2 1 1 1
1 1 5 1 1 1 1 2 1 1
1 1 6 1 1 1 1 1 2 1
1 1 1 1 1 1 1 1 1 5
1 1 7 1 1 1 1 1 1 1
2 9 10		// #2, N = 2, W = 9, H = 10
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
1 1 0 0 1 0 0 0 0
1 1 0 1 1 1 0 1 0
1 1 0 1 1 1 0 1 0
1 1 1 1 1 1 1 1 0
1 1 3 1 6 1 1 1 1
1 1 1 1 1 1 1 1 1
...		// 이하 sample_input.txt 참조


출력
#1 12
#2 27
#3 4
#4 8
#5 0

*/

/*

여러가지 개념이 혼합되어있는 시뮬레이션(완전탐색 + BFS) 문제.
문제에 주어진 정보가 많지 않아 Runtime error가 매우 많이 났었다.. ㅎㅎ;;
디버깅을 해볼까 하다가 시간이 더 오래 걸릴 것 같아 printf를 통해 최대한 오류를 해결하려고 했다.
다행히 출력만으로도 오류를 찾을 수 있어서 디버깅을 하지 않아도 됐다 ^_^


실수한 점

1) 기존 맵을 복사하고, 복사한 맵을 사용하는 형식으로 구현하려고 했는데, 바뀌면 안되는 기존 맵을 바꿔버렸다...
    --> 기존 맵을 바꾸지 않기 위해 기존 맵은 temp2에 집어넣고 시작하며,
          이후 새로운 열이 시작될 때마다 temp에 temp2의 내용을 집어넣고 시작했다.
          (temp는 벽돌이 깨지는 맵이고, temp2는 벽돌을 밑으로 떨어지게 한 맵이다.)
          또한, 벽돌을 밑으로 내릴 때는 temp에서 0이 아닌 부분을 temp2에 차례대로 넣어주도록 했다.

2) 해당 열에 더이상 깰 벽돌이 없으면 다음 열로 넘어가야 하는데, 그 부분을 처리해주지 못했다.
    --> 구슬이 명중할 위치를 의미하는 top이 H를 가리킨다면 해당 열에는 벽돌이 없다는 뜻이므로 다음 열로 넘어가게 해줬다.

3) visited 배열을 사용하지 않고, 맵이 0이 아니기만 하면 큐에 넣어줬더니 사라지는 벽돌을 세는 부분이 복잡해졌다.
    --> visited 배열을 사용하여 이미 큐에 들어가 있는 벽돌은 넣지 않도록 만들어주었다.


+ 남은 구슬 개수가 0일 때 다른 거 볼 필요 없이 끝나게 했더니 거의 1000ms 이상이 줄어들었다.


getComb() : 재귀함수를 이용한 조합을 만드는 함수
breakout() : 조합을 통해 얻은 열에 구슬을 명중시키며 벽돌을 깨는 함수
자세한 내용은 주석 참고.

*/

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

const int MAX = 20;

int N, W, H;
int map[MAX][MAX];
int total;

int temp[MAX][MAX];
int temp2[MAX][MAX];
bool visited[MAX][MAX];
int myMax;

int comb[MAX];
bool isFinished;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void breakout() {
    queue< pair<int, int> > q;
    int cnt = 0;
    
    // 초기 map을 temp2에 복사한다.
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            temp2[i][j] = map[i][j];
        }
    }
    
    for(int x=0; x<N; x++) {
        memset(visited, 0, sizeof(visited));
        
        // temp: 벽돌이 깨지는 맵
        // temp2: 벽돌을 밑으로 떨어지게 한 맵
        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                temp[i][j] = temp2[i][j];
            }
        }
        
        // 구슬이 명중할 벽돌 위치 찾기
        int top = 0;
        while(temp[top][comb[x]] == 0 && top < H) top++;
        if(top == H) continue; // 해당 열에 더이상 깰 벽돌이 없는 경우
        
        q.push(make_pair(top, comb[x]));
        visited[top][comb[x]] = true;
        
        while(!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            
            int range = temp[front.first][front.second];
            temp[front.first][front.second] = 0;
            cnt++;
            
            // 상하좌우 벽돌 깨기
            for(int i=1; i<range; i++) {
                for(int j=0; j<4; j++) {
                    int nextY = front.first + dy[j]*i;
                    int nextX = front.second + dx[j]*i;
                    
                    if(nextY < 0 || nextY > H-1 || nextX < 0 || nextX > W-1) continue;
                    
                    if(!visited[nextY][nextX] && temp[nextY][nextX] != 0) { // 방문하지 않은 지점이면서 벽돌이 있는 경우
                        visited[nextY][nextX] = true;
                        q.push(make_pair(nextY, nextX));
                    }
                }
            }
        }
        
        memset(temp2, 0, sizeof(temp2)); // temp2에 temp의 벽돌을 최대한 바닥으로 내려서 넣어준다.
        for(int i=0; i<W; i++) {
            int idx = H-1;
            for(int j=H-1; j>=0; j--) {
                if(temp[j][i] != 0) temp2[idx--][i] = temp[j][i];
            }
        }
    }
    
    if(myMax < cnt) myMax = cnt; // 깨진 벽돌의 최댓값
}

void getComb(int x) {
    if(isFinished) return;
    
    if(x >= N) {
        breakout();
        if(myMax == total) isFinished = true;
    }
    else {
        for(int i=0; i<W; i++) {
            comb[x] = i;
            getComb(x+1);
        }
    }
}

void solution() {
    getComb(0);
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        myMax = -987987987;
        total = 0;
        isFinished = false;
        scanf("%d %d %d", &N, &W, &H);
        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                scanf("%d", &map[i][j]);
                if(map[i][j] != 0) total++;
            }
        }
        
        solution();
        
        printf("#%d %d\n", test_case, total - myMax);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}