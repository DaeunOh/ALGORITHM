#include <stdio.h>

int getFactorial(int n) {
  if(n == 0) return 1;
  else return getFactorial(n-1) * n;
}

int main() {

  //Please Enter Your Code Here
  int n;
  scanf("%d", &n);
  
  printf("%d", getFactorial(n));

  return 0;
}