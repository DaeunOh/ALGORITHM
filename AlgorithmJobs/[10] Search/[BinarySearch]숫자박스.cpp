/*

문제
숫자박스에는 자연수들이 적혀있는 종이들이 N장 들어있다. 
숫자 M개가 주어졌을 때, 이 숫자가 적혀있는 숫자가 상자 안에 있는지 아닌지를 구하는 프로그램을 작성하시오.  

입력
첫째 줄에 윤성이가 가지고 있는 숫자 정보의 개수 N (1 ≤ N ≤ 300,000)이가 주어진다. 
둘째 줄에는 숫자 정보들이 주어진다. 
숫자는 절댓값 1,000,000 이하의 정수이다. 
두 숫자 카드에 같은 숫자가 적혀있는 경우는 없다.

셋째 줄에는 M (1 ≤ M ≤ 500,000)이 주어진다. 
넷째 줄에는 윤성이가 숫자 박스에 있는지 아닌지를 구해야 할 M개의 숫자가 주어지며, 
이 숫자는 공백으로 구분되어져 있다. 
이 숫자도 1,000,000이하의 정수이다.  

출력
첫째 줄에 입력으로 주어진 M개의 숫자에 대해서, 
각 숫자가 숫자 상자안에 있으면 1, 아니면 0을 개행으로 구분해 출력한다.

 

예제 입력
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10
예제 출력
1
0
0
1
1
0
0
1

*/

/*

주어진 숫자의 개수가 많고, 찾아야 할 숫자 또한 많기 때문에
숫자를 찾기 위해 처음부터 끝까지 확인하는 것보다
시간이 조금 걸려도 "미리" 정렬 해놓고, 이분 탐색으로 찾아나가는 것이 좋다.

*/

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 300000 + 10;
const int MAXM = 500000 + 10;

int N;
int nBox[MAXN] = {0, };

int M;

void getResult(int value, int start, int end) {
  // start부터 end 범위의 수 중 value가 있으면 1을 출력하고, 없으면 0을 출력하는 함수
  if(start >= end) {
    // start == end인 경우(범위 내의 수가 1개인 경우)
    if(nBox[start] == value) printf("1\n");
    else printf("0\n");
  }
  else {
    int mid = (start + end) / 2;
    
    if(nBox[mid] == value) printf("1\n");
    else if(nBox[mid] > value) getResult(value, start, mid-1);
    else getResult(value, mid+1, end);
  }
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &nBox[i]);
  
  sort(nBox, nBox + N);
  
  scanf("%d", &M);
  for(int i=0; i<M; i++) {
    int v;
    scanf("%d", &v);
    
    getResult(v, 0, N-1);
  }

  return 0;
}