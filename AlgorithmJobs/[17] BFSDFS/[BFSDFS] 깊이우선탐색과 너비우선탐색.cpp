/*

문제
그래프가 주어질 때, 0번 정점을 시작으로 하여 
깊이우선탐색과 너비우선탐색의 결과를 출력하는 프로그램을 작성하시오. 
단, 노드를 방문할 때는 노드 번호가 작은 순서대로 방문한다고 하자.

 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 
둘째 줄부터 간선의 정보가 주어진다. 
각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다. 
정점의 번호는 0번부터 N-1번까지이다.

 

출력
첫 번째 줄에 깊이우선탐색 결과, 두 번째 줄에 너비우선탐색 결과를 출력한다.

 

예제 입력
9 12
0 1
0 2
0 3
1 5
2 5
3 4
4 5
5 6
5 7
5 8
6 7
7 8
예제 출력
0 1 5 2 4 3 6 7 8
0 1 2 3 5 4 6 7 8

*/

/*

너무 기본적인 DFS, BFS문제라 빠르게 구현하고 넘어가려 했는데,
"노드 번호가 작은 순서대로 방문"해야 한다는 조건 설계에서 빠뜨려서
처음에 10개의 테스트 케이스 중 2개밖에 맞추질 못했다 ...

문제를 다시 읽어 보면서 작은 순서대로 방문해야 함을 깨달았고 ....
다시 모든 정점을 오름차순으로 sort한 후에 제출했더니 100점이 나왔다 ㅎㅎ.

*/

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 10;

int N, M;
vector<int> myGraph[MAX];

bool visitedD[MAX] = {false, };
bool visitedB[MAX] = {false, };

void DFS(int x) {
  visitedD[x] = true;
  printf("%d ", x);
  
  for(int i=0; i<myGraph[x].size(); i++) {
    int next = myGraph[x][i];
    
    if(!visitedD[next]) DFS(next);
  }
}

void BFS(int x) {
  queue<int> q;
  visitedB[x] = true;
  q.push(x);
  
  while(!q.empty()) {
    int front = q.front();
    q.pop();
    
    printf("%d ", front);
    
    for(int i=0; i<myGraph[front].size(); i++) {
      int next = myGraph[front][i];
      
      if(!visitedB[next]) {
        visitedB[next] = true;
        q.push(next);
      }
    }
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
  
  for(int i=0; i<N; i++) sort(myGraph[i].begin(), myGraph[i].end());
  
  DFS(0);
  printf("\n");
  BFS(0);

  return 0;
}