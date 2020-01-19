/*

문제
서로 다른 n개의 원소들 중에서 r개만을 뽑아 일렬로 나열하는 것을 순열이라 한다. 예를 들어, 3개의 원소 a, b, c 중에서 2개만을 뽑아 나열하면 ab, ac, ba, bc, ca, cb 의 6가지 경우가 있다. n과 r이 주어질 때, n개의 소문자 중에서 r개만을 뽑아 나열하는 모든 경우를 출력하는 프로그램을 작성하시오. 단, a부터 시작하여 연속으로 n개의 알파벳을 갖고 있다고 하자.

입력
첫 번째 줄에 n과 r이 주어진다. ( 1 ≤ n ≤ 10, 0 ≤ r ≤ min(n, 7) )

출력
각 줄에 n개의 소문자 중에서 r개만을 뽑아 나열하는 경우를 사전순으로 나열한 결과를 출력한다.

*/

#include <stdio.h>

const int MAX = 105;

int n, r;
char res[MAX];
bool check[MAX];

void getResult(int x) {
  if(x >= r) printf("%s\n", res);
  else {
    for(int i=0; i<n; i++) {
      char alpha = i + 'a';
      if(check[i] == false) {
        res[x] = alpha;
        check[i] = true;
        
        getResult(x+1);
        
        check[i] = false;
        res[x] = 0;
      }
    }
  }
}

int main() {

  //Please Enter Your Code Here
  scanf("%d %d", &n, &r);
  
  getResult(0);

  return 0;
}

/*

4 2
----
ab
ac
ad
ba
bc
bd
ca
cb
cd
da
db
dc

*/