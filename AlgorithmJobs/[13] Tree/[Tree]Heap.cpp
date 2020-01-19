#include <stdio.h>

const int MAX = 100;

struct PriorityQueue {
  int data[MAX];
  int len = 1; // 원소의 맨 끝을 가리킴
  
  void push(int x) {
    data[len++] = x; // 마지막에 넣어줌
    
    int idx = len-1;
    
    while(idx > 1) { // root가 아니면
      if(data[idx] < data[idx/2]) {
        int temp = data[idx];
        data[idx] = data[idx/2];
        data[idx/2] = temp;
      }
      else break;
      
      idx = idx / 2;
    }
   
  }
  
  void pop() {
    data[1] = data[len-1];
    data[len-1] = 0;
    len--;
    
    int idx = 1;
    while(1) {
      int pIdx = -1; // 우선순위가 높은 친구의 노드 번호
      
      if(len <= idx*2) {
        // 자식이 모두 없는 경우
        break;
      }
      else if((1 <= idx*2 && idx*2 < len) && len <= idx*2+1) {
        // 왼쪽 자식은 존재하고, 오른쪽 자식은 존재하지 않는 경우
        pIdx = idx*2;
      }
      else {
        // 자식이 모두 존재하는 경우
        if(data[idx*2] < data[idx*2+1]) pIdx = idx*2;
        else pIdx = idx*2+1;
      }
      
      if(data[idx] > data[pIdx]) {
        int temp = data[idx];
        data[idx] = data[pIdx];
        data[pIdx] = temp;
        
        idx = pIdx;
      }
      else {
        break;
      }
    }
  }
  
  int top() {
    return data[1];
  }
};

int main() {
  PriorityQueue myPQ;
  
  myPQ.push(3);
  myPQ.push(1);
  myPQ.push(2);
  
  printf("%d\n", myPQ.top());
  myPQ.pop();
  
  printf("%d\n", myPQ.top());
  myPQ.pop();
  
  printf("%d\n", myPQ.top());
  myPQ.pop();
  
  
  
  return 0;
}