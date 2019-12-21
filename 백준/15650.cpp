/*
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/


#include <cstdio>

using namespace std;

int n, m;
bool check[9] = { false, };
int list[8];

void dfs(int cnt) {
    int i, k;
    if (cnt == m) {
        for (k = 0; k < m - 1; k++) if (list[k] > list[k+1]) break;
        if (k == m-1) {
            for (i = 0; i < m; i++) {
                printf("%d ", list[i]);
            }
            printf("\n");
        }
        return;
    }
    for (i = 1; i <= n; i++) {
        // if already check -> skip
        if (!check[i]) {
            // if not checked yet,
            check[i] = true;        // check the number
            list[cnt] = i;          // add to printnig list
            dfs(cnt+1);             // try dfs starting from next number
            check[i] = false;       // after dfs, remove checked number
        }
    }

}

int main() {

    scanf("%d %d", &n, &m);
    
    dfs(0);
    return 0;
}