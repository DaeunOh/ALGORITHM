/*

문제
두 자연수가 주어질 때 그들의 덧셈을 계산하는 프로그램을 작성하시오. 
각 수는 1 이상 10^100(10의 100 거듭제곱) 미만의 범위를 가진다.  

입력
첫 번째 줄과 두 번째 줄에 각각 하나의 자연수가 주어진다.  

출력
첫 번째 줄에 덧셈의 결과를 출력한다.

 

예제 입력
123112981293812938139
1298928491101221811

예제 출력
124411909784914159950

*/

/*

숫자의 범위가 매우 크기 때문에, 문자열로 받아야 하는 것이 핵심이다.

또한, 덧셈은 보통 뒤에서부터 진행되기 때문에
받은 문자열을 가장 맨 뒤로 밀어넣는 작업이 필요하며,
10이 넘어갈 경우 앞 수에 넘겨주는 것 또한 필요하다.

*/

#include <stdio.h>
#include <string.h>

const int MAX = 100 + 10;

int main() {
  char str[MAX];
  int first[MAX] = {0, }, second[MAX] = {0, };
  int firstLen, secondLen;
  
  scanf("%s", str);
  firstLen = strlen(str);
  for(int i=0; i<firstLen; i++) first[MAX-firstLen+i] = str[i] - '0';
  
  scanf("%s", str);
  secondLen = strlen(str);
  for(int i=0; i<secondLen; i++) second[MAX-secondLen+i] = str[i] - '0';
  
  int res[MAX] = {0, };
  for(int i=MAX-1; i>=0; i--) {
    res[i] += first[i] + second[i];
    
    if(res[i] >= 10) {
      res[i] -= 10;
      res[i-1]++;
    }
  }
  
  for(int i=0; i<MAX; i++) {
    if(res[i] != 0) {
      for(int j=i; j<MAX; j++) printf("%d", res[j]);
      
      break;
    }
  }
  
  return 0;
}