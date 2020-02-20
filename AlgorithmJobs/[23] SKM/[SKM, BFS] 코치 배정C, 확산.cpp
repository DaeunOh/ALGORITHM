/*

문제
현재 몰입캠프를 수강하는 N 명의 학생이 코칭을 받기 위해 자리에 앉아있다. 
N 명의 학생 중 M 명의 학생을 배정받은 "X" 코치와 
나머지 학생들을 배정받은 "Y" 코치는 
각자 자신이 담당하는 학생들끼리 붙어서 앉아 있는지 확인한 후, 자리를 재배치하려고 한다. 
코치는 최소 한 명의 학생을 배정 받아야 한다. 
만약 배정받지 못했다면 수강생 재배정을 한다. 
현재 A 부터 F 학생들이 좌석에 앉은 정보를 그래프로 표현하여 나타내면 다음과 같다.

coach-b.png

수강생끼리 간선으로 연결되어 있다면 서로 붙어서 앉아 있다는 의미이다. 
예를 들어, C 학생은 A, B, D 학생과 붙어서 앉아있다. 
만약 다음과 같은 사례가 있다고 하자.

사례 1 - "X" : A, B, D / "Y" : C, E, F

사례 2 - "X": C, D, E / "Y": A, B, F

사례 3 - "X": A, B, C / "Y": D, E, F

사례 1의 경우 두 코치 모두 자신이 담당하는 학생들끼리 붙어서 앉아있지 않다. 
사례 2의 경우 "X" 코치가 담당하는 학생들끼리는 연결되어 있지만,
"Y" 코치가 담당하는 학생들끼리는 붙어 있지 않다. 
사례 3의 경우 코치가 배정받은 학생들끼리 연결되어있음을 확인할 수 있다.

사례 1, 2는 자리 재배치가 필요하다. 사례 3은 필요하지 않다. 
다르게 표현하면 사례 1, 2는 각 코치에게 배정된 학생들이 서로 붙어서 앉아 있지 않고, 떨어져서 앉아있다. 
사례 3은 붙어서 앉아있다.

코치가 배정받은 M명의 학생과 좌석에 앉은 정보가 주어졌을 때, 
각 코치에게 배정된 학생들이 붙어서 앉아 있는지 확인 해보자.

입력
첫 번째 줄에 학생 수 N, 코치가 배정받을 학생 수 M, 간선의 수 E 가 공백을 통해 구분하여 주어진다.

두 번째 줄에 M 명의 학생이 알파벳 대문자로 주어진다.

세 번째 줄부터 E 개의 줄에 걸쳐 학생 연결 정보가 주어진다. 
연결 정보는 알파벳 대문자 2개로 구성되어 있으며, 두 알파벳에 해당하는 학생끼리 연결 되어 있다는 의미이다.

알파벳은 A부터 차례대로 학생 수 만큼 매긴다.

(2 ≤ N ≤ 10, 1 ≤ M ≤ N, 1 ≤ E ≤ N*(N-1)/2)

출력
각 코치에게 배정된 학생끼리 붙어서 앉아 있을 경우 "1"을, 아니라면 "0"을 출력한다. 
만약 모든 학생이 한 명의 코치에게 배정된 경우에도 "0"을 출력한다.


입력의 예 1
6 4 5
A C D E
A C
B C
C D
D E
E F
출력의 예 1
0

입력의 예 2
6 4 5
A C D B
A C
B C
C D
D E
E F
출력의 예 2
1

입력의 예 3
6 6 5
D E A F C B 
A F
A B
C B
F E
A D
출력의 예 3
0

*/

/*

B 문제에 이어서 BFS에 flag 추가와 함께 N == M인 경우 0 출력이 추가되었다.

*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10 + 10;

int N, M, E;
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

int main() {
  scanf("%d %d %d", &N, &M, &E);
  
  char student;
  for(int i=0; i<M; i++) {
    scanf(" %c", &student);
    students[student - 'A'] = 1;
  }
  
  char first, second;
  for(int i=0; i<E; i++) {
    scanf(" %c %c", &first, &second);
    first -= 'A';
    second -= 'A';

    myGraph[first].push_back(second);
    myGraph[second].push_back(first);
  }
  
  if(N == M) {
    printf("0\n");
    return 0;
  }

  for(int i=0; i<N; i++) {
    if(students[i] == 1) {
      int cnt = BFS(i, 1);
      
      if(cnt < M) {
        printf("0\n");
        return 0;
      }
      
      break;
    }
  }
  
  memset(visited, 0, sizeof(visited));
  
  for(int i=0; i<N; i++) {
    if(students[i] == 0) {
      int cnt = BFS(i, 0);
      
      if(cnt < N-M) {
        printf("0\n");
        return 0;
      }
      
      break;
    }
  }
    
  printf("1\n");
  
  return 0;
}