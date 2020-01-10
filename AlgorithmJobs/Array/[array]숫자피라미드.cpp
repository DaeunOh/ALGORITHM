#include <stdio.h>

int main() {
  int N, S;
  scanf("%d %d", &N, &S);
  
  int space = N-1, number = 1;
  int prev_first, prev_last;
  
  for(int i=1; i<=N; i++) {
    for(int j=0; j<space; j++) printf(" ");
    space--;
    
    if(i % 2 == 0) {
      int cur_first = prev_first + 1;
      if(cur_first >= 10) cur_first = 1;
      
      for(int i=0; i<number; i++) {
        printf("%d", cur_first);
        prev_last = cur_first;
        cur_first++;
        if(cur_first >= 10) cur_first = 1;
      }
    }
    else {
      int cur_first;
      if(i == 1) cur_first = S;
      else {
        cur_first = prev_last;
        for(int i=0; i<number; i++) {
          cur_first++;
          if(cur_first >= 10) cur_first = 1;
        }
      }
      
      prev_first = cur_first;
      
      for(int i=0; i<number; i++) {
        printf("%d", cur_first);
        cur_first--;
        if(cur_first <= 0) cur_first = 9;
      }
    }
    
    number += 2;
    printf("\n");
  }
  
  return 0;
}