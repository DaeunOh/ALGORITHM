/*

▶ 소요시간 및 실행시간
51분, 0ms

▶ 문제
콘이 셔틀을 타고 사무실로 갈 수 있는 도착 시각 중 제일 늦은 시각을 구하시오.

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/17678

▶ 풀이
HH:MM으로 주어진 시간을 오름차순으로 정렬한 후, 분단위로 바꾸고, 가능한 셔틀 버스 시간대에 크루를 배정하여
최종적으로는 콘이 가장 늦은 시간대에 배정되도록 하는 콘의 도착 시각을 구하는 문제.

전체적인 수행 과정은 다음과 같다.

1) 크루들의 도착 시각을 오름차순으로 정렬한다.
   테스트케이스에 볼 수 있듯이 크루들이 도착하는 시각은 정렬되어 있지 않은 시각이므로,
   가장 먼저 도착 시각을 오름차순으로 정렬해놓는 것이 필요하다.
   그래야만 이후 셔틀버스에 크루를 배정할 때, 가장 먼저 온 순서부터 배정이 가능해진다.

2) timetable을 통해 얻은 도착 시각을 분단위로 바꾼 후, 셔틀 버스의 출발 시간에 맞게 크루를 배정한다.
   시간은 HH:MM 형식으로 주어있기 때문에 편리한 계산을 위해 모두 분단위로 바꿔주는 과정이 필요하다.
   또한, 셔틀 버스의 출발 시간은 9시를 시작으로 항상 정해져 있으므로 반복문을 돌리며
   크루의 도착 시각에 맞게 가장 빠른 시간으로 셔틀 버스를 배정해줘야 한다.
   이미 시간은 오름차순으로 정렬되어 있기 때문에 가장 먼저 온 사람 순서대로 배정이 되며,
   출발 시간에 맞춰 왔지만 버스가 꽉 차서 배정하지 못하는 경우는 다음 버스로 배정한다.

3) 콘을 가장 늦은 시간대의 버스에 배정한다.
   미리 셔틀 버스에 사람들을 다 배정해놓았기 때문에 콘을 마지막 버스에 배정하도록 시간을 설정해주면 된다.
   만약 마지막 버스에 자리가 남아있다면, 버스 출발 시간을 콘의 도착 시간으로 설정하면 되지만,
   자리가 없다면, 가장 늦게 온 사람보다는 일찍 와야 버스에 탈 수 있으므로
   가장 늦게 온 사람의 시각 - 1분을 한 시간을 콘의 도착 시간으로 설정한다.

4) 구한 분단위의 도착 시각을 HH:MM 형식으로 바꿔준다.

▶ 후기
가장 처음 분단위로 바꾸는 과정 이후에는 어떻게 가장 마지막 시간에 배치할 수 있을지 생각하는 것이 꽤 오래 걸렸던 문제이다.

많은 경우를 생각해야 하나? 싶었지만, 다행히 셔틀 출발 시간은 n과 t에 따라 미리 정해져 있으므로,
모든 크루들을 셔틀에 한 명씩 배정해가면서, 최대한 빈자리가 없이 버스를 채운다음
가장 마지막 버스에 콘을 배정시키도록 도착 시간을 정해주기만 하면 됐기에 사실 그렇게 어려운 문제는 아니었다.

그리고 콘은 항상 "마지막 버스"에 타야 한다는 것이 이 문제의 가장 핵심이라고 생각한다.
그렇기에 마지막 버스의 인원을 보고, 자리가 남아있는지 안 남아있는지에 따라
버스 출발 시간에 도착할지, 가장 늦게 온 사람보다 1분 일찍 도착할지가 한 번에 결정된다.

최대한 코드를 깔끔하게 짜기 위해 중간 중간에 코드 수정을 많이 했던 것 같다.
다른 사람의 풀이를 보니 버스 벡터를 따로 두지 않고, 버스 출발 시간을 기준으로 사람을 배정한 방식을 많이 사용했던데,
사실 나는 그 풀이보다 내 풀이가 더 명확하고 좋은 것 같다는 생각이 든다 ㅎㅎ

그리고 문제에서는 셔틀 버스에 가능한 모든 크루를 배정하고자 했지만,
사실 맨 마지막 버스가 꽉차게 되면 더이상 그 이후의 크루는 보지 않아도 되므로(오름차순이기 때문에)
중간에 조건을 걸어 break를 해준다면 지금보다 더 빠를 수도 있을 것 같다.
(근데 사실 지금 코드도 0ms이기에 ... 의미는 없는 것 같다 ..! ㅎㅎ..
만약 더 더 큰 테스트 케이스가 주어진다면, 그때는 의미 있을 수도!!)

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bus[1440];

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    // 시간을 오름차순으로 정렬한다.
    sort(timetable.begin(), timetable.end());
    
    for(int i=0; i<timetable.size(); i++) {
        // 분단위로 바꾼다.
        int HH = stoi(timetable[i].substr(0, 2));
        int MM = stoi(timetable[i].substr(3, 2));
        int TIME = HH * 60 + MM;
        
        // 셔틀 버스에 크루를 배정한다.
        // 단, 버스가 꽉 찼다면 다음 버스로 배정한다.
        for(int j=0; j<n; j++) {
            if(TIME <= 540 + j*t && bus[540 + j*t].size() < m) {
                bus[540 + j*t].push_back(TIME);
                break;
            }
        }
    }
    
    // 제일 늦은 도착 시각을 출력해야 하므로, 콘은 가장 늦은 시간대에 배정되어야 한다.
    // 따라서 가장 마지막 버스에 자리가 있다면 버스 출발 시간에 오면 되지만,
    // 자리가 없다면 가장 늦게 오는 사람보단 빨라야 하므로 그 시간에 -1 해준 시간에 와야한다.
    string HH, MM;
    if(bus[540 + (n-1) * t].size() < m) {
        HH = to_string((540 + (n-1) * t) / 60);
        MM = to_string((540 + (n-1) * t) % 60);
    }
    else {
        HH = to_string((bus[540 + (n-1) * t].back() - 1) / 60);
        MM = to_string((bus[540 + (n-1) * t].back() - 1) % 60);
    }
    
    // HH:MM 형식으로 설정하기 위해 0을 채워 넣는다.
    while(HH.size() != 2) HH = "0" + HH;
    while(MM.size() != 2) MM = "0" + MM;
    
    answer = HH + ":" + MM;
    
    return answer;
}