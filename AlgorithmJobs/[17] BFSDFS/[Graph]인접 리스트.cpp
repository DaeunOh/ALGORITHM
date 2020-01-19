/*

1 : 2 3 4
2 : 1 4
3 : 1 5
4 : 1 2 5
5 : 3 4

*/

#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100;

int main() {
  vector <int> myGraph[MAX]; // vector <int> 가 MAX개 생김
  
  int n, m;
  
  scanf("%d %d", &n, &m);
  
  for(int i=0; i<m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  for(int i=1; i<=n; i++) {
    printf("%d(%d) : ", i, myGraph[i].size());
    for(int j=0; j<myGraph[i].size(); j++) {
      printf("%d ", myGraph[i][j]);
    }
    printf("\n");
  }
  
  
  return 0;
}

/*

5 6
1 2
1 3
1 4
2 4
3 5
4 5
----------------
1(3) : 2 3 4 
2(2) : 1 4 
3(2) : 1 5 
4(3) : 1 2 5 
5(2) : 3 4 

*/