#include <algorithm>
#include <cstdio>
using namespace std;

int p[201];
int r[201];

int do_find(int x) {
    if (p[x] == x) return x;
    else return p[x] = do_find(p[x]);
}

void do_union(int a, int b) {
    int x = do_find(a);
    int y = do_find(b);

    if (x == y) return;

    if (r[x] < r[y]) swap(x, y);
    p[y] = x;

    if (r[x] == r[y]) r[x]++;
}

int main() {

    int n, m, i, j;

    scanf("%d", &n);
    scanf("%d", &m);

    int map[n+1][n+1];

    for (i = 0; i <= n; i++) {
        p[i] = i;
        r[i] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                int pi = do_find(i);
                int pj = do_find(j);

                if (pi != pj) do_union(i, j);
            }
        }
    }

    int cur, prev;
    bool flag = true;

    scanf("%d", &prev);
    for (i = 0; i < m-1; i++) {
        scanf("%d", &cur);
        int pp = do_find(prev);
        int pc = do_find(cur);
        if (pp != pc) {
            printf("NO\n");
            flag = false;
            break;
        }
        prev = cur;
    }

    if (flag) printf("YES\n");

    return 0;
}
