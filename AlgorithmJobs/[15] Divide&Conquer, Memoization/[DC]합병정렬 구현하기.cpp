/*

문제
n개의 정수가 주어질 때, 이를 합병정렬을 이용하여 오름차순으로 정렬하는 프로그램을 작성하시오.

 

입력
첫 번째 줄에 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 
두번째 줄에 n개의 정수가 주어진다.  

출력
첫 번째 줄에 n개의 숫자를 합병정렬을 이용하여 오름차순으로 정렬한 결과를 출력한다.

 

예제 입력
10
2 5 3 4 8 7 -1 9 10 2
예제 출력
-1 2 2 3 4 5 7 8 9 10

*/

/*

합병정렬을 오랜만에 구현하다보니 헷갈리는 부분이 많이 존재했다.

mergeSort 함수의 기저조건을 설정하는 부분에서, 아무런 행동도 하지 않고 "return"만 한다는 점이
그동안의 코딩과 다르게 매우 생소했기에, 설마 하는 생각이 들었다.
하지만, 재귀함수를 끝내기 위해서는 기저조건 부분에서 아무것도 하지 않아도 return하는 것은 필수이다.

또한, merge를 하는 부분에서도 처음에는 변수의 개수를 줄이기 위해
p와 q에 s1, s2를 저장하지 않고 s1과 s2 그대로를 사용했다.
하지만, 마지막에 s1부터 e2까지 반복문을 돌리는 부분이 있으므로 s1이 바뀌면 그 반복문의 범위도 바뀌게 된다.
따라서 p와 q에 따로 s1과 s2를 저장하고 증가시킬 때는 p, q를 사용해야 한다!

*/

#include <stdio.h>

const int MAX = 100000 + 10;

int n;
int num[MAX];

void merging(int s1, int e1, int s2, int e2) {
  int temp[MAX];
  int idx = 0;
  int p = s1, q = s2; // 마지막에 s1부터 e2까지 반복문을 돌리는 부분이 있으므로 s1이 바뀌면 안된다.
  
  while(p <= e1 && q <= e2) {
    if(num[p] < num[q]) temp[idx++] = num[p++];
    else temp[idx++] = num[q++];
  }
  
  if(p > e1) {
    for(int i=q; i<=e2; i++) temp[idx++] = num[i];
  }
  else {
    for(int i=p; i<=e1; i++) temp[idx++] = num[i];
  }
  
  for(int i=s1; i<=e2; i++) num[i] = temp[i-s1];
}

void mergeSort(int start, int end) {
  if(start >= end) {
    // 하나의 숫자는 정렬이 된 수이므로 함수를 종료한다.
    return;
  }
  else {
    int mid = (start + end) / 2;
    
    mergeSort(start, mid);
    mergeSort(mid+1, end);
    
    // start부터 mid까지의 수와 mid+1부터 end까지의 수를 합병시킨다.
    merging(start, mid, mid+1, end);
  }
}

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &num[i]);
  
  mergeSort(0, n-1);
  
  for(int i=0; i<n; i++) printf("%d ", num[i]);
  
  return 0;
}