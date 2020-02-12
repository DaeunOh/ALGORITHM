/*

문제
두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력하는 프로그램을 작성하세요.

 

입력
두 정수 n, k가 입력으로 주어진다. ( 0 < n <= 30, 0 <= k < 8 , n >= k )

 

출력
결과를 내림차순으로 출력한다.

 

예제 입력
2 1
예제 출력
10
01
 

예제 입력
2 0
예제 출력
00
 

예제 입력
4 2
예제 출력
1100
1010
1001
0110
0101
0011

*/

/*

초기 cnt는 k로, cnt가 의미하는 것은 나와야 할 남은 1의 개수이다.
그러므로 n자리수가 되었을 때 cnt가 0이 아니라면 원하는 조합이 아니게 된다.

또한 내림차순으로 출력해야하기 때문에 반복문은 1에서 0으로 떨어지게 만들었으며,
1이 나올 수 있는 시점은 cnt가 1이상이 될 때이다.

1이 나오고 나면 다음 함수에는 cnt에서 1을 감소시킨 만큼 보내줘야 한다.

*/

#include <stdio.h>

const int MAX = 30;

int n, k;
int res[MAX] = {0, };

void getResult(int x, int cnt) {
  if(x >= n) {
    if(cnt == 0) {
      for(int i=0; i<n; i++) printf("%d", res[i]);
      printf("\n");
    }
  }
  else {
    for(int i=1; i>=0; i--) {
      if(i == 1 && cnt != 0) {
        res[x] = 1;
        getResult(x+1, cnt-1);
      }
      else if(i == 0) {
        res[x] = 0;
        getResult(x+1, cnt);
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &k);
  
  getResult(0, k);

  return 0;
}