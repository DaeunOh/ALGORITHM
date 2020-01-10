#include <stdio.h>

const int MAX = 105;

int n, r;
char res[MAX];
bool check[MAX];

void getResult(int x) {
  if(x >= r) printf("%s\n", res);
  else {
    for(int i=0; i<n; i++) {
      char alpha = i + 'a';
      if(check[i] == false) {
        res[x] = alpha;
        check[i] = true;
        
        getResult(x+1);
        
        check[i] = false;
        res[x] = 0;
      }
    }
  }
}

int main() {

  //Please Enter Your Code Here
  scanf("%d %d", &n, &r);
  
  getResult(0);

  return 0;
}