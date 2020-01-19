#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  int N;
  int map[110][110] = {0, };
  int answer = 0;
  vector<int> tower_y, tower_x;
  
  scanf("%d", &N);
  
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      scanf("%d", &map[i][j]);
      if(map[i][j] == 2) {
        tower_y.push_back(i);
        tower_x.push_back(j);
      }
    }
  }
  
  for(int i=0; i<tower_y.size(); i++) {
    int y = tower_y[i];
    int x = tower_x[i];
    
    for(int j=1; j<N; j++) {
      if(y-j >= 1 && x-j >= 1) {
        if(map[y-j][x-j] == 1) {
          answer++;
          map[y-j][x-j] = 0;
        }
      }
      
      if(y-j >= 1 && x+j <= N) {
        if(map[y-j][x+j] == 1) {
          answer++;
          map[y-j][x+j] = 0;
        }
      }
      
      if(y+j <= N && x-j >= 1) {
        if(map[y+j][x-j] == 1) {
          answer++;
          map[y+j][x-j] = 0;
        }
      }
      
      if(y+j <= N && x+j <= N) {
        if(map[y+j][x+j] == 1) {
          answer++;
          map[y+j][x+j] = 0;
        }
      }
    }
  }
  
  printf("%d", answer);
  
  return 0;
}