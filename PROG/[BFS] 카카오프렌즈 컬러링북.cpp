// 소요시간: 13분
// 실행시간: 0ms

/*

문제 설명
출판사의 편집자인 어피치는 네오에게 컬러링북에 들어갈 원화를 그려달라고 부탁하여 여러 장의 그림을 받았다. 
여러 장의 그림을 난이도 순으로 컬러링북에 넣고 싶었던 어피치는 영역이 많으면 
색칠하기가 까다로워 어려워진다는 사실을 발견하고 그림의 난이도를 영역의 수로 정의하였다. 
(영역이란 상하좌우로 연결된 같은 색상의 공간을 의미한다.)

그림에 몇 개의 영역이 있는지와 가장 큰 영역의 넓이는 얼마인지 계산하는 프로그램을 작성해보자.

[그림 1]
위의 그림은 총 12개 영역으로 이루어져 있으며, 가장 넓은 영역은 어피치의 얼굴면으로 넓이는 120이다.

입력 형식
입력은 그림의 크기를 나타내는 m과 n, 그리고 그림을 나타내는 m × n 크기의 2차원 배열 picture로 주어진다. 
제한조건은 아래와 같다.
- 1 <= m, n <= 100
- picture의 원소는 0 이상 2^31 - 1 이하의 임의의 값이다.
- picture의 원소 중 값이 0인 경우는 색칠하지 않는 영역을 뜻한다.

출력 형식
리턴 타입은 원소가 두 개인 정수 배열이다. 그림에 몇 개의 영역이 있는지와 가장 큰 영역은 몇 칸으로 이루어져 있는지를 리턴한다.

예제 입출력
m	n	picture	answer
6	4	[[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]]	[4, 5]

예제에 대한 설명
예제로 주어진 그림은 총 4개의 영역으로 구성되어 있으며, 
왼쪽 위의 영역과 오른쪽의 영역은 모두 1로 구성되어 있지만 상하좌우로 이어져있지 않으므로 다른 영역이다. 
가장 넓은 영역은 왼쪽 위 1이 차지하는 영역으로 총 5칸이다.

*/

/*

◆ 풀이

주어진 그림에 따라 색깔 별로 영역을 정의하고,
그 수를 셈으로써 영역의 총 개수와 가장 큰 영역의 넓이를 계산해야 하는 BFS 문제.

영역이란 상하좌우로 연결된 같은 색상의 공간을 의미하므로,
그림을 보면서 0이 아닌 부분에 대해 이미 방문하지 않은 점을 기준으로 BFS를 시작하는 것이 핵심이다.

또한, 상하좌우를 볼 때는 1) 해당 픽셀을 방문한 적이 있는지, 2) 같은 색인지를 확인해야 하며,
이를 충족하는 픽셀들은 같은 영역이라는 소리이므로 큐에 들어가는 모든 픽셀들은 모두 같은 영역이 된다.

그리고 최종적으로는 그림의 모든 픽셀을 돌면서 발견한 영역의 개수와, 그 중 최대 넓이가 이 문제의 답이 된다.


◆ 후기

요즘에는 BFS 문제가 워낙 많이, 그리고 다양하게 나와서 쉽게 느껴졌지만,
이 문제가 2017년 문제이므로 당시에는 BFS 문제들이 지금보다는 적었을 것이다!
(아마 그때는 마냥 쉽기만 한 문제는 아니었을 수도!!)

그리고 대부분의 BFS/DFS 문제가 그렇듯이 이 문제는 BFS가 아닌, DFS로 풀어도 해결 가능하다!
(물론 BFS는 되지만 DFS로는 안 되는 것도, 그 반대인 것도 존재한다)

하지만 난 DFS보다는 BFS가 조금 더 편해서...ㅎㅎ 오늘도 역시 BFS로 풀었당..ㅎ
짧은 시간이었지만 오랜만에 BFS 문제를 풀어서 그런지 조금 재밌었다 ㅎㅎㅎㅎㅎㅎ

그리고 사실 문제를 푸는 건 좋은데.. 풀이와 후기를 적는 건 조금 귀찮다......
그래도 문제를 어떻게 풀었는지 다시 상기시키거나, 나중에 문제를 간단히 보고자 할 때, 그리고 새로운 개념을 배웠을 때는
정말 유용한 것 같아서 매일 매일 열심히 쓰는 중..! 귀찮다고 문제만 풀지는 말자! 화이팅!

*/

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[110][110] = {false, };

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int BFS(int y, int x, int k, int m, int n, vector<vector<int>> &picture) {
    queue<pair<int, int>> q;
    int cnt = 0;
    
    visited[y][x] = true;
    q.push(make_pair(y, x));
    
    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        cnt++;
        
        for(int i=0; i<4; i++) {
            int ny = front.first + dy[i];
            int nx = front.second + dx[i];
            
            if(ny < 0 || ny > m-1 || nx < 0 || nx > n-1) continue;
            
            if(!visited[ny][nx] && picture[ny][nx] == k) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
    
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!picture[i][j]) continue;
            
            if(!visited[i][j]) {
                number_of_area++;
                int cnt = BFS(i, j, picture[i][j], m, n, picture);
                max_size_of_one_area = max(cnt, max_size_of_one_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}