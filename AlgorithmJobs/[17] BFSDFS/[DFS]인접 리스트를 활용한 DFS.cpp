/*

1 ----- 2 ------- 6
 \     / \       /
  \   /   4 --- 5
   \ /   / \
    3 - 7 - 8 - 9

1 2 3 7 4 5 6 8 9

*/

#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100;

int n, m;
vector <int> myGraph[MAX]; // myGraph[x] = x의 인접 리스트
bool visited[MAX] = {0, };

void DFS(int x) {
  // x부터 시작해서 DFS하여 그 순서를 출력하는 함수.
  // 단, visited에 방문 기록이 있음.
  
  visited[x] = true;
  printf("%d ", x);
  
  for(int i=0; i<myGraph[x].size(); i++) {
    int y = myGraph[x][i];
    // x와 y가 연결이 되어 있다.
    
    if(visited[y] == false) {
      DFS(y);
    }
  }
  
}

int main() {
  scanf("%d %d", &n, &m);
  
  for(int i=0; i<m; i++) {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  DFS(1);
  printf("\n");
  
  return 0;
}

/*

9 12
1 2
1 3
2 3
2 4
2 6
3 7
4 5
4 7
4 8
5 6
7 8
8 9
------------------
1 2 3 7 4 5 6 8 9


*/