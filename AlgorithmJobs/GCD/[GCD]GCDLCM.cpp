#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int a, b;
  int A, B;
  int GCD, LCM;
  scanf("%d %d", &a, &b);
  
  A = a;
  B = b;
  
  while(1) {
    int r = a % b;
    
    if(r == 0) {
      GCD = b;
      break;
    }
    
    a = b;
    b = r;
  }
  
  LCM = (A/GCD) *(B/GCD) * GCD;
  
  printf("%d\n%d", GCD, LCM);
  
  return 0;
}