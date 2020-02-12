/*

문제
버섯 농장에서 이번에 새로운 종자를 가져와 시범삼아 기르기 시작했다. 
각 종자는 성장하는 속도가 다르다. 
버섯의 키가 K가 될 경우 주변에 포자를 뿌려 번식을 한다. 
버섯 격자판은 N * M 칸을 가지고 있고, 각 칸은 정사각형 형태로 되어있다.

적당한 위치의 칸에 버섯을 심으면 격자판을 최대한 가득 채우게 된다. 
버섯은 초기에 1의 키를 가지고 있고, 하루가 지날때마다 키가 1씩 자란다. 
키가 K가 될 경우 현재 위치를 (i, j)라 할때, (i+1, j), (i-1, j), (i, j+1), (i, j-1) 의 4방향에 포자를 뿌린다. 
만약 포자를 뿌린 자리에 이미 버섯이 있을 경우 해당 포자는 버섯으로 자라지 못한다. 
또한 한 자리에 여러 종류 종자의 포자가 동시에 뿌려질 경우, 
최대 키가 더 큰 종자의 포자가 자리를 잡는다.

포자가 뿌려지고 하루가 지나게되면 포자가 뿌려진 자리에서 새로운 버섯이 자라게된다. 
키가 K가 된 버섯은 더 이상 키가 더 크지않고 성장을 멈춘다. 
성장만 멈췄을뿐 살아있는 상태이다. 
버섯 격자판에 버섯을 심고 격자판의 모든 칸을 버섯으로 덮었을때, 
각 종자별 완전히 성장한 버섯의 개수를 알아내보자.

예를 들어, 5 * 6 격자판에 아래와 같이 버섯을 심었다고 가정하자. 
A, B, C 버섯은 각각 키가 1, 2, 3 이 되었을때 포자를 뿌린다.

mushroom1[그림 1]mushroom2[그림 2]

A 종자 11개, B 종자 18개, C 종자 1개 수확하게 된다.

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다.
각각의 테스트 케이스의 첫 번째 줄에 버섯 격자판의 크기 N, M이 공백을 통해 구분하여 주어진다. 
다음 줄부터 N개의 줄에 걸쳐 한 줄에 M개의 정보가 공백을 통해 구분없이 주어진다.
0은 아무것도 없음을 의미하고, 알파벳은 버섯 종자를 뜻한다. 
알파벳은 최소 A부터 최대 J까지 존재하며, 
각 종자별 버섯의 최대 키는 A는 1, B는 2, C는 3, .., I는 9, J는 10이다. (5 ≤ N, M ≤ 50)

출력
각 테스트 케이스에 대해 모든 종자별 완전히 성장한 버섯의 개수를 
공백을 통해 구분하여 A부터 J까지 순서대로 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. t는 테스트 케이스의 번호이며, 1부터 시작한다. 
r은 문제에 대한 결과값을 뜻한다.

*/

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 50 + 10;

int T;
int N, M;
char map[MAX][MAX];
int day[MAX][MAX];
int ans[10];

struct MUSHROOM {
  int y, x;
  
  MUSHROOM(int Y, int X) {
    y = Y;
    x = X;
  }
};

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

queue<MUSHROOM> q;

void BFS() {
  while(!q.empty()) {
    while(!q.empty()) {
      MUSHROOM front = q.front();
      q.pop();
      
      if(day[front.y][front.x] == map[front.y][front.x] - 'A' + 1) {
        // 포자 뿌리기
        for(int i=0; i<4; i++) {
          int nextY = front.y + dy[i];
          int nextX = front.x + dx[i];
          
          if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > M-1) continue;
          
          if(map[nextY][nextX] == '0'
              || day[nextY][nextX] == 0 && map[nextY][nextX] < map[front.y][front.x]) {
            map[nextY][nextX] = map[front.y][front.x];
            q.push(MUSHROOM(nextY, nextX));
          }
        }
      }
    }
    
    bool flag = false;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        if(day[i][j] < map[i][j] - 'A' + 1) day[i][j]++;
        if(map[i][j] != '0') q.push(MUSHROOM(i, j));
        
        if(day[i][j] == 0) flag = true;
      }
    }
    
    if(!flag) break;
  }
    
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    while(!q.empty()) q.pop();
    memset(day, 0, sizeof(day));
    memset(ans, 0, sizeof(ans));
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        scanf(" %c", &map[i][j]);
        if(map[i][j] != '0') q.push(MUSHROOM(i, j));
      }
    }
    
    BFS();

    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        ans[map[i][j]-'A']++;
      }
    }
    
    printf("#%d ",t);
    for(int i=0; i<10; i++) printf("%d ", ans[i]);
    printf("\n");
  }

  return 0;
}

/*

5
5 6
A0CB00
0B0000
000000
000000
000000
7 5
00000
0E00G
G0000
E00BC
0A0D0
00000
00H00
6 6
000I00
A0F000
0F000E
E00000
000000
00000A
9 6
00E0F0
I00I00
00G0BI
F00D0D
000000
EG0000
00G000
00A000
00F000
5 6
000A00
D0E000
00D000
0AH000
AI00J0
-------------------------------
#1 11 18 1 0 0 0 0 0 0 0 
#2 17 5 3 1 5 0 3 1 0 0 
#3 26 0 0 0 5 4 0 0 1 0 
#4 22 6 0 5 6 6 4 0 5 0 
#5 24 0 0 2 1 0 0 1 1 1 

*/