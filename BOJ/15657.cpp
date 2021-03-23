#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int printarr[8];

void dfs(int num, int cnt) {

    if (cnt == m) {
        // 개수가 모두 찼다면 m개 출력
        for (int i = 0; i < m; i++) {
            printf("%d ", printarr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        // i는 방문하려는 노드의 인덱스인데, 중복은 가능하지만 자기보다 같거나 큰 수만 출력
        if (num <= arr[i]) {
            printarr[cnt] = arr[i];
            dfs(arr[i], cnt + 1);
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    dfs(0, 0);

    return 0;
}
