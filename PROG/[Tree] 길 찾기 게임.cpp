/*

▶ 소요시간 및 실행시간
1시간 51분, 5ms

▶ 문제
이진트리를 구성하는 노드들의 좌표가 담긴 배열 nodeinfo가 매개변수로 주어질 때,
노드들도 구성된 이진트리를 전위 순회, 후위 순회한 결과를 2차원 배열에 순서대로 담아 return 하시오.

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/42892


▶ 풀이
좌표 값으로 주어지는 노드들을 트리로 구성하고, 전위 순회와 후위 순회한 결과를 구하는 문제.
전위 순회와 후위 순회의 방법은 어떤 순서대로 방문할 것인가만 알고 있으면 구현이 어렵지 않으므로,
이 문제의 핵심은 "좌표 값으로 주어지는 노드들을 어떻게 트리로 구성할 것인가"이다.

문제에서는 같은 y값은 같은 level을 의미하며,
임의의 노드 V의 왼쪽 서브트리는 항상 V의 x값보다 작으며, 오른쪽 서브트리는 항상 V의 x값보다 크다고 나와있다.

nodeinfo에는 1번 노드부터 N번 노드까지 순서대로 들어있기 때문에
x좌표, y좌표, 노드 번호를 담는 NODE라는 구조체를 선언하여 모든 노드를 벡터에 넣어준 후,
벡터를 정렬할 때는 y를 내림차순 우선 정렬하고, y값이 같으면 x를 오름차순으로 정렬한다.
(노드 번호를 기억하고 있어야 전위 순회, 후위 순회를 할 수 있다.)

정렬 과정을 거치면 nodes[0]에는 루트 노드가 들어갈 것이고,
1부터 N-1까지는 같은 레벨 내에서 x가 오름차순으로 정렬되어 있을 것이다.

트리를 구성하기 위해서는 루트 노드부터 차례로 왼쪽 노드와 오른쪽 노드를 설정해주는 것이 필요하다.
이때 항상 첫 시작은 루트 노드로 하는 재귀함수가 사용되며,
현재 노드의 x보다 작은지 큰지, 그리고 현재 노드의 왼쪽(또는 오른쪽) 노드가 있는지 없는지에 따라 트리가 구성된다.

만약 후보가 되는 노드가 현재 노드의 x보다 작다면 왼쪽 서브트리에 포함되는 노드가 되고,
왼쪽 서브트리에 포함되면서 현재 노드의 왼쪽 노드 NULL인 상태라면 후보가 되는 노드는 현재 노드의 왼쪽 노드로 설정된다.
(x보다 큰 경우도 오른쪽에 대하여 위 과정과 똑같이 진행된다.)

트리가 구성되고 나면 전위 순회는 Root, Left, Right의 순서로 방문하게 되며,
후위 순회는 Left, Right, Root의 순서로 방문하게 된다.

▶ 후기
사실 트리와 관련된 문제는 지금까지 푼 문제가 얼마 없기에 개념이 잘 잡혀있지 않은 상태이다.

부모와 자식이 확정되어 있는 트리에서 전위, 중위, 후위 순회까지는 할 수 있지만,
사실 내가 스스로 트리를 구성하는 데에는 자신이 없다.
(이 문제를 푸는데 1시간 51분이라는 엄청난 시간이 걸린 이유..ㅎㅎ;;ㅠㅠ)

그런 점에서 이 문제는 트리에 대해 조금 더 생각할 수 있도록 해준 좋은 문제라고 생각한다.
그리고 사실 트리뿐만 아니라 포인터와 레퍼런스에 대해서도 이 문제를 통해 개념을 잡을 수 있게 되었다.

대부분의 문제에서 레퍼런스를 사용하는 방식을 주로 이용해왔기에 레퍼런스에 대해선 어느정도 알고 있었으나,
포인터는 거의 이용한 경험이 없어 다른 사람이 포인터를 사용할 때마다 곤욕을 치뤘던 경험이 있다.

포인터와 레퍼런스는 어떠한 대상을 가리킨다는 점에서는 같으나,
1) NULL 허용 여부와 2) 참조 대상 할당 및 접근에 있어서는 차이가 있다.

조금 더 구체적으로 설명하면, 포인터는 NULL을 허용하지만, 레퍼런스는 NULL이 될 수 없기에
레퍼런스를 사용하면 잘못된 참조로 인해 발생되는 오류를 방지할 수 있으며,
포인터는 할당할 때 참조 대상에 대해 & 연산을 통해 주소값을 할당하지만, 레퍼런스는 참조 대상을 그대로 할당하기에
포인터는 ->와 같은 포인터 연산자를 통해 접근해야 하나, 레퍼런스는 지역변수처럼 접근할 수 있다는 것이다.

안정성을 고려할 때는 레퍼런스가 더 낫다는 말을 어디서 들었던 적이 있어서(?)
이 문제에서도 레퍼런스를 이용하려고 했으나, 구조체 내에서 자신의 구조체를 그대로 사용하기 위해서는
포인터로 선언해주지 않으면 사용할 수 없었기에 어쩔 수 없이 포인터를 사용하게 되었다.

그렇기에 addNode라는 함수 내에서는 같이 포인터 연산자를 이용하여 왼쪽 노드와 오른쪽 노드를 결정했고,
preorder와 postorder 역시 포인터를 사용하여 자신의 노드 번호를 결과에 넣어주는 방식을 사용했다.

사실 포인터 같은 경우 *와 & 그리고 ->와 같은 이상한 특수문자들을 많이 사용해서
그동안 사용하는 것을 꺼려왔는데, 이제 사용법도 제대로 알았으니 필요한 경우에는 잘 사용해보도록 해야겠다!
(포인터와 레퍼런스 참고자료: https://gracefulprograming.tistory.com/11)

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct NODE {
    int x, y, idx;
    NODE* left; // NODE를 구조체 내에서 사용하기 위해서는 포인터로 선언해줘야 한다.
    NODE* right;
};

vector<NODE> nodes;

bool comp(NODE &a, NODE &b) { // y를 내림차순 우선 정렬하고, y값이 같으면 x를 오름차순으로 정렬한다.
    if(a.y == b.y) return a.x < b.x;
    else return a.y > b.y;
}

void addNode(NODE *parent, NODE *child) {
    if(child->x < parent->x) { // child는 parent의 left subtree에 있는 노드이다.
        if(parent->left == NULL) parent->left = child; // 자신의 왼쪽 노드가 없을 경우
        else addNode(parent->left, child); // 자신의 왼쪽 서브트리로 넘어간다.
    }
    else { // child는 parent의 right subtree에 있는 노드이다.
        if(parent->right == NULL) parent->right = child;
        else addNode(parent->right, child);
    }
}

void preorder(NODE *node, vector<int> &answer) { // root L R
    answer.push_back(node->idx);
    if(node->left) preorder(node->left, answer);
    if(node->right) preorder(node->right, answer);
}

void postorder(NODE *node, vector<int> &answer) { // L R root
    if(node->left) postorder(node->left, answer);
    if(node->right) postorder(node->right, answer);
    answer.push_back(node->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    
    for(int i=0; i<nodeinfo.size(); i++)
        nodes.push_back({nodeinfo[i][0], nodeinfo[i][1], i+1});
    
    sort(nodes.begin(), nodes.end(), comp);
    
    for(int i=1; i<nodes.size(); i++)
        addNode(&nodes[0], &nodes[i]); // node[i]를 tree에 추가한다.
    
    preorder(&nodes[0], answer[0]);
    postorder(&nodes[0], answer[1]);
    
    return answer;
}