// 소요시간: 20분

/*

1부터 N까지의 수가 1개씩 들어있는 길이 N 수열에서 연속된 K개를 고르면 K개 중 가장 작은 정수로 바뀌는데,
이를 모두 같은 수로 변환하기 위한 최소 선택 횟수를 고르는 문제이다.

처음에는 완전탐색을 생각했으나, N이 최대 100,000이기 때문에 O(N^2)인 완전탐색으로는 해결할 수 없었다.
그래서 예시를 들어가며 가장 적은 횟수를 어떻게 알아낼까 생각했는데,
어떤 범위의 K개를 고르든 결국 마지막에는 가장 작은 수 1개로 치환되어야 하기 때문에
K개가 연결고리처럼 한개씩은 걸쳐있는 모습이 되어야 정답을 구할 수 있을 거라고 생각했다.

이를 구현하기 위해 연결고리를 위해 초기에 K개를 N개에서 빼주고,
나머지는 K-1개씩 빼줬을 때 생기는 덩어리 + 1을 출력하도록 했더니 정답이었다.

결과적으로는 주어진 num은 이 문제랑 아무 관련이 없게 되었고... 조금 허무했다 ㅎㅎㅎ;;
그래도 문제의 출제 의도는 완전탐색은 안된다는 것 같으니...... 오케이!

*/

#include <cstdio>

using namespace std;

int N, K;
int num[100010];

int main() {
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) scanf("%d", &num[i]);
	
    N -= K;
	
    if(N % (K-1) == 0) printf("%d\n", 1 + N/(K-1));
    else printf("%d\n", 2 + N/(K-1));
	
    return 0;
}