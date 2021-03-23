#include <cstdio>

using namespace std;

int parent[201];

int do_find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = do_find(parent[x]);
}

void do_union(int x, int y) {
    int px = do_find(x);
    int py = do_find(y);

    if (px < py) parent[py] = px;
    else parent[px] = py;
}

int main() {

    int n, m, prev, cur;
    
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i <= n; i++) parent[i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int road;
            scanf("%d", &road);
            if (road == 1) {
                do_union(i, j);
            }
        }
    }

    scanf("%d", &prev);
    for (int i = 0; i < m - 1; i++) {
        scanf("%d", &cur);
        if (do_find(cur) != do_find(prev)) {
            printf("NO\n");
            return 0;
        }
        prev = cur;
    }

    printf("YES\n");

    return 0;
}
