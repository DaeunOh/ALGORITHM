/*

▶ 소요시간 및 실행시간
12분, 0ms

▶ 문제
노드의 개수, 간선에 대한 정보가 담긴 2차원 배열이 매개변수로 주어질 때,
1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지를 구하시오.

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/49189

▶ 풀이
1부터 n까지 번호가 적혀있는 n개의 노드 중 1번 노드와의 거리가 최대인 노드들의 개수를 구하는 문제.

노드의 개수는 2 이상 20,000 이하이고, 주어진 그래프의 간선은 양방향이며 그 개수는 최소 1개 이상, 최대 50,000개 이하이다.
그래프의 간선이 양방향이므로, 처음 그래프를 구할 때 a -- b, b -- a와 같이 양방향으로 설정해줘야 함을 잊지 말자.

또한, 문제에서 구하고자 하는 값이 "1번 노드와의 거리가 최대인 노드들의 개수"이므로,
이 개수를 구하기 위해 나는 1번 노드로 시작하는 BFS를 사용했다.
즉, 1번 노드를 시작으로 그에 연결되어 있는 노드들은 1번 기준으로 거리가 1인 노드로 보고,
그 노드에 연결되어 있는 노드들은 1번 기준으로 거리가 2인 노드로 보는 것이다.

또한, 이분 그래프가 아닌 서로 무수히 연결되어 있을 수 있는 그래프이므로
해당 노드가 이미 방문된 노드인지 아닌지 확인하기 위한 visited 배열도 별도로 필요하다.
그리고 공간을 추가적으로 소모하지 않기 위해 visited 처리와 동시에 거리도 visited 배열에 넣어주는 방식을 활용했다.

따라서 1번 노드로부터 그와 연결되어 있는 다른 노드들을 매번 큐에 push하고 pop하는 과정을 반복하면서
1번 노드와의 거리를 구하게 되면, 그 거리들 중 최대 거리가 바로 1번 노드에서 가장 멀리 떨어진 노드의 거리가 된다.

따라서 큐가 빌 때까지 과정을 반복하게되면, visited에는 최종적으로 1번 노드와의 거리가 찍힐 것이고,
그 거리가 최대 거리인 노드들을 세어주게 되면 이 문제에서 원하는 답을 구할 수 있게 된다!

▶ 후기
이미 그래프의 형태가 정해져 있기에,
그 그래프에 맞춰 노드들을 서로 연결해줌과 동시에 1번과의 거리를 구하기만 하면 되므로
그래프 문제 중에서는 비교적 쉬운 문제라고 할 수 있다.
(물론 그래프의 기초 개념은 숙지하고 있다는 가정 하에!!)

하지만 여기서 추가적으로 그래프가 주어져 있지 않고,
주어진 조건에 따라 새로 그래프를 형성하고, 또 그 그래프를 이용하여 다른 답을 구하는 문제라면,
문제가 정말 어려워질 수도 있기에... 그런 문제도 많이 풀어봐야 할 것 같다!!

그래도 워밍업으로는 참 좋은 문제라고 생각한다! ㅎㅎ

*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 20000 + 10;

vector<int> myGraph[MAX];
int visited[MAX] = {0, }; // 방문하지 않은 노드라면 0, 방문한 노드라면 상대적 거리가 쓰여있다.
int myMax = 0; // 1번 노드와 다른 노드 사이의 최대 거리 + 1

void BFS(int n) {
    queue<int> q;
    visited[n] = 1;
    q.push(n);
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        if(myMax < visited[front]) myMax = visited[front]; // 최대 거리를 갱신해준다.
        
        for(int i=0; i<myGraph[front].size(); i++) {
            int next = myGraph[front][i]; // front번 노드와 연결되어 있는 노드
            
            if(!visited[next]) { // 방문하지 않은 노드라면
                visited[next] = visited[front] + 1;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0; i<edge.size(); i++) { // 양방향 그래프
        myGraph[edge[i][0]].push_back(edge[i][1]);
        myGraph[edge[i][1]].push_back(edge[i][0]);
    }
    
    BFS(1);
    
    for(int i=1; i<=n; i++) { // 1번 노드와의 거리가 myMax(최대)인 경우의 개수를 센다.
        if(visited[i] == myMax) answer++;
    }
    
    return answer;
}