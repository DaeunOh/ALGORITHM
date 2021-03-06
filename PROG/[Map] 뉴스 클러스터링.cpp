// 소요시간: 44분
// 실행시간: 0ms

/*

문제 설명
여러 언론사에서 쏟아지는 뉴스, 특히 속보성 뉴스를 보면 비슷비슷한 제목의 기사가 많아 정작 필요한 기사를 찾기가 어렵다. 
Daum 뉴스의 개발 업무를 맡게 된 신입사원 튜브는 
사용자들이 편리하게 다양한 뉴스를 찾아볼 수 있도록 문제점을 개선하는 업무를 맡게 되었다.

개발의 방향을 잡기 위해 튜브는 우선 최근 화제가 되고 있는 카카오 신입 개발자 공채 관련 기사를 검색해보았다.
- 카카오 첫 공채..'블라인드' 방식 채용
- 카카오, 합병 후 첫 공채.. 블라인드 전형으로 개발자 채용
- 카카오, 블라인드 전형으로 신입 개발자 공채
- 카카오 공채, 신입 개발자 코딩 능력만 본다
- 카카오, 신입 공채.. 코딩 실력만 본다
- 카카오 코딩 능력만으로 2018 신입 개발자 뽑는다

기사의 제목을 기준으로 블라인드 전형에 주목하는 기사와 코딩 테스트에 주목하는 기사로 나뉘는 걸 발견했다. 
튜브는 이들을 각각 묶어서 보여주면 카카오 공채 관련 기사를 찾아보는 사용자에게 유용할 듯싶었다.

유사한 기사를 묶는 기준을 정하기 위해서 논문과 자료를 조사하던 튜브는 자카드 유사도라는 방법을 찾아냈다.

자카드 유사도는 집합 간의 유사도를 검사하는 여러 방법 중의 하나로 알려져 있다. 
두 집합 A, B 사이의 자카드 유사도 J(A, B)는 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값으로 정의된다.

예를 들어 집합 A = {1, 2, 3}, 집합 B = {2, 3, 4}라고 할 때, 
교집합 A ∩ B = {2, 3}, 합집합 A ∪ B = {1, 2, 3, 4}이 되므로, 집합 A, B 사이의 자카드 유사도 J(A, B) = 2/4 = 0.5가 된다. 
집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1로 정의한다.

자카드 유사도는 원소의 중복을 허용하는 다중집합에 대해서 확장할 수 있다. 
다중집합 A는 원소 1을 3개 가지고 있고, 다중집합 B는 원소 1을 5개 가지고 있다고 하자. 
이 다중집합의 교집합 A ∩ B는 원소 1을 min(3, 5)인 3개, 합집합 A ∪ B는 원소 1을 max(3, 5)인 5개 가지게 된다. 
다중집합 A = {1, 1, 2, 2, 3}, 다중집합 B = {1, 2, 2, 4, 5}라고 하면, 
교집합 A ∩ B = {1, 2, 2}, 합집합 A ∪ B = {1, 1, 2, 2, 3, 4, 5}가 되므로, 자카드 유사도 J(A, B) = 3/7, 약 0.42가 된다.

이를 이용하여 문자열 사이의 유사도를 계산하는데 이용할 수 있다. 
문자열 FRANCE와 FRENCH가 주어졌을 때, 이를 두 글자씩 끊어서 다중집합을 만들 수 있다. 
각각 {FR, RA, AN, NC, CE}, {FR, RE, EN, NC, CH}가 되며, 교집합은 {FR, NC}, 합집합은 {FR, RA, AN, NC, CE, RE, EN, CH}가 되므로, 
두 문자열 사이의 자카드 유사도 J("FRANCE", "FRENCH") = 2/8 = 0.25가 된다.

입력 형식
- 입력으로는 str1과 str2의 두 문자열이 들어온다. 각 문자열의 길이는 2 이상, 1,000 이하이다.
- 입력으로 들어온 문자열은 두 글자씩 끊어서 다중집합의 원소로 만든다. 
  이때 영문자로 된 글자 쌍만 유효하고, 기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다. 
  예를 들어 ab+가 입력으로 들어오면, ab만 다중집합의 원소로 삼고, b+는 버린다.
- 다중집합 원소 사이를 비교할 때, 대문자와 소문자의 차이는 무시한다. AB와 Ab, ab는 같은 원소로 취급한다.

출력 형식
입력으로 들어온 두 문자열의 자카드 유사도를 출력한다. 
유사도 값은 0에서 1 사이의 실수이므로, 이를 다루기 쉽도록 65536을 곱한 후에 소수점 아래를 버리고 정수부만 출력한다.

예제 입출력
str1	str2	answer
FRANCE	french	16384
handshake	shake hands	65536
aa1+aa2	AAAA12	43690
E=M*C^2	e=m*c^2	65536

*/

