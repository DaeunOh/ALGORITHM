// 소요시간: 56분
// 실행시간: 최대 6ms

/*

문제 설명

고고학자인 튜브는 고대 유적지에서 보물과 유적이 가득할 것으로 추정되는 비밀의 문을 발견하였습니다. 
그런데 문을 열려고 살펴보니 특이한 형태의 자물쇠로 잠겨 있었고 
문 앞에는 특이한 형태의 열쇠와 함께 자물쇠를 푸는 방법에 대해 다음과 같이 설명해 주는 종이가 발견되었습니다.

잠겨있는 자물쇠는 격자 한 칸의 크기가 1 x 1인 N x N 크기의 정사각 격자 형태이고 
특이한 모양의 열쇠는 M x M 크기인 정사각 격자 형태로 되어 있습니다.

자물쇠에는 홈이 파여 있고 열쇠 또한 홈과 돌기 부분이 있습니다. 
열쇠는 회전과 이동이 가능하며 열쇠의 돌기 부분을 자물쇠의 홈 부분에 딱 맞게 채우면 자물쇠가 열리게 되는 구조입니다. 
자물쇠 영역을 벗어난 부분에 있는 열쇠의 홈과 돌기는 자물쇠를 여는 데 영향을 주지 않지만, 
자물쇠 영역 내에서는 열쇠의 돌기 부분과 자물쇠의 홈 부분이 정확히 일치해야 하며 
열쇠의 돌기와 자물쇠의 돌기가 만나서는 안됩니다. 
또한 자물쇠의 모든 홈을 채워 비어있는 곳이 없어야 자물쇠를 열 수 있습니다.

열쇠를 나타내는 2차원 배열 key와 자물쇠를 나타내는 2차원 배열 lock이 매개변수로 주어질 때, 
열쇠로 자물쇠를 열수 있으면 true를, 열 수 없으면 false를 return 하도록 solution 함수를 완성해주세요.

제한사항
1) key는 M x M(3 ≤ M ≤ 20, M은 자연수)크기 2차원 배열입니다.
2) lock은 N x N(3 ≤ N ≤ 20, N은 자연수)크기 2차원 배열입니다.
3) M은 항상 N 이하입니다.
4) key와 lock의 원소는 0 또는 1로 이루어져 있습니다.
  4-1) 0은 홈 부분, 1은 돌기 부분을 나타냅니다.

입출력 예
key	lock	result
[[0, 0, 0], [1, 0, 0], [0, 1, 1]]	[[1, 1, 1], [1, 1, 0], [1, 0, 1]]	true

입출력 예에 대한 설명
자물쇠와 열쇠.jpg

key를 시계 방향으로 90도 회전하고, 오른쪽으로 한 칸, 아래로 한 칸 이동하면 lock의 홈 부분을 정확히 모두 채울 수 있습니다.

*/

/*

key를 회전과 이동을 통해 여러 위치로 옮겨가면서 둘 사이의 돌기가 서로 만나지 않고,
lock의 홈이 모두 채워지는 경우를 찾아 true 또는 false를 반환하는 문제.

처음에는 어떻게 key를 lock에 딱 맞출 수 있도록 만들지 생각했는데,
key와 lock의 최대 크기가 20 x 20밖에 되지 않기 때문에, 완전탐색을 사용한다고 해도
시간복잡도를 대략적으로 계산하면 (맵의 크기 100 * 100) * (key의 크기 20 * 20) * (회전 횟수 4)로,
약 1억번의 연산 횟수가 1초가 걸린다고 하면, 1600만번 정도는 가뿐하게 진행될 수 있다!ㅎㅎ
그래서 별 고민없이 바로 완전탐색으로 구현에 들어갔다.

key는 회전과 이동이 가능하기 때문에, lock을 맵에 고정하여 key를 움직이는 것이 편리하다.
lock을 맵에 고정하기 위해 나는 key가 이동할 수 있는 반경을 고려해 맵의 가운데에 위치시켰다.

이후 (1, 1)부터 (N+M-1, N+M-1)까지를 key의 시작 지점으로 하여 key를 이동시키도록 했는데,
key가 이동할 때 lock의 숫자가 같은 부분이 있으면 안된다. (즉, 돌기와 돌기가 만나거나 홈과 홈이 만나면 안된다.)
또한, lock이 0이고 key가 1인 경우에는 lock부분을 1로 메꿔주는 것이 필요하다. (홈과 돌기가 만나는 부분)

key에 따라 lock을 적당히 채워주고, lock에 존재하는 모든 홈이 채워졌다면 다른 건 볼 필요 없이 true를 리턴하면 된다.
하지만 그렇지 않다면, 90도, 180도, 270도 회전과 함께 key를 계속 이동시켜 줘야한다.

2차원 배열을 회전하는 문제는 처음이지만, 알고 있으면 유용하게 쓰일 것 같다. 회전 방법은 다음과 같다.
for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
        temp[i][j] = arr[n-1-j][i];
    }
}
즉, 회전 후의 [i][j]는 회전 전의 [n-1-j][i]의 값을 넣은 것임을 알 수 있다.
(식 자체를 기억하지 않아도 예시를 들어 생각해보면 금방 식을 유도할 수 있다.)

그리고 만약 해당 과정을 다 거쳤음에도 key와 lock이 맞는 부분이 생기지 않는다면 false를 리턴하면 된다.


*/

#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 100;

int map[MAX][MAX] = {false, };
int N, M;

void rotateKey(vector<vector<int>> &key) {
    int temp[MAX][MAX];
    
    // key를 90도 회전시킨 값을 temp에 저장한다.
    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            temp[i][j] = key[M-1-j][i];
    
    // temp에 저장된 값을 다시 key에 옮긴다.
    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            key[i][j] = temp[i][j];
}

bool moveKey(vector<vector<int>> &key, int y, int x) {
    int temp[MAX][MAX];
    memcpy(temp, map, sizeof(temp));
    
    // 이동시에 key와 lock의 숫자가 같은 부분이 있으면 안된다.
    // 같은 부분 = 홈과 홈이 만나거나 돌기와 돌기가 만난 것을 의미한다.
    // lock이 0이고, key가 1인 부분은 lock을 1로 메꿔준다.
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            if(temp[i+y][j+x] == -1) continue;
            
            if(temp[i+y][j+x] == key[i][j]) return false;
            else if(!temp[i+y][j+x]) temp[i+y][j+x] = 1;
        }
    }
    
    // lock을 봤을 때, 0이 존재하면 안된다.
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(!temp[i+M][j+M]) return false;
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    N = lock.size();
    M = key.size();
    
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            map[i][j] = -1;
    
    // 1) 자물쇠를 가운데에 둔다.
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            map[i+M][j+M] = lock[i][j];
    
    // 2) key를 이동시킨 후에 90도 회전시킨다.
    for(int k=0; k<4; k++) {
        for(int i=1; i<N+M; i++)
            for(int j=1; j<N+M; j++)
                if(moveKey(key, i, j)) return true;
        
        rotateKey(key);
    }
    
    return false;
}