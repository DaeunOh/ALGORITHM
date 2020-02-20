/*

����
���� �ٸ� n���� ���ҵ� �߿��� r������ �̾� �Ϸķ� �����ϴ� ���� �����̶� �Ѵ�. 
���� ���, 3���� ���� a, b, c �߿��� 2������ �̾� �����ϸ� ab, ac, ba, bc, ca, cb �� 6���� ��찡 �ִ�. 
n�� r�� �־��� ��, n���� �ҹ��� �߿��� r������ �̾� �����ϴ� ��� ��츦 ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, a���� �����Ͽ� �������� n���� ���ĺ��� ���� �ִٰ� ����.

�Է�
ù ��° �ٿ� n�� r�� �־�����. ( 1 �� n �� 10, 0 �� r �� min(n, 7) )

���
�� �ٿ� n���� �ҹ��� �߿��� r������ �̾� �����ϴ� ��츦 ���������� ������ ����� ����Ѵ�.

*/

#include <stdio.h>

const int MAX = 105;

int n, r;
char res[MAX];
bool check[MAX];

void getResult(int x) {
  if(x >= r) printf("%s\n", res);
  else {
    for(int i=0; i<n; i++) {
      char alpha = i + 'a';
      if(check[i] == false) {
        res[x] = alpha;
        check[i] = true;
        
        getResult(x+1);
        
        check[i] = false;
        res[x] = 0;
      }
    }
  }
}

int main() {

  //Please Enter Your Code Here
  scanf("%d %d", &n, &r);
  
  getResult(0);

  return 0;
}

/*

4 2
----
ab
ac
ad
ba
bc
bd
ca
cb
cd
da
db
dc

*/