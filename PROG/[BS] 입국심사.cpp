/*

▶ 소요시간 및 실행시간
22분, 47ms

▶ 문제
입국심사를 기다리는 사람 수, 각 심사관이 한 명을 심사하는데 걸리는 시간이 매개변수로 주어질 때, 
모든 사람이 심사를 받는데 걸리는 시간의 최솟값을 구하시오.

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/43238

▶ 풀이
모든 사람이 심사를 받는데 걸리는 시간의 최솟값을 찾기 위해 이분탐색을 이용하는 문제.

심사를 받는데 걸리는 총 시간을 time이라고 할 때,
그 time을 각 심사 시간으로 나눈 값의 정수 부분만 다 더한 값이 바로 time이라는 시간이 주어졌을 때,
심사 받을 수 있는 사람의 수와 같다는 점을 이용하는 것이다.

이 방식으로 생각해보면 time은 1초에서 엄청 큰 수(long long)까지로 설정될 수 있고,
그 수에서 XXXXXOOOO의 패턴이 나오는 지점이 있다는 것이다!
이렇게 되면 O가 처음 나오는 시점을 구하는 것이 이 문제에서 구하고자 하는 바가 된다.

저 패턴이 나오는 경우, 매번 그랬듯이 이분 탐색을 이용하면 쉽게 구할 수 있는데,
그러면 start와 end의 초기값은 어떻게 정의하고, 어떻게 설정해주어야 가장 효율적일까?

XO 패턴이기에, 나는 start를 정답보다 항상 작은 수로 정의하고,
end를 정답보다 항상 크거나 같은 수로 정의했다.

또한 각 값의 설정할 때에는 (사실 이에 대한 답이 내가 생각한 답이 맞는지는 모르겠지만)
start를 times에 존재하는 심사 시간 중 최솟값-1으로 설정했고, (n이 1일 때는 최솟값이 답이 되므로 최솟값은 포함시키면 안된다.)
end를 times에 존재하는 심사 시간 중 최솟값*n으로 설정했다. (가장 적게 걸리는 심사관만 찾아가는 방법. 답은 항상 이보다 작다.)

그리고 이후 구하는 mid에 따라 그 mid를 각 심사시간으로 나누면서 cnt를 구하게 되고,
start와 end의 정의에 따라 cnt가 n보다 작은 경우에는 start를 mid로 옮겨주고,
크거나 같은 경우에는 end를 mid로 옮겨주는 방식을 사용하여 start와 end가 붙는 순간 end의 값이 answer이 되도록 구현하면
이 문제에서 원하는 답이 된다!

또한, 이 문제에서는 값의 범위가 매우 크므로, 중간 중간에 구하는 모든 값들이
int가 아닌 long long 타입으로 선언되어야 함도 잊지 말자!

▶ 후기
처음에는 이 문제가 이분탐색 문제임을 알았음에도, 어떻게 구현해야 할지 방향조차 잡지 못했다. ㅎㅎ...
n과 times[i]의 범위가 최대 10^9이며, times의 크기 또한 최대 10^5이기 때문에, 완전탐색? 생각도 하지 않았다. ㅋㅋㅋ

그러면 대체 어떻게 심사 받는데 걸리는 시간의 최솟값을 구할 수 있을까...

가장 먼저 떠올랐던 방법은 심사를 할 수 있는 시점에서
다른 심사관을 통해 심사를 받았을 때와의 시간 차이를 이용해 최적의 방법을 알아내는 방법..!
그런데 이 방법은 사실 말은 그럴듯해 보이지만 매번 10만명의 심사관을 어떻게 비교할지는 전혀 고려하지 않은 것이다...

결국에는 어떻게 생각해봐도 문제 방향을 잡을 수가 없어,
질문하기를 이용하여 힌트를 얻어냈고... 어떤 시간을 각 심사시간으로 나누면,
그 심사관에게 간 사람들의 수를 구할 수 있음을 알게 되었다! (이렇게 생각하니까 문제가 정말 쉬워졌다.)

항상 문제를 통해 문제 해결에 대한 인사이트를 얻곤 하지만,
가끔은 문제에서 나온 방법과 다른 방향으로 생각해야 답을 구할 수 있는 문제들이 은근 있다.
한 방향만 생각하지 말고 여러 방면으로도 생각해보도록 하는 습관을 가져야겠다! :)

*/

#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long myMin = 1000000000;
    for(int i=0; i<times.size(); i++) {
        if(myMin > times[i]) myMin = times[i];
    }
    
    long long start = myMin - 1, end = myMin * n;
    while(start + 1 != end) {
        long long mid = (start + end) / 2;
        
        long long cnt = 0;
        for(int i=0; i<times.size(); i++) {
            cnt += mid / times[i];
        }
        
        if(cnt < n) start = mid;
        else end = mid;
    }
    
    answer = end;
    
    return answer;
}