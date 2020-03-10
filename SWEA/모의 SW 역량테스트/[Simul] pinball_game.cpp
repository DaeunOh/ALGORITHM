// 소요시간: 1시간 5분
// 실행시간: 167ms

/*

시간 : 50개 테스트케이스를 합쳐서 C의 경우 3초 / C++의 경우 3초 / Java의 경우 3초 / Python의 경우 15초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


민기는 핀볼 게임을 개발 중에 있다. 
핀볼게임은 N x N 크기의 핀볼 게임판에 정사각형 블록과 4가지 형태의 삼각형 블록들이 섞여 있고, 
여기에 추가적으로 웜홀과 블랙홀이 존재한다. 
핀볼게임의 게임판의 하나의 예는 아래 [그림1]과 같다.
                
		[그림1]

각 블록들은 일정한 번호로 주어지는데, 블록들의 번호와 모양은 아래 [그림2]와 같다.
            
		[그림2]

웜홀과 블랙홀은 각각 아래 [그림3]의 번호로 주어진다.
              
		[그림3]

게임판 위에서는 작은 핀볼 하나가 상, 하, 좌, 우 중 한 방향으로 움직인다.

		[그림4]
 

핀볼은 블록이나 웜홀 또는 블랙홀을 만나지 않는 한 현재 방향을 유지하면서 계속 직진하며,
블록의 수평면이나 수직면을 만날 경우 방향을 바꿔 반대 방향으로 돌아오고, 
경사면을 만날 경우에는 직각으로 진행 방향이 꺾이게 된다.

		[그림5]
 

또한 핀볼은 벽을 만날 경우에도 반대 방향으로 돌아온다. 
아래의 그림과 같이 핀볼이 왼쪽으로 움직이다 벽을 만나면 반대 방향으로 다시 돌아오게 된다.
 
		[그림6]
 

핀볼이 웜홀에 빠지면 동일한 숫자를 가진 다른 반대편 웜홀로 빠져 나오게 되며 진행방향은 그대로 유지된다. 
(웜홀은 반드시 쌍으로 주어지며, 입력에서는 6 이상 10 이하의 숫자로 표시된다.)
 
		[그림7]
 

핀볼이 블랙홀을 만나면, 핀볼이 사라지게 되어 게임은 끝나게 된다.

		[그림8]
 

게임은 핀볼이 출발 위치로 돌아오거나, 블랙홀에 빠질 때 끝나게 되며, 점수는 벽이나 블록에 부딪힌 횟수가 된다. 
(웜홀을 통과하는 것은 점수에 포함되지 않는다.)
블랙홀에 빠져서 게임이 끝나더라도, 벽이나 블록에 부딪혀 획득한 점수는 남아있게 된다.
게임판 위에서 출발 위치와 진행 방향을 임의로 선정가능 할 때,
▶ 게임에서 얻을 수 있는 점수의 최댓값을 구하여라!
단, 블록, 웜홀 또는 블랙홀이 있는 위치에서는 출발할 수 없다.

 

[제약 사항]

게임판의 크기는 정사각형으로 주어지며, 한 변의 길이 N 은 5 이상 100 이하이다. (5 ≤ N ≤ 100)
웜홀은 게임판 내에서 숫자 6 ~ 10으로 주어진다.
블랙홀은 게임판 내에서 숫자 -1 로 주어진다.
게임판에서 웜홀 또는 블랙홀이 존재하지 않는 경우도 있다.
웜홀이 있는 경우 반드시 쌍(pair)으로 존재하며, 웜홀이 주어지는 경우 최대 5쌍 존재한다.
웜홀을 통과한 핀볼은 동일한 숫자를 가진 반대편 웜홀로 이동하게 되며, 이때 진행방향은 그대로 유지된다.
블랙홀은 최대 5개가 주어진다.
 

[입력]

입력의 가장 첫 줄에는 총 테스트 케이스의 개수 T가 주어지며, 그 다음 줄부터 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫째 줄에는 N이 주어지고, 다음 N줄에 걸쳐서 핀볼 게임판의 모양이 주어진다.
게임판의 모양은 -1 이상 10 이하의 정수로 주어지며, 각 숫자는 한 칸씩 띄어져서 주어진다.
숫자에 따른 의미는 다음과 같다

-1	: 블랙홀
0	: 빈공간
1 ~ 5	: 블록
6 ~ 10	: 웜홀


[출력]

테스트 케이스 t에 대한 결과는 "#t"를 찍고, 한 칸 띄고 정답을 출력한다.
(단, t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)



입력
5	 	// T = 5
10		// 테스트 케이스 #1, N = 10
0 1 0 3 0 0 0 0 7 0
0 0 0 0 -1 0 5 0 0 0
0 4 0 0 0 3 0 0 2 2
1 0 0 0 1 0 0 3 0 0
0 0 3 0 0 0 0 0 6 0
3 0 0 0 2 0 0 1 0 0
0 0 0 0 0 1 0 0 4 0
0 5 0 4 1 0 7 0 0 5
0 0 0 0 0 1 0 0 0 0
2 0 6 0 0 4 0 0 0 4
6		// 테스트 케이스 #2, N = 6
1 1 1 1 1 1
1 1 -1 1 1 1
1 -1 0 -1 1 1
1 1 -1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
8		// 테스트 케이스 #3, N = 8
0 0 0 3 0 0 0 0
0 0 2 0 0 5 0 0
0 0 5 0 3 0 0 0
0 0 1 1 0 0 0 4
0 0 0 0 0 0 0 0
0 0 0 0 0 0 5 0
0 0 4 0 0 3 1 0
2 0 0 4 3 4 0 0
...		// 이하 sample_input.txt 참조


출력
#1 9
#2 0
#3 7
#4 5
#5 19

*/

