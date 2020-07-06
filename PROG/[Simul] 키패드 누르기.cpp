/*

▶ 소요시간 및 실행시간
18분, 0ms

▶ 문제
순서대로 누를 번호가 담긴 배열, 왼손잡이인지 오른손잡이인지를 나타내는 문자열이 매개변수로 주어질 때, 
각 번호를 누른 엄지손가락이 왼손인지 오른손인지를 나타내는 연속된 문자열 형태를 구하시오.

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/67256

▶ 풀이
주어진 조건에 따라 왼손과 오른손의 엄지손가락만을 이용해서 키패드를 누르고,
각 번호를 누를 때마다 어떤 손을 이용했는지를 순서대로 구하는 문제.

문제에서 키패드 이동 한 칸은 거리로 1에 해당한다고 했으므로 일반적인 배열에서 두 요소간의 거리를 구할 때와 비슷하다.
따라서 나는 키패드에 적혀있는 숫자를 2차원 배열에 위치한다고 가정하고,
0부터 9까지 그에 맞는 좌표를 keypad라는 벡터에 차례대로 넣어주었다.

그리고 이후 키패드를 누를 때는 조건에 맞게 1, 4, 7은 항상 왼손을 이용하고, 3, 6, 9는 항상 오른손을 이용하도록 구현하고,
2, 5, 8, 0은 현재 왼손(오른손)의 좌표와 해당 숫자의 좌표간의 거리를 이용하여 그 거리에 맞게 손을 사용하도록 구현했다.
기본적으로는 거리가 더 가까운 손을 사용하도록 되어 있지만, 같은 경우에는 어떤 손잡인지에 따라 달라진다.

또한, 여기서 거리를 이용하려면 항상 현재 왼손(오른손)의 위치를 항상 기억하고 있어야 하므로,
매번 키패드를 누를 때마다 그 숫자에 맞게 왼손(오른손)의 위치를 변경해주는 작업도 잊지 말아야 한다.
(반복되는 코드가 많으므로 나는 이에 대한 코드를 함수로 따로 구현하여 사용했다.)

▶ 후기
거리를 쉽게 구하기 위해 키패드를 2차원 배열로 생각해야 하는 것과,
현재 손의 좌표를 매번 바꿔줘야 하는 것만 캐치하면 쉽게 해결할 수 있는 문제이다.

그 이후에는 주어진 조건에 따라 구현만 하면 되므로 빠른 시간 내에 구현하는 것이 관건이다!
나는 숫자에 따른 좌표를 설정하는 과정에서 최대한 하드 코딩을 줄이는 방법으로 하려다 보니 조금 시간이 지체 되었다..!
그래도 이 부분은 꾸준히 문제를 풀면 해결될 수 있을 것이라 생각한다! 많이 많이 풀도록 하자 ㅎㅎ

*/

#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> keypad;
int ly = 3, lx = 0, ry = 3, rx = 2;
string answer = "";

int getAbs(int x) {
    if(x > 0) return x;
    else return -x;
}

void leftOp(int num) {
    answer += "L";
    ly = keypad[num].first;
    lx = keypad[num].second;
}

void rightOp(int num) {
    answer += "R";
    ry = keypad[num].first;
    rx = keypad[num].second;
}

string solution(vector<int> numbers, string hand) {
    keypad.push_back(make_pair(3, 1));
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            keypad.push_back(make_pair(i, j));
        }
    }
    
    for(auto &num : numbers) {
        if(num == 1 || num == 4 || num == 7) {
            leftOp(num);
        }
        else if(num == 3 || num == 6 || num == 9) {
            rightOp(num);
        }
        else {
            int distL = getAbs(ly - keypad[num].first) + getAbs(lx - keypad[num].second);
            int distR = getAbs(ry - keypad[num].first) + getAbs(rx - keypad[num].second);
            
            if(distL == distR) {
                if(hand == "left") leftOp(num);
                else rightOp(num);
            }
            else if(distL < distR) leftOp(num);
            else rightOp(num);
        }
    }
    
    return answer;
}