/*

1 <= X, Y <= n <= 1000
root는 노드 0

&n &X &Y
&a &b(n-1개)


*/

#include <stdio.h>

const int MAX = 1010;

int n, X, Y;
int tree[MAX] = {0, };
bool parents[MAX] = {0, };

int main() {
  scanf("%d %d %d", &n, &X, &Y);
  
  for(int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    tree[b] = a;
  }
  
  while(1) {
    parents[X] = true;
    
    if(X == 0) break;
    
    X = tree[X];
  }
  
  while(1) {
    if(parents[Y] == true) {
      printf("%d", Y);
      return 0;
    }
    
    parents[Y] = true;
    Y = tree[Y];
  }

  return 0;
}