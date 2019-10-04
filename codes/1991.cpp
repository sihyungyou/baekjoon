/*
문제
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

예를 들어 위와 같은 이진 트리가 입력되면,

전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
가 된다.

입력
첫째 줄에는 이진 트리의 노드의 개수 N(1≤N≤26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 차례대로 영문자 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현된다.

출력
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.
*/

#include <cstdio>

using namespace std;

char arr[54];
int len;

void pre(int v) {
    if (arr[v] != '.') printf("%c", arr[v]);
    if (v*2 < len) pre(v*2);
    if (v*2+1 < len) pre(v*2+1);
}

void mid(int v) {
    if (v*2 < len) mid(v*2);
    if (arr[v] != '.') printf("%c", arr[v]);
    if (v*2+1 < len) mid(v*2+1);
}

void post(int v) {
    if (v*2 < len) post(v*2);
    if (v*2+1 < len) post(v*2+1);
    if (arr[v] != '.') printf("%c", arr[v]);
}

int main() {
    int n, i, j;
    char r, lc, rc;
    scanf("%d", &n);

    len = n*2+2;
    for (i = 0 ; i < len; i++) arr[i] = '.';
    arr[1] = 'A';

    for (i = 0 ; i < n; i++) {
        scanf(" %c %c %c", &r, &lc, &rc);
        if (r != '.') { 
            for (j = 1; j < len; j++) if (arr[j] == r) break; 
            if (lc != '.') arr[j*2] = lc;
            if (rc != '.') arr[j*2+1] = rc;
        }
    }

    pre(1);
    printf("\n");
    mid(1);
    printf("\n");
    post(1);
    printf("\n");
    

    return 0;
}