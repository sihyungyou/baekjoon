#include <cstdio>

using namespace std;

int parent[500000];

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
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (do_find(a) == do_find(b)) {
            printf("%d\n", i);
            return 0;
        }
        do_union(a, b);
    }


    printf("0\n");

    return 0;
}
