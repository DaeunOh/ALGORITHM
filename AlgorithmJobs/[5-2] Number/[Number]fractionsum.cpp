/*

1 <= a, b, c, d <= 30000

&a &b
&c &d

분자 분모

*/

#include <stdio.h>

int getGCD(int a, int b) {
  while(1) {
    int r = a % b;
    
    if(r == 0) return b;
    
    a = b;
    b = r;
  }
}

int main() {
  int a, b, c, d;
  int a2, b2, c2, d2;
  
  scanf("%d %d", &a, &b); // a / b
  scanf("%d %d", &c, &d); // c / d
  
  // b와 d의 최대공약수 구하기
  int GCD_bd = getGCD(b, d);
  
  int LCM_bd = (b / GCD_bd) * (d / GCD_bd) * GCD_bd;
  
  int e = a * (LCM_bd / b) + c * (LCM_bd / d);
  int f = LCM_bd;
  
  // 기약분수 구하기 (1) e와 f의 최대공약수 구하기
  int GCD_ef = getGCD(e, f);
  e /= GCD_ef;
  f /= GCD_ef;
  
  printf("%d %d", e, f);
  
  return 0;
}