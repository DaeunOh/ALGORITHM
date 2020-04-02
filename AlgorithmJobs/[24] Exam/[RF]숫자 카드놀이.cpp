// 소요시간: 10분

/*

문제
유니에게는 7살의 귀여운 조카가 있다. 유니는 조카를 3시간만 돌봐 달라는 부탁을 받았다. 
어린이와의 놀이에 익숙하지 않은 유니는 어떻게 조카와 놀아줄지 고민하게 되었다. 
유니에게 좋은 아이디어가 떠올랐는데, 바로 숫자 카드놀이를 하는 것이다.
유니에게는 0~9 까지의 숫자카드가 있다. 
유니는 숫자카드 중 3 장을 골라 조카에게 주면 조카는 만들수 있는 제일 작은 수 부터 시작해, 
만들 수 있는 가장 큰 수까지 만들어 나간다. 
이때 유니는 K 번째 수가 만들어졌을 때, STOP 을 외친다. 수의 맨 앞자리가 0으로 시작 할 수 있다.
STOP 을 외쳤을 때의 수를 출력하는 프로그램을 만드시오.
​ 

입력
​첫 번째 줄에 유니가 고른 3 장의 숫자카드 가 공백으로 구분된 정수로 주어진다.
두 번째 줄에 STOP을 외칠 K 가 정수로 주어진다. (1 ≤ K ≤ 6)​

출력
​STOP 을 외칠 때 만들어진 수를 출력하시오. 맨 앞자리가 0 이라면 0 도 그대로 출력한다.

 

입력의 예 1
1 0 2  
5
출력의 예 1
2 0 1
 ​

입력의 예 2
5 4 6
1
출력의 예 2
4 5 6

*/

/*

숫자가 꼭 3자리 수가 아니어도 되고, 중복된 수도 없으므로
이미 사용한 카드의 경우만 잘 처리해주고 K번째까지 조합을 구하면 되는 문제.

유의할 점은 작은 수부터 큰 수의 순으로 숫자를 만들어야 하는데,
주어지는 수는 오름차순이 보장되어 있지 않기 때문에 조합을 만들기 전 오름차순으로 정렬 후 조합을 구해야 한다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10 + 10;

int num[3];
int K;

int comb[3];
bool check[MAX] = {false, };

bool isFinished = false;
int cnt = 0;

void getComb(int x) {
  if(isFinished) return;
  
  if(x >= 3) {
    if(++cnt == K) {
      for(int i=0; i<3; i++) cout << comb[i] << " ";
      isFinished = true;
    }
  }
  else {
    for(int i=0; i<3; i++) {
      if(check[num[i]]) continue;
      
      comb[x] = num[i];
      check[num[i]] = true;
      getComb(x+1);
      check[num[i]] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> num[0] >> num[1] >> num[2];
  cin >> K;
  
  sort(num, num+3);
  
  getComb(0);

  return 0;
}