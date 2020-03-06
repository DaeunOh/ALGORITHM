/*

문제
그래프와 출발점, 도착점이 주어질 때 출발점에서 도착점까지 이동하기 위한 최단거리를 출력하는 프로그램을 작성하시오. 
예를 들어, 아래 그림에서 출발 정점이 0, 도착 정점이 10이라고 할 때, 최단거리는 3이다.

ec-21

 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 10,000, 1 ≤ M ≤ 1,000,000 ) 
둘째 줄부터 간선의 정보가 주어진다. 
각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다. 
M+1 번째 줄에 대하여 출발점과 도착점의 정점 번호가 주어진다. 
정점의 번호는 0번부터 N-1번까지이다.


출력
출발점에서 도착점까지 이동하기 위한 최단거리를 출력한다.

 

예제 입력
11 14
0 1
0 2
1 2
1 4
1 5
2 3
3 7
4 7
4 9
4 10
5 6
6 8
6 10
7 8
0 10
예제 출력
3

*/

/*

이전에 코딩테스트를 준비할 때, 최단거리를 구하는 문제들이 많이 있었다.
그때마다 어떻게 구현해야 할지 확신이 서지 않아 다양한 방법으로 접근 했었는데,
이런 알고리즘이 있다니..... 엄청난 혁명이었다 ㅎㅎ;;
조금 더 연습해서 빨리 익숙해져야겠다! ^ㅇ^


### T[i] = 정점 i까지 도달하기 위한 최단거리
1) 지금까지 방문 되지 않은 정점의 최단거리 중에서 최솟값을 찾는다.
2) 그 최솟값을 방문 처리한 후에, 그 정점으로부터 다른 정점으로 뻗어 나가며 최단거리를 업데이트 시킨다. (T[minIdx] + cost)

*/

#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 10000 + 10;

int N, M;
int S, E;

int T[MAX];
vector<int> myGraph[MAX];
bool visited[MAX] = {false, };

int main() {
  memset(T, 987987987, sizeof(T));
  scanf("%d %d", &N, &M);
  
  for(int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  scanf("%d %d", &S, &E);
  
  T[S] = 0;
  
  for(int i=0; i<N; i++) {
    int myMin = 987987987, minIdx = -1;
    
    // 방문 되지 않은 정점 중 최솟값 찾기
    for(int j=0; j<N; j++) {
      if(!visited[j] && myMin > T[j]) {
        myMin = T[j];
        minIdx = j;
      }
    }

    visited[minIdx] = true;
    
    // 그 정점으로부터 뻗어 나가기
    for(int j=0; j<myGraph[minIdx].size(); j++) {
      int next = myGraph[minIdx][j];
      
      if(T[next] > myMin + 1) T[next] = myMin + 1;
    }
  }
  
  printf("%d\n", T[E]);

  return 0;
}