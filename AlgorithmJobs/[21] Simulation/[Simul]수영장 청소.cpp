#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 10;

int N, M;
int map[MAX][MAX] = {0, };

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// 상 우 하 좌                
int d[5][4] = {{1, 0, 0, 0},
               {1, 0, 1, 0},
               {1, 1, 0, 0},
               {1, 1, 0, 1},
               {1, 1, 1, 1}};

vector <int> tap[MAX];

int main() {
  scanf("%d %d", &N, &M);

  vector <int> y, x;
  int tapNum = 0;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      scanf("%d", &map[i][j]);
      
      if(map[i][j] >= 1 && map[i][j] <= 5) {
        for(int k=0; k<4; k++) tap[tapNum].push_back(d[map[i][j]-1][k]);
        
        tapNum++;
        
        y.push_back(i);
        x.push_back(j);
      }
    }
  }
  
  int cnt = 0, max = -987987987;
  for(int t=0; t<tapNum; t++) {
    for(int r=0; r<4; r++) {
      cnt = 0;
      
      int temp = tap[t][0];
      for(int j=3; j>0; j--) {
        int next = (j + 1) % 4;
        tap[t][next] = tap[t][j];
      }
      
      tap[t][1] = temp;
      
      for(int i=0; i<4; i++) {
        if(tap[t][i] == 0) continue;
  
        if(dy[i] != 0) {
          for(int j=1; j<N; j++) {
            int next = y[t]+(dy[i] * j);
            if(map[next][x[t]] == 6 || next < 0 || next > N-1) break;
            else if(map[next][x[t]] == 0) cnt++;
          }
        }
        else {
          for(int j=1; j<M; j++) {
            int next = x[t]+(dx[i] * j);
            if(map[y[t]][next] == 6 || next < 0 || next > M-1) break;
            else if(map[y[t]][next] == 0) cnt++;
          }
        }
      }
      
      if(max < cnt) max = cnt;
    }
  }
  
  printf("%d", max);

  return 0;
}