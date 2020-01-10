#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int N, K;
  int arr[100010] = {0, };
  
  scanf("%d %d", &N, &K);
  for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
  
  for(int i=1; i<=K; i++) {
    for(int j=i+1; j<=N; j++) {
      if(arr[i] < arr[j]) {
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  
  printf("%d", arr[K]);
  
  return 0;
}