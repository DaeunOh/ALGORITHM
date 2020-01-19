#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int N;
  int arr[111][111] = {0, };
  int s[111] = {0, };
  
  scanf("%d", &N);
  for(int i=1; i<=N; i++) {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    for(int j=y; j<y+h; j++) {
      for(int k=x; k<x+w; k++) arr[j][k] = i;
    }
  }
  
  for(int i=0; i<101; i++) {
    for(int j=0; j<101; j++) {
      int num = arr[i][j];
      s[num]++;
    }
  }
  
  for(int i=1; i<=N; i++) printf("%d\n", s[i]);
  
  return 0;
}