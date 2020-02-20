/*

문제
alpha_yut
T개의 윷을 던진 상황이 주어질때, 각 상황에서 얻어지는 점수 중 최댓값을 알아보자.

각 상황에서 말 4개가 움직인다. 
얻은 점수의 합이란, 각 말이 얻은 점수의 총 합을 의미하며 
각 말은 마지막에 밟았던 칸의 점수를 자신의 점수로 갖는다.

말의 이동 시작점은 Start 이며, 도착지점은 End 이다. 
만약, 이동해야하는 칸이 도착 지점을 넘어서거나, 
도착 지점을 밟았을 경우 도착 지점의 점수를 얻고 해당 말은 판에서 제외된다. 
제외된 말은 더 이상 이동할 수 없다. 
50점과 75점 칸을 밟을 경우, 화살표가 가리키는 방향으로 움직여야한다. 
기본적으로 흰색 칸이 있는 경로로 이동한다.

이동하려고 하는 칸에 다른 말이 있는 경우 이동할 수 없다. 해당 상황의 결과값은 "-1"이다.

입력
첫 번째 줄에 상황의 개수 T가 주어진다. 
두 번째 줄부터 T x 2개의 줄에 걸쳐 윷을 던진 상황이 주어진다. 
각 상황의 첫 번째 줄에 이동하게될 칸의 수가 10개 주어진다. 
그리고 두 번째 줄에 각 이동하게될 칸의 수가 몇 번 말이 될지 주어진다.
(2 ≤ T ≤ 10, 1 ≤ 이동하는 칸의 수 ≤ 5, 1 ≤ 말의 번호 ≤ 4)

출력
T개의 상황에서 얻어지는 점수 중 최댓값을 알아보자. 
만약 주어진 모든 상황에서 얻은 결과값이 -1이라면 "-1"을 출력한다.


입력의 예
4
2 3 1 2 4 5 2 3 4 1 
1 1 2 3 4 1 2 2 3 1 
5 5 5 5 5 5 5 5 5 5 
1 2 3 4 1 2 3 4 1 2 
5 3 4 5 3 4 5 3 4 5 
1 1 1 2 2 2 3 3 3 4 
3 4 3 2 1 2 3 4 3 2 
1 2 2 3 4 3 1 4 4 1 
출력의 예
3050

*/

#include <stdio.h>
#include <cstring>

const int MAX = 31 + 10;
const int MAXN = 10 + 10;

int yut[MAX] = {
  0, 5, 10, 15, 20,
  50, 30, 35, 40, 45,
  100, 55, 60, 65, 70,
  75, 80, 85, 90, 95,
  500, 1000, 275, 250, 300, 
  150, 175, 150, 125, 350, 400
};

int moving[MAX][6];

int temp[15][6] = {
  {5, 22, 23, 24, 25, 26},
  {10, 27, 28, 24, 29, 30},
  {22, 23, 24, 25, 26, 15},
  {23, 24, 25, 26, 15, 16},
  {24, 29, 30, 20, 21, 21},
  {25, 26, 15, 16, 17, 18},
  {26, 15, 16, 17, 18, 19},
  {27, 28, 24, 29, 30, 20},
  {28, 24, 29, 30, 20, 21},
  {29, 30, 20, 21, 21, 21},
  {30, 20, 21, 21, 21, 21}
};

int seqN[MAXN] = {0, };
int seqI[MAXN] = {0, };
int cur[5] = {0, };
int sum;

int main() {
  for(int i=0; i<11; i++) {
    for(int j=1; j<=5; j++) {
      moving[temp[i][0]][j] = temp[i][j];
    }
  }
  
  int T;
  scanf("%d", &T);
  
  int myMax = -987987987;
  
  bool isFinished;
  for(int t=1; t<=T; t++) {
    memset(seqN, 0, sizeof(seqN));
    memset(seqI, 0, sizeof(seqI));
    memset(cur, 0, sizeof(cur));
    
    for(int i=0; i<10; i++) {
      scanf("%d", &seqN[i]);
    }
    
    for(int i=0; i<10; i++) {
      scanf("%d", &seqI[i]);
    }
    
    isFinished = false;
    for(int i=0; i<10; i++) {
      int idx = seqI[i];
      
      if(cur[idx] == 21) continue;
      
      bool flag = false;
      for(int j=0; j<11; j++) {
        if(cur[idx] == temp[j][0]) {
          flag = true;
          break;
        }
      }
      
      if(flag) {
        cur[idx] = moving[cur[idx]][seqN[i]];
      }
      else {
        cur[idx] += seqN[i];
        if(cur[idx] > 21) cur[idx] = 21;
      }
      
      if(cur[idx] != 21) {
        for(int j=1; j<=4; j++) {
          if(j != idx && cur[idx] == cur[j]) {
            isFinished = true;
            break;
          }
        }
      }
      
      
      if(isFinished) break;
    }
    
    sum = 0;
    if(isFinished) {
      if(myMax < -1) myMax = -1;
    }
    else {
      for(int i=1; i<=4; i++) {
        sum += yut[cur[i]];
      }
      
      if(myMax < sum) myMax = sum;
    }
  }
  
  printf("%d\n", myMax);
    
  return 0;
}