/*

문제
알랩이는 구구단표처럼 NN단표를 만들었다고 한다.
NN단표는 2차원 배열의 모양으로 곱셈 1단부터 N단까지의 값들을 적어놓은 형태이다.
NN단표의 배열을 A라고 했을 때, 배열의 들어가는 수 Ai=i*j이다.(즉, 4행 7열에는 28, 7행 5열에는 35가 들어가 있다.)
알랩이는 N단까지 나온 숫자들 중에서 K번째로 작은 수를 찾고 싶어한다.
이때, 중복되는 여러 수들을 고려한다. 즉 N*N개의 모든 수들 중에서 K번째 수를 구하는 것이다.

입력
첫째 줄에 배열의 크기 N이 주어진다. N은 100,000보다 작거나 같은 자연수이다. 둘째 줄에 K가 주어진다. K는 N*N보다 작거나 같은 자연수이다.

출력
K번째 원소를 출력한다.

*/

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

/*

3
7
---
6

*/