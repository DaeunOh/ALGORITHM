/*

문제
철수는 마을의 여러 건축물들을 폭파해달라는 요청을 받았다. 
이에 건축물들을 하나씩 폭파하려 한다. 
일반적으로, 하나의 건물을 폭파하기 위해서는 다이너마이트 하나가 필요하다고 하자. 
철수의 마을에 있는 건축물들 사이에는 특별한 단방향 통로가 존재한다. 
하나의 건축물을 폭파시킬 경우, 이 단방향 통로로 인하여 상황이 약간 복잡해지는데, 
이는 건물 A에서 건물 B로 통로가 이어져 있을 경우, 건물 A를 폭파시키면 건물 B 역시 폭파된다는 것이다. 
이유인 즉슨, 단방향 통로가 지하에 매설되어 있기 때문에, 지하의 통로가 무너지면서 건물 B가 함께 무너진다. 
철수의 마을에 존재하는 건축물의 개수가 주어지고, 이 건축물들 사이의 단방향 통로가 주어질 때, 
최소 몇 개의 다이너마이트가 있어야 모든 건축물을 폭파시킬 수 있는지를 구하는 프로그램을 작성하시오.

 

입력
첫째 줄에 건축물의 개수 N이 주어지고, 단방향 통로의 개수 M이 주어진다.( 2 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 
둘째 줄부터 단방향 통로의 정보가 주어진다. 
각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 건축물 a에서 건축물 b로 향하는 단방향 통로가 존재한다는 의미이다. 
각 정점의 번호는 1번부터 N번까지이다.

 

출력
모든 건축물을 폭파시키기 위해 필요한 최소의 다이너마이트 개수를 출력한다.

 

예제 입력
7 8
1 2
1 3
2 3
3 7
4 5
5 6
6 4
6 7
예제 출력
2

*/

/*

처음에는 단순하게 DFS로 그래프 순회만 하면 되는 거 아닌가? 생각했는데,
단순 그래프 순회만 이용하면 단방향 그래프기 때문에 시작 정점에 따라 답이 매번 달라지는 문제가 있었다.

"연쇄 작용"을 잘 이용하면 해결할 수 있을 거란 생각은 했지만, 아이디어가 좀처럼 떠오르지 않았다.
그래서 아이디어를 위해 최후의 방법으로 문제에 주어져 있는 힌트를 사용했다. ㅜㅜ

힌트에서는 1) SCC는 어떤 노드를 골라도 항상 연쇄 작용에 의해 같이 폭발되기 때문에 한 노드로 간주해도 되며,
2) 가장 적은 다이너마이트를 사용하기 위해서는 자신에게 들어오는 정점이 없는 노드를 구해야 한다는 것이었다.

그래서 처음에는 SCC를 한 노드로 간주하는 새로운 그래프를 다시 만들어야 하나? 했지만,
SCC를 구하는 것처럼 빠져나오는 시간이 작은 순서대로 노드 순서를 구하고,
빠져나오는 시간이 큰 것부터 DFS를 다시 진행하면(기존 SCC와 다르게 reverseGraph가 아닌 기존 graph를 이용한다.)
SCC는 연쇄적으로 한 번에 폭발되며, 자신에게 들어오는 정점이 없는 노드를 시작으로 연쇄 폭발이 일어난다.

그렇기에 그룹을 설정할 때 정점이 없는 노드에 연결되어 있는 것들은 같은 그룹이 되며,
그 그룹의 번호는 필요한 다이너마이트의 개수를 카운트하는 것과 같다.
따라서 그룹의 번호-1이 필요로 하게 되는 최소의 다이너마이트 개수가 된다.

graph 문제는 관점을 바꿔서 생각해보는 문제가 많은 것 같다.
한 방법만 고집하지 않고 여러 관점에서 생각해보는 연습도 많이 해봐야겠다. ㅎㅎ

*/

#include <stdio.h>
#include <vector>

using namespace std;

const int MAX = 1000 + 10;

int N, M;
vector <int> myGraph[MAX];
vector <int> myReverseGraph[MAX];

bool visited[MAX] = {false, };
bool visited2[MAX] = {false, };

int order[MAX], orderLen = 0;
int group[MAX], groupCnt = 1;

void getTime(int node) {
  visited[node] = true;
  
  for(int i=0; i<myGraph[node].size(); i++) {
    int node2 = myGraph[node][i];
    
    if(!visited[node2]) getTime(node2);
  }
  
  order[orderLen++] = node;
}

void getGroup(int node) {
  visited2[node] = true;
  group[node] = groupCnt;
  
  for(int i=0; i<myGraph[node].size(); i++) {
    int node2 = myGraph[node][i];
    
    if(!visited2[node2]) getGroup(node2);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    myGraph[a].push_back(b);
    myReverseGraph[b].push_back(a);
  }
  
  for(int i=1; i<=N; i++) {
    if(!visited[i]) getTime(i);
  }
  
  for(int i=orderLen-1; i>=0; i--) {
    int node = order[i];
    
    if(!visited2[node]) {
      getGroup(node);
      groupCnt++;
    }
  }
  
  printf("%d\n", groupCnt-1);
  
  return 0;
}