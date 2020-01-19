#include <stdio.h>

int main() {
  int a1, a2, a3;
  
  while(1) {
    scanf("%d %d %d", &a1, &a2, &a3);
    
    if(a1 == 0 && a2 == 0 && a3 == 0) return 0;
    
    // 등차수열인지 확인
    int d1, d2;
    d1 = a2 - a1;
    d2 = a3 - a2;
    
    if(d1 == d2) printf("AP %d\n", a3 + d1);
    else {
      d1 = a2 / a1;
      d2 = a3 / a2;
      
      printf("GP %d\n", a3 * d1);
    }
  }

  return 0;
}