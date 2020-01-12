#include <stdio.h>

long long N, K;

long long getOrder(long long x) {
  // 자신이 몇 번째인지 반환하는 함수
  
  long long res = 0;
  
  for(int i=1; i<=N; i++) {
    if(N * i < x) res += N;
    else {
      if(x % i == 0) res += (x / i) - 1;
      else res += (x / i);
    }
  }
  
  return res + 1;
}

int main() {
  scanf("%lld %lld", &N, &K);
  
  long long start = 1, end = N * N + 1;
  
  while(start + 1 < end) {
    long long mid = (start + end) / 2;
    
    long long my_order = getOrder(mid);
    
    if(my_order <= K) start = mid;
    else end = mid;
  }
  
  printf("%lld", start);
  
  return 0;
}