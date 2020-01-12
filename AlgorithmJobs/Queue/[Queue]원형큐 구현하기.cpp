#include <stdio.h>

const int MAX = 110;

struct Queue {
  int data[MAX];
  int f, r;
  int capacity;
  int len;
  
  void create(int y) {
    capacity = y;
    f = 0;
    r = 0;
    len = 0;
  }
  
  void push(int y) {
    if(len >= capacity) printf("Overflow\n");
    else {
      data[r] = y;
      r = (r+1) % MAX;
      len++;
    }
  }
  
  void pop() {
    if(len <= 0) printf("Underflow\n");
    else {
      data[f] = 0;
      f = (f+1) % MAX;
      len--;
    }
  }
  
  void front() {
    if(len <= 0) printf("NULL\n");
    else printf("%d\n", data[f]);
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  Queue q;
  q.create(n);
  
  for(int i=0; i<m; i++) {
    int num;
    scanf("%d", &num);
    
    if(num == 1) {
      scanf("%d", &num);
      q.push(num);
    }
    else if(num == 2) {
      q.pop();
    }
    else if(num == 3) {
      q.front();
    }
  }
  
  return 0;
}