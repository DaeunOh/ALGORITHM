/*

문제 설명
개발팀 내에서 이벤트 개발을 담당하고 있는 무지는 
최근 진행된 카카오이모티콘 이벤트에 비정상적인 방법으로 당첨을 시도한 응모자들을 발견하였습니다. 
이런 응모자들을 따로 모아 불량 사용자라는 이름으로 목록을 만들어서 
당첨 처리 시 제외하도록 이벤트 당첨자 담당자인 프로도 에게 전달하려고 합니다. 
이 때 개인정보 보호을 위해 사용자 아이디 중 일부 문자를 '*' 문자로 가려서 전달했습니다. 
가리고자 하는 문자 하나에 '*' 문자 하나를 사용하였고 아이디 당 최소 하나 이상의 '*' 문자를 사용하였습니다.
무지와 프로도는 불량 사용자 목록에 매핑된 응모자 아이디를 제재 아이디 라고 부르기로 하였습니다.

예를 들어, 이벤트에 응모한 전체 사용자 아이디 목록이 다음과 같다면
응모자 아이디
frodo
fradi
crodo
abc123
frodoc

다음과 같이 불량 사용자 아이디 목록이 전달된 경우,
불량 사용자
fr*d*
abc1**

불량 사용자에 매핑되어 당첨에서 제외되어야 야 할 제재 아이디 목록은 다음과 같이 두 가지 경우가 있을 수 있습니다.
제재 아이디
frodo
abc123
제재 아이디
fradi
abc123

이벤트 응모자 아이디 목록이 담긴 배열 user_id와 
불량 사용자 아이디 목록이 담긴 배열 banned_id가 매개변수로 주어질 때, 
당첨에서 제외되어야 할 제재 아이디 목록은 몇가지 경우의 수가 가능한 지 return 하도록 solution 함수를 완성해주세요.

[제한사항]
- user_id 배열의 크기는 1 이상 8 이하입니다.
- user_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
    - 응모한 사용자 아이디들은 서로 중복되지 않습니다.
    - 응모한 사용자 아이디는 알파벳 소문자와 숫자로만으로 구성되어 있습니다.
- banned_id 배열의 크기는 1 이상 user_id 배열의 크기 이하입니다.
- banned_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
    - 불량 사용자 아이디는 알파벳 소문자와 숫자, 가리기 위한 문자 '*' 로만 이루어져 있습니다.
    - 불량 사용자 아이디는 '*' 문자를 하나 이상 포함하고 있습니다.
    - 불량 사용자 아이디 하나는 응모자 아이디 중 하나에 해당하고
      같은 응모자 아이디가 중복해서 제재 아이디 목록에 들어가는 경우는 없습니다.
- 제재 아이디 목록들을 구했을 때 아이디들이 나열된 순서와 관계없이 
  아이디 목록의 내용이 동일하다면 같은 것으로 처리하여 하나로 세면 됩니다.

[입출력 예]
user_id	banned_id		result
["frodo", "fradi", "crodo", "abc123", "frodoc"]	["fr*d*", "abc1**"]	2
["frodo", "fradi", "crodo", "abc123", "frodoc"]	["*rodo", "*rodo", "******"]	2
["frodo", "fradi", "crodo", "abc123", "frodoc"]	["fr*d*", "*rodo", "******", "******"]	3

입출력 예에 대한 설명

입출력 예 #1
문제 설명과 같습니다.

입출력 예 #2
다음과 같이 두 가지 경우가 있습니다.

제재 아이디
frodo
crodo
abc123
제재 아이디
frodo
crodo
frodoc

입출력 예 #3
다음과 같이 세 가지 경우가 있습니다.

제재 아이디
frodo
crodo
abc123
frodoc
제재 아이디
fradi
crodo
abc123
frodoc
제재 아이디
fradi
frodo
abc123
frodoc

*/

