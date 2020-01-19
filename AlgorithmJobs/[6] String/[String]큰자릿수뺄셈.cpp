/*

문제
두 자연수가 주어질 때 그들의 뺄셈을 계산하는 프로그램을 작성하시오. 각 수는 1 이상 10의 100승 미만의 범위를 가진다.

입력
첫 번째 줄과 두 번째 줄에 각각 하나의 자연수가 주어진다.

출력
첫 번째 줄에 뺄셈의 결과를 출력한다.

*/

#include <stdio.h>
#include <string.h>

int main() {

  //Please Enter Your Code Here
  char temp[111];
  int A[111] = {0, }, B[111] = {0, }, C[111] = {0, };
  int big[111] = {0, }, small[111] = {0, };
  
  scanf("%s", temp);
  int len_A = strlen(temp);
  for(int i=0; i<len_A; i++) A[110-len_A+i+1] = temp[i] - '0';
  
  scanf("%s", temp);
  int len_B = strlen(temp);
  for(int i=0; i<len_B; i++) B[110-len_B+i+1] = temp[i] - '0';
  
  int compare = -1;
  if(len_A > len_B) compare = 0;
  else if(len_A < len_B) compare = 1;
  else {
    for(int i=0; i<111; i++) {
      if(A[i] > B[i]) {
        compare = 0;
        break;
      }
      else if(A[i] < B[i]) {
        compare = 1;
        break;
      }
    }
  }

  int flag = false;
  
  if(compare == 0) {
    for(int i=0; i<111; i++) big[i] = A[i];
    for(int i=0; i<111; i++) small[i] = B[i];
    int len_big = len_A;
    int len_small = len_B;
  }
  else if(compare == 1) {
    for(int i=0; i<111; i++) big[i] = B[i];
    for(int i=0; i<111; i++) small[i] = A[i];
    int len_big = len_B;
    int len_small = len_A;
    
    flag = true;
  }
  else {
    printf("0\n");
    return 0;
  }
  
  for(int i=110; i>=0; i--) {
    int num = big[i] - small[i];
    if(num < 0) {
      big[i-1]--;
      num += 10;
    }
    
    C[i] = num;
  }
  
  if(flag) printf("-");
  
  for(int i=0; i<111; i++) {
    if(C[i] != 0) {
      for(int j=i; j<111; j++) {
        printf("%d", C[j]);
      }
      return 0;
    }
  }
  
  return 0;
}

/*

1962831868293922
2528838232
----------
1962829339455690

18592918185
2195812983912895799129
----------
-2195812983894302880944

*/