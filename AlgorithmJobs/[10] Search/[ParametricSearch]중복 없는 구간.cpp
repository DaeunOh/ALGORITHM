/*

문제
n개의 숫자가 주어지고, 이 중에서 r개의 연속된 숫자를 선택했을 때, 
이 연속 부분 내에는 숫자가 중복되지 않기를 원한다. 
예를 들어, 다음과 같이 10개의 숫자에서 3개의 연속된 숫자를 선택할 수 있다.

중복없는구간

이렇게 선택을 하면, 선택된 숫자들 사이에서는 중복이 존재하지 않는다. 
r의 최댓값을 구하는 프로그램을 작성하시오. 위의 경우, 
(4, 2, 1, 3)을 선택하면 되므로 r의 최댓값은 4이다. 
r이 5 이상이 될 경우, 중복 없이 연속 부분을 선택하는 것이 불가능하다.

 

입력
첫째 줄에는 숫자의 개수 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 
둘째 줄에 n개의 숫자가 주어진다. 
각 숫자는 항상 1보다 크거나 같고, n보다 작거나 같다.  

출력
r의 최댓값을 출력한다.

 

예제 입력
10
1 3 1 2 4 2 1 3 2 1
예제 출력
4
 

예제 입력
7
7 1 4 2 5 3 6
예제 출력
7

*/

/*

### 두 번째 시도 ###
이분 탐색으로 범위를 점점 좁혀나가는 방식을 이용해 다시 구현해보았다.
이 방법이 가장 효율적인지는 모르겠지만 queue보다 코드가 조금 더 복잡해지고, 헷갈리기도 했다.


전체적인 메커니즘은 다음과 같다.

1) start를 "정답이 되는 수보다 작거나 같은 수", end를 "정답이 되는 수보다 큰 수" 로 두고,
   이분 탐색을 위해 mid를 구한다.

2) 맨 처음에는 mid를 한 단위로 보고, 앞에서부터 탐색하며 visited 배열을 1씩 증가시킨다.
    그리고 visited 배열이 2가 되는 시점에는 twoNum을 1 증가시킨다.
   (이때 주의할 점은 업데이트 하고 나서의 수가 "2"일 때만 카운트 하는 것이다.
    2 이상일 때도 카운트를 하면 중복된 수에 대한 카운트가 되어 버린다.)

3) 그 이후부터는 mid를 한 단위로 보되, 이전 인덱스의 visited 배열을 1 감소시키고,
   감소시키고 나서 1이 되는 시점에는 twoNum 또한 1 감소시킨다.
   그리고 새로 추가되는 부분의 visited 배열을 1 증가시키고, 2면 이전과 같이 1 증가시킨다.

4) 반복문이 진행될 때마다 맨 마지막에는 twoNum이 0인지 확인한다.
   만약 twoNum이 0이라면 mid 크기의 연속된 부분이 존재한다는 뜻이기 때문에
   그 즉시 반복문을 빠져나가고 start를 mid로 업데이트 시켜준다.
   만약 반복문이 모두 끝날 때까지 0이 되지 않는다면 end를 mid로 업데이트 시켜준다.

5) start + 1 == end를 만족 할 때까지 while문을 돌리면, 최종적으로는 start가 정답이 된다.
   (OOOOXXXX의 패턴임)

*/

#include <stdio.h>
#include <cstring>

const int MAX = 100000 + 10;

int n;
int num[MAX];
int visited[MAX] = {0, };

int main() {
  scanf("%d", &n);
  
  for(int i=1; i<=n; i++) scanf("%d", &num[i]);
  
  int start = 1, end = n+1;
  while(start + 1 < end) {
    int mid = (start + end) / 2;
    
    // mid가 되는지 확인
    memset(visited, 0, sizeof(visited));
    int twoNum = 0;
    for(int i=1; i<=n-mid+1; i++) {
      if(i == 1) {
        for(int j=1; j<=mid; j++) {
          visited[num[j]]++;
          if(visited[num[j]] == 2) twoNum++;
        }
      }
      else {
        visited[num[i-1]]--;
        if(visited[num[i-1]] == 1) twoNum--;
        
        visited[num[i+mid-1]]++;
        if(visited[num[i+mid-1]] == 2) twoNum++;
      }

      if(twoNum == 0) {
        start = mid;
        break;
      }
    }
    
    if(twoNum != 0) end = mid;
  }
  
  printf("%d\n", start);
  
  return 0;
}