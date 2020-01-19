#include <stdio.h>

struct maxMachine {
  int data[100];
  int len = 0;
  
  void insertNumber(int x) {
    data[len++] = x;
  }
  
  void removeNumber(int x) {
    for(int i=0; i<len; i++) {
      if(data[i] == x) {
        for(int j=i; j<len; j++) {
          data[j] = data[j+1];
        }
        
        len--;
        
        return;
      }
    }
  }
  
  int getMax() {
    int myMax = -99999;
    
    for(int i=0; i<len; i++) {
      if(data[i] > myMax) myMax = data[i];
    }
    
    return myMax;
  }
};

int main() {
  // 구조체는 캡슐화를 구현하기 위한 문법
  // 구조체는 타입을 정의하는 것이다.
  
  // maxMachine도 자료구조
  // struct를 이용하여 maxMachine이라는 자료구조를 "정의"
  // maxMachine이라는 자료구조 m1을 "선언"
  
  // maxMachine <- 타입(struct, class-c++)이므로 변수가 아님 m1은 변수(인스턴스, 개체 - 실체가 있는 무언가)
  // maxMachine이라는 struct의 인스턴스 m1
  maxMachine m1;
  
  m1.insertNumber(10);
  m1.insertNumber(20);
  m1.insertNumber(5);
  m1.insertNumber(30);
  
  printf("%d\n", m1.getMax()); // 30

  
  return 0;
}