/*

자신의 방향으로 쭉 가다가 만나는 벽, 블록, 웜홀에 의해 위치 및 방향을 바꾸고,
블랙홀 또는 시작위치에 도달하면 게임을 종료하는 시뮬레이션 문제.

블랙홀 또는 시작위치에 도달하기 전까지 자신의 다음 위치를 결정하고,
벽이나 블록의 수평면 또는 수직면에 부딪히면 반대 방향으로 방향을 전환하며,
블록의 경사면에 부딪히면 직각 방향으로 방향을 전환하도록 해야한다.
또한, 웜홀을 만나면 자신과 짝인 다른 웜홀으로 위치를 바꿔줘야 한다.

방향을 전환하는 것은 블록의 종류에 따라 그리고 자신의 방향에 따라
해당 방향의 반대 방향 또는 직각 방향으로 방향을 전환하도록 만들어야 한다.
나는 방향을 전환하는 함수를 따로 만들어 방향을 전환하였다!

그리고 웜홀의 경우에는 hole이라는 이차원 배열을 따로 만들어 서로 쌍인 웜홀을 연결시켜 주고,
맵이 6이상 10이하의 수이면 해당 좌표로 이동하게끔 만들었더니 웜홀의 번호에 신경쓰지 않아도 돼서 좋았다.

자신이 도착한 위치가 블랙홀인 경우는 맵에 적혀있기 때문에 다른 조건문들과 함께 else if문으로 해결이 되지만,
자신의 도착한 위치가 시작 위치인 경우에는 맵에 따로 적어놓지 않았으므로
else if문이 아닌 맨 마지막에 별도의 if문으로 검사해줘야 함을 잊지 말자!

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int MAX = 100 + 10;

int N;
int map[MAX][MAX];
pair<int, int> hole[MAX][MAX];
vector < pair<int, int> > wormhole[20];

int myMax;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int changeDir1(int d) {
    // 반대 방향으로 방향 전환
    if(d == 0) return 1;
    else if(d == 1) return 0;
    else if(d == 2) return 3;
    else return 2;
}

int changeDir2(int idx, int d) {
    // 직각 방향으로 방향 전환
    if(idx == 1) {
        if(d == 1) return 3;
        else return 0;
    }
    else if(idx == 2) {
        if(d == 0) return 3;
        else return 1;
    }
    else if(idx == 3) {
        if(d == 0) return 2;
        else return 1;
    }
    else {
        if(d == 1) return 2;
        else return 0;
    }
}

void playGame(int y, int x, int d) {
    int destY = y, destX = x, cnt = 0;
    
    while(1) {
        int nextY = y + dy[d];
        int nextX = x + dx[d];
        
        // 1) 벽에 부딪힌 경우 - 위치 이동 + 반대 방향으로 방향 전환 + cnt 증가
        // 2) 빈 공간에 도착한 경우	- 위치 이동
        // 2) 블록에 부딪힌 경우 - 위치 이동 + 수평 또는 수직면은 반대 방향, 경사면은 직각 방향으로 전환 + cnt 증가
        // 3) 웜홀에 도착한 경우 - 위치 이동
        // 4) 블랙홀에 도착한 경우 - 게임 종료
        if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > N-1) {
            d = changeDir1(d);
            cnt++;
            y = nextY, x = nextX;
        }
        else if(map[nextY][nextX] == 0) {
            y = nextY, x = nextX;
        }
        else if(1 <= map[nextY][nextX] && map[nextY][nextX] <= 5) {
            if(map[nextY][nextX] == 1) {
                if(d == 0 || d == 3) d = changeDir1(d);
                else d = changeDir2(1, d);
            }
            else if(map[nextY][nextX] == 2) {
                if(d == 1 || d == 3) d = changeDir1(d);
                else d = changeDir2(2, d);
            }
            else if(map[nextY][nextX] == 3) {
                if(d == 1 || d == 2) d = changeDir1(d);
                else d = changeDir2(3, d);
            }
            else if(map[nextY][nextX] == 4) {
                if(d == 0 || d == 2) d = changeDir1(d);
                else d = changeDir2(4, d);
            }
            else {
                d = changeDir1(d);
            }
            
            cnt++;
            y = nextY, x = nextX;
        }
        else if(6 <= map[nextY][nextX] && map[nextY][nextX] <= 10) {
            y = hole[nextY][nextX].first, x = hole[nextY][nextX].second;
        }
        else if(map[nextY][nextX] == -1) break;
        
        // 시작 지점으로 돌아온 경우
        if(y == destY && x == destX) break;
    }
    
    // 최대 점수 업데이트
    if(myMax < cnt) myMax = cnt;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        myMax = -987987987;
        for(int i=6; i<=10; i++) wormhole[i].clear();
        
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                scanf("%d", &map[i][j]);
                
                if(6 <= map[i][j] && map[i][j] <= 10) 
                    wormhole[map[i][j]].push_back(make_pair(i, j));
            }
        }
        
        for(int i=6; i<=10; i++) { // 서로의 위치에 자신의 위치를 저장한다.
            if(wormhole[i].size() == 0) continue;
            hole[wormhole[i][0].first][wormhole[i][0].second] = make_pair(wormhole[i][1].first, wormhole[i][1].second);
            hole[wormhole[i][1].first][wormhole[i][1].second] = make_pair(wormhole[i][0].first, wormhole[i][0].second);
        }
        
        // 빈 공간에서 시작해서 상하좌우 탐색
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(map[i][j] == 0) {
                    for(int d=0; d<4; d++) {
                        playGame(i, j, d);
                    }
                }
            }
        }
        
        printf("#%d %d\n", test_case, myMax);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}