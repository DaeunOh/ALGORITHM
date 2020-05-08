// 소요시간: 26분
// 실행시간: 282ms -> 136ms

/*

가을을 맞아 카카오프렌즈는 단체로 소풍을 떠났다. 
즐거운 시간을 보내고 마지막에 단체사진을 찍기 위해 카메라 앞에 일렬로 나란히 섰다. 
그런데 각자가 원하는 배치가 모두 달라 어떤 순서로 설지 정하는데 시간이 오래 걸렸다. 
네오는 프로도와 나란히 서기를 원했고, 
튜브가 뿜은 불을 맞은 적이 있던 라이언은 튜브에게서 적어도 세 칸 이상 떨어져서 서기를 원했다. 
사진을 찍고 나서 돌아오는 길에, 
무지는 모두가 원하는 조건을 만족하면서도 다르게 서는 방법이 있지 않았을까 생각해보게 되었다. 
각 프렌즈가 원하는 조건을 입력으로 받았을 때 모든 조건을 만족할 수 있도록 서는 경우의 수를 계산하는 프로그램을 작성해보자.

입력 형식
입력은 조건의 개수를 나타내는 정수 n과 n개의 원소로 구성된 문자열 배열 data로 주어진다. 
data의 원소는 각 프렌즈가 원하는 조건이 N~F=0과 같은 형태의 문자열로 구성되어 있다. 제한조건은 아래와 같다.
- 1 <= n <= 100
- data의 원소는 다섯 글자로 구성된 문자열이다. 각 원소의 조건은 다음과 같다.
  - 첫 번째 글자와 세 번째 글자는 다음 8개 중 하나이다. 
    {A, C, F, J, M, N, R, T} 각각 어피치, 콘, 프로도, 제이지, 무지, 네오, 라이언, 튜브를 의미한다. 
    첫 번째 글자는 조건을 제시한 프렌즈, 세 번째 글자는 상대방이다. 첫 번째 글자와 세 번째 글자는 항상 다르다.
  - 두 번째 글자는 항상 ~이다.
  - 네 번째 글자는 다음 3개 중 하나이다. {=, <, >} 각각 같음, 미만, 초과를 의미한다.
  - 다섯 번째 글자는 0 이상 6 이하의 정수의 문자형이며, 조건에 제시되는 간격을 의미한다. 
    이때 간격은 두 프렌즈 사이에 있는 다른 프렌즈의 수이다.

출력 형식
모든 조건을 만족하는 경우의 수를 리턴한다.

예제 입출력
n	data	answer
2	[N~F=0, R~T>2]	3648
2	[M~C\<2, C~M>1]	0

예제에 대한 설명
첫 번째 예제는 문제에 설명된 바와 같이, 네오는 프로도와의 간격이 0이기를 원하고 
라이언은 튜브와의 간격이 2보다 크기를 원하는 상황이다.

두 번째 예제는 무지가 콘과의 간격이 2보다 작기를 원하고, 반대로 콘은 무지와의 간격이 1보다 크기를 원하는 상황이다. 
이는 동시에 만족할 수 없는 조건이므로 경우의 수는 0이다.

*/

