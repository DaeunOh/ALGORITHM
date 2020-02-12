/*

문제
숫자를 입력 받아 이진수로 출력하는 프로그램을 작성하시오.

 

입력
첫 번째 줄에 숫자를 입력 받는다. 숫자의 크기는 1,000보다 작거나 같다.

 

출력
첫째 줄에 숫자를 이진수로 바꾸어 출력한다.

 

예제 입력
14
예제 출력
1110
 

예제 입력
31
예제 출력
11111

*/

#include <stdio.h>

const int MAX = 1000;

int main() {
  int n;
  scanf("%d", &n);
  
  int bin[MAX] = {0, };
  int idx = 0;
  while(n != 0) {
    bin[idx++] = n % 2;
    n /= 2;
  }
  
  for(int i=idx-1; i>=0; i--) printf("%d", bin[i]);

  return 0;
}