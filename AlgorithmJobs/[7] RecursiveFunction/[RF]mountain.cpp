/*

문제
봉우리가 여러개인 산 모양을 출력한다. 산 모양은 그림과 같고 좌우 대칭이다.

mountain

 

입력
첫 번째 줄에 숫자를 입력 받는다. 숫자의 크기는 20보다 작은 자연수이다.

 

출력
출력 예의 형식으로 출력한다.

 

예제 입력
3
예제 출력
1213121
 

예제 입력
5
예제 출력
1213121412131215121312141213121

*/

/*

n의 최대값이 20으로, 그리 크지 않아서
맨 앞에서부터 쌓아 올리는 방식으로 구현했다.

x는 새로 추가해야 할 수이고 산은 대칭이므로
x를 추가하고 나면 이전 벡터에 존재했던 요소들을 다시 뒤에 붙여넣으면 된다.


또한, 재귀함수에서 mSize를 사용하지 않고,
for문에다가 for(int i=0; i<mountain.size()-1; i++) 을 쓰면

terminate called after throwing an instance of 'std::bad_alloc' what(): std::bad_alloc

라는 에러가 발생한다.

그 이유는 반복문 안에 mountain의 사이즈가 변하는 부분이 있기 때문이다.
따라서 초기 배열의 사이즈를 저장해두고 그를 사용해야 함에 유의하자.

*/

#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<int> mountain;

void getResult(int x) {
  if(x > n) {
    for(int i=0; i<mountain.size(); i++) printf("%d", mountain[i]);
  }
  else {
    int mSize = mountain.size();
    mountain.push_back(x);
    for(int i=0; i<mSize; i++) mountain.push_back(mountain[i]);
    
    getResult(x+1);
  }
}

int main() {
  scanf("%d", &n);

  getResult(1);
  
  return 0;
}