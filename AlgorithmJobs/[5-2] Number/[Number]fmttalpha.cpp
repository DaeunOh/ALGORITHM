#include <stdio.h>

int main() {
  long long x, y;
  scanf("%lld %lld", &x, &y);
  
  long long gap = y-x;
  
  long long n = 1;
  long long ans = 0;
  while(1) {
    if(n * n < gap) {
      n++;
    }
    else {
      ans += (n * 2) - 1;
      long long temp = gap - (n * n);
      
      ans += temp / n;
      break;
    }
  }
  
  printf("%d", ans);
  
  return 0;
}