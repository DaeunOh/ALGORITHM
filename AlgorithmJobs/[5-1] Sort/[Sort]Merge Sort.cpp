#include <stdio.h>

const int MAX = 100010;

int n;
int arr[MAX] = {0, };
int res[MAX] = {0, };

void merging(int s1, int e1, int s2, int e2) {
  int idx = 0;
  int p, q;
  p = s1;
  q = s2;
  
  while(p <= e1 && q <= e2) {
    if(arr[p] < arr[q]) {
      res[idx++] = arr[p];
      p++;
    }
    else {
      res[idx++] = arr[q];
      q++;
    }
  }
  
  if(p > e1) {
    for(int i=q; i<=e2; i++) {
      res[idx++] = arr[i];
    }
  }
  else {
    for(int i=p; i<=e1; i++) {
      res[idx++] = arr[i];
    }
  }
  
  for(int i=s1; i<=e2; i++) {
    arr[i] = res[i-s1];
  }
}

void mergeSort(int s, int e) {
  if(s >= e) {
    return;
  }
  else {
    int mid = (s + e) / 2;
    
    mergeSort(s, mid);
    mergeSort(mid+1, e);
    merging(s, mid, mid+1, e);
  }
}

int main() {
  scanf("%d", &n);
  
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  
  mergeSort(0, n-1);
  
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}