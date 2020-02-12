/*

문제
alpha_yut_b
위와 같은 판에 말 1개가 이동한다. 
윷놀이 판에 존재하는 각 칸에는 점수가 적혀있다. 
윷을 N번 던져서 이동해야될 칸의 수가 각각 주어질때, 
이동하면서 밟게되는 칸의 점수를 모두 출력해보자.

말의 이동 시작점은 Start 이며, 도착지점은 End 이다. 
만약, 이동해야하는 칸이 도착 지점을 넘어서거나, 도착 지점을 밟았을 경우 
도착 지점의 점수를 얻고 해당 말은 판에서 제외된다. 제외된 말은 더 이상 이동할 수 없다.

 

입력
첫 번째 줄에 윷을 던진 횟수 N이 주어진다. 
두 번째 줄에 이동하는 칸의 개수 N개가 공백을 통해 구분하여 주어진다.
(1 ≤ N ≤ 10, 1 ≤ 이동하는 칸의 수 ≤ 5)

 

출력
첫 번째 줄에 이동하면서 밟게되는 칸의 점수를 공백을 통해 구분하여 모두 출력한다.

 

입력 예제 1
5
2 3 1 2 4
출력 예제 1
10 50 30 40 60

입력 예제 2
6
5 5 5 5 5 5
출력 예제 2
50 100 75 500 1000

*/

#include <stdio.h>

const int MAX = 22;

int N;
int yut[MAX] = {0, 50, 100, 75, 500};

int main() {
  scanf("%d", &N);
  
  int loc = 0;
  for(int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);
    
    loc += num;
    
    if(loc >= 21) {
      printf("1000");
      break;
    }
    
    if(loc % 5 != 0) printf("%d ", 5*loc);
    else printf("%d ", yut[loc/5]);
  }
  
  return 0;
}