#include <stdio.h>

int main() {
  int N;
  int students[1010][15];
  int max = 0;
  int student = 1;
  
  scanf("%d", &N);
  
  for(int i=1; i<=N; i++) {
    for(int j=0; j<5; j++) {
      scanf("%d", &students[i][j]);
    }
  }
  
  for(int i=1; i<=N; i++) {
    int cnt = 0;
    for(int j=1; j<=N; j++) {
      for(int k=0; k<5; k++) {
        if(i != j) {
          if(students[i][k] == students[j][k]) {
            cnt++;
            break;
          }
        }
      }
    }
    
    if(max < cnt) {
      max = cnt;
      student = i;
    }
  }
  
  printf("%d", student);
  
  return 0;
}