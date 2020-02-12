/*

문제
두 자연수가 주어질 때 그들의 곱셈을 계산하는 프로그램을 작성하시오. 
각 수는 1 이상 10^100 미만의 범위를 가진다.  

입력
첫 번째 줄과 두 번째 줄에 각각 하나의 자연수가 주어진다.  

출력
첫 번째 줄에 곱셈의 결과를 출력한다.  

예제 입력
123112981293812938139
1298928491101221811

예제 출력
159914959026945386297336486942660549729

*/

/*

손으로 곱셈을 하는 방식과 유사하게 구현하면 된다.

예를들어 99 * 12 = 99 * 2 + 99 * 10 과 같으므로,
second에 존재하는 수를 매 반복문의 피봇으로 해서
그 피봇이 존재하는 위치 만큼 앞으로 이동시킨 후 더해주면 된다.
(실제 곱셈에서 한칸 이동시키는 것은 *10 을 해주는 것과 같다.)

또한, 곱셈을 할 때 앞으로 넘겨주는 수는 10으로 나눈 수과 같고,(/10)
남아있게 되는 수는 10으로 나눈 나머지와 같다.(%10)

*/

#include <stdio.h>
#include <string.h>

const int MAX = 200 + 10;

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

  int res[MAX] = {0,};
  for(int i=0; i<MAX; i++) {
    int temp = second[MAX-1-i];
    
    if(temp != 0) {
      for(int j=MAX-1; j>=0; j--) {
        res[j-i] += first[j] * temp;
        
        if(res[j-i] >= 10) {
          res[j-i-1] += res[j-i] / 10;
          res[j-i] %= 10;
        }
      }
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