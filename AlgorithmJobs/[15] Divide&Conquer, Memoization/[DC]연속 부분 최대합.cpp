/*

문제
N개의 정수가 주어질 때, 연속된 부분을 선택하여 합을 최대화 하는 프로그램을 작성하시오. 
예를 들어, 아래와 같이 8개의 숫자가 있을 경우, 색칠된 부분을 선택했을 때 그 합이 가장 최대가 된다.
<그림>

 

입력
첫 번째 줄에 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 두 번째 줄에 n개의 정수가 주어진다.

출력
연속된 부분을 선택하였을 때의 최댓값을 출력한다.

 

예제 입력
8
2 3 -5 8 -3 4 2 -9
예제 출력
11 

예제 입력
5
-1 -2 3 -2 4
예제 출력
5

*/

#include <cstdio>

using namespace std;

const int MAX = 100;

int n;
int data[MAX];

int getSubMax(int start, int end) {
  // data의 start부터 end까지 구간 중 연속 부분 최대합을 반환하는 함수
  
  if(start >= end) return data[start];
  
  int mid = (start + end) / 2;
  
  int left = getSubMax(start, mid);
  int right = getSubMax(mid+1, end);
  
  // 중간부분을 포함하는 연속부분 중 최대합을 구하자.
  int leftSum = 0, leftMax = -987987987;
  for(int i = mid; i>=start; i--) {
    leftSum = leftSum + data[i];
    
    if(leftMax < leftSum) leftMax = leftSum;
  }
  
  int rightSum = 0, rightMax = -987987987;
  for(int i = mid+1; i<=end; i++) {
    rightSum = rightSum + data[i];
    
    if(rightMax < rightSum) rightMax = rightSum;
  }
  
  int myMax = leftMax + rightMax;
  
  if(left >= right && left >= myMax) return left;
  else if(right >= left && right >= myMax) return right;
  else return myMax;
  
  
}

int main() {
  scanf("%d", &n);
  
  for(int i=0; i<n; i++) {
    scanf("%d", &data[i]);
  }
  
  printf("%d\n", getSubMax(0, n-1));
  
  
  return 0;
}

/*

8
1 2 -5 3 7 -2 3 -9

*/