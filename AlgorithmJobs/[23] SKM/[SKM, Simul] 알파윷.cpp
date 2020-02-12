/*

시간제한 7초

문제
알파고를 보고 감명받은 한국의 박사들은 윷놀이의 알파고, "알파윷"을 만들기로 했다. 
"알파윷"은 윷놀이 인공지능으로  윷놀이 게임에서 어떠한 상대를 만나도 이길 수 있도록 만드는 것이 목표다.

alpha_yut
[그림 1]

알파윷이 윷놀이 판을 볼 때, 윷놀이 판의 각 칸에는 점수가 적혀있다. 
칸에 적힌 점수가 높을 수록 최종적으로 이길 확률이 높아진다. 
따라서, 알파윷의 차례에 말들을 모두 이동시킨 뒤 
최종적으로 말들이 놓인 칸에서 얻은 점수들의 총 합이 매번 최대가 되는 것이 이기기 위한 필수 조건이다. 
예를 들어, 이번 차례에 이동을 모두 마친 뒤 
각 말이 놓인 칸의 점수가 A 말이 110, B 말이 200, C 말이 500, D 말이 80이라면 
890점 정도 이길 확률이 있다는 의미다.

윷을 10번 던지게 되었을때 이동해야되는 칸 수를 미리 알고 있다. 
즉, 10번의 상황 각각에서 도, 개, 걸, 윷, 모 중 어떤 것이 나올지 미리 알고 있는 상황이다. 
이때, 10번의 이동 상황에서 적절히 말을 선택하여 최대한 많은 점수를 얻어야한다. 
이동하는 칸의 수는 도, 개, 걸, 윷, 모 로 각각 1, 2, 3, 4, 5칸을 뜻한다.

알파윷이 말을 이동시킬 때에 2 가지 규칙이 있다.

첫째로, 이동시 한 칸에 2마리 이상의 말이 존재할 수 없다. 
예를 들어, A 말이 있는 자리에 B, C, D 말이 올 수 없다.
둘째로, 검은 칸에 도착할 경우 무조건 화살표 있는 방향으로 이동해야한다.
셋째로, 기본적인 이동은 흰 칸이 있는 방향으로 이동해야한다.
윷놀이의 기본 규칙은 다음과 같다.

시작 지점에 말이 4개 존재한다.
만약, 이동해야하는 칸이 도착 지점을 넘어서거나, 
도착 지점을 밟았을 경우 도착 지점의 점수를 얻고 해당 말은 판에서 제외된다. 
제외된 말은 더 이상 이동할 수 없다.
말 선택 알고리즘에 치명적인 버그가 발생하여, 새로 만들어야하는 상황이다. 
현재 윷놀이 판의 점수 정보와 각 라운드별 이동 칸 수가 주어졌을때, 
말 4개를 적절히 선택하여 이동을 마친 후 말들이 존재하는 칸의 점수의 합이 최대가 되도록 만들어보자.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T(=50)가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다. 
각각의 테스트 케이스는 한 줄로 이루어져있고, 
10개의 숫자가 공백을 통해 구분하여 주어진다. 
각각의 숫자는 1부터 5까지의 자연수이다.

 

출력
각 테스트 케이스에 대해 만들 수 있는 숫자 합 중 최대값을 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. 
r은 문제에 대한 결과값을 뜻한다.

 

예제 입력
5
1 2 4 3 2 5 2 1 5 3
2 3 5 1 3 3 1 2 5 1
2 5 5 5 3 4 1 5 4 3 
5 4 4 4 2 5 2 3 4 3 
5 3 4 5 3 4 5 3 4 5 
예제 출력
#1 2010
#2 1525
#3 2065
#4 2035
#5 3050

*/

