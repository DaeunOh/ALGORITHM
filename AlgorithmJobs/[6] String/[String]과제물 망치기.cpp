/*

문제
철수는 영희를 괴롭히는 것을 매우 좋아한다. 
오늘도 철수는 영희를 어떻게 괴롭힐지 고민을 하다가, 영희가 최근에 작성하고 있던 문서가 떠올랐다. 
이에 철수는 영희의 문서를 망쳐놓기로 결심한다. 
바로 띄어쓰기를 모두 제거해버리는 것이다. 
영희의 문서를 확인한 철수는, 
띄어쓰기가 너무 많아 직접 모두 제거할 수는 없다는 것을 깨닫고 도움을 요청했다. 
영희의 문서가 주어질 때, 띄어쓰기를 모두 제거하는 프로그램을 작성하시오.


입력
첫째 줄에 영희의 문서가 주어진다. 
영희의 문서는 한 줄 짜리 문자열이며, 문서의 길이는 100,000을 넘지 않는다.  

출력
문자열의 띄어쓰기를 모두 제거한 결과를 출력한다.

예제 입력
Please do not touch anything
예제 출력
Pleasedonottouchanything

*/

/*

fgets로 띄어쓰기를 포함한 문자열을 받고,
이후 문자열 길이만큼 for문을 돌리면서 띄어쓰기인 부분만 제외하고 출력하면 되는 문제이다.

*/

#include <stdio.h>
#include <string.h>

const int MAX = 100000 + 10;

int main() {
  char str[MAX];
  fgets(str, MAX, stdin);
  
  int strLen = strlen(str);
  for(int i=0; i<strLen; i++) {
    if(str[i] == ' ') continue;
    else printf("%c", str[i]);
  }

  return 0;
}