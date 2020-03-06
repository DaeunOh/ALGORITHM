/*

시간제한 1초

문제
십자 숫자 카드는 아래와 같이 십자 모양으로 생긴 카드를 의미한다. 
카드의 상하좌우에는 숫자가 적혀있으며, 이 십자 숫자 카드는 회전이 가능하다.

crossnumber

N개의 숫자 카드가 일렬로 나열되어 있다. 
이제 이 카드들을 적절히 회전시킨 상태에 대하여 십자 카드의 인접한 숫자들에 주목하자. 
이제 이 인접한 두 숫자에 대하여 "인접값" 을 아래와 같이 계산한다. 
십자 카드의 왼쪽 끝과 오른쪽 끝의 숫자에 대해서는 "인접값"이 정의되어 있지 않다.

(1) 두 숫자가 모두 홀수이거나 모두 짝수일 경우, "인접값"은 0이다.
(2) 두 숫자가 하나는 홀수이고 하나는 짝수일 경우 "인접값"은 두 수의 곱이다.

N개의 숫자 카드에 대하여 "십자값"은 모든 "인접값"의 합이다. 
N개의 숫자 카드가 주어질 때, 
숫자 카드들을 적절히 회전시켜 얻을 수 있는 "십자값"의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. (1 ≤ T ≤ 10)
이후 각각의 테스트 케이스가 주어진다. 
각 테스트케이스의 첫 번째 줄에는 십자 숫자 카드의 갯수 N이 주어진다. (1 ≤ N ≤ 10) 
이후 N개의 줄에 대하여 카드의 정보가 주어진다. 
첫 번째로 입력되는 카드의가 가장 왼쪽에 위치하며, 
마지막으로 입력되는 카드가 가장 오른쪽에 위치한다. 
각 줄은 4개의 숫자로 이루어져 있으며, 북쪽 숫자, 서쪽 숫자, 동쪽 숫자, 그리고 남쪽 숫자의 순서대로 주어진다. 
모든 숫자들은 -100 이상 100이하의 정수이다.

출력
각 테스트케이스 별로 숫자 카드들을 적절히 회전시켜 얻을 수 있는 "십자값"의 최댓값을 출력한다. 
각 줄의 첫 번째 숫자는 테스트케이스 번호이며, 두 번째 숫자는 "십자값"의 최댓값이다. 
만약 인접값이 존재하지 않는 경우 0을 출력한다.

예제 입력
2
3
1 -3 -2 5
2 -3 4 8
9 2 3 5
3
-100 2 4 -100
2 -3 4 8
9 2 3 5
예제 출력
1 82
2 336

*/

#include <stdio.h>
#include <cstring>

const int MAXN = 10 + 10;

int T;
int N;
int card[MAXN][4];
int cardR[MAXN][4];
int cardR2[4][MAXN][4];

int comb[MAXN];
int myMax;

void rotate2() {
  for(int d=1; d<=3; d++) {
    for(int i=0; i<N; i++) {
      int temp = cardR2[d-1][i][0];
      
      for(int j=0; j<3; j++) {
        cardR2[d][i][j] = cardR2[d-1][i][j+1];
      }
      
      cardR2[d][i][3] = temp;
    }
  }
}

void getComb(int x, int cnt) {
  if(x >= N) {
    if(cnt == 0) {
      // 인접값 계산
      int sum = 0;
      for(int i=0; i<N-1; i++) {
        int A = cardR2[comb[i]][i][3] >= 0 ? cardR2[comb[i]][i][3] : cardR2[comb[i]][i][3]*(-1);
        int B = cardR2[comb[i+1]][i+1][1] >= 0 ? cardR2[comb[i+1]][i+1][1] : cardR2[comb[i+1]][i+1][1]*(-1);
        
        if(A == 0 || B == 0) continue;
        if((A % 2 == 0 && B % 2 == 1) || (A % 2 == 1 && B % 2 == 0)) {
          sum += cardR2[comb[i]][i][3] * cardR2[comb[i+1]][i+1][1];
        }
      }
      
      if(sum > myMax) myMax = sum;
    }
  }
  else {
    if(cnt != 0) {
      for(int i=1; i<=3; i++) {
        comb[x] = i;
        getComb(x+1, cnt-1);
      }
    }
    
    comb[x] = 0;
    getComb(x+1, cnt);
  }
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    memset(card, 0, sizeof(card));
    memset(comb, 0, sizeof(comb));
    myMax = -987987987;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
      scanf("%d %d %d %d", &card[i][0], &card[i][1], &card[i][3], &card[i][2]);
    }
    
    for(int i=0; i<N; i++) {
      for(int j=0; j<4; j++) {
        cardR2[0][i][j] = card[i][j];
      }
    }
    
    rotate2();
    
    for(int i=0; i<=N; i++) {
      getComb(0, i);
    }
    
    if(myMax != -987987987) printf("%d %d\n", t, myMax);
    else printf("%d 0\n", t);
  }

  return 0;
}