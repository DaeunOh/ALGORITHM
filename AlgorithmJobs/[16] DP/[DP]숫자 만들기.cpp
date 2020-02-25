/*

문제
숫자 1, 2, 3을 이용하여 숫자 N을 만드는 경우의 수를 출력하는 프로그램을 작성하시오. 
예를 들어, N이 4일 경우에는 다음의 7가지 경우가 존재한다. 
단, 경우의 수가 매우 많을 수 있으므로, 경우의 수를 1,000,007 로 나눈 나머지를 출력한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1

 

입력
첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100,000 )  

출력
1, 2, 3을 이용하여 N을 만들 수 있는 경우의 수를 1,000,007 로 나눈 나머지를 출력한다.  

예제 입력
4
예제 출력
7
 

예제 입력
200
예제 출력
290816

*/

/*

N이 100,000이고, 경우의 수는 계속해서 누적되기 때문에 경우의 수 자체를 출력하기엔 수가 너무 크다.
따라서 최종 출력 값은 1,000,007로 나눈 나머지를 출력하는 것인데,
T[i]에 값을 저장할 때 값 자체를 저장하는게 아니라, 1,000,007로 나눈 나머지를 저장해도
결과적으로는 1,000,007로 나눠야 하기 때문에 동일한 값이 나온다. ㅎㅎ

또한, 여기서는 1, 2, 3이라는 숫자가 고정되어 있지만,
만약 1부터 M까지의 수를 이용하여 숫자 i를 만든다면,
T[i] = T[i-1] + T[i-2] + ... + T[i-M]이 점화식이 되며,
따라서 기저조건을 설정하는 부분에서는 1부터 M까지 설정하면 된다.
###예시###
for(int i=2; i<=M; i++) {
  sum += T[i-1];
  T[i] = sum + 1
}

또한 이후의 값을 계산할 때는 i-M부터 i-1까지 M개의 수를 누적시켜야 하므로
하나의 반복문을 더 추가하여 계산하도록 한다.
###예시###
for(int i=M+1; i<=N; i++) {
  for(int j=i-M; j<=i-1; j++) {
    T[i] += T[j];
  }
}

*/

#include <stdio.h>

const int MAX = 100000 + 10;

int N;
int T[MAX];

int main() {
  scanf("%d", &N);
  
  // T[i] = 1, 2, 3을 이용하여 숫자 i를 만드는 경우의 수
  // T[i] = T[i-3] + T[i-2] + T[i-1];
  
  // 기저조건 설정
  T[1] = 1;
  int sum = 0;
  for(int i=2; i<=3; i++) {
    sum += T[i-1];
    
    T[i] = sum + 1;
  }
  
  for(int i=4; i<=N; i++) T[i] = (T[i-3] + T[i-2] + T[i-1]) % 1000007;
  
  printf("%d\n", T[N]);
  
  return 0;
}