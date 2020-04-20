// 소요시간: 37분
// 실행시간: 최대 66ms

/*

카카오톡 오픈채팅방에서는 친구가 아닌 사람들과 대화를 할 수 있는데, 
본래 닉네임이 아닌 가상의 닉네임을 사용하여 채팅방에 들어갈 수 있다.
신입사원인 김크루는 카카오톡 오픈 채팅방을 개설한 사람을 위해, 
다양한 사람들이 들어오고, 나가는 것을 지켜볼 수 있는 관리자창을 만들기로 했다. 

채팅방에 누군가 들어오면 다음 메시지가 출력된다.
"[닉네임]님이 들어왔습니다."

채팅방에서 누군가 나가면 다음 메시지가 출력된다.
"[닉네임]님이 나갔습니다."

채팅방에서 닉네임을 변경하는 방법은 다음과 같이 두 가지이다.
1) 채팅방을 나간 후, 새로운 닉네임으로 다시 들어간다.
2) 채팅방에서 닉네임을 변경한다.

닉네임을 변경할 때는 기존에 채팅방에 출력되어 있던 메시지의 닉네임도 전부 변경된다.
예를 들어, 채팅방에 Muzi와 Prodo라는 닉네임을 사용하는 사람이 순서대로 들어오면 
채팅방에는 다음과 같이 메시지가 출력된다.
"Muzi님이 들어왔습니다."
"Prodo님이 들어왔습니다."

채팅방에 있던 사람이 나가면 채팅방에는 다음과 같이 메시지가 남는다.
"Muzi님이 들어왔습니다."
"Prodo님이 들어왔습니다."
"Muzi님이 나갔습니다."

Muzi가 나간후 다시 들어올 때, Prodo 라는 닉네임으로 들어올 경우 
기존에 채팅방에 남아있던 Muzi도 Prodo로 다음과 같이 변경된다.
"Prodo님이 들어왔습니다."
"Prodo님이 들어왔습니다."
"Prodo님이 나갔습니다."
"Prodo님이 들어왔습니다."

채팅방은 중복 닉네임을 허용하기 때문에, 현재 채팅방에는 Prodo라는 닉네임을 사용하는 사람이 두 명이 있다. 
이제, 채팅방에 두 번째로 들어왔던 Prodo가 Ryan으로 닉네임을 변경하면 채팅방 메시지는 다음과 같이 변경된다.
"Prodo님이 들어왔습니다."
"Ryan님이 들어왔습니다."
"Prodo님이 나갔습니다."
"Prodo님이 들어왔습니다."

채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 매개변수로 주어질 때, 
모든 기록이 처리된 후, 최종적으로 방을 개설한 사람이 보게 되는 메시지를 
문자열 배열 형태로 return 하도록 solution 함수를 완성하라.

제한사항
- record는 다음과 같은 문자열이 담긴 배열이며, 길이는 1 이상 100,000 이하이다.
- 다음은 record에 담긴 문자열에 대한 설명이다.
  - 모든 유저는 [유저 아이디]로 구분한다.
  - [유저 아이디] 사용자가 [닉네임]으로 채팅방에 입장 - Enter [유저 아이디] [닉네임] (ex. Enter uid1234 Muzi)
  - [유저 아이디] 사용자가 채팅방에서 퇴장 - Leave [유저 아이디] (ex. Leave uid1234)
  - [유저 아이디] 사용자가 닉네임을 [닉네임]으로 변경 - Change [유저 아이디] [닉네임] (ex. Change uid1234 Muzi)
  - 첫 단어는 Enter, Leave, Change 중 하나이다.
  - 각 단어는 공백으로 구분되어 있으며, 알파벳 대문자, 소문자, 숫자로만 이루어져있다.
  - 유저 아이디와 닉네임은 알파벳 대문자, 소문자를 구별한다.
  - 유저 아이디와 닉네임의 길이는 1 이상 10 이하이다.
  - 채팅방에서 나간 유저가 닉네임을 변경하는 등 잘못 된 입력은 주어지지 않는다.

입출력 예
record	result
["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]

*/

