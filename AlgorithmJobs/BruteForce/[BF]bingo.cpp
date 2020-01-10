#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int bingo[10][10] = {0, };
  int idx = 1;
  
  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      scanf("%d", &bingo[i][j]);
    }
  }
  
  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      int num;
      scanf("%d", &num);
      
      // 지우기
      for(int k=0; k<5; k++) {
        for(int p=0; p<5; p++) {
          if(bingo[k][p] == num) {
            bingo[k][p] = 0;
            break;
          }
        }
      }
      
      int cnt = 0;
      
      // 가로
      for(int k=0; k<5; k++) {
        bool flag = false;
        for(int p=0; p<5; p++) {
          if(bingo[k][p] != 0) {
            flag = true;
            break;
          }
        }
        if(flag == false) cnt++;
      }
      
      // 세로
      for(int k=0; k<5; k++) {
        bool flag = false;
        for(int p=0; p<5; p++) {
          if(bingo[p][k] != 0) {
            flag = true;
            break;
          }
        }
        if(flag == false) cnt++;
      }
      
      // 대각선
      if(bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0)
        cnt++;
      if(bingo[0][4] == 0 && bingo[1][3] == 0 && bingo[2][2] == 0 && bingo[3][1] == 0 && bingo[4][0] == 0)
        cnt++;
      
      if(cnt >= 3) {
        printf("%d", idx);
        return 0;
      }
      
      idx++;
    }
  }
  
  
  return 0;
}