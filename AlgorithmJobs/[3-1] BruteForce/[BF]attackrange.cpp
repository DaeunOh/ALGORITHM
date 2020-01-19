#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int N;
  int X, Y, R;
  
  scanf("%d", &N);
  scanf("%d %d %d", &X, &Y, &R);
  
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      int dist_A = i-X >= 0 ? i-X : X-i;
      int dist_B = j-Y >= 0 ? j-Y : Y-j;
      int dist = dist_A + dist_B;
      
      if(dist <= R) {
        if(dist != 0) printf("%d ", dist);
        else printf("x ");
      }
      else printf("0 ");
    }
    printf("\n");
  }

  return 0;
}