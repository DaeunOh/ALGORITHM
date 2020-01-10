#include <stdio.h>

int main() {
  int N;
  int arr[1010];
  
  scanf("%d", &N);
  
  if(N < 6) {
    printf("NO\n");
    return 0;
  }
  
  for(int i=0; i<N; i++) {
    int temp;
    scanf("%d", &temp);
    
    arr[temp]++;
  }
  
  int cnt = 0;
  
  for(int i=1; i<=N; i++) {
    if(arr[i] >=2) cnt += 2;
    else cnt += arr[i];
  }
  
  if(cnt >=6) printf("YES\n");
  else printf("NO\n");
  
  return 0;
}