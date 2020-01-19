#include <stdio.h>

int main() {
  int arr[10][10];
  for(int i=0; i<10; i++) {
    for(int j=0; j<10; j++) {
      arr[i][j] = 10;
    }
  }
  
  for(int i=1; i<=5; i++) {
    for(int j=1; j<=5; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  
  for(int i=1; i<=5; i++) {
    for(int j=1; j<=5; j++) {
      if(arr[i-1][j] <= arr[i][j] || arr[i+1][j] <= arr[i][j]
          || arr[i][j-1] <= arr[i][j] || arr[i][j+1] <= arr[i][j])
        printf("%d ", arr[i][j]);
      else
        printf("* ");
    }
    printf("\n");
  }
  
  return 0;
}