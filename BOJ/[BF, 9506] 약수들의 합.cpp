// 소요시간: 30분
// 실행시간: 888ms, 76ms

/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초		128 MB		244	105	89	45.876%

문제
암호화 방식 중에는 소수를 이용하는 것들이 많다. 
보통은 매우 큰 두 개의 소수를 선택하고, 두 소수를 곱한 값을 암호화에서의 키로 사용하고는 한다. 
이러한 방법이 좋은 이유는 일반적으로 매우 큰 수를 소인수분해 하는 것이 어렵기 때문이다.

소수를 택할 때 큰 수를 택하면, 이 둘을 곱해서 얻어지는 키 값도 커지게 된다. 
하지만 그 반대는 성립하지 않을 수도 있다. 즉, 키 값이 매우 큰 경우에도 이를 소인수분해 하는 것은 쉬울 수도 있다.

따라서 암호문이 크랙되지 않도록 하기 위해서는, 키 값이 적절히 큰 수들의 곱으로 이루어져 있는지를 확인해야 할 필요가 있다.
키 값 K(4≤K≤10^100)와 정수 L(2≤L≤1,000,000)이 주어졌을 때, 
K를 인수분해 했을 때, 항상 L 이상의 값으로만 이루어져 있는지를 확인하고 싶다. 
물론 인수분해 할 때 1로 나누는 경우는 고려하지 않는다.

예를 들어 K=143인 경우, 이는 11과 13의 곱으로 이루어져 있다. 
즉, 이를 인수분해 하는 방법은 11×13, 143의 두 가지 경우뿐이다. 
따라서 L이 11일 경우에는 인수분해 했을 때 나온 수들이 모두 L 이상이므로 좋은 경우지만, 
L이 12이상일 경우에는 좋은 암호가 아니다.

K와 L이 주어졌을 때, 좋은 암호인지 판단하는 프로그램을 작성하시오.

입력
첫째 줄에 두 정수 K, L이 주어진다.

출력
좋은 암호인 경우에는 GOOD을 출력한다. 나쁜 암호일 경우에는 BAD를 출력하고, K의 가장 작은 (1 아닌) 인수를 출력한다.

예제 입력 1 
143 11
예제 출력 1 
GOOD

예제 입력 2 
143 12
예제 출력 2 
BAD 11

*/

/*

정수 K를 2부터 L-1까지 나눠보면서 나누어 떨어지는지(BAD), 떨어지지 않는지 확인하는 문제.

정수 K가 최대 10^100으로 매우 큰 수기 때문에 일반 숫자를 담는 변수가 아닌 string을 사용해야 하는 것과,
인수분해 했을 때 L이상인 수는 고려할 필요가 없으므로
2부터 L-1까지 나눠봤을 때 나눠지는지 아닌지만 확인하면 된다는 것은 금방 캐치할 수 있었다.

하지만 string에 대한 나눗셈을 도대체 어떻게 해야하는지는 전혀 떠오르지 않았고,
이건 아무리 생각해도 절대 떠오르지 않을 방법이라 생각하여 나누는 방법에 대한 힌트를 찾아봤다.

그 결과 유용하게 쓰이는 mod 함수가 존재했다. (자세한 내용은 코드 참조)
나는 나눗셈을 어떻게 해야하는지를 생각하고 있었는데, 알고보니 나눗셈이 아닌 "나머지"가 존재하는지만 보면 된 것이었다.
이 함수를 알게된 이후에는 이를 적용해서 나머지가 0인 경우에는 바로 BAD와 해당 수를 출력하고 return하도록 코드를 짰다.

그리고 제출했을 때는 888ms라는.. 꽤 높은 실행시간을 접할 수 있었다.. ㄷㄷ
어떻게 하면 이를 줄일 수 있을지 생각하다가, 초기에 생각이 났었던 소수를 이용해보면 어떨까 하는 생각이 들었다.
즉, 2로 나누었을 때 나눠지지 않는다면 4로 나눠도, 6으로 나눠도... 어떤 2의 배수로 나눠도 나눠지지 않을 것이다.

그래서 2부터 L-1까지의 소수를 에라토스테네스의 체를 이용하여 구하고,
이를 사용하여 소수만 나눠보도록 했더니 76ms라는 실행시간을 얻을 수 있게 되었다!

*/

#include <iostream>
#include <string>

using namespace std;

const int MAX = 1000000 + 10;

string K;
int L;
bool notPrime[MAX];

void getPrime() {
    for (int i = 2; i < L; i++) {
        if (!notPrime[i]) {
            for (int j = i + i; j < L; j += i) {
                notPrime[j] = true;
            }
        }
    }
}

int mod(int l) {
    int R = 0;
    for (int i = 0; i < K.length(); i++) R = (R * 10 + (K[i] - '0')) % l;

    return R;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> K >> L;
    getPrime();

    for (int i = 2; i < L; i++) {
        if (!notPrime[i] && !mod(i)) {
            cout << "BAD " << i;
            return 0;
        }
    }

    cout << "GOOD";

    return 0;
}