/*

문제
트리가 주어지고, 두 노드 X, Y가 주어질 때, 이 두 노드 사이의 거리를 출력하는 프로그램을 작성하시오. 
트리에서는 두 노드를 잇는 경로가 유일하기 때문에, 정답은 항상 유일하다는 것을 참고한다. 
예를 들어, 다음과 같은 트리에서 노드 3, 노드 6 사이의 거리는 4이다.

tree_distance

 

입력
첫 번째 줄에 트리의 노드 개수 n, 두 노드 X, Y의 번호가 주어진다. ( 0 ≤ X, Y ≤ n < 1000 ) 
두 번째 줄부터 트리의 간선 정보가 주어진다. 
각 줄은 2개의 숫자 a, b로 이루어지며, 이는 노드 a가 노드 b의 부모노드라는 것을 의미한다. 
루트는 노드 0이라고 가정한다.  

출력
두 노드 X, Y 사이의 거리를 출력한다.

 

예제 입력
11 3 6
0 1
0 2
1 3
1 4
1 5
2 6
2 10
6 7
6 8
6 9
예제 출력
4

*/

/*

노드 간의 거리를 구하는 문제.

입력을 받을 때, 부모 자식에 상관 없이 양쪽 벡터에 다 넣어줬기 때문에
사실 누가 부모고, 누가 자식이며, 심지어는 누가 루트인지 알 필요가 없다.

X를 시작지점으로 BFS를 돌리고, visited배열에 거리를 찍으며 순회한다면
최종적으로 visited배열의 인덱스 Y가 X와 Y간의 거리가 된다.

*/

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000 + 10;

int n, X, Y;
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
  scanf("%d %d %d", &n, &X, &Y);
  
  for(int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  BFS(X);
  
  printf("%d\n", visited[Y] - 1);
  
  return 0;
}