/*

다른 풀이 방법이 많겠지만, 나는 map을 이용하여 풀었다!
이 문제에서 알파벳은 대소문자의 구분이 없으므로, 소문자와 대문자를 0부터 시작하는 숫자로 치환하고,
그 숫자를 넣은 벡터를 하나의 키로 하는 맵 2개를 사용했다.

다중집합을 만드는 것이 끝나면, 공집합인지 확인한 후 공집합이 아닐 때 다음과 같은 과정을 수행한다.
1) m1의 처음부터 끝까지 보면서, 두 집합 사이에 같은 원소가 있다면 교집합과 합집합에 min과 max를 더한다.
2) 하지만 같은 원소가 없다면 교집합은 없다는 것이므로 max만 합집합에 더한다.
3) m2의 처음부터 끝까지 보면서, 같은 원소가 없는 경우만 찾아 max를 합집합에 더한다.
4) 합집합과 교집합을 이용하여 자카드 유사도를 계산한다.

풀면서 교집합과 합집합을 찾는데 살짝 헷갈리는 점도 있었는데, 다음에 다시 한 번 풀어보면 그때는 잘 풀 수 있을 것 같다.

또한, 해설을 보니 map이 아닌 multiset을 사용하여 key의 중복을 허용하는 방법을 사용했는데,
(또한 카운트를 따로 값으로 저장하지 않고 count 함수를 사용했다.)
이 방법이 훨씬 더 간단하고 좋은 것 같다. 다음에는 중복이 허용되는 경우가 있다면 multiset을 사용해봐야겠다.
(또는 다시 한 번 풀어봐도 좋을 것 같다!!)

그리고 오늘도 역시 해설을 보면서 유용한 함수를 찾을 수 있었다.

1) 영문자인지 숫자인지 구분해주는 함수
isalnum(문자): 영문자 또는 숫자인 경우만 참을 리턴 
isalpha(문자): 문자가 영문자인 경우만 참을 리턴 
isdigit(문자): 문자가 숫자인 경우만 참을 리턴 
islower(문자): 문자가 영어 소문자인 경우만 참을 리턴 
isupper(문자): 문자가 영어 대문자인 경우만 참을 리턴 
ispunct(문자): 문자가 기호문자인 경우에만 참을 리턴 
isspace(문자): 문자가 스페이스인 경우에만 참을 리턴

2) 문자를 소문자(대문자)로 바꿔주는 함수
transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
transform(str1.begin(), str1.end(), str1.begin(), ::toupper);

때에 따라 유용하게 사용할 수 있는 좋은 함수들이다 ㅎㅎㅎ 특히 스트링에서 굿!

*/

#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<vector<int>, int> m1, m2;
map<vector<int>, int> ::iterator iter;

void createSet(string str, map<vector<int>, int> &m) {
    for(int i=0; i<str.size()-1; i++) {
        vector<int> temp;

        // 소문자와 대문자를 0부터 시작하는 숫자로 치환
        if('a' <= str[i] && str[i]<= 'z') temp.push_back(str[i] - 'a');
        else if('A' <= str[i] && str[i] <= 'Z') temp.push_back(str[i] - 'A');
        else continue;

        if('a' <= str[i+1] && str[i+1] <= 'z') temp.push_back(str[i+1] - 'a');
        else if('A' <= str[i+1] && str[i+1] <= 'Z') temp.push_back(str[i+1] - 'A');
        else {
            i++;
            continue;
        }

        // 없는 key라면 초키 카운트를 1로 설정해주고, 존재하는 key라면 카운트를 증가시킨다.
        if(m.find(temp) == m.end()) m.insert(make_pair(temp, 1));
        else m[temp]++;
    }
}

int solution(string str1, string str2) {
    int answer = 0;

    createSet(str1, m1);
    createSet(str2, m2);

    if(m1.empty() && m2.empty()) answer = 65536; // 두 집합 모두 공집합인 경우
    else {
        int A = 0; // 교집합
        int B = 0; // 합집합

        for(iter = m1.begin(); iter != m1.end(); iter++) {
            if(m2.find(iter -> first) != m2.end()) { // 둘 사이에 같은 원소가 존재하는 경우
                A += min(iter -> second, m2[iter -> first]);
                B += max(iter -> second, m2[iter -> first]);
            }
            else {
                B += iter -> second;
            }
        }

        for(iter = m2.begin(); iter != m2.end(); iter++) {
            if(m1.find(iter -> first) == m1.end()) {
                B += iter -> second;
            }
        }

        answer = (int)(((double)A/B) * 65536);
    }

    return answer;
}