/*

시간제한 9초

문제
미국의 블랙프라이데이처럼 한국에서도 연말을 맞아 할인을 시작하였다. 
현재 백화점 내부에 각 매장 별로 할인을 시작했다. 
백화점 내부 상황을 표현하면 다음과 같다. 
사람들의 위치는 Pi로 매장의 위치는 Si로 표기되었다. 
또한 각 매장 아래에 적힌 숫자는 (입장 제한 인원, 쇼핑 제한 시간)을 의미한다. 
각 매장은 안전을 위해 입장 제한 인원과 쇼핑 제한 시간을 설정해두고 행사를 진행하였다. 
만약 입장 인원이 꽉 찼을 경우, 매장 앞에서 대기할 수 있도록 하였다.

balck_friday1[그림 1]

[그림 1]에 나타난 예시로 S1 매장은 입장 제한 인원이 3명, 쇼핑 제한 시간이 5분이다. 
S2 매장은 입장 제한인원이 4명, 쇼핑 제한 시간이 7분이다. 
고객이 (y, x)에 위치해있다면 매장(a, b)에 도착하는데 |(y-a)|+|(x-b)| 분이 소요된다. 
고객은 어떤 매장이든 입장하게 되면 쇼핑 제한 시간을 모두 사용한다. 
매장 입장은 매장에 도착한 동시에 이루어지며, 매장에 도착한 순서대로 입장하게 된다. 
현재 백화점 운영측은 원활한 행사 운영을 위해 
모든 인원이 어떤 매장이든 한 번이라도 들려서 쇼핑을 하고 나오는데 소요되는 최소 시간을 알고싶다. 
[그림 1]의 상황에서 최소 시간을 얻기 위해서는 다음과 같이 고객들이 움직여야한다.

매장 S1 - P1, P2, P5
매장 S2 - P3, P4, P6

1분 경과 - 고객 P4, 매장 S2 입장
2분 경과 - 고객 P5, 매장 S1 입장
3분 경과 - 고객 P2, 매장 S1 입장, 고객 P3, P6, 매장 S2 입장
4분 경과 - ..
5분 경과 - 고객 P1, 매장 S1 입장
6분 경과 - ..
7분 경과 - 고객 P5, 매장 S1 쇼핑 종료
8분 경과 - 고객 P2, 매장 S1 소핑 종료, 고객 P4, 매장 S2 쇼핑 종료
9분 경과 - ..
10분 경과 - 고객 P1, 매장 S1 쇼핑 종료, 고객 P3, P6, 매장 S2 쇼핑 종료

[그림 1]의 상황에서 모든 인원이 한 번이라도 쇼핑을 하고 나오는 최소 시간은 10분이다. 
N * M 크기의 백화점 현재 상황이 주어졌을때, 
현재 백화점에 있는 모든 인원이 한 번이라도 쇼핑을 하고 나오는데 걸리는 최소 시간을 알아내보자.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다.

각각의 테스트 케이스의 첫 번째 줄에 
매장의 크기를 나타내는 N, M과 매장의 개수 K가 공백을 통해 구분하여 입력된다.

두 번째 줄부터 K 개의 줄에 걸쳐 
각 매장별 입장 제한 인원 P, 쇼핑 제한 시간 S가 공백을 통해 구분되어 입력된다. 
입력된 순서대로 A부터 차례대로 매장의 개수만큼 번호가 매겨진다.

다음 줄부터 N 줄에 걸쳐 N * M의 백화점 정보가 주어진다. 
백화점 정보는 0, 1, 알파벳 A부터 E까지 존재하며 각 줄은 공백을 통한 구분없이 주어진다. 
0의 의미는 해당 위치에 아무것도 존재하지않는다는 것, 1의 의미는 해당 위치에 사람이 존재한다는 것, 
알파벳은 해당 위치에 매장이 존재한다는 것을 의미한다. 
백화점 내부에 존재하는 고객은 최소 0명, 최대 8명이다.

(1 ≤ T ≤ 50, 5 ≤ N, M ≤ 10, 2 ≤ K ≤ 4, 2 ≤ P ≤ 10, 3 ≤ S ≤ 15)

 

출력
각 테스트 케이스에 대해 
모든 인원이 어떤 매장이든 한 번이라도 들려서 쇼핑을 하고 나오는데 소요되는 최소 시간을 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. r은 문제에 대한 결과값을 뜻한다.

 

예제 입력
3
5 6 2
3 5
4 7
101000
0100A0
000000
010010
0B0010
5 5 2
3 3
3 5
01100
0010A
01010
00000
10B00
5 5 2
3 2
3 5
00110
0010A
00010
01000
10B00

예제 출력
#1 10
#2 8
#3 7

*/

