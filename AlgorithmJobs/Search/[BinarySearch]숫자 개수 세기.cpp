#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100010;

int n, q;
int arr[MAX];

int getStartPoint(int value) {
  int start, end; // start: v보다 항상 작은 값 가리킴
                  // end  : v보다 항상 크거나 같은 값 가리킴
  if(arr[0] < value) start = 0;
  else {
    if(arr[0] > value) return -1;
    else return 0;
  }
  
  if(arr[n-1] >= value) end = n-1;
  else return -1;
  
  while(start + 1 < end) { // start와 end가 붙어있지 않다면
    int mid = (start + end) / 2;
    
    if(arr[mid] < value) start = mid;
    else end = mid;
  }
  
  if(arr[end] == value) return end;
  else return -1;
}

int getEndPoint(int value) {
  int start, end; // start : value보다 항상 작거나 같은 값 가리킴
                  // end : value보다 항상 큰 값 가리킴
  if(arr[0] <= value) start = 0; 
  else return -1;
  
  if(arr[n-1] > value) end = n-1;
  else {
    if(arr[n-1] < value) return -1;
    else return n-1;
  }
  
  while(start + 1 < end) {
    int mid = (start + end) / 2;
    
    if(arr[mid] > value) end = mid;
    else start = mid;
  }
  
  if(arr[start] == value) return start;
  else return -1;
}

int main() {
  scanf("%d %d", &n, &q);
  
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  
  sort(arr, arr+n);
  
  for(int i=0; i<q; i++) {
    int num;
    scanf("%d", &num);
    
    int front = getStartPoint(num);
    int rear = getEndPoint(num);
    
    if(front == -1) printf("0\n");
    else printf("%d\n", rear - front + 1);
  }
  
  return 0;
}