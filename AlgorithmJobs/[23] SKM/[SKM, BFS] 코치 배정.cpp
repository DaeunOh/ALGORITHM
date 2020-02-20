/*

시간제한 1초

문제
현재 몰입캠프를 수강하는 N 명의 학생이 코칭을 받기 위해 자리에 앉아있다. 
자리에 앉아있는 상태를 보고 기윤과 영진은 각자 담당 수강생을 정해 코칭을 진행하려한다. 
기윤과 영진은 최소 1명의 수강생을 담당하여 코칭을 진행해야한다. 
이때, 코치의 움직임 효율성을 높히기 위해 기윤이 담당한 수강생끼리 연결되어있도록, 
영진이 담당한 수강생끼리 연결되어있도록 인원을 배정하고자 한다. 
연결된 수강생들은 모두 같은 담당 코치여야하며, 모든 수강생은 반드시 담당 코치가 존재해야한다. 
수강생이 앉아있는 상태에서 서로 근처에 있는 상태를 그래프를 통해 나타내었다. 
만약 간선으로 연결되어있다면 바로 옆에 있다는 뜻이다. 
또한, 각 수강생이 준비해온 질문 수가 학생 이름 옆에 적혀있다.

coach1
[그림 1]

코치의 효율성을 높히는 인원 배정와 높히지 못하는 인원 배치의 예는 다음과 같다.

coach2
[그림 2] 좌측 2가지 효율이 높은 경우, 우측 1가지 효율이 낮은 경우

두 사람이 비슷한 수의 질문을 받을 수 있도록 인원을 배정하여 코칭을 진행하고자 한다. 
수강생이 앉아있는 상태와 각 수강생의 질문 수가 주어졌을때, 
코치의 움직임 효율성을 높히는 배정을 통해 
기윤과 영진에게 배정된 수강생에게 받게되는 질문수 차이의 최솟값을 구해보자.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다. 
각각의 테스트 케이스의 첫 번째 줄에 수강생 수 N이 주어진다. 
두 번째 줄부터 N 개의 줄에 걸쳐 수강생이 앉아 있는 상태가 주어진다. 
주어지는 순서대로 A부터 차례대로 수강생의 번호가 매겨지며, 
각 줄에 제공되는 정보는 해당 번호 수강생의 질문수 Q, 근처에 앉아있는 수강생 수, 
주어진 수강생 수 만큼의 수강생의 번호가 공백을 통해 구분하여 주어진다. 
수강생의 번호는 알파벳 대문자로 주어지며, 'A' 부터 차례대로 매겨진다. 
주어진 그래프는 무방향 그래프이다. (2 ≤ N ≤ 10, 1 ≤ Q ≤ 100)

 

출력
각 테스트 케이스에 대해 최소 질문 수 차이를 출력한다. 
만약 코치의 효율성을 높히는 인원 배정을 못할 경우 "-1"을 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. t는 테스트 케이스의 번호이며, 1부터 시작한다. 
r은 문제에 대한 결과값을 뜻한다.

 

예제 입력
6
6
3 1 C
5 1 C
2 3 A B D
3 2 C E
4 2 D F
8 1 E
2
10 0 
7 0 
3
3 1 C 
2 0 
1 1 A 
2
4 1 B 
4 1 A 
5
6 2 C E 
2 1 C 
4 3 A B D 
8 2 C E 
10 2 A D 
5
5 2 B C 
4 2 A C 
3 2 A B 
4 0 
7 0 
예제 출력
#1 1
#2 3
#3 2
#4 0
#5 2
#6 -1

*/

/*

1) 사용자 입력을 받는다.
2) 조합을 구한다.
3) 효율성을 높이는 배정인지 확인한다
4) 효율성을 높이는 배정이라면, 차이를 구한다.
5) 효율성을 높이는 배정이 없다면 -1을 출력, 있다면 구한 차이 중 최솟값을 출력한다.

[코드 깔끔하게 짜는 팁] 
조합을 구하고 나서는 일반적으로 반복적인 프로세스가 수행되므로,
최대한 함수로 묶어 그 함수를 호출하도록 한다.

*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10 + 10;

int T;
int N, M;
int Q[MAXN];

int comb[MAXN] = {0, };
int myMin;

int students[MAXN];
vector <int> myGraph[MAXN];

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

void getDiff() {
  int X = 0, Y = 0;
  
  for(int j=0; j<N; j++) {
    if(students[j] == 1) X += Q[j];
    else Y += Q[j];
  }
  
  int diff = getAbs(X-Y);
  if(myMin > diff) myMin = diff;
}

bool isEfficient(int K) {
  memset(visited, 0, sizeof(visited));

  for(int j=0; j<N; j++) {
    if(students[j] == 1) {
      int cnt = BFS(j, 1);
      
      if(cnt < K) return false;
      
      break;
    }
  }
  
  memset(visited, 0, sizeof(visited));

  for(int j=0; j<N; j++) {
    if(students[j] == 0) {
      int cnt = BFS(j, 0);
      
      if(cnt < N-K) return false;
      
      break;
    }
  }
  
  return true;
}

void getComb(int x, int K) {
  if(x >= K) {
    memset(students, 0, sizeof(students));
    for(int i=0; i<K; i++) students[comb[i]] = 1;
    
    if(isEfficient(K)) getDiff();
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
  scanf("%d", &T);
  
  for(int t=1; t<=T; t++) {
    scanf("%d", &N);
    for(int i=0; i<N; i++) myGraph[i].clear();
    myMin = 987987987;
    
    for(int i=0; i<N; i++) {
      int adjNum;
      scanf("%d %d", &Q[i], &adjNum);
  
      for(int j=0; j<adjNum; j++) {
        char student;
        scanf(" %c", &student);
        
        myGraph[i].push_back(student - 'A');
      }
    }
    
    for(int i=1;i<=N-1; i++) getComb(0, i);
    
    if(myMin == 987987987) printf("#%d -1\n", t);
    else printf("#%d %d\n", t, myMin);
  }

  return 0;
}