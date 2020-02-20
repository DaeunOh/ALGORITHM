/*

문제
현재 몰입캠프를 수강하는 N 명의 학생이 코칭을 받기 위해 자리에 앉아있다. 
N 명의 학생 중 M 명의 학생을 배정받은 담당 코치는 
자신이 담당하는 학생들끼리 붙어서 앉아 있는지 확인한 후, 자리를 재배치하려고 한다. 
현재 A 부터 F 학생들이 좌석에 앉은 정보를 그래프로 표현하여 나타내면 다음과 같다.

coach-b.png

수강생끼리 간선으로 연결되어 있다면 서로 붙어서 앉아 있다는 의미이다. 
예를 들어, C 학생은 A, B, D 학생과 붙어서 앉아있다. 
만약 배정받은 학생이 1명이라면 붙어 앉아 있다고 정의한다.

코치가 배정받은 M명의 학생과 좌석에 앉은 정보가 주어졌을 때, 
M 명의 학생들이 붙어서 앉아 있는지 확인 해보자.

입력
첫 번째 줄에 학생 수 N, 코치가 배정받을 학생 수 M, 간선의 수 E 가 공백을 통해 구분하여 주어진다.
두 번째 줄에 M 명의 학생이 알파벳 대문자로 주어진다.
세 번째 줄부터 E 개의 줄에 걸쳐 학생 연결 정보가 주어진다. 
연결 정보는 알파벳 대문자 2개로 구성되어 있으며, 두 알파벳에 해당하는 학생끼리 연결 되어 있다는 의미이다.

알파벳은 A부터 차례대로 학생 수 만큼 매긴다.

(2 ≤ N ≤ 10, 1 ≤ M ≤ N, 1 ≤ E ≤ N*(N-1)/2)

출력
배정 받은 학생끼리 연결되어있다면 "1"을, 아니라면 "0"을 출력한다.


입력의 예 1
6 4 5
A C D E
A C
B C
C D
D E
E F
출력의 예 1
1

입력의 예 2
6 4 5
A C D F
A C
B C
C D
D E
E F
출력의 예 2
0

입력의 예 3
6 6 5
D E A F C B 
A F
A B
F B
F E
A D
출력의 예 3
0

*/

/*

BFS 또는 DFS를 이용해서 연결되어 있는지 확인하는 문제.
(BFS로 구현했지만, DFS로 구현하면 더 깔끔한 코드가 나온다.)

나는 문자 A를 처리하는 과정에서 A의 아스키코드를 몰라 직접 출력해보고 
그 숫자를 빼는 방식으로 사용했는데,
그렇게 할 필요 없이 student라는 변수가 문자 하나를 담고 있는 변수라면
student - 'A' 를 하게 되면, student가 'A'일 시에 0으로 처리 된다.

또한, BFS 방식으로 그래프를 순회하는 과정에서
매번 추가적인 M번짜리 반복문을 사용하여 가야 하는 정점이 맞는지 확인했지만,
초기 M명의 학생들을 입력받을 때, students의 0번째 부터 차례로 넣는 것이 아닌
students의 해당 알파벳 자리(A면 0, B면 1...)에 1 표시를 해두면
반복문을 돌 필요 없이 students[myGraph[front][i]]가 1인지 확인만 하면 된다.

*/

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 10 + 10;

int N, M, E;
int students[MAXN];
vector <int> myGraph[MAXN];
queue <int> q;

int visited[MAXN] = {0, };
int cnt = 0;

int main() {
  scanf("%d %d %d", &N, &M, &E);
  
  char student;
  for(int i=0; i<M; i++) {
    scanf(" %c", &student);
    students[i] = student - 'A';
  }
  
  char first, second;
  for(int i=0; i<E; i++) {
    scanf(" %c %c", &first, &second);
    first -= 'A';
    second -= 'A';

    myGraph[first].push_back(second);
    myGraph[second].push_back(first);
  }
  
  q.push(students[0]);
  visited[students[0]] = 1;
  
  while(!q.empty()) {
    int front = q.front();
    q.pop();
    cnt++;

    for(int i=0; i<myGraph[front].size(); i++) {
      if(!visited[myGraph[front][i]]) {
        for(int j=0; j<M; j++) {
          if(students[j] == myGraph[front][i]) {
            visited[myGraph[front][i]] = 1;
            q.push(myGraph[front][i]);
            break;
          }
        }
      }
    }
  }
  
  if(cnt == M) printf("1\n");
  else printf("0\n");
  
  return 0;
}