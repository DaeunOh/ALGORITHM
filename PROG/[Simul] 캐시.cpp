/*

지도개발팀에서 근무하는 제이지는 지도에서 도시 이름을 검색하면 
해당 도시와 관련된 맛집 게시물들을 데이터베이스에서 읽어 보여주는 서비스를 개발하고 있다.
이 프로그램의 테스팅 업무를 담당하고 있는 어피치는 서비스를 오픈하기 전 각 로직에 대한 성능 측정을 수행하였는데, 
제이지가 작성한 부분 중 데이터베이스에서 게시물을 가져오는 부분의 실행시간이 너무 오래 걸린다는 것을 알게 되었다.
어피치는 제이지에게 해당 로직을 개선하라고 닦달하기 시작하였고, 
제이지는 DB 캐시를 적용하여 성능 개선을 시도하고 있지만 캐시 크기를 얼마로 해야 효율적인지 몰라 난감한 상황이다.

어피치에게 시달리는 제이지를 도와, DB 캐시를 적용할 때 캐시 크기에 따른 실행시간 측정 프로그램을 작성하시오.

입력 형식
- 캐시 크기(cacheSize)와 도시이름 배열(cities)을 입력받는다.
- cacheSize는 정수이며, 범위는 0 ≦ cacheSize ≦ 30 이다.
- cities는 도시 이름으로 이뤄진 문자열 배열로, 최대 도시 수는 100,000개이다.
- 각 도시 이름은 공백, 숫자, 특수문자 등이 없는 영문자로 구성되며, 대소문자 구분을 하지 않는다. 
  도시 이름은 최대 20자로 이루어져 있다.

출력 형식
입력된 도시이름 배열을 순서대로 처리할 때, 총 실행시간을 출력한다.

조건
- 캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다.
- cache hit일 경우 실행시간은 1이다.
- cache miss일 경우 실행시간은 5이다.

입출력 예제
캐시크기(cacheSize)	도시이름(cities)	실행시간
3	[Jeju, Pangyo, Seoul, NewYork, LA, Jeju, Pangyo, Seoul, NewYork, LA]	50
3	[Jeju, Pangyo, Seoul, Jeju, Pangyo, Seoul, Jeju, Pangyo, Seoul]	21
2	[Jeju, Pangyo, Seoul, NewYork, LA, SanFrancisco, Seoul, Rome, Paris, Jeju, NewYork, Rome]	60
5	[Jeju, Pangyo, Seoul, NewYork, LA, SanFrancisco, Seoul, Rome, Paris, Jeju, NewYork, Rome]	52
2	[Jeju, Pangyo, NewYork, newyork]	16
0	[Jeju, Pangyo, Seoul, NewYork, LA]	25

*/

/*

◆ 풀이

cache에 사용되는 페이지 교체 알고리즘 중 하나인 LRU를 구현하는 문제.
LRU의 개념만 잘 숙지하고 있으면 구현은 크게 어렵지 않다.

전체적인 과정은 다음과 같다.
1) 도시 이름을 모두 소문자화(또는 대문자화)한다. (이 문제에서 도시 이름은 대소문자 구분을 하지 않으므로)
2) 캐시를 보고, 캐시 안에 존재하면 참조했던 시간을 업데이트 시켜주고, 실행 시간을 1 증가시킨다.
3) 캐시 안에 존재하지 않으면 캐시의 사이즈에 따라 맨 끝에 삽입시킬지, 캐시 내용만 바꿔줄지 정하는데,
   현재 캐시 사이즈가 캐시 최대 사이즈보다 작다면 끝에 추가한 후 참조 시간을 기록하고,
   최대 사이즈보다 같거나 크다면 가장 오래 전에 참조된 도시를 골라서 캐시 내용을 변경하고 참조 시간을 업데이트 시켜준다.
   또한, 이 과정이 끝나면 실행 시간을 5 증가시킨다.

위의 과정은 맨 처음 구현에 시도했던 방법인데, 참조 시간을 별도로 기록해야 하고, 코드가 깔끔하지 못하다는 단점이 있었다.

그래서 2번째 시도로는 erase를 사용해서 최근에 사용되지 않은 도시를 가장 앞으로,
그리고 최근에 사용된 도시를 가장 뒤로 배치하는 방법을 활용하고자 했다. (맨 아래 주석처리한 코드)

이 방법은 코드가 조금 더 짧고, 시간을 기록해두는 공간이 별도로 필요하진 않으나 최대 23ms가 걸린다는 단점이 있다.
하지만 7ms밖에 차이가 나지 않으므로 가급적이면 이와 같은 코딩 방식을 활용하는게 더 좋다고 생각한다!


◆ 후기

풀이에서도 언급했듯이 LRU의 개념만 잘 숙지하고 있으면 되는 문제이긴 하지만,
이러한 개념을 "알아야만" 풀 수 있는 문제는 거의 처음 접해본 것 같다.

다른 문제에서는 보통 이름이 주어지고, 그에 대한 개념또한 같이 주어지는게 일반적이었는데,
이번엔 그게 아니다보니 조금 당황했다...ㄷㄷㄷ (그래도 알고 있던 개념이라 다행이었다..ㅎㅎㅎ)

이 문제는 처음 구현할 때보다 두번째 구현할 때 더 좋았던 문제이다.
평소 vector의 erase를 어느 특정 구간을 지울 때 빼고는 잘 사용하지 않았는데,
특정 요소 하나를 지울 때에도 유용하다는 것을 알게 되었기 때문이다 ㅎㅎㅎ

오늘도 메모장에 적어둘 내용이 하나 더 늘었다! 야호~~


*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 30 + 10;

vector<string> cache;
int t[MAX] = {0, };

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    for(int i=0; i<cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        
        bool flag = false;
        for(int j=0; j<cache.size(); j++) {
            if(cache[j] == cities[i]) { // 해당 도시가 캐시에 있는 경우
                flag = true;
                t[j] = i;
                answer += 1;
                break;
            }
        }
        
        if(!flag) {
            // cache의 사이즈를 본다.
            if(cache.size() < cacheSize) {
                cache.push_back(cities[i]);
                t[cache.size()-1] = i;
            }
            else {
                // 가장 오래된 도시를 찾는다.
                int myMin = 987987987, minIdx = -1;
                for(int j=0; j<cache.size(); j++) {
                    if(myMin > t[j]) {
                        myMin = t[j];
                        minIdx = j;
                    }
                }
                
                if(minIdx != -1) {
                    cache[minIdx] = cities[i];
                    t[minIdx] = i;
                }
            }
            
            answer += 5;
        }
    }

    return answer;
}

/*

// erase를 사용해서 최근에 사용되지 않은 도시를 가장 앞으로, 최근에 사용된 도시를 가장 뒤로 배치하는 방법
// 코드가 조금 더 짧고, 시간을 기록해두는 공간이 별도로 필요하진 않으나 최대 23ms가 걸린다. (조금 더 느림)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    for(int i=0; i<cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        
        bool flag = false;
        for(int j=0; j<cache.size(); j++) {
            if(cache[j] == cities[i]) {
                flag = true;
                cache.erase(cache.begin() + j);
                cache.push_back(cities[i]);
                answer += 1;
                break;
            }
        }
        
        if(!flag) {
            if(cacheSize > 0 && cache.size() >= cacheSize) cache.erase(cache.begin());
            if(cacheSize > cache.size()) cache.push_back(cities[i]);
            answer += 5;
        }
    }
    
    
    
    return answer;
}

*/