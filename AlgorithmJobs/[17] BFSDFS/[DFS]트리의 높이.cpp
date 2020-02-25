/*

문제
트리의 높이는 루트로부터 가장 멀리 떨어진 노드와의 거리로 정의된다. 
예를 들어, 아래의 트리에서 0번 노드가 루트라고 하면, 
7번 노드까지의 거리가 가장 멀고, 그 거리는 3이다. 
따라서 이 트리의 높이는 3이 된다.

tree_height

트리가 주어질 때, 그 트리의 높이를 출력하는 프로그램을 작성하시오.

 

입력
첫 번째 줄에 트리의 노드 개수 n, 그리고 루트노드의 번호 r이 주어진다. ( 1 ≤ n ≤ 100, 0 ≤ r ≤ n - 1 ) 
두 번째 줄부터 트리의 간선 정보가 주어진다. 
각 줄은 2개의 숫자 a, b로 이루어지며, 이는 a번 노드와 b번 노드가 연결되어 있다는 뜻이다. 
각 노드의 번호는 0 ~ n-1까지 존재한다. 
또한, 연결이 되지않은 노드는 없다.  

출력
트리의 높이를 출력한다.

 

예제 입력
8 0
0 1
0 2
1 3
1 4
1 5
2 6
6 7
예제 출력
3

예제 입력
1 0
예제 출력
0

*/

/*

최근에 DFS로 구현을 많이 안했더니, 재귀 함수를 디자인하는데 있어서 살짝 어려움이 있었다.
또한, BFS와 달리 여기 저기에 추가해야 할 조건도 많았다. ㅠㅠ

항상 DFS 또는 재귀함수를 디자인할 때에는 바로 코딩에 들어가는 것보다
상황의 예시를 직접 들어가며 디자인하는게 좋은 것 같다.


[주의해야 할 점]
1) myMax는 반복문을 시작하기 전 항상 초기화해줘야 한다.
   해당 노드를 부모로 하는 자식들 간에서 최댓값을 찾는 것이기 때문이다.

2) +1을 해줘야 할 부분은 return 밖에 없다.
   그러므로 반복문에서는 +1을 해줄 필요가 없다.

3) tree의 부모노드에도 자식노드가 있고, 자식노드에도 부모노드가 있음에 유의하라.
   그러므로 기저조건에서 tree의 size가 0임을 확인하는 것이 아닌, 1임을 확인해야 한다.
   또한, 노드가 2개밖에 없을 때는 두 노드의 사이즈가 둘 다 1이므로
   기저조건에 빠지지 않도록 기저조건에 "x가 루트가 아닐 때"라는 조건을 추가한다.

4) n이 1인 경우에는 1이 아닌 0이 출력되어야 한다. 따라서 출력 부분에 조건을 추가한다.


*/

#include <stdio.h>
#include <vector>

using namespace std;

const int MAX = 100 + 10;

int n, r;
vector<int> tree[MAX];
int visited[MAX] = {0, };

int DFS(int x) {
  if(x != r && tree[x].size() == 1) return 0;
  
  visited[x] = 1;
  
  int myMax = 0;
  for(int i=0; i<tree[x].size(); i++) {
    int next = tree[x][i];
    
    if(!visited[next]) {
      int height = DFS(next);
      if(myMax < height) myMax = height;
    }
  }

  return myMax + 1;
}

int main() {
  scanf("%d %d", &n, &r);
  
  for(int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  if(n != 1) printf("%d\n", DFS(r));
  else printf("0\n");
  
  return 0;
}