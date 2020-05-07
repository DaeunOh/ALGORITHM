// 소요시간: 17분
// 실행시간: 0ms

/*

문제 설명

네오는 평소 프로도가 비상금을 숨겨놓는 장소를 알려줄 비밀지도를 손에 넣었다. 
그런데 이 비밀지도는 숫자로 암호화되어 있어 위치를 확인하기 위해서는 암호를 해독해야 한다. 
다행히 지도 암호를 해독할 방법을 적어놓은 메모도 함께 발견했다.

1. 지도는 한 변의 길이가 n인 정사각형 배열 형태로, 각 칸은 공백(" ) 또는벽(#") 두 종류로 이루어져 있다.
2. 전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다. 각각 지도 1과 지도 2라고 하자. 
   지도 1 또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다. 
   지도 1과 지도 2에서 모두 공백인 부분은 전체 지도에서도 공백이다.
3. 지도 1과 지도 2는 각각 정수 배열로 암호화되어 있다.
4. 암호화된 배열은 지도의 각 가로줄에서 벽 부분을 1, 공백 부분을 0으로 부호화했을 때 
   얻어지는 이진수에 해당하는 값의 배열이다.

[그림1]

네오가 프로도의 비상금을 손에 넣을 수 있도록, 비밀지도의 암호를 해독하는 작업을 도와줄 프로그램을 작성하라.

입력 형식
입력으로 지도의 한 변 크기 n 과 2개의 정수 배열 arr1, arr2가 들어온다.
- 1 ≦ n ≦ 16
- arr1, arr2는 길이 n인 정수 배열로 주어진다.
- 정수 배열의 각 원소 x를 이진수로 변환했을 때의 길이는 n 이하이다. 즉, 0 ≦ x ≦ 2n - 1을 만족한다.

출력 형식
원래의 비밀지도를 해독하여 '#', 공백으로 구성된 문자열 배열로 출력하라.

*/

/*

◆ 풀이

십진수를 이진수로 바꾸는 방법과, 0과 1의 OR 연산을 통해 주어진 암호를 해독하면 되는 문제.

arr에 들어있는 모든 숫자를 bin 배열에 이진수로 바꾼 후 집어 넣은 다음,
OR연산을 거친 결과들은 거꾸로 다시 정렬되어야 하므로 배열의 뒤에서부터 확인하는 방식을 사용했다.


◆ 후기

나는 두 개의 수를 각각 2진수로 바꾸고, 그 바꾼 값에다가 OR 연산을 사용했는데,
알고보니 두 개의 수를 OR한 다음에 그 값을 이진수로 바꿔도 원하는 값이 나옴을 다른 해설을 통해 보았다..!

그리고 str = "#" + str; 과 같이 기존 스트링의 앞에 붙여주는 방식을 사용하면
굳이 뒤에서부터 볼 필요 없이 스트링의 연장이 가능하게 된다.
새로운 방법을 알아가서 좋당 ㅎㅎ

*/

#include <string>
#include <vector>

using namespace std;

const int MAX = 16 + 10;

void toBinary(int n, int bin[]) {
    int idx = 0;
    while(n) {
        bin[idx++] = n % 2;
        n /= 2;
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++) {
        int bin1[MAX] = {0, };
        int bin2[MAX] = {0, };
        string str = "";
        
        toBinary(arr1[i], bin1);
        toBinary(arr2[i], bin2);
        
        for(int j=n-1; j>=0; j--) {
            if(bin1[j] | bin2[j]) str += "#";
            else str += " ";
        }
        
        answer.push_back(str);
    }
    
    return answer;
}