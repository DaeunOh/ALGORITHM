/*

문제
철수네 마을에는 N개의 집이 있으며, 각 집은 고유한 번호를 부여받는다. 
각 번호는 1보다 크거나 같고, N보다 작거나 같다. 
철수는 마을 K에 살고 있다. 
집과 집 사이에는 단방향 도로가 존재하기 때문에, 이 도로를 통하여 서로 이동할 수 있다. 
즉, N개의 마을은 그래프 구조를 이룬다. 
편의상 각 집에는 한 사람만이 살고 있다고 가정하자. 
크리스마스인 오늘, 철수는 본인의 집에서 파티를 열려고 한다. 
따라서 다른 모든 사람들이 철수의 집에 모여 파티를 즐기고, 파티가 끝난 후에는 다시 본인의 집으로 돌아가려 한다. 
사람들은 본인의 집에서 철수네 집까지 이동하기 위하여 항상 최단거리로 이동하기를 원하고, 
마찬가지로 철수네 집에서 본인의 집에 갈 때도 최단거리로 이동하기를 원한다. 
집의 개수와 두 집을 잇는 단방향 도로의 정보, 그리고 철수의 집 번호가 주어질 때, 
마을 사람들이 파티를 즐기기 위해서 이동해야 하는 총 거리의 합을 출력하는 프로그램을 작성하시오.

 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M, 그리고 철수의 집 번호 K가 주어진다. ( 1 ≤ N, K ≤ 1,000, 1 ≤ M ≤ 100,000 ) 
둘째 줄부터 간선의 정보가 주어진다. 
각 줄은 두 개의 숫자 a, b, c로 이루어져 있으며, 이는 정점 a에서 정점 b로 이동하는 데 시간이 c만큼 걸린다는 의미이다. 
양방향 도로가 아님에 주의하자. 각 정점의 번호는 1번부터 N번까지이다.

 

출력
마을 사람들이 파티를 즐기기 위해서 이동해야 하는 총 거리의 합을 출력한다.



예제 입력
6 10 3
1 2 1
2 5 2
3 1 5
3 2 3
3 4 1
3 6 4
4 1 1
5 3 1
6 5 3
6 4 2
예제 출력
32

*/

/*

다익스트라 알고리즘을 우선순위큐를 사용해서 풀어보았다.
우선 우선순위큐는 <자료형, 구현체, 비교 연산자>로 정의된다.


### priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq

나는 pair 자료형을 사용하여 first에 최단거리를 넣고 second에 인덱스를 넣어서
거리가 작은순으로 뽑히게 하고 싶었기 때문에 새로운 비교 연산자가 필요했다.

따라서 비교 연산자를 위한 구조체 comp를 다음과 같이 정의했다.
struct comp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first; // > : 낮은 순으로 뽑는다. < : 높은 순으로 뽑는다.
  }
};

return하는 곳에 '>'를 사용하면 낮은 순으로 뽑히고(따라서 top에는 first가 가장 작은 것이 존재한다)
'<'를 사용하면 높은 순으로 뽑힌다.


이후 방문하지 않은 정점중에서 거리의 최솟값을 구하고,
그로부터 다른 정점으로 뻗어나가며 방문하지 않은 정점인 경우에만 (거리, 인덱스)를 pq에 넣어준다.

우선순위큐를 사용하는 문제가 꽤 있었는데,
비교 연산자를 오버로딩해서 사용한 적은 거의 처음인 것 같다!!
이제 완벽하게 이해했으니 다른 문제에서도 잘 쓸 것 같당~

*/

#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1000 + 10;

int N, M, K;
vector<int> myOutGraph[MAX];
vector<int> myInGraph[MAX];
vector<int> myOutCost[MAX];
vector<int> myInCost[MAX];

int T[MAX];
bool visited[MAX];

int sum = 0;

struct comp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first; // > : 낮은 순으로 뽑는다. < : 높은 순으로 뽑는다.
  }
};

void getResult(vector <int> myGraph[MAX], vector <int> myCost[MAX]) {
  memset(T, 987987987, sizeof(T));
  memset(visited, false, sizeof(visited));
  T[K] = 0;
  
  // .first : 최단거리, .second : 인덱스
  priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
  pq.push(make_pair(0, K));
  
  while(!pq.empty()) {
    if(visited[pq.top().second]) {
      pq.pop();
      continue;
    }
    
    int myMin = pq.top().first;
    int minIdx = pq.top().second;
    pq.pop();
    
    visited[minIdx] = true;
    sum += myMin;
    
    for(int i=0; i<myGraph[minIdx].size(); i++) {
      int next = myGraph[minIdx][i];
      int cost = myCost[minIdx][i];

      if(visited[next]) continue;
      
      if(T[next] > myMin + cost) T[next] = myMin + cost;
      
      pq.push(make_pair(T[next], next));
    }
  }
}

int main() {
  scanf("%d %d %d", &N, &M, &K);
  
  for(int i=0; i<M; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    myOutGraph[a].push_back(b);
    myInGraph[b].push_back(a);
    
    myOutCost[a].push_back(c);
    myInCost[b].push_back(c);
  }
  
  getResult(myOutGraph, myOutCost);
  getResult(myInGraph, myInCost);

  printf("%d", sum);

  return 0;
}