/*

문제
문자열이 주어질 때, 이것이 팰린드롬인지 조사하는 프로그램을 작성하시오. 
팰린드롬이란, 앞으로 읽을 때와 뒤로 읽을 때의 결과가 같은 문자열을 말한다.  

입력
첫 번째 줄에 문자열이 주어진다. ( 1 ≤ 문자열의 길이 ≤ 1,000 )  

출력
입력된 문자열이 팰린드롬이면 YES, 아니면 NO를 출력한다.


예제 입력
abcba
예제 출력
YES

*/

/*

중간을 기준으로, 양쪽의 문자를 비교해서 다른게 있으면 그 즉시 NO를 출력하고 return한다.
만약 모두 같다면(반복문을 무사히 빠져 나온다면) YES를 출력한다.

*/

#include <stdio.h>
#include <string.h>

const int MAX = 1000 + 10;

int main() {
  char str[MAX];
  fgets(str, MAX, stdin);
  
  int strLen = strlen(str);
  
  for(int i=0; i<strLen/2; i++) {
    if(str[i] != str[strLen-i-1]) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");

  return 0;
}