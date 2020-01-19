/*

0 <= n <= 45

&n

n번째 피보나치 수

*/

#include <stdio.h>

const int MAX = 55;

int main() {
  int n;
  scanf("%d", &n);
  
  int data[MAX] = {0, };
  for(int i=0; i<=n; i++) {
    if(i == 0 || i == 1) data[i] = i;
    else {
      data[i] = data[i-1] + data[i-2];
    }
  }
  
  printf("%d", data[n]);
  
  return 0;
}

/*

input:
10

output:
55

*/