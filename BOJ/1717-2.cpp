#include <cstdio>
using namespace std;

#define MAX 1000000

int arr[MAX + 1];

int do_find (int x) {
    if (arr[x] == x) {
        return x;
    }
    else {
        return arr[x] = do_find(arr[x]);
    }
}

void do_union(int a, int b) {
    int x = do_find(a);
    int y = do_find(b);
    arr[y] = x;
}

int main() {

    int n, m, i, a, b, op;
    scanf("%d %d", &n, &m);

    for (i = 0; i <= n; i++) arr[i] = i;

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &op, &a, &b);
        if (op == 0)  {
            // union
            do_union(a, b);
        }
        else {
            // check disjoint
            int pa = do_find(a);
            int pb = do_find(b);
            if (pa == pb) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
