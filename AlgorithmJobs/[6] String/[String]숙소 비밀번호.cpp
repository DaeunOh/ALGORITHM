/*

문제
이번에 유럽 여행을 가게 된 원영은 WaterBnB를 통해 숙소를 예약했다. 
프랑스의 정취를 흠뻑 느끼기 위해서 역에서 15분가량 떨어진 곳으로 결정했다. 
체크인 주의사항을 유심히 읽어보지 않은채 
툴루즈 블라냐크 공항에 도착하자마자 숙소로 돌진했다. 
예약한 방에 들어가 짐을 풀려고 했으나 열쇠를 찾을 수 없었다. 
다시 WaterBnB 앱을 켜 숙소 안내사항을 읽어보았다. 
해당 숙소에서 방 열쇠를 얻기위해서는 열쇠함을 열어야됐다. 
열쇠함에는 다이얼이 붙어있고 주어진 숫자를 조합하여 
규칙에 맞는 숫자를 다이얼에 입력해야 열 수 있다.

규칙은 다음과 같다.
숫자의 개수는 18개이며, 각각의 숫자는 32진수로 주어진다. 
주어진 수열의 순서를 섞을 수는 없다. 
다이얼의 모양은 정육각형이며, 다이얼을 시계 방향 또는 반시계 방향으로 돌릴 수 있다. 
다이얼 한 변에 3개의 숫자를 둘 수 있으며, 한 변에 있는 수열이 비밀번호 1개가 된다. 
1회 회전할때마다 새로운 비밀번호들이 생성된다. 
만약 같은 순서의 숫자조합을 가진 비밀번호가 있다면, 
해당 비밀번호들은 서로 다른 비밀번호가 아닌 같은 비밀번호로 생각한다. 
생성된 비밀번호를 오름차순으로 정렬했을때, 
K 번째 큰 값을 가진 비밀번호를 열쇠함을 열 수 있는 비밀번호로 설정되어있다. 
비밀번호 입력은 육각 다이얼의 상단(빨간색)에서 이루어진다.

hotel_password

위와 같이 수열 "0CPSF6D9ELA43ITVKN"이 주어졌다고 가정했을때, 
시계 방향으로 돌릴 경우 나올 수 있는 회전 회차별 비밀번호 조합은 다음과 같다.
0회차 - 0CP, SF6, D9E, LA4, 3IT, VKN
1회차 - N0C, PSF, 6D9, ELA, 43I, TVK
2회차 - KN0, CPS, F6D, 9EL, A43, ITV
3회차 - VKN, 0CP, SF6, D9E, LA4, 3IT
4회차 - TVK, N0C, PSF, 6D9, ELA, 43I
5회차 - ITV, KN0, CPS, F6D, 9EL, A43
6회차 - 3IT, VKN, 0CP, SF6, D9E, LA4
7회차 - 43I, TVK, N0C, PSF, 6D9, ELA
8회차 - A43, ITV, KN0, CPS, F6D, 9EL
9회차 - LA4, 3IT, VKN, 0CP, SF6, D9E
10회차 - ELA, 43I, TVK, N0C, PSF, 6D9
11회차 - 9EL, A43, ITV, KN0, CPS, F6D
12회차 - D9E, LA4, 3IT, VKN, 0CP, SF6
13회차 - 6D9, ELA, 43I, TVK, N0C, PSF
14회차 - F6D, 9EL, A43, ITV, KN0, CPS
15회차 - SF6, D9E, LA4, 3IT, VKN, 0CP
16회차 - PSF, 6D9, ELA, 43I, TVK, N0C
17회차 - CPS, F6D, 9EL, A43, ITV, KN0

다음은 반시계 방향으로 돌렸을 경우 얻어지는 회차별 비밀번호 조합이다.
0회차 - 0CP, SF6, D9E, LA4, 3IT, VKN
1회차 - CPS, F6D, 9EL, A43, ITV, KN0
2회차 - PSF, 6D9, ELA, 43I, TVK, N0C
3회차 - SF6, D9E, LA4, 3IT, VKN, 0CP
4회차 - F6D, 9EL, A43, ITV, KN0, CPS
5회차 - 6D9, ELA, 43I, TVK, N0C, PSF
6회차 - D9E, LA4, 3IT, VKN, 0CP, SF6
7회차 - 9EL, A43, ITV, KN0, CPS, F6D
8회차 - ELA, 43I, TVK, N0C, PSF, 6D9
9회차 - LA4, 3IT, VKN, 0CP, SF6, D9E
10회차 - A43, ITV, KN0, CPS, F6D, 9EL
11회차 - 43I, TVK, N0C, PSF, 6D9, ELA
12회차 - 3IT, VKN, 0CP, SF6, D9E, LA4
13회차 - ITV, KN0, CPS, F6D, 9EL, A43
14회차 - TVK, N0C, PSF, 6D9, ELA, 43I
15회차 - VKN, 0CP, SF6, D9E, LA4, 3IT
16회차 - KN0, CPS, F6D, 9EL, A43, ITV
17회차 - N0C, PSF, 6D9, ELA, 43I, TVK

생성된 비밀번호를 중복없이 오름차순으로 나열할 경우, 
0CP 3IT 43I 6D9 9EL A43 D9E CPS ELA F6D ITV KN0 LA4 N0C PSF SF6 TVK VKN 가 된다.
이때, K 가 15 인 경우 15 번째로 큰 비밀번호는 PSF 가 된다. 
PSF 를 얻기 위해서는 다이얼을 반시계 방향으로 2회 돌리는 것이 최소 회전 횟수이다.

시차 적응이 안된 원영은 현재 잠이 부족한 상태이다. 
숙소 문을 어서 빨리 열어 짐을 풀고 쉬고 싶다. 
다이얼에 적힌 32진수 수열이 주어졌을때, 
비밀번호를 입력하는데에 필요한 최소 다이얼 회전 횟수와 
열쇠함의 비밀번호를 10진수로 바꾼 값을 구해보자!

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다.(1 ≤ T ≤ 50) 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다. 
각각의 테스트 케이스는 한 줄에 K와 수열을 공백을 통해 구분하여 입력된다. 
K는 몇 번째 비밀번호가 상자를 여는 비밀번호인지를 알려주는 값이며, 
수열은 다이얼의 초기 상태를 뜻한다. 
K는 생성된 비밀번호 개수를 초과하지 않으며, 수열은 항상 18자리로 고정되어 있다. 
또한, 각 숫자는 0이상 V이하이다. (A~V 는 대문자로 주어진다. A는 32진수에서 10이고, V는 31이다.)

출력
각 테스트 케이스에 대해서 "#t result"의 형식을 맞춰 출력한다. 
t는 테스트 케이스의 번호를 뜻하며, 1부터 시작한다. 
result는 문제를 해결한 결과값을 의미한다. 
해당 문제에서는 최소 회전 횟수와 비밀번호를 10진수로 변환한 값이다.

*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX = 18;

int main() {
  int T;
  scanf("%d", &T);
  
  int K;
  char str[MAX];
  vector<string> v;
  
  for(int t=1; t<=T; t++) {
    scanf("%d %s", &K, str);
    
    v.clear();
    
    for(int i=0; i<MAX; i++) {
      string key = "";
      for(int j=0; j<3; j++) {
        int next = (i + j) % MAX;
        key += str[next];
      }
      
      v.push_back(key);
    }
    
    sort(v.begin(), v.end());
    string ans = v[K-1];
  
    int cnt = 0;
    for(int i=0; i<MAX; i++) {
      string key = "";
      for(int j=0; j<3; j++) {
        int next = (i + j) % MAX;
        key += str[next];
      }
      
      if(key == ans) {
        if(i < 9) {
          cnt = i;
          break;
        }
        else {
          cnt = i;
        }
      }
    }
    
    int password = 0;
    
    if(ans[2] < 'A') password += ans[2] - '0';
    else password += ans[2] - 'A' + 10;
    
    if(ans[1] < 'A') password += (ans[1] - '0') * 32;
    else password += (ans[1] - 'A' + 10) * 32;
    
    if(ans[0] < 'A') password += (ans[0] - '0') * 32 * 32;
    else password += (ans[0] - 'A' + 10) * 32 * 32;
    
    if(cnt > 9) printf("#%d %d %d\n", t, 18-cnt, password);
    else printf("#%d %d %d\n", t, cnt, password);
  }
  
  return 0;
}

/*

3
15 0CPSF6D9ELA43ITVKN
15 0CPSF6D9ELA43NKNKN
4 OUFMDHJSBEPGVC36L4
-----------------------------------
#1 2 26511
#2 3 24215
#3 8 11737

*/