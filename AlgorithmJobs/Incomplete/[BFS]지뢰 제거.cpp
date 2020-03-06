/*

시간제한 1초

문제
N x M의 크기의 지도에 지뢰가 매설되어 있다. 
지뢰는 1 x 1 크기를 차지하며, 아래와 같이 3가지 종류의 지뢰가 존재한다. 
초기에는 지뢰가 매설되어 있기만 한 상태로 존재한다.

missile

각 지뢰에는 번호가 적혀 있으며, 각 지뢰는 위의 그림과 같이 폭발한다. 
색칠된 부분은 지뢰 폭발의 영향을 받는 부분이며, 이 부분은 그 잔해로 인해 땅이 새까맣게 타버린다. 
만약 색칠된 부분에 지뢰가 있을 경우, 그 지뢰 또한 폭발하게 된다. 
이제 이 지도에 2발의 미사일을 쏘려 한다. 
한 개의 미사일은 1 x 1 크기의 칸 한 개를 정확하게 폭발시켜 새까맣게 태울 수 있으며, 
만약 해당 칸에 지뢰가 있을 경우 그 지뢰는 폭발하게 된다. 
2발의 미사일을 쏘아 최대한 지도 위의 많은 칸을 새까맣게 태우고 싶다고 할 때, 
(1) 그 새까맣게 태울 수 있는 칸의 최댓값과 
(2) 해당 최댓값을 얻을 수 있도록 미사일을 발사할 수 있는 서로 다른 모든 경우의 수를 출력하는 프로그램을 작성하시오.

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. (1 ≤ T ≤ 10) 
이후 각각의 테스트 케이스가 주어진다. 
각 테스트케이스의 첫 번째 줄에는 지도의 세로 길이 N과 가로 길이 M이 주어진다. (1 ≤ N, M ≤ 15) 
이후 N개의 줄에 대하여 지도의 정보가 주어진다. 
각 줄은 M개의 숫자로 이루어져 있으며, 
0은 지뢰 없음, 1은 1번 지뢰, 2는 2번 지뢰, 3은 3번 지뢰가 해당 칸에 존재함을 나타낸다.

출력
각 테스트케이스 별로 2발의 미사일을 쏘아 새까맣게 태울 수 있는 칸의 갯수의 최댓값을 출력한다. 
각 줄의 첫 번째 숫자는 테스트케이스의 번호이며, 
두 번째 숫자는 칸의 갯수의 최댓값, 
세 번째 숫자는 해당 최댓값을 얻을 수 있도록 미사일을 발사 할 수 있는 서로 다른 모든 경우의 수이다.

예제 입력
3
3 3
0 0 3
0 1 0
0 0 0
5 5
1 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 0 0 0 1
7 7
2 0 0 1 0 0 0
0 0 0 1 0 3 0
0 0 0 0 0 0 0
0 0 0 2 0 1 1
0 0 0 0 0 0 0
1 1 0 0 0 0 0
1 1 0 0 0 0 2
예제 출력
1 9 1
2 6 6
3 28 4

*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXNM = 15 + 10;
const int MAXB = 300;

int T;
int N, M;
int map[MAXNM][MAXNM];
int visited[MAXNM][MAXNM];
int visitedCopy[MAXNM][MAXNM];

int B[MAXB];

vector<pair<int, int>> v;
vector<pair<int, int>> r[4];

int myMax;

int bomb(int y, int x, int s) {
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      visitedCopy[i][j] = visited[i][j];
    }
  }
  
  queue<pair<int, int>> q;
  int cnt = 1;
  visited[y][x] = s;
  q.push(make_pair(y, x));
  
  while(!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    
    int idx = map[front.first][front.second];
    for(int i=0; i<r[idx].size(); i++) {
      int nextY = front.first + r[idx][i].first;
      int nextX = front.second + r[idx][i].second;
      
      if(nextY < 0 || nextY > N-1 || nextX < 0 || nextX > M-1) continue;
      
      if(!visited[nextY][nextX] || visited[nextY][nextX] < s) {
        visited[nextY][nextX] = s;
        cnt++;
        if(map[nextY][nextX] != 0) {
          q.push(make_pair(nextY, nextX));
        }
      }
    }
  }
  
  return cnt;
}

int main() {
  scanf("%d", &T);
  
  r[1].push_back(make_pair(-1, 0));
  r[1].push_back(make_pair(0, -1));
  r[1].push_back(make_pair(0, 1));
  r[1].push_back(make_pair(1, 0));
  
  r[2].push_back(make_pair(-1, -1));
  r[2].push_back(make_pair(-1, 1));
  r[2].push_back(make_pair(1, -1));
  r[2].push_back(make_pair(1, 1));

  r[3].push_back(make_pair(-2, -2));
  r[3].push_back(make_pair(-2, 0));
  r[3].push_back(make_pair(-2, 2));
  r[3].push_back(make_pair(0, -2));
  r[3].push_back(make_pair(0, 2));
  r[3].push_back(make_pair(2, -2));
  r[3].push_back(make_pair(2, 0));
  r[3].push_back(make_pair(2, 2));
  
  for(int t=1; t<=T; t++) {
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    memset(B, 0, sizeof(B));
    myMax = -987987987;
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        scanf("%d", &map[i][j]);
        
        if(map[i][j] != 0) v.push_back(make_pair(i, j));
      }
    }
    
    int seq = 1;
    
    int cnt1, cnt2;
    int count = 1;
    for(int i=0; i<v.size()-1; i++) {
      memset(visited, 0, sizeof(visited));
      bomb(v[i].first, v[i].second, i+1);
      
      for(int j=i+1; j<v.size(); j++) {
        cnt1 = 0, cnt2 = 0;
        if(!visited[v[j].first][v[j].second]) bomb(v[j].first, v[j].second, j+1);
        
        for(int k=0; k<N; k++) {
          for(int l=0; l<M; l++) {
            if(visited[k][l] == i+1) cnt1++;
            if(visited[k][l] == j+1) cnt2++;
          }
        }
        
        if(cnt1 + cnt2 > myMax){
          myMax = cnt1 + cnt2;
          count = 1;
        }
        else if(cnt1 + cnt2 == myMax) {
          count++;
        }
        
        for(int k=0; k<N; k++) {
          for(int l=0; l<M; l++) {
            visited[k][l] = visitedCopy[k][l];
          }
        }
      }
    }
    
    printf("%d %d %d\n", t, myMax, count);
  }
  
  return 0;
}