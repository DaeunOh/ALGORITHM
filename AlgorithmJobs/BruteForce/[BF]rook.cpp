#include <stdio.h>
#include <vector>

int main() {

  //Please Enter Your Code Here
  int arr[18][18];
  int y_king, x_king;
  
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      scanf("%d", &arr[i][j]);
      
      if(arr[i][j] == 1) {
        y_king = i;
        x_king = j;
      }
    }
  }
  
  // 상
  for(int i=y_king+1; i>=0; i--) {
    if(arr[i][x_king] == 3) break;
    else if(arr[i][x_king] == 2) {
      printf("1\n");
      return 0;
    }
  }
  
  // 하
  for(int i=y_king-1; i<8; i++) {
    if(arr[i][x_king] == 3) break;
    else if(arr[i][x_king] == 2) {
      printf("1\n");
      return 0;
    }
  }
  
  // 좌
  for(int j=x_king-1; j>=0; j--) {
    if(arr[y_king][j] == 3) break;
    else if(arr[y_king][j] == 2) {
      printf("1\n");
      return 0;
    }
  }
  
  // 우
  for(int j=x_king+1; j<8; j++) {
    if(arr[y_king][j] == 3) break;
    else if(arr[y_king][j] == 2) {
      printf("1\n");
      return 0;
    }
  }
  
  printf("0\n");
  
  return 0;
}