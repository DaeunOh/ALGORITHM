#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int A[20] = {0, }, B[20] = {0, };
  int cnt_A = 0, cnt_B = 0;
  
  for(int i=0; i<10; i++) scanf("%d", &A[i]);
  for(int i=0; i<10; i++) scanf("%d", &B[i]);
  
  for(int i=0; i<10; i++) {
    if(A[i] > B[i]) cnt_A++;
    else if(A[i] < B[i]) cnt_B++;
  }
  
  if(cnt_A > cnt_B) printf("A\n");
  else if(cnt_A < cnt_B) printf("B\n");
  else printf("D\n");
  
  return 0;
}