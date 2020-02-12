/*

문제
문자열 A와 B가 주어질 때, 
문자열 B가 문자열 A에 포함되어 있는지를 조사하는 프로그램을 작성하시오. 
단, 문자열 A와 B에는 알파벳으로만 이루어져 있으며, 공백은 포함되지 않는다고 가정한다.  

입력
첫 번째 줄에 문자열 A, 두 번째줄에 문자열 B가 주어진다. 
각각의 길이는 1,000을 넘지 않는다. 두 문자열은 모두 소문자 알파벳으로만 구성되어있다.  

출력
문자열 B가 문자열 A에 포함되면 YES, 아니면 NO를 출력한다.

 

예제 입력
watermelon
melon

예제 출력
YES

*/

/*

문자열을 스캔하면서 같은 부분이 나오는 시점부터 확인하면 된다.
여기서 주의할 점은 i+bLen-1 < aLen과 같이 A의 남은 길이가 bLen만큼은 있어야한다는 것이다.

사실 MAX의 길이를 여유있게 놨기 때문에 상관은 없으나,
이를 신경쓰지 않으면 풀리지 않는 문제도 있기 때문에 항상 배열 범위는 신경 써줘야 한다.

*/

#include <stdio.h>
#include <string.h>

const int MAX = 1000 + 10;

int main() {
  char A[MAX], B[MAX];
  
  scanf("%s", A);
  scanf("%s", B);
  
  int aLen = strlen(A);
  int bLen = strlen(B);
  
  for(int i=0; i<aLen; i++) {
    if(A[i] == B[0] && i+bLen-1 < aLen) {
      bool flag = false;
      for(int j=1; j<bLen; j++) {
        if(A[i+j] != B[j]) {
          flag = true;
          break;
        }
      }
      
      if(!flag) {
        printf("YES\n");
        return 0;
      }
    }
  }
  
  printf("NO\n");
  
  return 0;
}