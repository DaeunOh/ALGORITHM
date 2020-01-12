/*

1 <= N <= 80

&N

길이가 N인 좋은 수열들 중에서 가장 작은 수

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