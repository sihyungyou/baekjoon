#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int tree[10001][10001] = { 0, };
int visit[10001] = { false, };
int v;

int dfs(int src) {
    printf("dfs at %d\n", src);
    visit[src] = true;

    int weight = 0;
    for (int i = 1; i <= v; i++) {
        if (tree[src][i] != 0 && !visit[i]) {
            // 간선이 있고 아직 방문하지 않았다면 dfs
            weight = max(weight, tree[src][i] + dfs(i));
        }
    }

    visit[src] = false;
    printf("return %d from %d\n", weight, src);
    return weight;
}

int main() {

    int n;
    scanf("%d", &n);
    v = n;

    for (int i = 0; i < n - 1; i++) {
        int p, c, w;
        scanf("%d %d %d", &p, &c, &w);
        tree[p][c] = w;
    }

    // 1번노드에서
    int answer = 0;
    for (int i = 2; i <= v; i++) {
        if (tree[1][i] != 0) {
            answer = max(answer, tree[1][i] + dfs(i));
            printf("answer : %d\n", answer);
        }
    }

    printf("%d\n", answer);

    return 0;
}
