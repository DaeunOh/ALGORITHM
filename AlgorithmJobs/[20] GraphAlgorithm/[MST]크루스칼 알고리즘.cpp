/*

크루스칼 알고리즘 및 disjoint set의 원리, 동작은 강의를 통해 배웠지만,
이를 직접 구현하는 문제는 따로 없어서 강의에 사용된 예제를 가지고 직접 예제 입력을 만들고 구현해보았다.

사용한 예제 입력은 다음과 같다.
8 11	// 노드 개수 N, 간선 개수 M
1 2 3	// 노드1, 노드2, 가중치
1 6 1
2 3 1
2 4 4
2 6 3
3 5 1
3 7 1
3 8 4
4 5 3
5 7 1
7 8 2

EDGE 구조체를 만들고, 나중에 sort함수를 사용할 때 가중치를 오름차순으로 정렬하기 위해 비교 함수도 추가했다.
정렬된 간선을 가지고 최종적으로 MST를 만드는 것이 목적이기 때문에 다음과 같은 단계를 거쳤다.

1) 두 트리를 합치는 것이 가능한지를 판단하기 위해 각 노드의 루트를 찾아 루트가 같은지를 확인한다.
   (이때 루트를 찾아 나가는 과정에서의 경로를 압축하기 위해 루트를 찾음과 동시에 루트를 계속 업데이트 해주었다.)
2) 서로의 루트가 다르면 두 트리를 합치게 되는데,
   합칠 때는 rank가 더 낮은 트리가 rank가 더 높은 트리의 하위트리로 들어가도록 rank를 비교하여 root를 설정해준다.

해당 과정을 graph에 있는 모든 노드들에 대해 거치면 최종적으로 MST가 만들어진다.

*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 10;

int N, M; // N: 노드 개수, M: 간선 개수
int myRoot[MAX];
int myRank[MAX];

struct EDGE {
  int a, b, c;
  
  EDGE(int _a, int _b, int _c) {
    a = _a;
    b = _b;
    c = _c;
  }
  
  bool operator <(EDGE &e) {
    return c < e.c;
  }
};

vector<EDGE> myGraph;

int findRoot(int node) {
  // 자신이 루트인 경우에는 자신을 반환하고, 아닌 경우에는 루트 찾아 반환한다.
  // 또한 이후 연산을 줄이기 위해, 중간에 거치는 노드들도 루트로 바꿔준다.
  if(myRoot[node] == node) return node;
  else return myRoot[node] = findRoot(myRoot[node]);
}

void unionTree(int a, int b) {
  a = findRoot(a);
  b = findRoot(b);
  
  
  // 같은 트리에 포함되어 있는 경우
  if(a == b) return;

  // rank는 트리의 높이(크기)를 다 표현하진 않지만, 트리의 높이에 비례하는 값이다.
  // 따라서 트리의 rank가 더 낮은 트리가 더 높은 트리의 하위 트리가 되도록 root를 설정해주되,
  // 트리의 rank가 같다면 뒤에 오는 트리가 앞의 트리의 하위 트리가 되도록 하고,
  // 앞의 트리의 rank를 1 증가시켜 준다.
  if(myRank[a] < myRank[b]) myRoot[a] = b;
  else {
    myRoot[b] = a;
    if(myRank[a] == myRank[b]) myRank[a]++;
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i=0; i<M; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    myGraph.push_back(EDGE(a, b, c));
  }
  
  for(int i=1; i<=N; i++) {
    myRoot[i] = i;
    myRank[i] = 0;
  }
  
  sort(myGraph.begin(), myGraph.end());
  
  for(int i=0; i<myGraph.size(); i++) {
    // root가 다르면 a를 포함하는 트리와 b를 포함하는 트리를 합쳐지게 된다.
    unionTree(myGraph[i].a, myGraph[i].b);
  }

  return 0;
}