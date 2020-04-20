// 소요시간: 58분
// 실행시간: 최대 1.51ms

/*

문제 설명
초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

제한사항
prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
prices의 길이는 2 이상 100,000 이하입니다.
입출력 예
prices	return
[1, 2, 3, 2, 3]	[4, 3, 1, 1, 0]
입출력 예 설명
1초 시점의 ₩1은 끝까지 가격이 떨어지지 않았습니다.
2초 시점의 ₩2은 끝까지 가격이 떨어지지 않았습니다.
3초 시점의 ₩3은 1초뒤에 가격이 떨어집니다. 따라서 1초간 가격이 떨어지지 않은 것으로 봅니다.
4초 시점의 ₩2은 1초간 가격이 떨어지지 않았습니다.
5초 시점의 ₩3은 0초간 가격이 떨어지지 않았습니다.

*/

/*

첫 시도에서 O(N^2)으로 풀고, 효율성까지 통과했지만,
스택을 사용한다면 O(N)까지 줄일 수 있다는 소문을 듣고 다시 도전한 문제!!
사실 스택을 사용해야 한다는 힌트를 몰랐다면 아마 완탐으로 푼 O(N^2)의 방법만 풀고 끝났을 것 같다.
그래도 한 문제를 여러 시각에서 바라본다는 것 자체가 중요하니 의미는 있었다고 생각한다!

이 문제를 풀기 위해서 나는 answer의 사이즈를 미리 prices.size()로 초기화해놓고,
push_back이 아닌 인덱스로 접근하게끔 만들었다.
그리고 pair<int, int>를 담는 스택을 하나 선언하여 first에는 price를 넣고,
second에는 해당 가격이 몇 번째인지에 대한 인덱스를 넣었다.

이후 price를 한 개씩 푸쉬해야 하는데 푸쉬하기 전에 top의 가격과 현재 가격을 비교하는 과정을 추가했다.
만약 top에 있는 price가 현재 price보다 크다면 top에 있는 price는 가격이 떨어진 것을 의미하므로
해당 인덱스의 answer는 그 즉시 "현재 price의 인덱스(i) - top의 인덱스(second)"로 변경하고, top에 있는 건 pop하도록 구현했다.

이와 같은 과정을 스택이 빌 때까지, 또는 top에 있는 price가 현재 price보다 작거나 같을 때까지 반복시키고,
맨 마지막에는 price와 index를 푸쉬하도록 구현했다.
(이렇게 되면 중간에 가격이 떨어지는 경우가 생기는 가격들만 떨어지지 않은 기간이 answer에 들어가게 된다.)

모든 price를 한 번 다 돌았다면, 이후 스택이 빌 때까지 탑에 있는 price에 대해 answer을 정해준다.
즉, 해당 answer은 끝까지 한 번도 가격이 떨어지지 않았다는 얘기이므로 "prices.size() - second - 1"이 된다.

결과적으로 stack을 이용한 해당 코드는 O(N)의 시간 복잡도로 해결할 수 있게 된다. ㅎㅎ^_^
다시 풀어보길 잘한 것 같다 ㅎㅎㅎㅎㅎㅎㅎㅎ~

아 근데, 지금 다시 코드를 리뷰하면서 생각이 든 건데,
pair를 이용해 price와 index를 저장하지 않아도, 스택에 index만 저장해 놓는다면,
index를 이용하여 price에 접근할 수 있었다!!!....

즉, s.push(i)를 사용하게 되면 해당 스택에는 index가 들어가는 것이므로
s.top().first를 prices[s.top()]으로 대체할 수 있게 되는 것이다 ㄷㄷㄷ
그리고 s.top().second도 그냥 s.top()으로 사용할 수 있게 된다..!

괜히 pair를 사용해서 메모리를 더 낭비한 것 같다..! 다음에는 실수하지 말아야징 ㅎㅎ ㅠㅠ

*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> s; // price, index
    int pSize = prices.size();
    
    for(int i=0; i<pSize; i++) {
        while(!s.empty() && s.top().first > prices[i]) {
            answer[s.top().second] = i-s.top().second;
            s.pop();
        }
        s.push(make_pair(prices[i], i));
    }
    
    while(!s.empty()) {
        answer[s.top().second] = pSize - s.top().second - 1;
        s.pop();
    }
    
    return answer;
}