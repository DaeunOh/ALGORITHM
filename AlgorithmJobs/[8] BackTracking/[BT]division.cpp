/*

문제
임의의 자연수는 그보다 작은 자연수들의 합으로 표현될 수 있다. 예를 들어 4의 경우,

4
= 3+1
= 2+2
= 2+1+1
= 1+1+1+1

위와 같은 방법으로 표현 될 수 있다. 이 때 , 숫자의 구성이 같으면서 그 순서만이 다른 경우는 같은 경우로 생각하는데, 예를 들어 다음 세 가지 경우는 모두 같은 경우이다.

2 + 1 + 1, 1 + 2 + 1 , 1 + 1 + 2

자연수 n을 입력 받아 이를 n보다 작은 자연수들의 합으로 나타내는 방법을 모두 출력하는 프로그램을 재귀 호출을 사용하여 작성하시오.

입력
첫 줄에 2 이상 20 이하의 자연수 n이 주어진다.

출력
첫째 줄부터 모든 방법을 한 줄에 하나씩 출력한다. 하나의 식 안에는 큰 숫자가 앞으로 오도록 하고, 전체적으로는 앞의 숫자가 큰 식이 먼저 출력되도록 한다. 숫자와 더하기 사이에는 공백이 없다. 그리고 마지막 줄에는 나누어진 자연수의 개수를 출력한다.

*/

#include <stdio.h>

const int MAX = 30;

int n;
int res[30] = {0, };
int cnt = 0;

void getResult(int x, int start) {
  int sum = 0;
  for(int i=0; i<n; i++) {
    sum += res[i];
  }
  
  if(sum >= n) {
    if(sum == n) {
      cnt++;
      
      for(int i=0; i<n; i++) {
        if(res[i] != 0) {
          if(i != 0) printf("+%d", res[i]);
          else printf("%d", res[i]);
        }
        else {
          printf("\n");
          break;
        }
      }
    }
  }
  else if(x < n) {
    for(int i=start; i>=0; i--) {
      int num = i;
      res[x] = i;
      getResult(x+1, i);
      res[x] = 0;
    }
  }
  
  
}

int main() {

  //Please Enter Your Code Here
  scanf("%d", &n);
  
  getResult(0, n-1);
  printf("\n%d", cnt);
  
  return 0;
}

/*

5
--------------
4+1
3+2
3+1+1
2+2+1
2+1+1+1
1+1+1+1+1
6

*/