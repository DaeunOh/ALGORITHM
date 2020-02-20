/*

문제
현재 몰입캠프를 수강하는 N 명의 학생이 코칭을 받기 위해 자리에 앉아있다. 
현재 A 부터 F 학생들이 좌석에 앉은 정보를 그래프로 표현하여 나타내면 다음과 같다.

coach-b.png

수강생끼리 간선으로 연결되어 있다면 서로 붙어서 앉아 있다는 의미이다. 
예를 들어, C 학생은 A, B, D 학생과 붙어서 앉아있다.

N 명의 학생 중 M 명의 학생을 선택하는 경우의 수 중 선택된 M 명의 학생들이 모두 붙어 앉아 있고, 
나머지 선택되지 못한 (N-M) 명의 학생들이 모두 붙어 앉아 있는 경우가 몇 가지 있는지 궁금하다.

예를 들어, 위 그림처럼 앉아있는 학생 중 3명을 선택하는 경우를 확인해보자.

A, B, C 학생을 선택할 경우 A, B, C 학생끼리 연결되어 있고, 나머지 D, E, F 학생도 연결되어 있다. 
C, D, E 학생을 선택할 경우 선택된 학생끼리 연결되어 있으나, 
나머지 학생인 A, B, F 학생끼리 연결되어 있지 않다.

해당 예제에서 모든 경우의 수 중 가능한 경우의 수는 10가지이다. 나열 했을 시 다음과 같다.

A B C D E / A B C D / A B C / A C D E F / B C D E F / A / B / D E F / E F / F

입력
첫 번째 줄에 학생의 수 N이 주어진다.

두 번째 줄부터 N 개의 줄에 걸쳐 수강생이 앉아 있는 상태가 주어진다. 
주어지는 순서대로 A부터 차례대로 수강생의 번호가 매겨지며, 
각 줄에 제공되는 정보는 해당 번호 수강생 근처에 앉아있는 수강생 수, 
주어진 수강생 수 만큼의 수강생의 번호가 공백을 통해 구분하여 주어진다. 
수강생의 번호는 알파벳 대문자로 주어지며, 'A' 부터 차례대로 매겨진다.

(2 ≤ N ≤ 10)

출력
선택된 M 명의 학생들이 모두 붙어 앉아 있고, 
나머지 선택되지 못한 (N-M) 명의 학생들이 모두 붙어 앉아 있는 경우의 수를 출력한다.


입력의 예 1
6
1 C
1 C
3 A B D
2 C E
2 D F
1 E
출력의 예 1
10

입력의 예 2
5
2 B D 
1 A 
2 D E 
3 A C E 
2 C D 
출력의 예 2
10

입력의 예 3
3
1 B 
1 A 
0
출력의 예 3
2

*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10 + 10;

int N, M;

int comb[MAXN] = {0, };
int ans = 0;

int students[MAXN];
vector <int> myGraph[MAXN];

queue <int> q;
int visited[MAXN] = {0, };

int BFS(int x, int flag) {
  int cnt = 0;
  
  q.push(x);
  visited[x] = 1;
  
  while(!q.empty()) {
    int front = q.front();
    q.pop();
    cnt++;

    for(int i=0; i<myGraph[front].size(); i++) {
      int next = myGraph[front][i];
      
      if(!visited[next] && students[next] == flag) {
        visited[next] = 1;
        q.push(next);
      }
    }
  }
  
  return cnt;
}

void getComb(int x, int K) {
  if(x >= K) {
    memset(students, 0, sizeof(students));
    for(int i=0; i<K; i++) students[comb[i]] = 1;
    
    memset(visited, 0, sizeof(visited));
    
    bool flag1 = false;
    for(int j=0; j<N; j++) {
      if(students[j] == 1) {
        int cnt = BFS(j, 1);
        
        if(cnt < K) flag1 = true;
        
        break;
      }
    }
    
    if(flag1) return;

    memset(visited, 0, sizeof(visited));
    
    bool flag2 = false;
    for(int j=0; j<N; j++) {
      if(students[j] == 0) {
        int cnt = BFS(j, 0);
        
        if(cnt < N-K) flag2 = true;
        
        break;
      }
    }
    
    if(flag2) return;
    
    ans++;
  }
  else {
    for(int i=0; i<N; i++) {
      if(x == 0 || comb[x-1] < i) {
        comb[x] = i;
        getComb(x+1, K);
      }
    }
  }
}

int main() {
  scanf("%d", &N);

  for(int i=0; i<N; i++) {
    int adjNum;
    scanf("%d", &adjNum);

    for(int j=0; j<adjNum; j++) {
      char student;
      scanf(" %c", &student);
      
      myGraph[i].push_back(student - 'A');
    }
  }
  
  // 조합 짜기
  for(int i=1;i<=N-1; i++) getComb(0, i);

  printf("%d\n", ans);
  
  return 0;
}