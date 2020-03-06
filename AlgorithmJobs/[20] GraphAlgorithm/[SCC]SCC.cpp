// 16분

/*

문제
SCC (Strongly Connected Component)란, 
방향성 그래프가 주어질 때 정점을 여러 집합으로 나누는 기법으로써, 
같은 집합에 속해있는 정점끼리는 서로 왔다갔다 할 수 있어야 한다. 
아래 그림은 그래프의 예제와, 이 그래프에서 SCC를 구한 예제이다.

ec-24

아래 그림처럼, 정점을 {1, 2, 5}, {6, 7}, {3, 4, 8} 의 3개의 집합으로 나누게 되면, 
같은 집합에 속한 정점들끼리는 모두 왔다갔다 할 수 있다. 
그래프가 주어질 때, SCC를 구하였을 때 얻을 수 있는 정점의 집합의 개수를 구하는 프로그램을 작성하시오.


입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 
둘째 줄부터 간선의 정보가 주어진다. 
각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a에서 정점 b로 향하는 간선이 존재한다는 의미이다. 
각 정점의 번호는 1번부터 N번까지이다.


출력
주어진 그래프에서 SCC를 구하였을 때, 얻을 수 있는 정점의 집합의 개수를 출력한다.


예제 입력
8 14
1 5
2 1
2 3
2 6
3 4
3 8
4 3
4 8
5 2
5 6
6 7
7 3
7 6
8 4
예제 출력
3

*/

/*

코사라주 알고리즘을 통해 SCC로 된 그룹을 찾는 문제.
알고리즘의 원리만 정확하게 알고 있다면 구현은 어렵지 않다.


1) 간선의 정보를 입력받는다. 이때 간선 방향을 뒤집은 그래프도 함께 저장한다.

2) 1번부터 N번까지 방문되지 않은 정점이 있다면 그 정점을 시작으로 DFS를 하면서
   빠져나오는 순서대로 시간과 순서를 기록한다.

3) 뒤집은 그래프에 대해서 아까 기록했던 빠져나오는 시간이 큰 노드부터 순회한다.
   즉, order에 빠져나오는 시간이 작은 순서대로 기록되어 있기 때문에 맨 끝부터 반복문을 돌린다.
   (이때 만나는 노드들이 모두 같은 그룹이 된다.)

4) DFS를 하며 해당 노드의 그룹을 groupCnt로 설정해준다.


머릿 속에 코사라주 알고리즘의 원리 및 동작을 그려가며 설계노트에 설계를 했더니
헷갈리는 것 없이 구현할 수 있었다.
오늘은 배운지 얼마 안돼서 그런 거일 수도 있으니 내일 다시 다른 문제를 통해 연습해봐야겠다! ^_^

*/

#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1000 + 10;

int N, M; // N: 정점의 개수, M: 간선의 개수
vector <int> myGraph[MAX]; 
vector <int> myReverseGraph[MAX];

bool visited[MAX] = {false, };
bool visited2[MAX] = {false, };

int time[MAX], clock = 1;
int order[MAX], orderLen = 0;
int group[MAX], groupCnt = 1; // group[i] : 정점 i가 속한 그룹

void getTime(int node) {
  // node부터 시작해서 DFS를 하면서, 빠져나오는 순서대로 시간을 기록한다.
  visited[node] = true;
  
  for(int i=0; i<myGraph[node].size(); i++) {
    // node -> node2
    int node2 = myGraph[node][i];
    
    if(!visited[node2]) getTime(node2);
  }
  
  // 빠져나가는 시간 기록후 clock을 증가시켜준다.
  time[node] = clock;
  clock++;
  
  // order에다가 빠져나오는 노드 번호를 기록한다. (빠져나오는 시간이 작은 순서대로 기록될 것)
  order[orderLen++] = node;
}

void getGroup(int node) {
  // 거꾸로 된 그래프에 대해 node부터 시작해서 DFS를 한다.
  // 방문 처리를 한 후, node의 그룹을 groupCnt로 설정해준다.
  visited2[node] = true;
  group[node] = groupCnt;
  
  for(int i=0; i<myReverseGraph[node].size(); i++) {
    int node2 = myReverseGraph[node][i];
    
    if(!visited2[node2]) getGroup(node2);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    // a -> b (a에서 b로 가는 간선이 연결되어 있다.)
    myGraph[a].push_back(b);
    myReverseGraph[b].push_back(a);
  }
  
  // DFS를 하면서 빠져나오는 순서대로 시간을 기록한다.
  for(int i=1; i<=N; i++) {
    if(!visited[i]) getTime(i);
  }

  // 원래는 여기서 간선 방향을 뒤집어야 하지만, 이미 myReverseGraph에 저장되어 있다.
  // 따라서 뒤집은 그래프에 대해서 빠져나오는 시간이 큰 노드부터 순회한다.
  // 이때 만나는 노드들이 모두 같은 그룹이 된다.
  // order에는 빠져나오는 시간이 작은 순서대로 기록되어 있기 때문에 맨 끝부터 반복문을 돌린다.
  for(int i=orderLen-1; i>=0; i--) {
    int node = order[i];
    
    // 빠져나온 시간이 큰 순서대로 노드를 구하고, 그 노드를 방문하지 않았다면 그 노드부터 DFS를 시작한다.
    if(!visited2[node]) {
      getGroup(node);
      groupCnt++;
    }
  }
  
  printf("%d\n", groupCnt-1);
  // 각 노드가 어떤 그룹에 속하는지를 보려면 노드의 번호와 그룹을 출력한다.
  // for(int i=1; i<=N; i++) printf("%d : %d\n", i, group[i]);
  
  return 0;
}