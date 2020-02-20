/*

문제
KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 용액을 보유하고 있다. 
각 용액에는 그 용액의 특성을 나타내는 하나의 정수가 주어져있다. 
산성 용액의 특성값은 1부터 1,000,000,000까지의 양의 정수로 나타내고, 
알칼리성 용액의 특성값은 -1부터 -1,000,000,000까지의 음의 정수로 나타낸다. 
같은 양의 두 용액을 혼합한 용액의 특성값은 혼합에 사용된 각 용액의 특성값의 합으로 정의한다. 
이 연구소에서는 같은 양의 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 한다. 
예를 들어, 주어진 용액들의 특성값이 [-2, 4, -99, -1, 98]인 경우에는 
특성값이 -99인 용액과 특성값이 98인 용액을 혼합하면 특성값이 -1인 용액을 만들 수 있고, 
이 용액이 특성값이 0에 가장 가까운 용액이다. 
참고로, 두 종류의 알칼리성 용액만으로나 혹은 두 종류의 산성 용액만으로 특성값이 0에 가장 가까운 혼합 용액을 만드는 경우도 존재할 수 있다. 
산성 용액과 알칼리성 용액의 특성값이 주어졌을 때, 
이 중 두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액을 찾는 프로그램을 작성하시오.

 

입력
첫째 줄에는 전체 용액의 수 N이 입력된다. N은 2 이상 100,000 이하이다. 
둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 
이 수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다. 
N개의 용액들의 특성값은 모두 다르고, 산성 용액만으로나 알칼리성 용액만으로 입력이 주어지는 경우도 있을 수 있다.  

출력
첫째 줄에 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 출력한다. 
출력해야하는 두 용액은 특성값의 오름차순으로 출력한다. 
특성값이 0에 가장 가까운 용액을 만들어내는 경우가 두 개 이상일 경우에는 특성값의 최솟값이 가장 작은 숫자를 출력한다. 
해당 경우에서 특성값의 최솟값이 같은 경우는 없다고 가정한다.  


예제 입력1
5
-2 4 -99 1 98
예제 출력1
-99 98

예제 입력2
3
2 -1 -2
예제 출력2
-2 2

*/

/*

### 첫 번째 시도 ###
1) 음수 + 음수가 0에 가장 가까운 수는 음수 + 제일 큰 음수 이고,
2) 양수 + 양수가 0에 가장 가까운 수는 양수 + 제일 작은 양수 이며,
3, 4) 음수 + 양수가 0에 가장 가까운 수는 고정음수 + binary search를 통해 얻은 음수의 반대값과 가장 비슷한 수
또는 binary search를 통해 얻은 양수의 반댓값과 가장 비슷한 수 + 고정양수 이다.

그렇기 때문에 음수와 양수를 따로 벡터에 넣어서 정렬 후
고정음수 + 가변양수 를 비교해 본 후 최솟값을 찾고,
고정양수 + 가변음수 를 비교해 본 후 최솟값을 찾아서
최종적으로 1) 2) 3) 4) 중 최솟값을 구해 출력하는 방식으로 구현했다.

하지만 이렇게 따로 구현을 하다보니 배열 범위 이슈도 잦았고,
코드가 조금 복잡해졌던 단점이 있었다.

따라서 음수, 양수를 나누지 않고 다시 새롭게 구현해 보기로 했다.

*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <long long> left, right;

pair<int, int> leftMin, rightMin;

bool isFinished = false;

bool isNotFirst;

long long getAbs(long long x) {
  if(x >= 0) return x;
  else return -x;
}

void getLeftResult(int idx, int start, int end) {
  if(isFinished) return;
  
  if(start >= end) {
    if(!isNotFirst || getAbs(left[leftMin.first] + right[leftMin.second]) > getAbs(left[idx] + right[start])) {
      if(!isNotFirst) isNotFirst = true;
      
      leftMin.first = idx;
      leftMin.second = start;
    }
  }
  else {
    int mid = (start + end) / 2;
    
    if(left[idx] + right[mid] == 0) {
      isFinished = true;
      printf("%lld %lld\n", left[idx], right[mid]);
      return;
    }
    
    if(!isNotFirst || getAbs(left[leftMin.first] + right[leftMin.second]) > getAbs(left[idx] + right[mid])) {
      if(!isNotFirst) isNotFirst = true;
      
      leftMin.first = idx;
      leftMin.second = mid;
    }

    if(left[idx] + right[mid] > 0) getLeftResult(idx, start, mid-1);
    else getLeftResult(idx, mid+1, end);
  }
}

void getRightResult(int idx, int start, int end) {
  if(isFinished) return;
  
  if(start >= end) {
    if(!isNotFirst || getAbs(left[rightMin.first] + right[rightMin.second]) > getAbs(left[start] + right[idx])) {
      if(!isNotFirst) isNotFirst = true;
      
      rightMin.first = start;
      rightMin.second = idx;
    }
  }
  else {
    int mid = (start + end) / 2;
    
    if(left[mid] + right[idx] == 0) {
      isFinished = true;
      printf("%lld %lld\n", left[mid], right[idx]);
      return;
    }
    
    if(!isNotFirst || getAbs(left[rightMin.first] + right[rightMin.second]) > getAbs(left[mid] + right[idx])) {
      if(!isNotFirst) isNotFirst = true;
      
      rightMin.first = mid;
      rightMin.second = idx;
    }

    if(left[mid] + right[idx] > 0) getRightResult(idx, start, mid-1);
    else getRightResult(idx, mid+1, end);
  }
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    long long num;
    scanf("%lld", &num);

    if(num < 0) left.push_back(num);
    else right.push_back(num);
  }
  
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());
  
  isNotFirst = false;
  if(right.size() != 0) for(int i=0; i<left.size(); i++) getLeftResult(i, 0, right.size()-1);
  
  isNotFirst = false;
  if(left.size() != 0) for(int i=0; i<right.size(); i++) getRightResult(i, 0, left.size()-1);

  // 이 조건문을 추가하지 않으면 불필요한 시간을 사용하게 되기도 하며, 출력이 2번 된다.
  if(isFinished) return 0;
  
  // 특성값의 최솟값 찾기
  long long myMin = 9999999999;
  long long minA, minB;
  
  if(left.size() != 0 && right.size() != 0 && getAbs(left[leftMin.first] + right[leftMin.second]) < myMin) {
    myMin = getAbs(left[leftMin.first] + right[leftMin.second]);
    minA = left[leftMin.first];
    minB = right[leftMin.second];
  }
  
  if(left.size() != 0 && right.size() != 0 && getAbs(left[rightMin.first] + right[rightMin.second]) < myMin) {
    myMin = getAbs(left[rightMin.first] + right[rightMin.second]);
    minA = left[rightMin.first];
    minB = right[rightMin.second];
  }

  if(left.size() >= 2 && getAbs(left[left.size()-2] + left[left.size()-1]) < myMin) {
    myMin = getAbs(left[left.size()-2] + left[left.size()-1]);
    minA = left[left.size()-2];
    minB = left[left.size()-1];
  }
  
  if(right.size() >= 2 && getAbs(right[0] + right[1]) < myMin) {
    myMin = getAbs(right[0] + right[1]);
    minA = right[0];
    minB = right[1];
  }
  
  printf("%lld %lld", minA, minB);

  return 0;
}