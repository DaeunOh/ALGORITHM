/*

문제
2색 칠하기란, 다음 두 조건을 만족하면서 그래프의 정점을 모두 색칠할 수 있는지 묻는 문제이다. 
2개의 색이 존재한다. 인접한 두 정점은 색깔이 다르다. 
그래프가 주어질 때, 2색 칠하기가 가능한지 출력하는 프로그램을 작성하시오. 
예를 들어, 아래의 그래프는 2색 칠하기가 가능한 그래프이며, 정점을 색칠한 결과는 다음과 같다.

ec-13

 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 10,000, 1 ≤ M ≤ 100,000 ) 
둘째 줄부터 간선의 정보가 주어진다. 
각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다.(0 ≤ a, b ≤ N-1)

 

출력
주어진 그래프에 대하여 2색 칠하기를 할 수 있으면 YES, 할 수 없으면 NO를 출력한다.

 

예제 입력
9 10
0 1
0 2
0 3
1 5
2 5
3 4
5 6
5 8
6 7
7 8
예제 출력
YES
 

예제 입력
9 11
0 1
0 2
0 3
1 5
2 5
3 4
4 5
5 6
5 8
6 7
7 8
예제 출력
NO

*/

/*

깊이우선탐색(DFS)으로 모든 정점을 탐색하며 2색칠하기가 되는지 확인하는 문제.

정점 0을 시작지점, 처음 색칠할 색을 0으로 DFS를 시작한다.
DFS의 첫 시작은 항상 1) 방문체크, 2) 그룹지정 이다.

그 이후에는 인접 정점들을 보며
방문 되지 않은 정점이라면 그 정점을 새 시작지점으로하고 반대 색을 가지도록 DFS를 시작한다.
그리고 방문된 정점이라면 자신의 색과 다른 색이어야 하는데, 만약 자신의 색과 같다면
NO를 출력하도록 플래그를 설정후 return한다.

*/

#include <stdio.h>
#include <vector>

using namespace std;

const int MAX = 10000 + 10;

int N, M;
vector<int> myGraph[MAX];

bool visited[MAX] = {false, };
bool group[MAX] = {false, };
bool printNo = false;

void DFS(int x, bool g) {
  if(printNo) return;
  
  visited[x] = true;
  group[x] = g;
  
  for(int i=0; i<myGraph[x].size(); i++) {
    int next = myGraph[x][i];
    
    if(visited[next] && group[next] == group[x]) {
      printNo = true;
      return;
    }
    
    if(!visited[next]) DFS(next, !g);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  
  for(int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  DFS(0, 0);
  
  if(printNo) printf("NO\n");
  else printf("YES\n");
  
  return 0;
}