/*

map을 사용하여 아이디와 닉네임을 관리하고, 명령에 따라 입장 또는 퇴장 메세지를 출력하는 문제.

아이디는 유일하며 고정되어 있지만, 닉네임은 같은 닉네임이 존재할 수 있고 계속해서 바뀔 수 있기 때문에
key와 value의 특성을 이용하여 map을 사용하는 것이 편리하다.
그리고 여기서는 Enter와 Change라는 명령이 구분되어 있지만, 사실 둘의 기능은 코드 상으로는 똑같다;;ㅎㅎ
그렇기에 둘을 구분지어서 조건문을 따로 만들지 않아도 된다 ㅎ!!

또한, 여기서의 문자열은 공백으로 구분되어 있는데, 나는 이 문제를 풀기 전까지 stringstream의 존재를 몰랐기 때문에...
해당 문자열의 맨 앞글자만 보고 그게 Enter인지, Leave인지, Change인지 구분하는 방법을 사용했다.
그리고 첫번째 공백 이후부터 두번째 공백이 나오기 전까지가 유저 아이디가 되고,
두번째 공백 이후부터 맨 마지막까지가 유저 닉네임이 된다는 것을 이용하여 아이디와 닉네임을 추출하도록 했다.

또한, 닉네임 변경과 달리 입장과 퇴장은 그에 맞는 메세지가 있어야 하므로
string 쌍을 담는 벡터를 미리 선언하여, first는 "E(입장)" 또는 "L(퇴장")을 넣어주고, second는 아이디를 넣어줬다.
그렇기에 모든 추출 과정이 끝난 이후에는 벡터를 보면서 입장과 출력에 맞도록
맵에서 아이디에 해당하는 value를 찾아 answer에 push_back하도록 구현했다.

추가적으로, 문제를 다 풀고 나서 다른 사람의 풀이를 봤는데, stringstream이라는 좋은 함수가 있었다.
이 함수는 띄어쓰기 기준으로 문자열을 파싱해주는 함수이며, 사용방법은 다음과 같다.

for(string input:record) {
    stringstream ss(input);
    ss>>command;
    ss>>uid;
    if(command=="Enter" || command=="Change") {
        ss>>ID;
        m[uid]=ID;
    }
}

나는 추가적으로 벡터도 이용했기 때문에
if(커맨드가 Enter 또는 Leave일 경우) res.push_back("E 또는 L", uid);
와 같은 코드를 추가적으로 넣어주면 된다.

또한, 마지막에 정답에 맞게 변환하는 부분도
for(auto &r : res) { // 정답에 맞게 변환
    if(r.first == "E") answer.push_back(um.find(r.second)->second + "님이 들어왔습니다.");
    else if(r.first == "L") answer.push_back(um.find(r.second)->second + "님이 나갔습니다.");
}
와 같이 변경해주면 더 깔끔한 코드를 만들 수 있다.
(원래 코드에서는 find를 사용하지 않았지만, 이것 저것 알아두면 좋을 것 같아 추가해보았다 ㅎㅎ)

*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> um;
vector<pair<string, string>> res;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(auto &r : record) {
        if(r[0] == 'E' || r[0] == 'C') { // 입장, 변경
            int i = (r[0] == 'E')? 6 : 7;
            string uid = "";
            for(; i<r.size(); i++) { // 아이디 추출
                if(r[i] == ' ') break;
                else uid += r[i];
            }
            string nickname = r.substr(i+1, 10); // 닉네임 추출
            um[uid] = nickname;
            if(r[0] == 'E') res.push_back(make_pair("E", uid));
        }
        else if(r[0] == 'L') { // 퇴장
            string uid = r.substr(6, 10); // 아이디 추출
            res.push_back(make_pair("L", uid));
        }
    }
    
    for(auto &r : res) { // 정답에 맞게 변환
        string ans = um[r.second]; // 또는 um.find(r.second)->second
        if(r.first == "E") ans += "님이 들어왔습니다.";
        else if(r.first == "L") ans += "님이 나갔습니다.";
        answer.push_back(ans);
    }
    
    return answer;
}