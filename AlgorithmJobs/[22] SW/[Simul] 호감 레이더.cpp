/*

시간 제한 1초

문제
YouWork 로 출근하던 현종은 의문의 문자 한 통을 받게된다. 

[Web발신]

(광고)아맞다 신규 기능 업데이트 기념 무료 리본 랜덤 지급 이벤트가 시작되었습니다! 
업데이트 이벤트에 참여하여 리본을 받으시고, 신규 기능 "호감 레이더"를 이용해보세요~ 

이벤트 참여하기 : https://..

신규 기능이 궁금한 현종은 한치의 의심없이 링크를 눌러 앱을 다시 다운받았다. 
분석한 기능은 다음과 같았다. 
사용자가 입력한 데이터를 토대로 앱을 킨 위치의 주변에 자신에게 호감을 가질만한 이성을 알려준다. 
자신에게 호감을 가질만한 이성을 "호감 추정 이성"이라 정의한다. 
가까이 있는 이성일수록 가중치가 높게 매겨지며, 
멀리 있는 이성일수록 가중치가 낮게 매겨진다. 
현재 위치에서 가장 가까운 거리는 10m이며, 가장 먼 거리는 (N+M-2)*10m 이다. 
이때, 거리 계산은 현재 위치가 (i, j)이고, 호감 추정 이성이 (y, x)에 있다면 거리는 (|i-y|+|j-x|)*10m 이다. 
레이더의 범위는 10m씩 잘라서 가중치를 측정하며, 
10m 미만의 범위에 사람이 있을 경우 레이더를 사용할 수 없다. 
호감 레이더를 켰을 때 현재 위치에서 얻을 수 있는 호감 가중치 합이 계산되어 화면에 보여진다. 
호감을 가질만한 이성들이 누구인지 프로필 목록을 확인하기 위해서는 
호감 가중치 합 만큼의 리본을 소모해야한다. 
호감 가중치의 계산은 레이더의 범위와 연관이 되어있다.

rader1[그림 1]

만약 랜덤으로 얻은 리본의 개수가 5이고, 호감 추정 이성 정보가 N * M 크기의 지도에 주어졌다고 하자. 
현재 현종이의 위치가 (2, 2), 레이더 범위가 20m라면 가중치 계산은 다음과 같다.

호감 가중치
= 현 위치에서 10m 떨어져있는 호감 추정 이성의 수 * 2 + 현 위치에서 20m 떨어져있는 호감 추정 이성의 수 * 1
= 1 * 2 + 4 * 1 = 6

랜덤 리본 보상으로 얻은 개수가 5개라면 아쉽지만 프로필을 열어볼 수 없는 상태이다.

rader2rader3
[그림 3]

만약 현재 위치가 (0, 1)이고, 레이더의 범위에 따른 호감 추정 이성의 수와 가중치의 합은 다음과 같다.
레이더 범위 : 10m, 호감 추정 이성 : 2, 가중치의 합 : 1 * 2 = 2
레이더 범위 : 20m, 호감 추정 이성 : 3, 가중치의 합 : 2 * 2 + 1 * 1 = 5
레이더 범위 : 30m, 호감 추정 이성 : 5, 가중치의 합 : 3 * 2 + 2 * 1 + 1 * 2 = 10
레이더 범위 : 40m, 호감 추정 이성 : 6, 가중치의 합 : 4 * 2 + 3 * 1 + 2 * 2 + 1 * 1 = 16
레이더 범위 : 50m, 호감 추정 이성 : 7, 가중치의 합 : 5 * 2 + 4 * 1 + 3 * 2 + 2 * 1 + 1 * 1 = 23
레이더 범위가 10m이라면 가중치 합은 2 * 1 로 2이고, 호감 추정 이성은 2명이다. 
레이더 범위가 20m라면 가중치 합은 2 * 2 + 1 * 1 로 5이고, 호감 추정 이성은 3이다. 
레이더 범위가 30m이라면 가중치 합은 3 * 2 + 2 * 1 + 1 * 2 로 10이고, 호감 추정 이성은 5이다. 
레이더 범위가 50m일때 해당 위치에서 가장 많은 호감 추정 이성을 소개받을 수 있지만, 
리본이 부족하여 프로필 리스트를 열어볼 수 없다. 
따라서, 가장 리본을 효율적으로 쓸 수 있는 레이더 범위는 2이다.

현재 보상받은 랜덤 리본을 통해 최대한 많은 인원의 호감 추정 이성의 프로필 목록을 확인하고 싶다. 
얻은 랜덤 보상 리본 수와 호감 정보 지도가 N*M 크기로 주어졌을때, 
1이 아닌 임의의 위치에서 호감 레이더 기능을 이용하여 확인할 수 있는 최대한 많은 인원의 프로필 수를 알아내보자.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다.(1 ≤ T ≤ 50) 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다. 
각각의 테스트 케이스의 첫 번째 줄에 호감 정보 지도의 크기 N, M, 
랜덤으로 지급 받은 리본의 갯수 K가 공백을 통해 구분하여 주어진다. (3 ≤ N, M ≤ 20, 1 ≤ K ≤ 10) 
다음 줄부터 N 줄에 걸쳐 M 개의 숫자가 공백을 통해 구분하여 주어진다. 
각 숫자는 0 혹은 1로 구성되어있다. 
0은 호감 추정 이성이 아니라는 의미, 1은 호감 추정 이성이라는 의미이다.

 

출력
각 테스트 케이스에 대해 프로필을 확인할 수 있는 최대 인원을 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. r은 문제에 대한 결과값을 뜻한다.

 

예제 입력
3
4 4 5
1 0 1 0
0 0 0 1
1 1 0 0
1 0 0 1
4 4 5
1 0 0 1
0 0 1 1
1 0 0 0
0 1 0 1
3 4 2
0 1 1 0 
1 1 0 1 
0 0 1 0 
예제 출력
#1 3
#2 3
#3 2

*/

#include <cstdio>
#include <cstring>

const int MAX = 48;
const int MAXNM = 30;

int N, M, K;
int map[MAXNM][MAXNM];
int love[MAX];

void getDist(int i, int j) {
  for(int k=0; k<N; k++) {
    for(int l=0; l<M; l++) {
      if(map[k][l] == 1) {
        int distY = i-k >= 0 ? i-k : k-i;
        int distX = j-l >= 0 ? j-l : l-j;
        
        love[distY+distX]++;
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  
  
  
  
  for(int t=1; t<=T; t++) {
    memset(map, 0, sizeof(map));
    scanf("%d %d %d", &N, &M, &K);
    
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        scanf("%d", &map[i][j]);
      }
    }
    
    int max = -987987987;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        if(map[i][j] == 0) {
          memset(love, 0, sizeof(love));
          
          getDist(i, j);
          
          int end = 1;
          while(1) {
            int sum = 0, num = 0;
            for(int k=0; k<end; k++) {
              sum += (end-k) * love[k+1];
              num += love[k+1];
            }

            if(sum > K) {
              end--;
              break;
            }
            
            end++;
          }
          
          int ans = 0;
          for(int k=0; k<end; k++) ans += love[k+1];
          
          if(max < ans) max = ans;
        }
      }
    }
    
    printf("#%d %d\n", t, max);
  }
  
  return 0;
}