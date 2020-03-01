/*

문제
무방향 그래프가 주어질 때,
정점 1번에서 정점 N번으로 가는 최단거리를 구하려 하는데, 그 과정에서 두 개의 정점을 반드시 거쳐야 한다. 
한 번 방문했던 정점을 또 다시 방문하는 것도 허용하고, 간선도 마찬가지로 여러번 방문하는 것을 허용한다고 할 때, 
1번에서 N번으로 가는 “특정한" 최단거리를 출력하는 프로그램을 작성하시오.

 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 
둘째 줄부터 간선의 정보가 주어진다. 
각 줄은 두 개의 숫자 a, b, c로 이루어져 있으며, 이는 정점 a와 정점 b가 가중치 c인 간선으로 연결되어 있다는 의미이다. 
마지막 줄에는 반드시 거쳐야 하는 두 정점 A, B가 주어진다. ( 1 ≤ a, b, A, B ≤ 1,000, 1 ≤ c ≤ 50,000 )

 

출력
1번 정점에서 N번 정점으로 가는 “특정한" 최단거리를 출력한다. 
단, “특정한" 최단거리란, 주어진 정점 A와 B를 반드시 방문할 때의 최단거리를 의미한다.

 

예제 입력
4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3
예제 출력
7

*/

/*

크게 봤을 때는 1부터 N까지 도착하는 최단거리를 구하는 문제인데,
그 사이에 두 개의 정점을 반드시 거쳐야 하는 것이 일반 최단거리 문제와 다르다.

하지만 이 문제는 방문했던 정점을 재방문하는 것이 가능하고, 방문했던 간선도 재방문이 가능하므로
3단계로 쪼개서 생각해보면 기존 최단거리 문제와 똑같은 문제라고 할 수 있다.

이 문제의 정답은 어떻게든 1 - A - B - N 또는 1 - B - A - N 의 순서로 거치기만 하면 된다.
따라서 1부터 A까지, A부터 B까지, B부터 N까지 세단계로 나눠서 최단거리를 구하고,
이와 똑같이 1부터 B까지, B부터 A까지, A부터 N까지 최단거리를 구한 것 중 최솟값이
둘 중 최솟값이 중간에 A와 B를 거쳐 1부터 N까지 가는 최단거리가 되는 것이다.
--> min(dist1A + distAB + dist BN, dist1B + distBA + distAN)

여기서 A부터 B까지와 B부터 A까지는 같으므로, 총 5번의 거리만 찾으면 답을 얻을 수 있다!
(재방문이 가능하므로 거리를 찾을때마다 T와 visited 배열을 초기화 시켜주는 것을 잊지 말자)

*/

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 987987987;
const int MAXN = 1000 + 10;

int N, M;
vector<int> myGraph[MAXN];
vector<int> myCost[MAXN];
int A, B;

int T[MAXN];
bool visited[MAXN];

int getMinDistance(int S, int E) {
  // S부터 E까지의 최단거리를 반환하는 함수
  memset(T, MAX, sizeof(T));
  memset(visited, false, sizeof(visited));
  
  T[S] = 0;
  
  for(int i=1; i<=N; i++) {
    int myMin = MAX, minIdx = -1;
    
    for(int j=1; j<=N; j++) {
      if(!visited[j] && myMin > T[j]) {
        myMin = T[j];
        minIdx = j;
      }
    }
    
    visited[minIdx] = true;
    
    for(int j=0; j<myGraph[minIdx].size(); j++) {
      int next = myGraph[minIdx][j];
      int cost = myCost[minIdx][j];
      
      if(T[next] > myMin + cost) T[next] = myMin + cost;
    }
  }
  
  return T[E];
}

int main() {
  scanf("%d %d", &N, &M);
  
  for(int i=0; i<M; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
    
    myCost[a].push_back(c);
    myCost[b].push_back(c);
  }
  
  scanf("%d %d", &A, &B);

  // 1부터 A까지의 최단거리, B부터 N까지의 최단거리
  int dist1A = getMinDistance(1, A);
  int distBN = getMinDistance(B, N);
  
  // 1부터 B까지의 최단거리, A부터 N까지의 최단거리
  int dist1B = getMinDistance(1, B);
  int distAN = getMinDistance(A, N);
  
  // A부터 B까지의 최단거리
  int distAB = getMinDistance(A, B);
  
  if(dist1A + distBN < dist1B + distAN) printf("%d\n", dist1A + distBN + distAB);
  else printf("%d\n", dist1B + distAN + distAB);

  return 0;
}