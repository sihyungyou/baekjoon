#include <cstdio>
#include <vector>
using namespace std;

#define N 100000

// N x N 배열을 만들기에는 공간복잡도에서 실패
vector<int> tree[N+1];
bool visit[N+1] = { false, };
int n;

int ans[N+1];

void dfs(int from) {
    visit[from] = true;

    for (int i = 0; i < tree[from].size(); i++) {
        int node = tree[from][i];
        if (!visit[node]) {
            // node의 부모로 from을 저장하고 i에서 다시 dfs
            ans[node] = from;
            dfs(node);
        }
    }

    return;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
