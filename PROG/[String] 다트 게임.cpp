// 소요시간: 23분
// 실행시간: 0ms

/*

카카오톡에 뜬 네 번째 별! 심심할 땐? 카카오톡 게임별~

카카오톡 게임별의 하반기 신규 서비스로 다트 게임을 출시하기로 했다. 
다트 게임은 다트판에 다트를 세 차례 던져 그 점수의 합계로 실력을 겨루는 게임으로, 모두가 간단히 즐길 수 있다.
갓 입사한 무지는 코딩 실력을 인정받아 게임의 핵심 부분인 점수 계산 로직을 맡게 되었다. 
다트 게임의 점수 계산 로직은 아래와 같다.

1. 다트 게임은 총 3번의 기회로 구성된다.
2. 각 기회마다 얻을 수 있는 점수는 0점에서 10점까지이다.
3. 점수와 함께 Single(S), Double(D), Triple(T) 영역이 존재하고 
   각 영역 당첨 시 점수에서 1제곱, 2제곱, 3제곱 (점수1 , 점수2 , 점수3 )으로 계산된다.
4. 옵션으로 스타상(*) , 아차상(#)이 존재하며 스타상(*) 당첨 시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다. 
   아차상(#) 당첨 시 해당 점수는 마이너스된다.
5. 스타상(*)은 첫 번째 기회에서도 나올 수 있다. 이 경우 첫 번째 스타상(*)의 점수만 2배가 된다. (예제 4번 참고)
6. 스타상(*)의 효과는 다른 스타상(*)의 효과와 중첩될 수 있다. 이 경우 중첩된 스타상(*) 점수는 4배가 된다. (예제 4번 참고)
7. 스타상(*)의 효과는 아차상(#)의 효과와 중첩될 수 있다. 이 경우 중첩된 아차상(#)의 점수는 -2배가 된다. (예제 5번 참고)
8. Single(S), Double(D), Triple(T)은 점수마다 하나씩 존재한다.
9. 스타상(*), 아차상(#)은 점수마다 둘 중 하나만 존재할 수 있으며, 존재하지 않을 수도 있다.

0~10의 정수와 문자 S, D, T, *, #로 구성된 문자열이 입력될 시 총점수를 반환하는 함수를 작성하라.

입력 형식
점수|보너스|[옵션]으로 이루어진 문자열 3세트.
예) 1S2D*3T
- 점수는 0에서 10 사이의 정수이다.
- 보너스는 S, D, T 중 하나이다.
- 옵선은 *이나 # 중 하나이며, 없을 수도 있다.

출력 형식
3번의 기회에서 얻은 점수 합계에 해당하는 정수값을 출력한다.
예) 37

입출력 예제
예제	dartResult	answer	설명
1	1S2D*3T	37	11 * 2 + 22 * 2 + 33
2	1D2S#10S	9	12 + 21 * (-1) + 101
3	1D2S0T	3	12 + 21 + 03
4	1S*2T*3S	23	11 * 2 * 2 + 23 * 2 + 31
5	1D#2S*3S	5	12 * (-1) * 2 + 21 * 2 + 31
6	1T2D3D#	-4	13 + 22 + 32 * (-1)
7	1D2S3T*	59	12 + 21 * 2 + 33 * 2

*/

/*

◆ 풀이

주어진 문자열을 목적(점수|보너스|[옵션])에 맞게 파싱하고, 추출된 문자에 따라 점수를 계산하는 문제.

만약 점수가 0점에서 9점이었다면 점수는 항상 한자리수 이므로 더 쉽게 파싱이 가능했겠지만,
10점까지 존재하므로 점수가 항상 한자리수라는 보장이 없었다.
그래서 나는 S, D, T가 나오기 전까지의 점수를 저장하고, 해당 문자가 나왔을 때 누적된 숫자로 점수를 계산하는 방식을 사용했다.

그리고 이후 *이나 #이 나올 때에는 그동안 구해진 점수에 따라 *2를 하거나 *-1을 하도록 했다.
(그러므로 매 라운드마다 점수를 저장해 놓는 것이 필요했다)

그런데 사실 이러한 방법 없이도, stringstream을 사용하면 정수가 몇 자리 수인지 알 필요 없이 바로 점수를 꺼낼 수 있다..!
(모르고 있었는데 다른 분의 풀이를 보고 알게 되었다 ㅎㅎ;;;)
사용 방법은 다음과 같다.

#include <sstream>

stringstream ss(dartResult);
int score;
char bonus, option;

ss >> score; // score가 int형 변수이므로 다른 문자가 나오기 전까지의 정수는 모두 score에 저장된다.
bonus = ss.get(); // 1자리 문자를 bonus에 넣는다.
option = ss.get();

// *이나 #는 항상 존재하는 건 아니므로 get한 문자가 *이나 #이 아니라면 get했던 문자를 다시 되돌린다.
if(option != '*' && option != '#') ss.unget(); 

그리고 나는 세제곱까지는 오퍼레이션이 길지 않아서 그냥 같은 수를 최대 3번까지 곱하는 걸로 구현했는데,
cmath에 있는 pow(숫자, 몇 번 곱할 건지)를 사용하면 좋다.

해당 방법을 사용한 코드는 맨 아래에 주석처리 해놓았으니 참고하자!


◆ 후기

다른 무엇보다도 이 문제를 통해 string을 다룰 때 유용한 팁들을 배울 수 있어서 좋았다.

평소 stringstream은 잘 사용하지 않고, 그냥 for문으로 0부터 보는 방식을 자주 사용했는데,
이번 기회를 통해 stringstream이 이점이 많다는 점을 알게 되었다.
특히 선언한 변수에 따라 파싱이 가능하다는 점이 가장 좋았던 것 같다.

메모장에 적어 두고 까먹지 않게 두고두고 봐야겠다 ㅎㅎ~

*/

#include <string>

using namespace std;

int scores[3] = {0, };

int solution(string dartResult) {
    int answer = 0;
    
    string score = "";
    int idx = 0;
    for(auto &s : dartResult) {
        if(s == 'S' || s == 'D' || s == 'T') {
            if(s == 'S') scores[idx++] = stoi(score);
            else if(s == 'D') scores[idx++] = stoi(score) * stoi(score);
            else scores[idx++] = stoi(score) * stoi(score) * stoi(score);
            score = "";
        }
        else if(s == '*') {
            scores[idx - 1] *= 2;
            if(idx > 1) scores[idx - 2] *= 2; 
        }
        else if(s == '#') {
            scores[idx - 1] *= -1;
        }
        else {
            score += s;
        }
    }
    
    for(int i=0; i<3; i++) answer += scores[i];
    
    return answer;
}

/*

#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int scores[3] = {0, };

int solution(string dartResult) {
    int answer = 0;
    stringstream ss(dartResult);
    
    for(int i=0; i<3; i++) {
        int score;
        char bonus, option;
        
        ss >> score;
        bonus = ss.get();
        option = ss.get();
        
        if(option != '*' && option != '#') ss.unget();
        
        if(bonus == 'S') scores[i] = pow(score, 1);
        else if(bonus == 'D') scores[i] = pow(score, 2);
        else scores[i] = pow(score, 3);
        
        if(option == '*') {
            scores[i] *= 2;
            if(i > 0) scores[i-1] *= 2;
        }
        else if(option == '#') scores[i] *= -1;
    }
    
    for(int i=0; i<3; i++) answer += scores[i];
    
    return answer;
}

*/