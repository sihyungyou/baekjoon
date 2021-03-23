#include <cstdio>
using namespace std;

int arr[101][101] = { 0, };
bool visit[101] = { false, };
int n, ans = 0;

void dfs(int me, int find, int num) {
    visit[me] = true;

    if (me == find) {
        // 만약 찾았다면 지금까지 누적된 촌수를 저장하고 return
        ans = num;
        return;
    }

    for (int i = 1; i <= n; i++) {
        // 부모나 자식을 촌수를 올리며 순회해본다
        if (arr[me][i] == 1 && !visit[i]) {
            dfs(i, find, num + 1);
        }
    }

    // 연결된 모든 부모 및 자식을 순회했다면 return
    return;
}

int main() {
    int a, b, m;
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int parent, child;
        scanf("%d %d", &parent, &child);
        arr[child][parent] = 1;
        arr[parent][child] = 1;
    }

    dfs(a, b, 0);

    ans == 0 ? printf("-1\n") : printf("%d\n", ans);

    return 0;
}
