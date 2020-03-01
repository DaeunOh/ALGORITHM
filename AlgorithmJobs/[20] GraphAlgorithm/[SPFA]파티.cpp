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

단방향 그래프가 주어져 있을 때, K번을 제외한 나머지 1~N번의 집에서 K번 집으로 오는 최단경로와
K번 집에서 K번을 제외한 나머지 1~N번의 집으로 가는 최단경로를 구하는 것이 핵심인 문제이다.

철수 집 K에서 각자 집으로 돌아가는 최단경로는 다익스트라 알고리즘 1번이면 구할 수 있다.
하지만, 각자의 집에서 철수 집 K로 오는 최단경로는 각자의 집마다 매번 Start가 바뀌므로
우선순위큐를 사용하지 않을시에 시간복잡도가 O(N^3)에 이른다.

따라서 그 방법을 제외한 다른 방법이 필요했는데, 나는 아이디어를 떠올리기 위해 또 예시를 들어보았다. ㅎㅎ;;
그 결과 간선을 뒤집어서 생각해보면 어떨까? 라는 아이디어가 떠올랐다.
K번으로 들어왔던 간선은 K번에서 나가고, 나갔던 간선은 K번으로 들어오도록 말이다!

그렇게 간선의 방향을 바꿔서 다익스트라를 돌리면 각자의 집으로 가는 최단경로가
결국에는 실제 각자의 집에서 K번 집으로 오는 최단경로랑 같게 된다 ㅎㅎㅎ
그렇기 때문에 이 문제는 다익스트라 알고리즘 2번이면 풀 수 있는 문제로 바뀌게 되는 것이다!!

오랜만에 아이디어가 금방 떠올라서 풀면서 많이 행복했던 문제 ㅎㅎ
그리고 다익스트라 알고리즘을 항상 우선순위큐 없이 풀었었는데,
우선순위큐 연습좀 할겸 우선순위큐 사용해서 풀어도 봐야겠다!

*/

#include <stdio.h>
#include <vector>
#include <cstring>

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

void getResult(vector <int> myGraph[MAX], vector <int> myCost[MAX]) {
  memset(T, 987987987, sizeof(T));
  memset(visited, false, sizeof(visited));
  T[K] = 0;

  for(int i=1; i<=N; i++) {
    int myMin = 987987987, minIdx = -1;
    
    for(int j=1; j<=N; j++) {
      if(!visited[j] && myMin > T[j]) {
        myMin = T[j];
        minIdx = j;
      }
    }
    
    visited[minIdx] = true;
    sum += myMin;
    
    for(int j=0; j<myGraph[minIdx].size(); j++) {
      int next = myGraph[minIdx][j];
      int cost = myCost[minIdx][j];
      
      if(T[next] > myMin + cost) T[next] = myMin + cost;
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