/*

문제
이분 그래프란, 아래 그림과 같이 정점을 크게 두 집합으로 나눌 수 있는 그래프를 말한다. 여기서 같은 집합에 속한 정점끼리는 간선이 존재해서는 안된다. 예를 들어, 아래 그래프의 경우 정점을 크게 {1, 4, 5}, {2, 3, 6} 의 두 개의 집합으로 나누게 되면, 같은 집합에 속한 정점 사이에는 간선이 존재하지 않으므로 이분 그래프라고 할 수 있다.
<그림>
그래프가 입력으로 주어질 때, 이 그래프가 이분그래프인지를 판별하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 2 ≤ N ≤ 1,000, N-1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다. (1 ≤ a, b ≤ N)

출력
주어진 그래프가 이분 그래프이면 Yes, 아니면 No를 출력한다.
 
*/

/*

&N, &M
&a, &b (M개)

*/

#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1010;

int N, M;
vector <int> myGraph[MAX];
bool visited[MAX] = {0, };
bool isSameGroup[MAX] = {0, }; // 0이면 그룹0, 1이면 그룹1
bool isFinished = false;

void DFS(int x, bool flag) {
  if(isFinished) return;
  
  for(int i=0; i<myGraph[x].size(); i++) {
    int adj = myGraph[x][i];
    if(visited[adj] == false) {
      visited[adj] = true;
      isSameGroup[adj] = !flag;
      DFS(adj, !flag);
    }
    else {
      if(isSameGroup[adj] != !flag) {
        isFinished = true;
        return;
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  
  int a, b;
  scanf("%d %d", &a, &b);
    
  myGraph[a].push_back(b);
  myGraph[b].push_back(a);
  
  int start = a;
  
  for(int i=1; i<M; i++) {
    scanf("%d %d", &a, &b);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  visited[start] = true;
  isSameGroup[start] = 0;
  DFS(start, 0);
  
  if(!isFinished) printf("Yes");
  else printf("No");
  
  return 0;
}