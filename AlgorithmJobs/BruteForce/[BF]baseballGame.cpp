#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int N;
  int arr[110][3] = {0, };
  int ans = 0;
  
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

  for(int i=1; i<=9; i++) {
    for(int j=1; j<=9; j++) {
      for(int k=1; k<=9; k++) {
        if(i != j && j != k && k != i) {
          int flag = false;
          
          for(int p=0; p<N; p++) {
            int s = 0;
            int b = 0;
            
            int first = arr[p][0] / 100;
            int second = arr[p][0] % 100 / 10;
            int third = arr[p][0] % 10;
            
            if(first == i) s++;
            if(second == j) s++;
            if(third == k) s++;
            
            if(first == j || first == k) b++;
            if(second == i || second == k) b++;
            if(third == i || third == j) b++;
            
            if(s != arr[p][1] || b != arr[p][2]) {
              flag = true;
              break;
            }
          }
          
          if(flag == false) ans++;
        }
      }
    }
  }
  
  printf("%d", ans);
  
  return 0;
}