/*

전형적인 시뮬레이션 문제이다.
문제에서 주어진 정보를 가지고 그대로 구현하기만 하면 된다.

하지만, 각 칸마다 방향이 정해져 있고,
점수도 일정한 패턴이 있는 것이 아니기 때문에
자칫하면 빙 돌아가는 방식으로 구현하게 될 수도 있다.

나도 역시 처음에는 문제 안에서 최대한 패턴을 찾으려고 하며
배열에 직접 값을 넣어주는 것은 최대한 피하면서 구현을 하려 했다.

그러나 이 문제를 쉽게 푸는 핵심은
주어진 정보를 잘 활용하여 배열에 직접 집어넣고,
기존의 방향이 아닌 방향이 바뀌는 방향에 대해서
이동할 위치를 확실하게 정해주는 것이었다.
(그러므로 필요할 때는 배열에 값을 직접 넣어주는 방식을 적극적으로 활용해야 한다!)


또한, 이를 다 파악하고 구현에 돌입했으나, 풀면서 실수했던 점이 두 가지 존재했다.

1) 윷을 한 번 더 던지면 이전보다 더 높은 점수를 얻게 될 것이라 생각했다.

-->그러나 기존의 점수가 누적되는 방식이 아니라,
"가장 마지막 지점의 점수"가 획득되는 방식이며,
해당 칸의 점수가 점점 커지는 것도 아니기 때문에
윷을 한번 더 던진다고 해서 반드시 높은 점수를 얻게 될 것이라는 보장이 없다.

2) 도착지점에 도착한 말의 차례가 와도 건너뛰기만 하면 된다고 생각했다.

--> 하지만 도착지점에 도착한 말은 이후의 게임에서 움직이는 경우가 있으면 안되므로
해당 말의 순번 자체가 오면 안된다. (해당 말의 순번이 오면 게임의 규칙에 위배된다)

항상 문제를 "정확히" 파악하고, 그를 토대로 구현을 해야 함을 다시 한 번 깨닫게 해준 문제였다.

*/

#include <stdio.h>
#include <cstring>

const int MAX = 31 + 10;
const int MAXN = 10 + 10;

int map[MAX] = {
  0, 5, 10, 15, 20,
  50, 30, 35, 40, 45,
  100, 55, 60, 65, 70,
  75, 80, 85, 90, 95,
  500, 1000, 275, 250, 300,
  150, 175, 150, 125, 350,
  400
};

int temp[11][6] = {
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

int moving[MAX][6];

int T;
int N = 10;
int moveInfo[MAXN];
int comb[MAXN];

int cur[5];
int myMax;

int playGame() {
  memset(cur, 0, sizeof(cur));
  
  for(int i=0; i<N; i++) {
    int idx = comb[i]; // 몇번 말?
    
    // 제외된 말이 움직이려고 하는 경우가 있으면 안되므로
    if(cur[idx] == 21) return -1;
    
    bool flag = false;
    for(int j=0; j<11; j++) {
      if(cur[idx] == temp[j][0]) {
        flag = true;
        break;
      }
    }
    
    if(!flag) { // 기존처럼 진행
      cur[idx] += moveInfo[i];
      if(cur[idx] > 21) cur[idx] = 21;
    }
    else {
      cur[idx] = moving[cur[idx]][moveInfo[i]];
    }
    
    if(cur[idx] == 21) continue;
    
    // 말이 겹치는 경우 (도착지점 제외)
    for(int j=1; j<=4; j++) {
      if(j != idx && cur[idx] == cur[j]) {
        return -1;
      }
    }
  }
  
  // 말 이동이 다 끝나면 점수 계산
  int sum = 0;
  for(int i=1; i<=4; i++) {
    sum += map[cur[i]];
  }
  
  return sum;
}

void getComb(int x) {
  if(x >= N) {
    int res = playGame();
    
    if(myMax < res) myMax = res;
  }
  else {
    // 1번 ~ 4번 말
    for(int i=1; i<=4; i++) {
      comb[x] = i;
      getComb(x+1);
      comb[x] = 0;
    }
  }
}

int main() {
  // 초기 map 설정
  for(int i=0; i<11; i++) {
    for(int j=1; j<=5; j++) {
      moving[temp[i][0]][j] = temp[i][j];
    }
  }
  
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    myMax = -987987987;
    
    // 이동해야 할 칸 수 입력
    for(int i=0; i<N; i++) scanf("%d", &moveInfo[i]);
    
    // 조합 짜기
    getComb(0);
    
    printf("#%d %d\n", t, myMax);
  }

  return 0;
}