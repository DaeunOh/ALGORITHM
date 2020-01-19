/*

문제
N과 시작 숫자 S가 주어지면 숫자 피라미드를 만드는 프로그램을 작성하시오.
예를 들어, N이 5이고 S가 3 이라면, 그 숫자 피라미드는 다음과 같다.

    3
   456
  21987
 3456789
987654321

시작 숫자 S는 꼭대기부터 1씩 증가한다.
시작 행의 번호가 1번이라고 했을때, 짝수번째 행은 왼쪽에서 오른쪽으로 1씩 증가하도록 적고, 홀수번째 행은 거꾸로 적는다.
숫자가 만약 10이 될 경우, 1로 바꾸고 다시 증가한다.

입력
입력의 첫 번째 줄에 N과 시작 숫자 S가 주어진다. ( 1≤N≤100, 1 ≤S≤ 9)

출력
첫 번째 줄부터 숫자 피라미드를 출력한다. (각 줄에 존재하는 공백의 개수와 숫자의 개수를 정확하게 확인해주시바랍니다.)

*/

#include <stdio.h>

int main() {
  int N, S;
  scanf("%d %d", &N, &S);
  
  int space = N-1, number = 1;
  int prev_first, prev_last;
  
  for(int i=1; i<=N; i++) {
    for(int j=0; j<space; j++) printf(" ");
    space--;
    
    if(i % 2 == 0) {
      int cur_first = prev_first + 1;
      if(cur_first >= 10) cur_first = 1;
      
      for(int i=0; i<number; i++) {
        printf("%d", cur_first);
        prev_last = cur_first;
        cur_first++;
        if(cur_first >= 10) cur_first = 1;
      }
    }
    else {
      int cur_first;
      if(i == 1) cur_first = S;
      else {
        cur_first = prev_last;
        for(int i=0; i<number; i++) {
          cur_first++;
          if(cur_first >= 10) cur_first = 1;
        }
      }
      
      prev_first = cur_first;
      
      for(int i=0; i<number; i++) {
        printf("%d", cur_first);
        cur_first--;
        if(cur_first <= 0) cur_first = 9;
      }
    }
    
    number += 2;
    printf("\n");
  }
  
  return 0;
}

/*

5 3
----------
    3
   456
  21987
 3456789
987654321

*/