/*

경우의 수를 세는게 꽤나 복잡해 보이지만, 단순하게 단계를 나눠보면 다음과 같다.
1) 밴 아이디를 보면서 나머지 유저 아이디들과 매칭되는가 확인한다. ('*'이면 넘어간다)
2) i번째 밴 아이디와 매칭되는 유저 아이디가 있다면 idx[i].push_back(유저 아이디 인덱스)를 실행한다.
3) 생성된 2차원 벡터 idx를 가지고 중복되지 않도록 조합을 만든다.
4) 생성된 조합을 오름차순으로 정렬한 후, 이미 정답으로 처리된 아이디와 겹치는지 확인하여 겹치지 않는 것만 v에 넣는다.
5) v의 사이즈가 곧 answer이 된다.

3)까지는 무난하게 구현했으나, 4)가 알고 있던 지식 내에서는 꽤 복잡했다.
또한, 4번의 경우 이미 나온 목록과 중복되지 않도록 하기 위해 생성된 조합을 오름차순으로 정렬한 후
이미 나온 목록과 비교해서 겹치지 않는지 확인하는 부분이 있는데,
구한 조합 자체를 sort함수로 정렬해버렸기 때문에 구한 조합이 망가지는 경우를 경험했다;;;
(이 때문에 꽤 시간을 많이 소비했다 ㅠㅠ 처음에는 sort가 이상한줄 알았다.....)

따라서 오름차순으로 정렬하기 전에 comb를 copy해놓아야 하고, 그걸 오름차순으로 정렬해서 비교해야 한다!!! 꼭!!!
또한, v의 뒷부분에 정답으로 채택된 조합이 넣어져야 하는데, 뒷부분이 어느 인덱슨지 확인할 방법이 없어서
answer를 매번 정답이 구해질 때 증가시키면서 answer 자리에 조합의 요소를 push_back 하는 방법을 사용했다.

**** 하지만 굳이 이렇게 구현하지 않아도, 빈 vector를 하나 생성하고 comb에 있는 원소를 빈 vector에 옮겨 담은 후
그 vector를 v에 push_back하면 진행된 인덱스가 몇 번인지 알 필요가 없어진다!!! ****

그리고 사실은 이 방식을 사용하지 않아도 중복된 목록은 알아서 중복처리 해주는 set이라는 좋은 라이브러리가 있다.
set은 insert에 의해 삽입되면 자동 정렬되며, 중복을 허용하지 않는다는 특성을 가지고 있으므로
구한 조합을 1차원 set에 넣고, 그 set을 다시 2차원 set에 넣는 방식을 사용하면
중복이 없는 목록들이 알아서 생성된다 ㅠㅠㅠ..... 눈물....

예시를 들어 설명하자면,
set<set<int>> s;
set<int> tmp1, tmp2;
tmp1.insert(3); tmp1.insert(2);
s.insert(tmp1);
tmp2.insert(2); tmp2.insert(3);
s.insert(tmp2);
을 하고, s의 사이즈를 출력하면 {3, 2} {2, 3}은 동일한 것으로 보므로 1이 출력된다.
잘 알아두면 유용하게 사용할 수 있다!!

그리고 또 사실!!!! (카카오 해설에서 참고한 내용이며, 주석처리 해놓은 코드 내용이다!)
응모자 아이디 목록의 길이가 N, 불량 사용자 아이디 목록의 길이가 K 일 때, 
응모자 아이디 N개 중 K개를 선택하는 모든 방법을 시도해도 된다!!
선택된 아이디 목록이 불량 사용자 목록으로 매핑될 수 있다면 카운트를 하나 증가시키고,
최종적으로 매핑에 성공한 횟수를 반환하면 되기 때문이다!

매번 웬만한 문제는 완전탐색으로 시작했는데... 대체 왜 이건 그러지 않았는지 하아....
역시 모든 문제는...완전탐색으로 접근해보는게 최고다 하하!

많은 걸 깨닫게 해준 문제.... 감사합니다!

*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> idx;
vector<vector<int>> v(100);

int comb[10];
int copyComb[10];
bool check[10] = {false, };
int answer = 0;

void getComb(int x, int bSize) {
    if(x >= bSize) {
        for(int i=0; i<bSize; i++) copyComb[i] = comb[i];
        sort(copyComb, copyComb + bSize);
        
        bool flag1 = false;
        for(int i=0; i<answer; i++) {
            bool flag2 = false;
            for(int j=0; j<v[i].size(); j++) {
                if(v[i][j] != copyComb[j]) {
                    flag2 = true;
                    break;
                }
            }
            
            // 같은게 있는 경우
            if(!flag2) {
                flag1 = true;
                break;
            }
        }
        
        if(!flag1) {
            for(int i=0; i<bSize; i++) {
                v[answer].push_back(copyComb[i]);
            }
            
            answer++;
        }
    }
    else {
        for(int i=0; i<idx[x].size(); i++) {
            if(!check[idx[x][i]]) {
                check[idx[x][i]] = true;
                comb[x] = idx[x][i];
                
                getComb(x+1, bSize);
                
                check[idx[x][i]] = false;
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    idx.resize(banned_id.size());
    
    for(int i=0; i<banned_id.size(); i++) {
        for(int j=0; j<user_id.size(); j++) {
            // 사이즈가 다른 경우
            if(banned_id[i].size() != user_id[j].size()) continue;
            
            // 사이즈가 같은 경우
            bool flag = false;
            for(int k=0; k<user_id[j].size(); k++) {
                if(banned_id[i][k] == '*') continue;
                
                if(banned_id[i][k] != user_id[j][k]) {
                    flag = true;
                    break;
                }
            }
            
            // 매칭되는 경우
            if(!flag) {
                idx[i].push_back(j); // j번째 user_id가 i번째 banned_id에 매칭된다.
            }
        }
    }
    
    getComb(0, banned_id.size());
    
    return answer;
}

// set과 BF를 이용한 풀이 방법
/*
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<string> U, B;

int comb[10];
bool check[10] = {0, };
set<set<int>> S;

void getComb(int x) {
    if(x >= B.size()) {
        bool flag = false;
        for(int i=0; i<B.size(); i++) {
            string user = U[comb[i]];
            string ban = B[i];
            
            if(user.size() != ban.size()) {
                flag = true;
                break;
            }
            
            for(int j=0; j<ban.size(); j++) {
                if(ban[j] == '*') continue;
                
                if(ban[j] != user[j]) {
                    flag = true;
                    break;
                }
            }
            
            if(flag) break;
        }
        
        if(!flag) {
            set<int> temp;
            for(int i=0; i<B.size(); i++) temp.insert(comb[i]);
            S.insert(temp);
        }
    }
    else {
        for(int i=0; i<U.size(); i++) {
            if(!check[i]) {
                check[i] = true;
                comb[x] = i;
                getComb(x+1);
                check[i] = false;
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    U = user_id;
    B = banned_id;
    
    getComb(0);
    
    answer = S.size();
    
    return answer;
}
*/