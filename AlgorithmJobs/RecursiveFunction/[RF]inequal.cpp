#include <stdio.h>

int k;
char arr[20];
int res[20];
bool checkMax[20] = {0, }, checkMin[20] = {0, };
bool printfMax = false, printMin = false;

void getMax(int index) {
  if(printfMax) return;
  
  if(index > k) {
    for(int i=0; i<index; i++) printf("%d", res[i]);
    printf("\n");
    
    printfMax = true;
  }
  else {
    for(int i=9; i>=0; i--) {
      res[index] = i;
      
      if(checkMax[i] == false) {
        bool flag = false;
        
        if(index == 0) flag = true;
        else {
          if(arr[index-1] == '>') {
            if(res[index-1] > res[index]) flag = true;
          }
          else {
            if(res[index-1] < res[index]) flag = true;
          }
        }
          
        if(flag) {
          checkMax[i] = true;
          getMax(index+1);
          checkMax[i] = false;
        }
      }
    }
  }
}

void getMin(int index) {
  if(printMin) return;
  
  if(index > k) {

    for(int i=0; i<index; i++) printf("%d", res[i]);
    printMin = true;
  }
  else {
    for(int i=0; i<=9; i++) {
      res[index] = i;
      
      if(checkMin[i] == false) {
        bool flag = false;
        
        if(index == 0) flag = true;
        else {
          if(arr[index-1] == '>') {
            if(res[index-1] > res[index]) flag = true;
          }
          else {
            if(res[index-1] < res[index]) flag = true;
          }
        }
        
        if(flag) {
          checkMin[i] = true;
          getMin(index+1);
          checkMin[i] = false;
        }
      }
    }
  }
}

int main() {

  //Please Enter Your Code Here
  scanf("%d", &k);
  for(int i=0; i<k; i++) {
    scanf(" %c", &arr[i]);
  }

  getMax(0);
  getMin(0);
  
  return 0;
}