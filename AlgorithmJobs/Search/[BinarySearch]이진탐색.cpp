#include <stdio.h>

const int MAX = 100010;

int arr[MAX];

void binarySearch(int s, int e, int value) {
  if(s >= e) {
    if(arr[s] == value) {
      printf("YES\n");
    }
    else {
      printf("NO\n");
    }
    
    return;
  }
  else {
    int mid = (s + e) / 2;
    
    if(arr[mid] == value) {
      printf("YES\n");
      return;
    }
    else if(arr[mid] > value) {
      binarySearch(s, mid-1, value);
    }
    else {
      binarySearch(mid+1, e, value);
    }
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  
  for(int i=0; i<q; i++) {
    int num;
    scanf("%d", &num);
    
    binarySearch(0, n-1, num);
  }
  
  return 0;
}