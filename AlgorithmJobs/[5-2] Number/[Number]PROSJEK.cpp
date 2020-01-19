/*

1 <= N <= 100
1 <= B[i] <= 10^9
1 <= A[i] <= 10^9

&N
&B[i] (N개)

수열 A를 이루는 N개의 정수 출력

*/

#include <stdio.h>

const int MAX = 110;

int main() {
  int N;
  int A[MAX] = {0, }, B[MAX] = {0, };
  
  scanf("%d", &N);
  
  for(int i=1; i<=N; i++) {
    scanf("%d", &B[i]);
    B[i] *= i;
  }
  
  for(int i=1; i<=N; i++) {
    if(i == 1) A[i] = B[i];
    else A[i] = B[i] - B[i-1];
  }
  
  for(int i=1; i<=N; i++) printf("%d ", A[i]);
  
  return 0;
}

/*

[1]
1
2
----------------
2

[2]
4
3 2 3 5
----------------
3 1 5 11

*/