#include <stdio.h>
#include <vector>
#include <string.h>

int T, N, M; // T: 테스트 케이스 수, N: 세로, M: 가로
int map[12][12];
bool visited[201];
std::vector<int> sums;

void dfs(int i, int j, int sum) {
  visited[map[i][j]] = 1;
  sum += map[i][j];
  
  if(i + 1 < N && !visited[map[i+1][j]]) dfs(i+1, j, sum);
  
  if(j + 1 < M && !visited[map[i][j+1]]) dfs(i, j+1, sum);
  
  visited[map[i][j]] = 0;
  if(i == N-1 && j == M-1) {
    sums.push_back(sum);
  }
}

int main() {

  //Please Enter Your Code Here
  
  int max;
  
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        scanf("%d", &map[i][j]);
      }
    }
    
    printf("#%d ", t);
    dfs(0, 0, 0);
    
    if(!sums.empty()) max = sums[0];
    else max = -1;
    
    for(int i=1; i<sums.size(); i++) {
      if(max < sums[i]) max = sums[i];
    }
    
    printf("%d %d\n", sums.size(), max);
    
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    sums.clear();
  }
  

  return 0;
}