/*

시간 제한이 9초로 넉넉하고,
모든 변수의 값이 매우 작았기 때문에
모든 조합을 생각하는 완전탐색으로 접근했다.

하지만, 구현함에 있어 cnt를 0부터 시작해서 나중에 증가시키는 방식으로 구현했기 때문에
vector로 선언된 d에서 -1로 체크하는 시점에 유의하는 것이 핵심이다.

또한, check를 감소시킬 때, 감소시킨 값이 0이 되면
그 즉시 store의 자리를 늘려줘야 하는 것도 잊지 말아야 한다.

코드 전체적으로 봤을 때,  어떠한 감소가 일어난다면 flag를 무조건 true로 처리해주는 것이 옳다.
처음에 언급했듯이, 이는 필자가 정의한 cnt의 특징때문에 그런 것이다.

*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 10 + 10;
const int MAXS = 100;

int T;
int N, M, K;
vector<pair<int, int>> store(MAXS);
char map[MAX][MAX];
vector<pair<int, int>> person;
vector<pair<int, int>> storeYX(MAXS);
int comb[MAX];
int myMin;
vector<int> check[MAX];

int goShopping() {
  int cnt = 0;
  vector<pair<int, int>> d;
  
  int y, x, a, b;
  for(int i=0; i<person.size(); i++) {
    y = person[i].first;
    x = person[i].second;
    a = storeYX[comb[i]].first;
    b = storeYX[comb[i]].second;
    
    int distY = y - a >= 0 ? y - a : a - y;
    int distX = x - b >= 0 ? x - b : b - x;

    d.push_back(make_pair(distY+distX, comb[i]));
  }
  
  sort(d.begin(), d.end());
  
  while(1) {
    bool flag1 = false;
    for(int i=0; i<d.size(); i++) {
      if(d[i].first == -1) {
        continue;
      }
      else if(d[i].first == 0) {
        int idx = d[i].second; // A~E
        
        if(store[idx].first > 0) {
          check[idx-65].push_back(store[idx].second);
          store[idx].first--;
          d[i].first = -1;
        }
      }
      else {
        d[i].first--;
        flag1 = true;
      }
    }
    
    bool flag2 = false;
    for(int i=0; i<5; i++) {
      for(int j=0; j<check[i].size(); j++) {
        if(check[i][j] == 0) continue;
        else {
          check[i][j]--;
          
          if(check[i][j] == 0) store[i+65].first++;
          
          flag2 = true;
        }
      }
    }
    
    if(!flag1 && !flag2) break;
    
    cnt++;
  }
  
  return cnt;
}

void getCombination(int x) {
  if(x >= person.size()) {
    int res = goShopping();
    
    if(res < myMin) myMin = res;
  }
  else {
    for(int i=65; i<65+K; i++) {
      comb[x] = i;
      
      getCombination(x+1);
    }
  }
}

int main() {
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    myMin = 987987987;
    store.clear();
    person.clear();
    memset(map, 0, sizeof(map));
    scanf("%d %d %d", &N, &M, &K);

    for(int i=65; i<65+K; i++) {
      scanf("%d %d", &store[i].first, &store[i].second);
    }
    
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        scanf(" %c", &map[i][j]);
        
        if(map[i][j] == '0') continue;
        
        if(map[i][j] == '1') {
          person.push_back(make_pair(i, j));
        }
        else {
          storeYX[map[i][j]].first = i;
          storeYX[map[i][j]].second = j;
        }
      }
    }
    
    getCombination(0);
    
    printf("#%d %d\n", t, myMin);
  }
  
  return 0;
}