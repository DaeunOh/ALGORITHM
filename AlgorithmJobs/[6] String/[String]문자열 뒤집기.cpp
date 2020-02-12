/*

문제
문자열이 주어질 때, 이를 뒤집어서 출력하는 프로그램을 작성하시오.  

입력
첫 번째 줄에 문자열이 주어진다. ( 1 ≤ 문자열의 길이 ≤ 1,000 )  

출력
문자열을 뒤집은 결과를 출력한다.


예제 입력
Hello World!
예제 출력
!dlroW olleH

*/

/*

fgets로 띄어쓰기를 포함한 문자열을 받고,
이후 문자열 길이만큼 for문을 돌리면서 끝에서부터 출력하면 된다.

*/

#include <stdio.h>
#include <string.h>

const int MAX = 1000 + 10;

int main() {
  char str[MAX];
  fgets(str, MAX, stdin);
  
  int strLen = strlen(str);
  
  for(int i=strLen-1; i>=0; i--) printf("%c", str[i]);
  
  return 0;
}