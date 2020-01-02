#include <cstdio>

using namespace std;

bool graph[101][101] = { 0, };
bool v[101] = { false, };
int n, m, i, src, dest, cnt = 0;

void dfs(int s) {
    int i;
    v[s] = true;

    for (i = 1; i <= n; i++) {
        if (graph[s][i] && !v[i]) {
            cnt++;
            dfs(i);
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = true;
        graph[dest][src] = true;
    }

    dfs(1);
    printf("%d\n", cnt);

    return 0;
}