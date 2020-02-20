/*

문제
구간은 [s, e] 로 나타내고, 이 의미는 s, (s+1), (s+2), …, (e-1), e 와 같이 숫자를 나열한 것을 의미한다. 
예를 들어, [1, 4]는 1, 2, 3, 4로 숫자를 나열한 것을 의미한다. 
n개의 구간이 있고, 이 구간들의 숫자를 모두다 새로운 배열 S에 넣어 정렬을 한다. 
이 때 S[i] 의 값이 무엇인지 출력하는 프로그램을 작성하시오. 
예를 들어, 3개의 구간 [1, 3], [2, 10], [1, 8] 이 있고, S[5]를 알고싶다고 하자. 
그러면 S = [1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10] 이 되고, 따라서 S[5]는 3이 된다. 
배열의 인덱스는 0부터 시작한다는 것에 주의하자.

 

입력
첫 번째 줄에 구간의 개수 n이 주어진다 ( 1 ≤ n ≤ 10,000 ) 
두 번째 줄부터 각 구간을 나타내는 숫자 s, e가 주어진다. ( 1 ≤ s ≤ e ≤ 1,000,000,000 ) 
그 후, 마지막 줄에는 값을 알고 싶은 숫자의 위치 i가 주어진다. ( 1 ≤ i ≤ 10,000,000,000,000 ) 
i번째 위치에는 항상 숫자가 존재한다고 가정한다.  

출력
S[i]를 출력한다.  


예제 입력
2
1 4
3 5
3
예제 출력
3

예제 입력
3
1 3
2 10
1 8
5
예제 출력
3

*/

/*

처음에 떠오른 구현 방법은 당연히 완전탐색이었다.
하지만 구간의 개수가 최대 10,000개이며, 구간을 나타내는 숫자가 최대 1,000,000,000까지 있기에
입력 받아서 배열에 카운트한다고 해도 입력에만 10,000 * 1,000,000,000 번의 시간이 소요되며,
위치 i의 숫자를 찾기 위해서 정렬을 하고, 탐색을 하면 또 많은 시간이 소요될 수밖에 없었다.

그래서 탐색 시간을 줄이기 위해, 이분 탐색을 생각해보았다.
어떤 부분에서 이분 탐색을 이용해보면 좋을지 생각을 하다가 "숫자 x는 몇 번째일까?" 라는 아이디어를 얻게 되었다.

예를 들어 구간 [1, 3], [2, 10], [1, 8]이 주어지고,
1(최솟값)을 start로, 11(최댓값+1)을 end로 둔다면 mid는 6이 될 것이다.
(start는 정답인 수보다 작거나 같은 수, end는 정답인 수보다 큰 수로 정의했기 때문에 end는 최댓값에서 +1을 해주었다.)
그리고 여기서 6이 몇 번째인지 계산하면 12번째라는 답이 나온다.

원하는 i가 만약 5라면, mid인 6이 12번째 이므로 원하는 번째의 수는 mid보다 이전에 존재한다.
따라서 구간이 start ~ end에서 start ~ mid로 좁혀지게 되는 것이다.

이를 계속 반복하고, start + 1 == end가 될 때까지 반복문을 돌리면,
최종적으로 start의 값이 i번째에 존재하는 수가 된다.

*/

#include <stdio.h>
#include <vector>

using namespace std;

const int MAX = 10000 + 10;

int n;
vector<pair<int, int>> se;
long long i;

long long getOrder(int value) {
  // 정렬된 수에서 가장 처음나오는 value가 몇 번째 수인지 반환하는 함수
  long long sum = 0;
  for(int i=0; i<se.size(); i++) {
    int s, e;
    
    // 구간의 시작이 value보다 크거나 같다면 value의 번째에 영향을 주지 않으므로 넘어간다.
    if(se[i].first >= value) continue;
    
    // 구간의 끝이 value보다 크거나 같다면 구간의 시작부터 value 이전까지만 카운트하고,
    // 작다면 구간의 시작부터 구간의 끝까지 카운트한다.
    if(se[i].second >= value) sum += value - se[i].first;
    else sum += se[i].second - se[i].first + 1;
  }
  
  return sum;
}

int main() {
  scanf("%d", &n);
  
  int start = 987987987, end = -987987987;
  for(int i=0; i<n; i++) {
    int s, e;
    scanf("%d %d", &s, &e);
    
    se.push_back(make_pair(s, e));
    
    if(s < start) start = se[i].first;
    if(e > end) end = se[i].second;
  }

  end++;
  
  scanf("%lld", &i);
  
  long long myOrder;

  while(start + 1 < end) {
    // start: 정답인 수보다 작거나 같은 수
    // end: 정답인 수보다 큰 수
    int mid = (start + end) / 2;
    
    myOrder = getOrder(mid);
    
    // 정답인 수보다 크다면 end를 mid로, 작거나 같다면 start를 mid로 바꿔준다.
    if(myOrder > i) end = mid;
    else start = mid;
  }
  
  printf("%d\n", start);
    
  return 0;
}