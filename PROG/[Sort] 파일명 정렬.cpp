// 소요시간: 30분
// 실행시간: 0ms

/*

세 차례의 코딩 테스트와 두 차례의 면접이라는 기나긴 블라인드 공채를 무사히 통과해
카카오에 입사한 무지는 파일 저장소 서버 관리를 맡게 되었다.

저장소 서버에는 프로그램의 과거 버전을 모두 담고 있어, 이름 순으로 정렬된 파일 목록은 보기가 불편했다. 
파일을 이름 순으로 정렬하면 나중에 만들어진 ver-10.zip이 ver-9.zip보다 먼저 표시되기 때문이다.

버전 번호 외에도 숫자가 포함된 파일 목록은 여러 면에서 관리하기 불편했다. 
예컨대 파일 목록이 [img12.png, img10.png, img2.png, img1.png]일 경우, 
일반적인 정렬은 [img1.png, img10.png, img12.png, img2.png] 순이 되지만, 
숫자 순으로 정렬된 [img1.png, img2.png, img10.png, img12.png"] 순이 훨씬 자연스럽다.

무지는 단순한 문자 코드 순이 아닌, 파일명에 포함된 숫자를 반영한 정렬 기능을 저장소 관리 프로그램에 구현하기로 했다.

소스 파일 저장소에 저장된 파일명은 100 글자 이내로, 영문 대소문자, 숫자, 공백(" ), 마침표(.), 빼기 부호(-")만으로 이루어져 있다. 
파일명은 영문자로 시작하며, 숫자를 하나 이상 포함하고 있다.

파일명은 크게 HEAD, NUMBER, TAIL의 세 부분으로 구성된다.
- HEAD는 숫자가 아닌 문자로 이루어져 있으며, 최소한 한 글자 이상이다.
- NUMBER는 한 글자에서 최대 다섯 글자 사이의 연속된 숫자로 이루어져 있으며, 앞쪽에 0이 올 수 있다. 
  0부터 99999 사이의 숫자로, 00000이나 0101 등도 가능하다.
- TAIL은 그 나머지 부분으로, 여기에는 숫자가 다시 나타날 수도 있으며, 아무 글자도 없을 수 있다.

파일명	HEAD	NUMBER	TAIL
foo9.txt	foo	9	.txt
foo010bar020.zip	foo	010	bar020.zip
F-15	F-	15	(빈 문자열)

파일명을 세 부분으로 나눈 후, 다음 기준에 따라 파일명을 정렬한다.
- 파일명은 우선 HEAD 부분을 기준으로 사전 순으로 정렬한다. 이때, 문자열 비교 시 대소문자 구분을 하지 않는다. 
  MUZI와 muzi, MuZi는 정렬 시에 같은 순서로 취급된다.
- 파일명의 HEAD 부분이 대소문자 차이 외에는 같을 경우, NUMBER의 숫자 순으로 정렬한다. 
  9 < 10 < 0011 < 012 < 13 < 014 순으로 정렬된다. 숫자 앞의 0은 무시되며, 012와 12는 정렬 시에 같은 같은 값으로 처리된다.
- 두 파일의 HEAD 부분과, NUMBER의 숫자도 같을 경우, 원래 입력에 주어진 순서를 유지한다. 
  MUZI01.zip과 muzi1.png가 입력으로 들어오면, 정렬 후에도 입력 시 주어진 두 파일의 순서가 바뀌어서는 안 된다.

무지를 도와 파일명 정렬 프로그램을 구현하라.

입력 형식
입력으로 배열 files가 주어진다.
- files는 1000 개 이하의 파일명을 포함하는 문자열 배열이다.
- 각 파일명은 100 글자 이하 길이로, 영문 대소문자, 숫자, 공백(" ), 마침표(.), 빼기 부호(-")만으로 이루어져 있다. 
  파일명은 영문자로 시작하며, 숫자를 하나 이상 포함하고 있다.
- 중복된 파일명은 없으나, 대소문자나 숫자 앞부분의 0 차이가 있는 경우는 함께 주어질 수 있다. 
  (muzi1.txt, MUZI1.txt, muzi001.txt, muzi1.TXT는 함께 입력으로 주어질 수 있다.)

출력 형식
위 기준에 따라 정렬된 배열을 출력한다.

입출력 예제
입력: [img12.png, img10.png, img02.png, img1.png, IMG01.GIF, img2.JPG]
출력: [img1.png, IMG01.GIF, img02.png, img2.JPG, img10.png, img12.png]

입력: [F-5 Freedom Fighter, B-50 Superfortress, A-10 Thunderbolt II, F-14 Tomcat]
출력: [A-10 Thunderbolt II, B-50 Superfortress, F-5 Freedom Fighter, F-14 Tomcat]

*/

