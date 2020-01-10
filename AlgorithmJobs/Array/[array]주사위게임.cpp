#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int N;
  int money = 0, max = 0;
  
  scanf("%d", &N);
  
  for(int i=0; i<N; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    if(a == b && b == c) money = 10000 + a * 1000;
    else if(a == b || a == c) money = 1000 + a * 100;
    else if(b == c) money = 1000 + b * 100;
    else {
      if(a > b && a > c) money = a * 100;
      else if(b > a && b > c) money = b * 100;
      else if(c > a && c > b) money = c * 100;
    }
    
    if(max < money) max = money;
  }
  
  printf("%d", max);

  return 0;
}