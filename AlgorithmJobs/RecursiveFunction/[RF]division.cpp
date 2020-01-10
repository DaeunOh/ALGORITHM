#include <stdio.h>

const int MAX = 30;

int n;
int res[30] = {0, };
int cnt = 0;

void getResult(int x, int start) {
  int sum = 0;
  for(int i=0; i<n; i++) {
    sum += res[i];
  }
  
  if(sum >= n) {
    if(sum == n) {
      cnt++;
      
      for(int i=0; i<n; i++) {
        if(res[i] != 0) {
          if(i != 0) printf("+%d", res[i]);
          else printf("%d", res[i]);
        }
        else {
          printf("\n");
          break;
        }
      }
    }
  }
  else if(x < n) {
    for(int i=start; i>=0; i--) {
      int num = i;
      res[x] = i;
      getResult(x+1, i);
      res[x] = 0;
    }
  }
  
  
}

int main() {

  //Please Enter Your Code Here
  scanf("%d", &n);
  
  getResult(0, n-1);
  printf("\n%d", cnt);
  
  return 0;
}