/*

◆ 풀이

주어진 파일명을 HEAD, NUMBER, TAIL 세 부분으로 분리하고, 주어진 조건에 따라 정렬하는 문제.
문제에서 어떤 방식으로 구현해야 할지 방향을 잡아 주었기 때문에 그대로 구현만 하면 된다.

전체적인 수행 과정은 다음과 같다.

1) 파일명을 HEAD, NUMBER, TAIL로 분리한다. (사실 이 문제에서 TAIL은 필요하지 않다.)
    파일명의 맨 처음부터 숫자가 나오기 전까지는 모두 HEAD가 되므로
    isdigit가 false인 경우까지 반복문을 돌리며 HEAD에 한 글자씩 더해준다. (isdigit는 문자가 숫자인 경우에 true를 리턴한다.)
    isdigt가 true가 되는 시점부터는 숫자인 부분이라는 뜻이므로 최대 5글자의 숫자를 모두 NUMBER로 처리한다.
    숫자가 5글자를 넘어가거나, 숫자가 아닌 부분이 나타난다면 그 부분부터는 TAIL이 된다.

2) HEAD를 모두 소문자로 변환해준다.
    HEAD를 정렬할 때, 대소문자의 구분이 없도록 정렬하기 위해서는 
    HEAD를 모두 대문자 또는 소문자로 변환해주는 것이 필요하다.

3) 정렬을 수행한다. 단, 정렬 조건은 다음과 같다.
    [1] HEAD 기준으로 사전 순으로 정렬
    [2] HEAD가 같다면 NUMBER의 숫자 순으로 정렬
    [3] NUMBER 또한 같다면 원래 입력에 주어진 순서를 유지

4) 정렬된 벡터의 idx에 따라 answer에 파일명을 넣어준다.


◆ 후기

문자열을 목적에 따라 잘 분리한 후 변환시킬 수 있고, 조건에 따라 비교 함수를 작성할 수 있다면 구현이 어렵지 않은 문제이다.

처음에는 숫자인지 확인하기 위해 '0' 보다 크거나 같고, '9' 보다 작거나 같은 경우를 조건문에 사용했는데,
생각해보니 굳이 저렇게 비교하지 않아도 저번에 알게된 isdigit라는 함수를 사용해도 무방했기에 다시 바꿔주었다.
(isdigt는 문자가 숫자인 경우 true를 리턴한다.)

또한, 처음에는 아무 생각 없이 files를 모두 소문자로 바꿔줬는데,
사실 소문자로 바꿔주는 행위는 HEAD를 비교할 때만 사용되는 것이므로
files 자체를 변경하는 것보다 HEAD만 바꾸는 것이 더 효율적이다.

또한, 나는 idx라는 변수를 추가적으로 활용하여 기존 files에서 몇 번째에 위치하는 지에 대한 정보를 기록함으로써
HEAD와 NUMBER가 같은 경우 기존 순서를 유지하는 방식으로 비교함수를 작성했는데,
stable_sort를 이용하면 idx를 비교함수에서 사용하지 않아도 기존 순서가 유지된채로 정렬이 수행된다.
(평소에 자주 사용하는 sort 함수는 unstable한 정렬이므로 기존 순서가 유지되지 않는다.)
사용 방법은 sort와 똑같으므로, stable_sort라는게 있구나! 정도만 알아두면 좋을 것 같다!ㅎㅎ

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct MYFILE {
    string HEAD;
    int NUMBER, IDX;
};

bool comp(MYFILE a, MYFILE b) {
    // HEAD 기준으로 사전 순으로 정렬
    // HEAD가 같다면 NUMBER의 숫자 순으로 정렬
    // NUMBER 또한 같다면 원래 입력에 주어진 순서를 유지
    if(a.HEAD == b.HEAD && a.NUMBER == b.NUMBER)
        return a.IDX < b.IDX;
    else if(a.HEAD == b.HEAD)
        return a.NUMBER < b.NUMBER;
    else
        return a.HEAD < b.HEAD;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<MYFILE> v;
    
    for(int i=0; i<files.size(); i++) {
        string HEAD = "", NUMBER = "";
        for(int j=0; j<files[i].size(); j++) {
            if(!isdigit(files[i][j])) HEAD += files[i][j]; // 문자인 부분은 모두 HEAD로 처리한다.
            else { // 숫자인 부분
                for(int k=j; k<files[i].size(); k++) { // 최대 5글자의 숫자를 NUMBER로 처리한다.
                    if(k < j+5 && isdigit(files[i][k])) NUMBER += files[i][k];
                    else break;
                }
                break;
            }
        }
        
        transform(HEAD.begin(), HEAD.end(), HEAD.begin(), ::tolower); // 모두 소문자로 바꿔준다.
        v.push_back({HEAD, stoi(NUMBER), i});
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<v.size(); i++) answer.push_back(files[v[i].IDX]);
    
    return answer;
}