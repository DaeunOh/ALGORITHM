/*

▶ 소요시간 및 실행시간
2시간 15분, 0ms

▶ 문제
검색어와 웹페이지의 HTML 목록이 주어졌을 때, 매칭점수가 가장 높은 웹페이지의 index를 구하라. 
만약 그런 웹페이지가 여러 개라면 그중 번호가 가장 작은 것을 구하라.

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/42893

▶ 풀이
HTML에 주어져 있는 태그를 이용하여 자신의 웹페이지, 외부 링크의 url을 구하고
그에 따라 매칭 점수를 계산하는 문자열 문제.

주어진 조건에 따라 HTML에 주어져 있는 주소(자신, 외부)들을 구하는 부분과,
기본점수를 위해 단어 단위로 보면서 검색 단어가 나타난 횟수를 구하는 부분만 제대로 구현하면 된다.

전체적인 수행과정은 다음과 같다.

1) 해당 문제에서는 대소문자를 구분하지 않으므로, 검색 단어(word)와 HTML 목록을 소문자로 바꿔준다.

2) 각 페이지들을 보며 meta 태그 안에 존재하는 자신의 url을 찾고, 맵에 {url, i}의 key, value 쌍을 넣어준다.
    <meta property=\"og:url\" content=로 시작하는 시점을 찾으면, 그 이후에 나오는 https://부분이 바로 자신의 url이 된다.

3) 외부 링크 url을 찾는다. 
    외부 링크는 항상 <a href으로 시작하고, 개수가 여러 개 있을 수 있다.
    따라서 while문을 이용하여 범위를 줄여가면서 <a href으로 시작하는 부분이 없을 때까지 외부 링크 탐색을 반복한다.
    즉, <a href으로 시작하는 시점이 있다면, 그 뒤에 나오는 https:// 부분이 외부 링크 주소가 되며,
    그 다음 <a href를 찾기 위해 문자열을 a태그가 끝난 시점(</a>)으로 잘라주고 다시 처음으로 돌아간다.

4) page에서 body부분의 시작과 끝을 찾고, 그 안에서 단어 단위로 문장을 자른 후, 잘라진 단어가 검색 단어와 일치하는지 확인한다.
    단어 단위로 문장을 읽기 위해서는 영문자가 아닌 문자가 나오기 전까지 단어를 누적시키고,
    영문자가 나오는 순간의 누적된 단어를 한 단어로 보면 된다.

5) 매칭 점수를 계산한다.
    모든 매칭 점수는 기본으로 자신의 기본 점수가 들어가며,
    추가적으로 다른 링크에서 자신을 외부 링크로 갖는 곳에서 점수가 들어온다.
    따라서 자신이 가지고 있는 외부 링크를 탐색하면서 자신의 링크 점수를 해당 외부 링크의 매칭점수에 더해주면 된다.
    이때, 외부 링크 중에는 맵에 없는 링크가 존재할 수도 있으므로, 맵에 없는 링크라면 점수를 더해주지 않는다.

6) 매칭 점수가 가장 크면서, 인덱스가 가장 작은 페이지의 인덱스를 반환한다.

▶ 후기
문자열을 분리하고, 원하는 문자를 찾는 문제에 대해서는 정말 자신이 있다고 생각했는데,
HTML 안에서 자신의 주소를 구하고, 외부 링크를 찾고, 검색 단어가 몇 번 나오는지 구하는 과정이 생각보다 복잡하고 까다로웠다.

실제로 meta 태그 안에 존재하는 웹페이지 url을 찾는 부분에서도 meta 태그만을 시작으로 https를 찾으면
자신의 url이 아닌 경우도 있기에 꼭 <meta property=\"og:url\" content=을 시작으로 https를 찾아야 했고,
외부 링크 url을 찾는 부분도 반복문을 이용해서 계속 찾아나가는게 생각만큼 쉽지 않았따.

또한, 가장 아이디어가 떠오르지 않았던 부분은 문자열을 단어 단위로 끊는 부분이었는데,
이 부분은 어떻게 처리해야할지 몰라서 다른 사람의 코드를 참고했다. (https://real-012.tistory.com/47)

외부 링크를 저장하는 부분에서는 굳이 set을 사용하지 않아도 됐지만,
set을 사용한지가 꽤 되어서 이터레이터를 복습할겸 한 번 사용해봤다 ㅋㅋㅋㅎㅎ

결과적으로는 문제에서 주어진 조건대로 문자열을 분리하고,
원하는 문자열을 뽑아낸 후 그에 따라 구현만 하면 되는 문제이긴 했지만,
조건이 까다롭고 문자열 분리하는게 생각만큼 쉽지가 않아서 시간이 매우 오래걸렸던 문제이다.

문자열에 대해서 아직 조금 더 연습이 필요한 것 같다! 화이팅!

*/

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MAX = 20 + 10;

int solution(string word, vector<string> pages) {
    int answer = 0;
    map<string, int> m; // m["url"] : 해당 url의 인덱스
    set<string> exlink[MAX]; // exlink[i] : i번 웹페이지가 가지고 있는 외부 링크
    vector<pair<int, int>> v; // first : 기본점수, second : 외부 링크 수
    double matching[MAX] = {0, }; // matching[i] : i번 웹페이지의 매칭 점수
    
    transform(word.begin(), word.end(), word.begin(), ::tolower); // 소문자로 변환
    
    for(int i=0; i<pages.size(); i++) {
        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower); // 소문자로 변환
        
        // 웹페이지 url 찾기 (meta 태그 안에 존재)
        string meta = pages[i].substr(pages[i].find("<meta property=\"og:url\" content="));
        string url = meta.substr(meta.find("https://"), meta.find("\"/>") - meta.find("https://"));
        m[url] = i;
        
        // 외부 링크 url 찾기
        string a = pages[i];
        while(1) {
            // <a href로 시작하도록 a를 자른다.
            if(a.find("<a href") != string::npos) a = a.substr(a.find("<a href"));
            else break;
            
            string ex = a.substr(a.find("https://"), a.find("\">") - a.find("https://"));
            exlink[i].insert(ex);
            
            a = a.substr(a.find("</a>")); // a 태그가 끝난 시점으로 자른다.
        }
        
        int s = pages[i].find("<body>") + 6;
        int e = pages[i].find("</body>");
        string temp = "";
        int score = 0;
        for(int j=s; j<e; j++) {
            if(!('a' <= pages[i][j] && pages[i][j] <= 'z')) { // 영문자가 아닌 경우
                if(temp == word) score++; // 지금까지 누적된 단어가 word와 같다면 기본점수 + 1
                temp = "";
            }
            else temp += pages[i][j];
        }
        
        v.push_back({score, exlink[i].size()});
    }
    
    for(int i=0; i<pages.size(); i++) {
        matching[i] += v[i].first;
        
        double myScore = (double)v[i].first / v[i].second;
        
        for(set<string>::iterator it = exlink[i].begin(); it != exlink[i].end(); it++) {
            if(m.find(*it) == m.end()) continue; // pages에 없는 주소인 경우
            
            int idx = m[*it];
            matching[idx] += myScore;
        }
    }
    
    double myMax = -1;
    for(int i=0; i<pages.size(); i++) {
        if(myMax < matching[i]) {
            myMax = matching[i];
            answer = i;
        }
    }
    
    return answer;
}