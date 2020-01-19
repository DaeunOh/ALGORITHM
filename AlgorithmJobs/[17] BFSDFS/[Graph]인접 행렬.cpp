// 인접행렬을 이용한 그래프의 구현

// Q1. 정점 X와 Y가 연결이 되어 있는가? (YES / NO)
// Q2. 정점 X와 연결이 되어 있는 모든 정점을 출력하라.

#include <stdio.h>

const int MAX = 10;

bool isConnected(int myGraph[][MAX], int x, int y) { // 크기를 적어주지 않으면 컴파일 에러남
  // myGraph에서 x와 y가 연결이 되어 있으면 true, 아니면 false를 반환
  return myGraph[x][y] == 1 ? true : false;
}

void getAdj(int myGraph[][MAX], int n, int x) {
  // n개의 정점을 갖는 myGraph에서 x와 연결되어 있는 모든 정점을 출력하는 함수
  for(int i=1; i<=n; i++) {
    if(myGraph[x][i] == 1) printf("%d ", i);
  }
  
  printf("\n");
}

int main() {
  int n, m;
  int myGraph[MAX][MAX] = {0, };
  
  scanf("%d %d", &n, &m);
  
  for(int i=0; i<m; i++) {
    int a, b;
    
    scanf("%d %d", &a, &b); // a와 b가 연결 되어 있다.
    
    myGraph[a][b] = 1;
    myGraph[b][a] = 1;
  }
  
  // isConnected O(1)
  
  printf("%d\n", isConnected(myGraph, 1, 2)); // 1
  printf("%d\n", isConnected(myGraph, 1, 5)); // 0
  printf("%d\n", isConnected(myGraph, 3, 5)); // 1
  
  // getAdj O(n)
  
  getAdj(myGraph, n, 2); // 1 4
  getAdj(myGraph, n, 4); // 1 2 5
  
  return 0;
}

/*

(정점의 갯수, 간선의 갯수)
5 6

1 2
1 3
1 4
2 4
4 5
3 5

*/