/*

문제 설명
[본 문제는 정확성과 효율성 테스트 각각 점수가 있는 문제입니다.]

카카오 초등학교의 니니즈 친구들이 라이언 선생님과 함께 
가을 소풍을 가는 중에 징검다리가 있는 개울을 만나서 건너편으로 건너려고 합니다. 
라이언 선생님은 니니즈 친구들이 무사히 징검다리를 건널 수 있도록 다음과 같이 규칙을 만들었습니다.

징검다리는 일렬로 놓여 있고 각 징검다리의 디딤돌에는 모두 숫자가 적혀 있으며
디딤돌의 숫자는 한 번 밟을 때마다 1씩 줄어듭니다.
디딤돌의 숫자가 0이 되면 더 이상 밟을 수 없으며 이때는 그 다음 디딤돌로 한번에 여러 칸을 건너 뛸 수 있습니다.
단, 다음으로 밟을 수 있는 디딤돌이 여러 개인 경우 무조건 가장 가까운 디딤돌로만 건너뛸 수 있습니다.
니니즈 친구들은 개울의 왼쪽에 있으며, 개울의 오른쪽 건너편에 도착해야 징검다리를 건넌 것으로 인정합니다.
니니즈 친구들은 한 번에 한 명씩 징검다리를 건너야 하며, 
한 친구가 징검다리를 모두 건넌 후에 그 다음 친구가 건너기 시작합니다.

디딤돌에 적힌 숫자가 순서대로 담긴 배열 stones와 한 번에 건너뛸 수 있는 디딤돌의 최대 칸수 k가 매개변수로 주어질 때, 
최대 몇 명까지 징검다리를 건널 수 있는지 return 하도록 solution 함수를 완성해주세요.

[제한사항]
- 징검다리를 건너야 하는 니니즈 친구들의 수는 무제한 이라고 간주합니다.
- stones 배열의 크기는 1 이상 200,000 이하입니다.
- stones 배열 각 원소들의 값은 1 이상 200,000,000 이하인 자연수입니다.
- k는 1 이상 stones의 길이 이하인 자연수입니다.

[입출력 예]
stones	k	result
[2, 4, 5, 3, 2, 1, 4, 2, 5, 1]	3	3

입출력 예에 대한 설명
입출력 예 #1

첫 번째 친구는 다음과 같이 징검다리를 건널 수 있습니다.
step_stones_104.png

첫 번째 친구가 징검다리를 건넌 후 디딤돌에 적힌 숫자는 아래 그림과 같습니다.
두 번째 친구도 아래 그림과 같이 징검다리를 건널 수 있습니다.
step_stones_101.png

두 번째 친구가 징검다리를 건넌 후 디딤돌에 적힌 숫자는 아래 그림과 같습니다.
세 번째 친구도 아래 그림과 같이 징검다리를 건널 수 있습니다.
step_stones_102.png

세 번째 친구가 징검다리를 건넌 후 디딤돌에 적힌 숫자는 아래 그림과 같습니다.
네 번째 친구가 징검다리를 건너려면, 세 번째 디딤돌에서 일곱 번째 디딤돌로 네 칸을 건너뛰어야 합니다. 
하지만 k = 3 이므로 건너뛸 수 없습니다.
step_stones_103.png

따라서 최대 3명이 디딤돌을 모두 건널 수 있습니다.

*/

/*

이분탐색을 통해 징검다리를 건널 수 있는 친구들의 수를 구하는 문제.
사실 이 문제는 잘만 생각해보면 "OOOOOOXXXXX"의 패턴이 보이는 문제인데,
이걸 빠르게 캐치하지 못하고 map으로 접근했다가 시간만 버리게 된.... 안타까운 사연이 있다..
(이전 문제가 map을 사용하는 문제여서 더 그랬던 것 같다..ㅎ)

정답을 구하기 위해 생각해봐야 할 것은 총 두가지이다.
1) M번째 친구가 징검다리를 건널 수 있다면, 첫 번째 ~ M-1번째 친구들 또한 징검다리를 건널 수 있다.
    따라서 정답은 M이상 MAX이하가 된다.
2) M번째 친구가 징검다리를 건널 수 없다면, M번째 ~ MAX번째 친구들 또한 징검다리를 건널 수 없다.
    따라서 정답은 0이상 M-1이하가 된다.
바로 이러한 특징 때문에 바로 "OOOOOOXXXXX"의 패턴을 얻어낼 수 있는 것이다!

그렇다면 M번째를 어떻게 구할 수 있을까? 그건 바로 중간값을 이용하는 것이다.
중간값을 구하기 위해 사용하는 변수를 start, end라고 하자.
그리고 start는 정답이 되는 수보다 항상 작거나 같은 수, end는 정답이 되는 수보다 항상 큰 수로 정의한다면,
중간값인 mid는 (start + end) / 2가 된다. (또한 초기 end의 값은 MAX가 아닌 MAX+1임에 유의하자!)
또한, mid를 찾는 것이 끝나는 시점은 start와 end가 붙어있을 경우, 즉 start + 1이 end가 되는 경우이다.

mid를 구하고 나면 징검다리에 적혀있는 수들을 보면서, mid보다 작은 수들은 다 0으로 생각한다.
그리고 연속적으로 0이 나오는 구간의 수를 세면서, 0이 연속으로 K개 나오는 구간이 있는지 확인한다.

만약 그런 구간이 있다면, mid번째 친구는 징검다리를 건널 수 없다는 얘기고, 정답은 0이상 mid-1이하에 존재하게 된다.
따라서 start와 end의 특성에 맞춰서 값을 새로 정의하게 되면, start는 변화가 없고, end만 mid로 변경한다.
(end는 정답이 되는 수보다 항상 작으므로 mid-1이 아닌 mid로 설정해줘야 한다!)

하지만 만약 그런 구간이 없다면, mid번째 친구는 징검다리를 건널 수 있다는 얘기고, 정답은 mid이상 MAX이하에 존재하게 된다.
따라서 start와 end의 특성에 맞춰서 값을 새로 정의하게 되면, start를 mid로 변경하고, end는 그대로 둔다.

이와 같은 단계를 start + 1 == end가 될 때까지 반복하게 되면, 최종적으로는 start가 가리키는 값이 정답이 된다!

효율성 문제가 나올 때 이분탐색을 고려하고자 한다면, 무턱대고 시작하거나 무턱대고 버리는 것이 아니라
"OOOOOOXXXXX"의 패턴이 있는지 확인하자!!!!!!!
또한, 만약 효율성 문제가 아니라면, 완전탐색을 가장 먼저 생각해보자!!!!!
(효율성 문제가 아님에도 이분탐색을 사용해야 할 경우도 있으니 주의!)

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int start = 0, end = 0;
    for(auto& s : stones) end = max(end, s);
    end++;
    
    while(start + 1 != end) {
        int mid = (start + end) / 2;
        
        int cnt = 0;
        for(auto& s : stones) {
            if(s < mid) {
                if(++cnt == k) break;
            }
            else {
                cnt = 0;
            }
        }
        
        if(cnt == k) end = mid;
        else start = mid;
    }
    
    answer = start;
    
    return answer;
}