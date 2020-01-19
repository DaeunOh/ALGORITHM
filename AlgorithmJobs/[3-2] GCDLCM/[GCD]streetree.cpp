#include <stdio.h>

int get_GCD(int a, int b) {
  while(1) {
    int r = a % b;
    
    if(r == 0) return b;
    
    a = b;
    b = r;
  }
}

int main() {

  //Please Enter Your Code Here
  int N;
  int tree[100010];
  
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    scanf("%d", &tree[i]);
  }
  
  int GCD = 1;
  
  for(int i=0; i<N-1; i++) {
    int distance = tree[i+1] - tree[i];
    
    if(i == 0) GCD = distance;
    else GCD = get_GCD(GCD, distance);
  }
  
  int total_tree = ((tree[N-1] - tree[0]) / GCD) + 1;
  
  printf("%d", total_tree - N);

  return 0;
}