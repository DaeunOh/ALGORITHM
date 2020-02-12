/*

문제
n명의 사람중 m명을 순서에 상관없이 뽑는 경우의 수를 조합이라고 하며 nCm으로 나타낸다.

nCm은 수식으로 n!/m!(n-m)! 으로 구할 수 있다. (5! = 1 * 2 * 3 * 4 * 5)

n과 m이 주어졌을때 nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.  

입력
첫째 줄에 정수 n, m(0≤m≤n≤1,000,000)이 들어온다.

 

출력
첫째 줄에 0의 개수를 출력한다.

 

예제 입력
25 12
예제 출력
2

*/

/*

끝자리 0의 개수는, 실제로 10으로 몇 번이나 나누어 떨어지냐와 관련된 것이다.
10은 5와 2의 곱으로 되어있기 때문에, 팩토리얼 계산을 할 때 2와 5의 개수를 세어주면 된다.

*/


#include <stdio.h>

int n, m;

int main() {
  scanf("%d %d", &n, &m);
  
  int num2 = 0, num5 = 0;
  for(int i=n; i>n-m; i--) {
    int num = i;
    while(num % 2 == 0) {
      num2++;
      
      num /= 2;
    }
    
    num = i;
    while(num % 5 == 0) {
      num5++;
      
      num /= 5;
    }
  }
  
  
  
  for(int i=m; i>=1; i--) {
    int num = i;
    while(num % 2 == 0) {
      num2--;
      
      num /= 2;
    }
    
    num = i;
    while(num % 5 == 0) {
      num5--;
      
      num /= 5;
    }
    
    if(num2 <= 0 || num5 <= 0) {
      printf("0");
      return 0;
    }
  }
  
  if(num2 < num5) printf("%d", num2);
  else printf("%d", num5);
  
  return 0;
}