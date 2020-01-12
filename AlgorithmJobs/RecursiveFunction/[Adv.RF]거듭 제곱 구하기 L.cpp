#include <stdio.h>

long long power(long long n, long long m) {
  if(m == 0) {
    return 1;
  }
  else {
    if(m % 2 == 0) {
      long long temp = power(n, m/2);
      return (temp * temp) % 10007;
    }
    else {
      long long temp = power(n, m-1);
      return (temp * n) % 10007;
    }
  }
}

int main() {
  
  long long n, m;
  scanf("%lld %lld", &n, &m);
  
  long long ans = power(n, m);
  printf("%lld", ans);
  
  return 0;
}