#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 510;
const int MAXK = 10;

int T;
int N, M, X, Y; // 가로, 세로, 위치
int map[MAX][MAX];

int K;
int rotate[MAXK];

int L;

int score;

int dy[4] = {-1, 1, 0, 0}; // N S W E
int dx[4] = {0, 0, -1, 1};

int moveRobot(char dir, int rotDir, int rotK, int idx) {
  int newIdx, rot;

  if(rotDir == 1) newIdx = idx - rotK;
  else newIdx = idx + rotK;
  
  while(newIdx < 0) {
    newIdx += K;
  }
  
  newIdx = newIdx % K;
    
  rot = rotate[newIdx];
      
  switch(dir) {
    case 'N':
      for(int i=0; i<rot; i++) {
        if(map[Y-1][X] == -1 || Y-1 < 1 || Y-1 > M || X < 1 || X > N) break;
        
        Y--;
        
        score += map[Y][X];
        map[Y][X] = 0;
      }
      break;
    case 'S':
      for(int i=0; i<rot; i++) {
        if(map[Y+1][X] == -1 || Y+1 < 1 || Y+1 > M || X < 1 || X > N) break;
        
        Y++;
        
        score += map[Y][X];
        map[Y][X] = 0;
      }
      break;
    case 'W':
      for(int i=0; i<rot; i++) {
        if(map[Y][X-1] == -1 || Y < 1 || Y > M || X-1 < 1 || X-1 > N) break;
        
        X--;
        
        score += map[Y][X];
        map[Y][X] = 0;
      }
      break;
    case 'E':
      for(int i=0; i<rot; i++) {
        if(map[Y][X+1] == -1 || Y < 1 || Y > M || X+1 < 1 || X+1 > N) break;
        
        X++;
        
        score += map[Y][X];
        map[Y][X] = 0;
      }
      break;
  }
  
  return newIdx;
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    memset(map, 0, sizeof(map));
    memset(rotate, 0, sizeof(rotate));
    score = 0;
    
    scanf("%d %d %d %d", &N, &M, &X, &Y);
    
    for(int i=1; i<=M; i++) {
      for(int j=1; j<=N; j++) {
        scanf("%d", &map[i][j]);
      }
    }
    
    scanf("%d", &K);
    
    for(int i=0; i<K; i++) {
      scanf("%d", &rotate[i]);
    }
    
    scanf("%d", &L);
    
    score += map[Y][X];
    map[Y][X] = 0;
    
    int temp = 0, idx = 0;
    for(int i=0; i<L; i++) {
      char dir;
      int rotDir, rotK;
      scanf(" %c %d %d", &dir, &rotDir, &rotK);
      
      temp = moveRobot(dir, rotDir, rotK, idx);
      idx = temp;
    }
    
    printf("#%d %d %d %d\n", t, score, X, Y);
  }
  
  return 0;
}