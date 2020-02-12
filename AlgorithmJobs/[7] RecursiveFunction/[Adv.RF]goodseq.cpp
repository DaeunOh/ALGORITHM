/*

문제
숫자 1, 2, 3으로만 이루어지는 수열이 있다. 
임의의 길이의 인접한 두 개의 부분 수열이 동일한 것 이 있으면, 
그 수열을 나쁜 수열이라고 부른다. 
그렇지 않은 수열은 좋은 수열이다.

다음은 나쁜 수열의 예이다.
33
32121323
123123213

다음은 좋은 수열의 예이다.
2
32
32123
1232123

길이가 N인 좋은 수열들을 N자리의 정수로 보아 
그중 가장 작은 수를 나타내는 수열을 구하는 프로그램 을 작성하라. 
예를 들면, 1213121과 2123212는 모두 좋은 수열이지만 그 중에서 작은 수를 나타내는 수 열 1213121이다.

 

입력
입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다.

출력
첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 
가장 작은 수를 나타내 는 수열만 출력한다. 
수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다.

 

예제 입력
7
예제 출력
1213121

*/

#include <stdio.h>

const int MAX = 90;

int N;
int data[MAX];
bool isFinished = false;

bool check(int x, int length) {
  for(int i=0; i<length; i++) {
    if(data[x-i] != data[x-i-length]) return true;
  }
  
  return false;
}

void getResult(int x) {
  if(isFinished) return;
  
  if(x >= N) {
    for(int i=0; i<N; i++) printf("%d", data[i]);
    printf("\n");
    
    isFinished = true;
    return;
  }
  else {
    for(int i=1; i<=3; i++) {
      data[x] = i;
      
      bool flag = false;
      
      for(int j=1; j<=(x+1)/2; j++) {
        if(!check(x, j)) { // i를 사용할 수 없음
          flag = true;
          break;
        }
      }
      
      if(!flag) getResult(x+1);
    }
  }
}

int main(){
  scanf("%d", &N);
  
  getResult(0);
  
  return 0;
}

/*

input:
7

output:
1213121

*/