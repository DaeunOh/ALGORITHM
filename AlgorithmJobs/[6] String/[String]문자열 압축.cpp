/*

문제
문자열의 길이가 굉장히 길 경우, 이를 압축하여 짧게 만들어야 할 때가 종종 있다. 
이 문제에서는 문자열이 주어졌을 때, 
같은 알파벳이 연속된 부분 문자열을 압축하여 결과를 출력하는 프로그램을 작성한다. 
예를 들어, 문자열이 AAABBBBBCCCCDDDDEFFF 라고 하자. 
이 문자열을 압축하면, 연속으로 같은 문자가 나오는 부분에, 
그 문자가 몇번 나왔는지를 적어줌으로써 압축한다. 
즉, 이 문자열은 3A5B4C4DE3F 로 압축된다. 
E는 1개밖에 없기 때문에 따로 1을 적어주지 않는다.

 

입력
첫 번째 줄에 압축하고자 하는 문자열이 주어진다. 
문자열의 길이는 1000보다 작다. 문자열에 구성된 알파벳은 대문자다.  

출력
문자열을 압축한 결과를 출력한다.

 

예제 입력
AAABBBBBCCCCDDDDEFFF

예제 출력
3A5B4C4DE3F

*/

/*

같은 문자열이 나왔을 때 압축만 하면 되는 문제이나,
마지막 문자의 경우 프린트를 해주는 경우를 빠뜨려서 답이 제대로 나오지 않았었다.

예를들어, 처음부터 끝까지 같은 문자가 나오는 경우에는
반복문에서 다를 경우 프린트해주는 영역에 들어가지 않는다.

따라서 반복문을 다 돈 후에 따로 조건문으로 프린트문을 처리해줘야 한다.

*/

#include <stdio.h>
#include <string.h>

const int MAX = 1000 + 10;

int main() {
  char str[MAX];
  scanf("%s", str);
  
  int strLen = strlen(str);
  int cnt = 1;
  for(int i=0; i<strLen-1; i++) {
    if(str[i] == str[i+1]) {
      cnt++;
    }
    else {
      if(cnt != 1) printf("%d%c", cnt, str[i]);
      else printf("%c", str[i]);
      
      cnt = 1;
    }
  }
  
  if(cnt != 1) printf("%d%c", cnt, str[strLen-1]);
  else printf("%c", str[strLen-1]);
  
  return 0;
}