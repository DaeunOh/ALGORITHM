#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int p1, p2, p3, p4;
  int count = 0;
  
  scanf("%d %d %d %d", &p1, &p2, &p3, &p4);
  
  count = p1 + p2 + p3 + p4;
  
  if(count == 0) {
    printf("D");
  } else if (count == 1) {
    printf("C");
  } else if (count == 2) {
    printf("B");
  } else if (count == 3) {
    printf("A");
  } else {
    printf("E");
  }

  return 0;
}