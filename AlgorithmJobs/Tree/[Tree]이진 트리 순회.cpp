#include <stdio.h>

const int MAX = 100;

struct Tree {
  int left;
  int right;
};

Tree tree[MAX];

// tree[i] = 노드 i의 정보를 담고 있음.
// tree[i].left = 노드 i의 왼쪽 노드 번호.
// tree[i].right = 노드 i의 오른쪽 노드 번호.

void preorder(int x) {
  // x를 루트로 하는 서브트리를 전위순회 하여 출력하는 함수.
  if(tree[x].left == -1 && tree[x].right == -1) {
    printf("%d ", x);
  }
  else {
    // Root --> Left --> right
    printf("%d ", x);
    if(tree[x].left != -1) preorder(tree[x].left);
    if(tree[x].right != -1) preorder(tree[x].right);
  }
}

void inorder(int x) {
  // x를 루트로 하는 서브트리를 중위순회 하여 출력하는 함수.
  if(tree[x].left == -1 && tree[x].right == -1) {
    printf("%d ", x);
  }
  else {
    // Left --> Root --> right
    if(tree[x].left != -1) inorder(tree[x].left);
    printf("%d ", x);
    if(tree[x].right != -1) inorder(tree[x].right);
  }
}

void postorder(int x) {
  // x를 루트로 하는 서브트리를 후위순회 하여 출력하는 함수.
  if(tree[x].left == -1 && tree[x].right == -1) {
    printf("%d ", x);
  }
  else {
    // Left --> right --> Root
    if(tree[x].left != -1) postorder(tree[x].left);
    if(tree[x].right != -1) postorder(tree[x].right);
    printf("%d ", x);
  }
}

int main() {
  int n;
  
  scanf("%d", &n);
  
  for(int i=0; i<n; i++) {
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    tree[a].left = b;
    tree[a].right = c;
    
  }
  
  preorder(1);
  printf("\n");
  
  inorder(1);
  printf("\n");
  
  postorder(1);
  printf("\n");
  
  return 0;
}

/*

5
1 2 3
2 4 5
3 -1 -1
4 -1 -1
5 -1 -1

*/