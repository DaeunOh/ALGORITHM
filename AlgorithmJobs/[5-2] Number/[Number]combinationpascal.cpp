/*

문제
n명의 사람중 m명을 순서에 상관없이 뽑는 경우의 수를 조합이라고 하며 nCm으로 나타낸다.
이 조합은 파스칼의 삼각형과 아주 밀접한 관련이 있다고 한다.
n과 m이 주어졌을때 nCm의 값을 출력하는 프로그램을 작성하시오.  

입력
첫째 줄에 정수 n, m(0 ≤ m ≤ n ≤ 30)이 들어온다.

출력
첫째 줄에 nCm의 값을 출력한다.

*/

#include <stdio.h>

const int MAX = 40;

int arr[MAX][MAX] = {0, };

int n, m;

int main() {
  scanf("%d %d", &n, &m);
  
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=i; j++) {
      if(j == 0 || j == i) arr[i][j] = 1;
      else {
        arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
      }
      
      if(i == n && j == m) {
        printf("%d", arr[i][j]);
        return 0;
      }
    }
  }
  
  return 0;
}

/*

5 2
-----
10

*/