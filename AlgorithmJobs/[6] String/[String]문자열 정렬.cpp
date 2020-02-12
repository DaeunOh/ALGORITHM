/*

문제
n개의 문자열이 주어질 때, 이 문자열을 사전순으로 빠른 순서대로 정렬하는 프로그램을 작성하시오.  

입력
첫 번째 줄에 문자열의 개수 n이 주어진다 ( 1 ≤ n ≤ 100 ) 
그 후 n개의 줄에 대하여 정렬하고자 하는 문자열이 주어진다 ( 1 ≤ 문자열의 길이 ≤ 100 )  

출력
문자열을 사전순으로 빠른 순서대로 정렬한 결과를 출력한다.

 

예제 입력
9
acid
apple
banana
acquire
cat
crop
crab
power
cat

예제 출력
acid
acquire
apple
banana
cat
cat
crab
crop
power

*/

/*

어떻게 해야할지 방법은 빠르게 떠올렸으나,
strcmp와 strcpy의 사용법이 익숙하지 않았던 점이 가장 큰 문제였다.

함수를 쓰지 않고는 반복문으로 비교하고, 복사하는 과정에서
범위를 어느정도까지 해야하는지 불확실 한 것이 많았기 때문에
제대로 된 구현이 힘들었다. (널문자 고려가 안되기 때문에)

하지만 라이브러리의 함수를 사용한다면
쉽게 풀 수 있는 문제였다.

strcmp(s1, s2) > 0 : s1이 s2보다 크다. 즉, 사전순으로 순서가 s1이 s2보다 뒤이다.
strcmp(s1, s2) == 0 : 두 문자열이 같다.
strcmp(s1, s2) < 0 : s1이 s2보다 작다. 즉, 사전순으로 순서가 s1이 s2보다 앞이다.

strcpy(s1, s2) : s1에 s2를 복사한다.

*/

#include <stdio.h>
#include <string.h>

const int MAX = 100 + 10;

int main() {
  int n;
  char str[MAX][MAX];
  char temp[MAX];
  
  scanf("%d", &n);
  
  for(int i=0; i<n; i++) {
    scanf("%s", str[i]);
  }
  
  for(int i=0; i<n; i++) {
    int idx = i;
    for(int j=i+1; j<n; j++) {
      if(strcmp(str[idx], str[j]) > 0) idx = j;
    }
    
    strcpy(temp, str[i]);
    strcpy(str[i], str[idx]);
    strcpy(str[idx], temp);
  }
  
  for(int i=0; i<n; i++) printf("%s\n", str[i]);
  
  return 0;
}