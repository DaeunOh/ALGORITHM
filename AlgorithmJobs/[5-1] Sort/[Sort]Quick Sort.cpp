#include <stdio.h>

int getLeft(int arr[], int start, int end, int pivot, int result[]) {
  // arr의 start부터 end까지 숫자들 중에서
  // pivot보다 작거나 같은 값을 result에 채우는 함수
  // 또한, 작거나 같은 원소의 개수를 반환.
  
  int idx = 0;
  for(int i=start; i<=end; i++) {
    if(arr[i] <= pivot) {
      result[idx++] = arr[i];
    }
  }
  
  return idx;
}

int getRight(int arr[], int start, int end, int pivot, int result[]) {
  // arr의 start부터 end까지 숫자들 중에서
  // pivot보다 큰 값을 result에 채우는 함수
  // 또한, 큰 원소의 개수를 반환.
  
  int idx = 0;
  for(int i=start; i<=end; i++) {
    if(arr[i] > pivot) {
      result[idx++] = arr[i];
    }
  }
  
  return idx;
}

void quickSort(int arr[], int start, int end) {
  // arr을 start부터 end까지 퀵정렬하는 함수
  
  if(start >= end) {
    return;
  }
  else {
    int pivot = arr[start];
    int left[100], right[100];
    
    int left_cnt = getLeft(arr, start+1, end, pivot, left);
    int right_cnt = getRight(arr, start+1, end, pivot, right);
    
    for(int i=0; i<left_cnt; i++) {
      arr[start+i] = left[i];
    }
    
    arr[start+left_cnt] = pivot;
    
    for(int i=0; i<right_cnt; i++) {
      arr[start+left_cnt+1+i] = right[i];
    }
    
    quickSort(arr, start, left_cnt-1);
    quickSort(arr, start+left_cnt+1, end);
  }
  
}

int main() {

  //Please Enter Your Code Here
  int n;
  int arr[100];
  
  scanf("%d", &n);
  
  for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    
  quickSort(arr, 0, n-1);
  
  for(int i=0; i<n; i++) printf("%d ", arr[i]);

  return 0;
}