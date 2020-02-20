/*

문제
현재 몰입캠프를 수강하는 N 명의 학생이 코칭을 받기 위해 자리에 앉아있다. 
N 명의 학생 중 M 명의 학생을 배정받은 "X" 코치와 
나머지 학생들을 배정받은 "Y" 코치는 각자 자신이 담당하는 학생들끼리 붙어서 앉아 있는지 확인한다. 
만약 붙어서 앉아 있다면 질문을 받고, 붙어서 앉아 있지 않다면 자리 재배치를 진행한다. 
코치는 최소 한 명의 학생을 배정 받아야 한다. 
만약 배정받지 못했다면 수강생 재배정을 한다. 
현재 A 부터 F 학생들이 좌석에 앉은 정보를 그래프로 표현하여 나타내면 다음과 같다.

coach-1.png

수강생끼리 간선으로 연결되어 있다면 서로 붙어서 앉아 있다는 의미이다. 
예를 들어, C 학생은 A, B, D 학생과 붙어서 앉아있다. 
만약 다음과 같은 사례가 있다고 하자.

사례 1 - "X" : A, B, C / "Y" : D, E, F

사례 2 - "X": A, B, C, D / "Y": E, F

사례 3 - "X": E, F / "Y": A, B, C, D

사례 4 - "X": A, B / "Y": C, D, E, F

사례 1, 2, 3은 자리 재배치가 필요하지 않다. 사례 4는 필요하다. 
따라서, 사례 1, 2, 3의 경우 코치가 질의응답을 진행한다. 
각 사례마다 질문 수를 세어보면 다음과 같다.

사례 1 - "X": 10 / "Y": 15

사례 2 - "X": 13 / "Y": 12

사례 3 - "X": 12 / "Y": 13

"X" 코치와 "Y" 코치의 질문 수 차이의 최솟값이 궁금하다. 
자리 재배치 혹은 수강생 재배정이 필요한 경우 비교 대상에서 제외한다. 
위 예제에서 최소 차이는 1이다.

현재 수강생의 정보와 코치가 배정받은 M명의 학생이 주어 졌을 때, 
"X" 코치와 "Y" 코치의 질문 수 차이의 최솟값을 구해보자.

입력
첫 번째 줄에 학생의 수 N이 주어진다.

두 번째 줄부터 N 개의 줄에 걸쳐 수강생이 앉아 있는 상태가 주어진다. 
주어지는 순서대로 A부터 차례대로 수강생의 번호가 매겨지며, 
각 줄에 제공되는 정보는 해당 번호 수강생의 질문수 Q, 근처에 앉아있는 수강생 수, 
주어진 수강생 수 만큼의 수강생의 번호가 공백을 통해 구분하여 주어진다. 
수강생의 번호는 알파벳 대문자로 주어지며, 'A' 부터 차례대로 매겨진다.

다음 줄에 사례의 수 T가 주어진다.

T개의 줄에 걸쳐 선택된 학생 정보가 주어진다. 
줄의 가장 처음에는 학생의 수 C가 주어진다. 
다음으로 C개의 알파벳이 주어진다. 
학생 정보는 모두 대문자 알파벳으로 구성되어있다. 
'A' 부터 시작하여 최대 N번째 알파벳까지 존재한다.

(2 ≤ N ≤ 10, 1 ≤ T ≤ 10, 1 ≤ C ≤ N, 1 ≤ 질문 수 ≤ 100)

출력
"X" 코치와 "Y" 코치의 질문 수 차이의 최솟값을 출력한다. 
만약 모든 사례에서 자리 재배치 혹은 수강생 재배정이 필요한 경우 -1을 출력한다.


입력의 예 1
6
3 1 C
5 1 C
2 3 A B D
3 2 C E
4 2 D F
8 1 E
4
3 A B C 
4 A B C D 
2 E F 
2 A B 
출력의 예 1
1

입력의 예 2
5
10 2 B D 
85 1 A 
68 2 D E 
67 3 A C E 
46 2 C D 
6
3 E C A 
3 B C A 
5 D A B E C 
2 A D 
2 C A 
5 C E D B A
출력의 예 2
-1

*/

/*

C 문제에서 했던 코딩을 그대로 복사하고 추가적으로 코딩을 하다보니
제대로 이루어지지 않은 초기화와 반복문의 변수 겹침으로 인해 오류를 찾아내기가 어려웠다.

초기화와 반복문 변수 확인은 항상 확실히 해주기!

*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10 + 10;

int N, M;
int Q[MAXN];
int T;

int students[MAXN];
vector <int> myGraph[MAXN];

int myMin = 987987987;

queue <int> q;
int visited[MAXN] = {0, };

int getAbs(int x) {
  if(x >= 0) return x;
  else return -x;
}

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

int main() {
  scanf("%d", &N);

  for(int i=0; i<N; i++) {
    int adjNum;
    scanf("%d %d", &Q[i], &adjNum);

    for(int j=0; j<adjNum; j++) {
      char student;
      scanf(" %c", &student);
      
      myGraph[i].push_back(student - 'A');
    }
  }
  
  scanf("%d", &T);

  for(int i=0; i<T; i++) {
    memset(students, 0, sizeof(students));
    scanf("%d", &M);
    
    for(int j=0; j<M; j++) {
      int student;
      scanf(" %c", &student);
      students[student - 'A'] = 1;
    }
    
    if(N == M) continue;
    
    memset(visited, 0, sizeof(visited));
    
    bool flag1 = false;
    for(int j=0; j<N; j++) {
      if(students[j] == 1) {
        int cnt = BFS(j, 1);
        
        if(cnt < M) flag1 = true;
        
        break;
      }
    }
    
    if(flag1) continue;
    
    memset(visited, 0, sizeof(visited));
    
    bool flag2 = false;
    for(int j=0; j<N; j++) {
      if(students[j] == 0) {
        int cnt = BFS(j, 0);
        
        if(cnt < N-M) flag2 = true;
        
        break;
      }
    }
    
    if(flag2) continue;
    
    int X = 0, Y = 0;
    
    for(int j=0; j<N; j++) {
      if(students[j] == 1) X += Q[j];
      else Y += Q[j];
    }
    
    int diff = getAbs(X-Y);
    if(myMin > diff) myMin = diff;
  }

  if(myMin == 987987987) printf("-1\n");
  else printf("%d\n", myMin);
  
  return 0;
}