#include <stdio.h>

int n, m;

struct Queue {
  int data[110];
  int f, r;
  int capacity;
  
  void create(int y) {
    capacity = y;
    f = 0;
    r = 0;
  }
  
  void push(int y) {
    if(r >= n) printf("Overflow\n");
    else data[r++] = y;
  }
  
  void pop() {
    if(r - f <= 0 || f >= n) printf("Underflow\n");
    else data[f++] = 0;
  }
  
  void front() {
    if(r - f <= 0) printf("NULL\n");
    else printf("%d\n", data[f]);
  }
};

int main() {
  scanf("%d %d", &n, &m);
  
  Queue q;
  q.create(n);
  
  for(int i=0; i<m; i++) {
    int num;
    scanf("%d", &num);
    
    switch(num) {
      case 1:
        scanf("%d", &num);
        q.push(num);
        break;
      case 2:
        q.pop();
        break;
      case 3:
        q.front();
        break;
    }
  }

  return 0;
}