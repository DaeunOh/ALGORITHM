#include <stdio.h>

struct Stack {
  int arr[110];
  int len = 0;
  int capacity = 0;
  
  void create(int y) {
    capacity = y;
  }
  
  void push(int y) {
    if(len >= capacity) printf("Overflow\n");
    else arr[len++] = y;
  }
  
  void pop() {
    if(len <= 0) printf("Underflow\n");
    else {
      arr[len-1] = 0;
      len--;
    }
  }
  
  int top() {
    if(len <= 0) printf("NULL\n");
    else printf("%d\n", arr[len-1]);
  }
};

int main() {

  //Please Enter Your Code Here
  int n, m;
  scanf("%d %d", &n, &m);
  
  Stack s;
  s.create(n);
  
  for(int i=0; i<m; i++) {
    int num, y;
    scanf("%d", &num);
    
    switch(num) {
      case 1:
        scanf("%d", &y);
        s.push(y);
        break;
      case 2:
        s.pop();
        break;
      case 3:
        s.top();
        break;
    }
  }

  return 0;
}