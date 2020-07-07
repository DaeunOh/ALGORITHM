/*

▶ 소요시간 및 실행시간
34분, 0ms

▶ 문제
참가자에게 주어진 연산 수식이 담긴 문자열이 매개변수로 주어질 때, 우승 시 받을 수 있는 가장 큰 상금 금액을 구하시오.

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/67257

▶ 풀이
수식에 나오는 연산자를 가지고 우선순위를 재정의하면서 수식을 계산하고, 이 중 가장 큰 결과값(절댓값)을 구하는 문제.

전체적인 수행 과정은 다음과 같다.
1) 수식을 보면서 숫자와 연산자를 나누어 벡터에 저장하고, 연산자의 종류도 중복되지 않도록 추가적으로 저장한다.
2) 연산자의 종류에 따라 여러 개의 우선순위 조합을 생성한다.
3) 우선순위 조합에 따라 숫자들을 계산한다.
4) 절댓값이 가장 큰 결과값을 찾는다.

가장 먼저 우선순위를 재정의하기 위해서는 연산자가 총 몇 개가 나오는지 확인해야 하는데,
수식에는 최소 1개, 최대 3개의 연산자가 있으며 이는 중복해서 나타날 수 있다.
따라서 중복을 허용하지 않는 set을 이용하여 몇 종류의 연산자가 나오는지 확인하는 과정이 필요하다.

또한, 값을 계산하기 위해서는 수식에서 숫자 부분과 연산자 부분을 따로 저장해야 한다.
따라서 수식의 앞에서부터 끝까지 보면서 연산자가 나오기 전까지의 숫자를 하나의 숫자로 보도록 구현해야 한다.
즉, 연산자가 나오기 전까지는 num이라는 string에 숫자를 누적시키다가 연산자가 나오는 순간에는
누적된 num을 숫자 벡터에 넣고, 연산자를 연산자 벡터에 넣은 후 num을 다시 빈 문자열로 초기화 시켜주는 것이다.
또한, 가장 마지막 숫자는 뒤에 연산자가 없으므로 추가적으로 벡터에 한 번 더 넣어주도록 한다.

이후에는 연산자의 종류를 이용하여 우선순위 조합을 만들고, 이에 따라 값을 계산하는 것이 필요하다.
이 부분에서는 2가지 방법을 이용할 수 있다.

(1) 두 숫자를 연산을 하고, 그 연산 결과를 항상 왼쪽 수의 위치에 저장하는 방식.
    연산 결과를 항상 왼쪽 숫자의 위치에 저장하고, 오른쪽 숫자의 위치에는 -1을 저장하게 되면,
    현재 계산해야 할 연산자를 기준으로 -1이 아닌 가장 가까이에 있는 숫자가 연산의 왼쪽 수가 되며,
    오른쪽 수는 항상 연산자의 +1에 존재하게 된다.
    따라서 결과값은 항상 숫자 벡터의 0번째 인덱스에 존재하도록 결과값을 구할 수 있다.

(2) 두 숫자를 연산을 하고, 그 연산 결과를 항상 왼쪽 수의 위치에 저장하되, 벡터에서 이미 사용된 숫자와 연산자는 제거하는 방식.
    이는 erase를 이용하여 이미 연산에 사용된 숫자와 연산자는 다시 보지 않도록 제거하는 방법이다.
    이렇게 되면 별도의 인덱스를 저장하지 않고도 항상 j번째 자리의 수는 업데이트하고, j+1번째 자리의 수는 없애게 되므로
    계산 결과를 훨씬 직관적으로 구할 수 있다.
    이 역시도 결과값은 항상 숫자 벡터의 0번째 인덱스에 존재한다.

▶ 후기

위에서 우선순위 조합에 따라 연산을 할 때,
1번째 방법은 내 머릿속에서 나온 아이디어고, 2번째 방법은 다른 사람의 풀이를 참고한 것이다.

2번째 방법처럼 아예 숫자와 연산자를 제거해가면서 결과값을 구하는 방식은 생각하지 못했었는데,
내 방법보다는 2번째 방법이 더 직관적이고 좋은 방법이라고 생각한다.

시간이 꽤 오래 걸린 것 같아서 조금 아쉬웠던 문제.
내 풀이는 직관적인 풀이가 아니라 조금 생각이 필요한 풀이기 때문에 조금 오래걸린 것 같다.
쉬운 코드를 작성하는 데에도 많은 노력이 필요한 것 같다.

*/

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<long long> nums;
vector<char> ops;

set<char> s;
set<char>::iterator it;
vector<char> seq;

long long solution(string expression) {
    long long answer = 0;
    
    string num = "";
    for(int i=0; i<expression.size(); i++) {
        if(isdigit(expression[i])) num += expression[i];
        else {
            nums.push_back(stoi(num));
            ops.push_back(expression[i]);
            s.insert(expression[i]);
            num = "";
        }
    }
    nums.push_back(stoi(num));
    
    for(it=s.begin(); it!=s.end(); it++) seq.push_back(*it);
    
    do {
        vector<long long> temp_nums = nums;
        for(int i=0; i<seq.size(); i++) {
            for(int j=0; j<ops.size(); j++) {
                if(seq[i] == ops[j]) {
                    int idx;
                    
                    for(int k=j; k>=0; k--) {
                        if(temp_nums[k] == -1) continue;
                        idx = k;
                        break;
                    }
                    
                    if(seq[i] == '+') {
                        temp_nums[idx] = temp_nums[idx] + temp_nums[j+1];
                        temp_nums[j+1] = -1;
                    }
                    else if(seq[i] == '-') {
                        temp_nums[idx] = temp_nums[idx] - temp_nums[j+1];
                        temp_nums[j+1] = -1;
                    }
                    else {
                        temp_nums[idx] = temp_nums[idx] * temp_nums[j+1];
                        temp_nums[j+1] = -1;
                    }
                }
            }
        }
        
        answer = max(answer, abs(temp_nums[0]));
    } while(next_permutation(seq.begin(), seq.end()));
    
    return answer;
}

/*

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<long long> nums;
vector<char> ops;

set<char> s;
set<char>::iterator it;
vector<char> seq;

long long solution(string expression) {
    long long answer = 0;
    
    string num = "";
    for(int i=0; i<expression.size(); i++) {
        if(isdigit(expression[i])) num += expression[i];
        else {
            nums.push_back(stoi(num));
            ops.push_back(expression[i]);
            s.insert(expression[i]);
            num = "";
        }
    }
    nums.push_back(stoi(num));
    
    for(it=s.begin(); it!=s.end(); it++) seq.push_back(*it);
    
    do {
        vector<long long> temp_nums = nums;
        vector<char> temp_ops = ops;
        
        for(int i=0; i<seq.size(); i++) {
            for(int j=0; j<temp_ops.size(); j++) {
                if(seq[i] == temp_ops[j]) {
                    if(seq[i] == '+')
                        temp_nums[j] = temp_nums[j] + temp_nums[j+1];
                    else if(seq[i] == '-')
                        temp_nums[j] = temp_nums[j] - temp_nums[j+1];
                    else
                        temp_nums[j] = temp_nums[j] * temp_nums[j+1];
                    
                    temp_nums.erase(temp_nums.begin() + j + 1);
                    temp_ops.erase(temp_ops.begin() + j);
                    j--;
                }
            }
        }
        
        answer = max(answer, abs(temp_nums[0]));
    } while(next_permutation(seq.begin(), seq.end()));
    
    return answer;
}

*/