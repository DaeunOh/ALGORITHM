#include <stdio.h>
#include <string.h>

int main() {

  //Please Enter Your Code Here
  int C, R;
  bool map[30][30];
  int arr[30] = {0, };
  
  memset(map, 1, sizeof(map));
  
  scanf("%d %d", &C, &R);
  for(int i=1; i<=R; i++) {
    for(int j=1; j<=C; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  
  // 세로로 스캔하면서 처음 1 나오는 곳 찾고
  // 범위 넘어가는지 확인 후 제일 깊은 곳 찾기
  int X = 0, depth = 0;
  
  for(int i=1; i<=C; i++) {
    for(int j=1; j<=R+1; j++) {
      if(map[j][i] == 1) {
        if(j - 4 < 1) break;
        
        if(depth < j) {
          depth = j;
          X = i;
        }
        
        break;
      }
    }
  }
  
  int Y = 0;
  
  for(int i=1; i<=4; i++) {
    bool flag = false;
    for(int j=1; j<=C; j++) {
      if(j != X) {
        if(map[depth - i][j] == 0) {
          flag = true;
          break;
        }
      }
    }
    
    if(flag == false) Y++;
  }
  
  if(Y == 0) X = 0;

  printf("%d %d", X, Y);

  return 0;
}

