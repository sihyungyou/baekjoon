#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int printarr[8];

void dfs(int cnt) {

    if (cnt == m) {
        // 개수가 모두 찼다면 m개 출력
        for (int i = 0; i < m; i++) {
            printf("%d ", printarr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        // i는 방문하려는 노드의 인덱스인데, 중복도 가능하고 자기보다 큰 수만 출력하지 않아도 괜찮음
        printarr[cnt] = arr[i];
        dfs(cnt + 1);
    }
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    dfs(0);

    return 0;
}
