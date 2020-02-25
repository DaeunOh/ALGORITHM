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

BFS로 그래프에 존재하는 정점을 돌며, 2색칠하기가 가능한지 보면 되는 문제.

BFS의 인자로 시작지점(x)과 색칠할 색(g)을 넣어준다.
그리고 방문을 체크하고, 어떤 색을 칠했는지 group에 넣어준다.

한 정점과 직접적으로 연결되어 있는 다른 정점들은 다른 색으로 색칠해야 하므로
방문이 되지 않았다면 자신과 반대 색으로 칠해주고,
방문이 되었는데 자신과 같은 색으로 칠해져 있다면 2색칠하기가 되지 않므로 바로 return한 후 NO를 출력한다.

2색칠하기가 되는 그래프라면 큐가 다 비고 끝나므로 그때는 YES를 출력하면 된다.

*/

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000 + 10;

int N, M;
vector<int> myGraph[MAX];

bool visited[MAX] = {false, };
bool group[MAX] = {false, };
bool printNo = false;

void BFS(int x, bool g) {
  queue<int> q;
  visited[x] = true;
  q.push(x);
  
  while(!q.empty()) {
    int front = q.front();
    q.pop();
    
    for(int i=0; i<myGraph[front].size(); i++) {
      int next = myGraph[front][i];
      
      if(visited[next] && group[next] == group[front]) {
        printNo = true;
        return;
      }
      
      if(!visited[next]) {
        visited[next] = true;
        group[next] = !group[front];
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
  
  BFS(0, 0);
  
  if(printNo) printf("NO\n");
  else printf("YES\n");

  return 0;
}