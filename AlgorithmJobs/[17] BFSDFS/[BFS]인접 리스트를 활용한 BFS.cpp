/*

1 ----- 2 ------- 6
 \     / \       /
  \   /   4 --- 5
   \ /   / \
    3 - 7 - 8 - 9
  
1 2 3 4 6 7 5 8 9

*/
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100;

int n, m;
vector <int> myGraph[MAX];

void BFS() {
  bool check[MAX] = {0, }; // check[x] = true면 x가 색칠이 됨.
  queue <int> Queue;
  
  // 1. 시작점을 색칠한다.
  // 2. 시작점을 큐에다가 삽입한다.
  
  check[1] = true;
  Queue.push(1);
  
  // BFS 시작!
  
  // 3. 큐에서 하나를 뺀다. 얘가 우리의 현재 위치이다.
  // 4. 인접한 모든 정점에게 방문했는지 물어보고
  //    방문을 하지 않았다면, 색칠하고 큐에 삽입한다.
  // 5. 모두 완료했다면 다시 3. 으로 돌아간다
  
  while(!Queue.empty()) {
    int current = Queue.front();
    Queue.pop();
    
    printf("%d ", current);
    
    for(int i=0; i<myGraph[current].size(); i++) {
      int next = myGraph[current][i];
      
      if(check[next] == false) {
        check[next] = true;
        Queue.push(next);
      }
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
  
  BFS();
  
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
1 2 3 4 6 7 5 8 9

*/