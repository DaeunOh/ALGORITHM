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

조건을 꼼꼼하게 읽지 않아서 꽤 오래 걸렸던 문제.
예제 입력만 보고, a가 부모 b가 자식으로 고정되어 있다고 착각해버렸다.

실제로 조건에서는 "a번 노드와 b번 노드가 연결되어 있다"와 같이 부모, 자식에 대한 언급은 없었는데,
자의적으로 당연히 그렇겠구나 라고 생각하고 넘어갔던게 문제가 되었다.

결과적으로는 BFS방식으로 푸는 코드에 tree[b].push_back(a); 한줄만 더 넣어주면 되는 문제였다.
문제를 풀때 DFS보다 BFS로 푸는 방식을 더 선호하는데, DFS로도 풀어봐야겠다.

*/

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100 + 10;

int n, r;
vector<int> tree[MAX];
int visited[MAX] = {0, };

void BFS(int x) {
  queue<int> q;
  visited[x] = 1;
  q.push(x);
  
  while(!q.empty()) {
    int front = q.front();
    q.pop();
    
    for(int i=0; i<tree[front].size(); i++) {
      int next = tree[front][i];
      
      if(!visited[next]) {
        visited[next] = visited[front] + 1;
        q.push(next);
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &r);
  
  for(int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  BFS(r);
  
  int myMax = 0;
  for(int i=0; i<n; i++) {
    if(myMax < visited[i]) myMax = visited[i];
  }
  
  printf("%d", myMax-1);

  return 0;
}