/*

◆ 풀이

조건의 개수는 최대 100개지만, 단체사진을 찍는 프렌즈는 8명이므로
완전 탐색을 통해 프렌즈의 모든 조합을 찾아도 제한 시간 내에 해결이 가능한 문제이다.

그렇기 때문에 나는
1) 완전 탐색을 통해 모든 프렌즈 조합을 구하고,
2) 구한 조합이 data에 들어 있는 모든 조건에 부합하는지 확인한 후,
3) 모든 조건을 통과한다면 answer를 1 증가시키는 방식으로 구현했다.

1)의 경우에는 재귀 함수를 잘 이용해서 "ACFJMNRT"에 해당하는 인덱스를 "01234567"로 생각하여 조합을 구했다.

그리고 2)의 경우에는 조건을 보며 모든 조건에 부합하는지 확인해야 하는데,
문제에서 어느 번째 글자에 어떤 정보를 담고 있는지 미리 알려 줬기 때문에 이를 활용하여 두 프렌즈 사이의 거리를 구했고,
구한 거리와 주어진 간격을 비교하여 =, <, >에 따라 조건을 만족하는지를 확인했다.

만약 조건이 한 개라도 맞지 않는다면 그 즉시 false를 리턴하기 때문에 answer의 개수는 증가되지 않으며,
모든 조건을 다 통과해야 true를 리턴하고 ansewr의 개수가 1 증가된다.

그리고 최종적으로는 answer를 그대로 solution 함수에서 리턴하도록 하면 된다.


◆ 후기

2017 카카오는 왠지 모르게 전역 변수를 사용하고자 할 때에 solution 함수에서 초기화 해줘야 한다는 불편함이 있다..
그래서 최대한 전역변수를 쓰는 방법을 지양하거나, 매개변수로 옮겨 주는 방법을 사용했더니 코드가 지저분해지는(?) 단점이 있었다..ㅜ
다른 사람들 코드를 보면 전역 변수를 사용하지 않아도 깔끔하게 잘 짜던데..ㅎㅎ 부럽다 너무!

어쨌든, 해당 문제는 1)에서 조합을 구하는 것이 필요한데,
나는 예전부터 모든 조합은 재귀함수를 통해 구하는 방식을 사용해왔기에 이번에도 그 방식을 사용했으나,
문제를 맞추고 나서는 갑자기 next_permutation이란 함수를 다시 사용해보고 싶었다.

사실 저번에 같이 취업을 준비하는 친구가 저 함수에 대해 언급한 적이 있는데,
그때는 뭔가 할 일도 많고 해서 나중에 봐야지~란 생각으로 지나갔었다. (그리고 오늘 다시 생각난거임..ㅎㅎ)

완전탐색 문제는 기본으로 여러 기업에서 많이 출제하기에, 이번 기회에 정리해두면 좋을 것 같다는 생각을 했다.
그래서 구글에 검색해본 결과, next_permutation의 사용 방법은 다음과 같다.

#include <algorithm>
do {
    // 조합을 사용하고자 하는 부분
} while(next_permutation(조합 배열, 조합 배열 + 조합 크기); // 또는 벡터.begin(), 벡터.end()

실제로 해당 문제에서도 위와 같은 방법을 사용하여 다시 코드를 짜봤었는데 (맨 아래 주석처리된 코드가 바로 이것이다.)
함수를 짜지 않아도, 여러 변수를 선언하지 않아도 된다는 것이 너무 신세계였다..ㅋㅋㅋㅋ
다음에 조합 짜는 문제가 생긴다면, 이 함수를 적극적으로 이용해봐야겠다!

아! 그리고 첫번째 코드를 짤 때에는, 조합에서 0~7의 숫자들을 그 번호에 해당하는 프렌즈라고 여기고
조합에서 두 프렌즈 간의 거리를 구하는 함수를 별도로 작성하여 사용했는데,
사실 그렇게 함수를 작성하지 않아도, 0~7의 숫자들을 각 인덱스 번호에 해당하는 프렌즈의 "위치"라고 생각하면
어느 위치에 어느 프렌즈가 있는지 확인하지 않아도, 해당 프렌즈의 인덱스에 접근함으로써 거리의 계산이 쉽게 가능해진다.
즉, |comb[f1] - comb[f2]| - 1 만으로도 거리가 구해진다는 것!!!!

평소 코드를 짤 때, 해당 인덱스에 직접 무언가를 넣는 코딩 방식을 자주 사용하는데,
이처럼 직접 무언가를 넣는게 아니라, 그 위치를 저장하면 코드가 더 깔끔해지는 문제들이 많이 있곤 했다.

매번 그럴 때마다 어떻게 그게 한 번에 정리가 될까... 하면서 감탄만 했었는데,
앞으로 그렇게 생각하는 방식을 적극적으로 사용하려고 노력해봐야겠다.

*/

#include <string>
#include <vector>

using namespace std;

int answer;
vector<string> myData;

int changeAlpha(char alpha) {
    if(alpha == 'A') return 0;
    else if(alpha == 'C') return 1;
    else if(alpha == 'F') return 2;
    else if(alpha == 'J') return 3;
    else if(alpha == 'M') return 4;
    else if(alpha == 'N') return 5;
    else if(alpha == 'R') return 6;
    else return 7;
}

int getAbs(int x) {
    if(x > 0) return x;
    else return -x;
}

int getDistance(int f1, int f2, int comb[]) {
    int idx1, idx2;
    for(int i=0; i<8; i++) {
        if(comb[i] == f1) idx1 = i;
        else if(comb[i] == f2) idx2 = i;
    }
    
    return getAbs(idx1 - idx2) - 1;
}

bool isPossible(int comb[]) {
    for(int i=0; i<myData.size(); i++) {
        int f1 = changeAlpha(myData[i][0]);
        int f2 = changeAlpha(myData[i][2]);
        int dist = getDistance(f1, f2, comb);
        int target = myData[i][4] - '0';
        
        if(myData[i][3] == '=' && dist != target) return false;
        else if(myData[i][3] == '<' && dist >= target) return false;
        else if (myData[i][3] == '>' && dist <= target) return false;
    }
    
    return true;
}

void getComb(int x, int comb[], bool check[]) {
    if(x >= 8) {
        if(isPossible(comb)) answer++;
    }
    else {
        for(int i=0; i<8; i++) {
            if(!check[i]) {
                comb[x] = i;
                check[i] = true;
                getComb(x+1, comb, check);
                check[i] = false;
            }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    myData = data;
    
    int comb[10];
    bool check[10] = {false, };
    
    getComb(0, comb, check);
    
    return answer;
}

/*

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int changeAlpha(char alpha) {
    if(alpha == 'A') return 0;
    else if(alpha == 'C') return 1;
    else if(alpha == 'F') return 2;
    else if(alpha == 'J') return 3;
    else if(alpha == 'M') return 4;
    else if(alpha == 'N') return 5;
    else if(alpha == 'R') return 6;
    else if(alpha == 'T') return 7;
}

int getAbs(int x) {
    if(x > 0) return x;
    else return -x;
}

bool isPossible(int comb[], vector<string> &data) {
    for(int i=0; i<data.size(); i++) {
        int f1 = changeAlpha(data[i][0]);
        int f2 = changeAlpha(data[i][2]);
        int dist = getAbs(comb[f1] - comb[f2]) - 1;
        int target = data[i][4] - '0';
        
        if(data[i][3] == '=' && dist != target) return false;
        else if(data[i][3] == '<' && dist >= target) return false;
        else if (data[i][3] == '>' && dist <= target) return false;
    }
    
    return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    const int MAX = 8;
    
    int answer = 0;
    int comb[MAX] = {0, 1, 2, 3, 4, 5, 6, 7};
    
    do {
        if(isPossible(comb, data)) answer++;
    } while(next_permutation(comb, comb + MAX));
    
    return answer;
}

*/