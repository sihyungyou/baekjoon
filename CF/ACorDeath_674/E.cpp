#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int a[3];
    int b[3];
    scanf("%d", &n);
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    scanf("%d %d %d", &b[0], &b[1], &b[2]);

    int maxWin = 0;
    maxWin += min(a[0], b[1]);
    maxWin += min(a[1], b[2]);
    maxWin += min(a[2], b[0]);

    int minWin = 0;
    int r = a[0] - b[0] - b[2];
    int s = a[1] - b[1] - b[0];
    int p = a[2] - b[2] - b[1];
    if (r < 0) r = 0;
    if (s < 0) s = 0;
    if (p < 0) p = 0;

    minWin = max(r, s);
    minWin = max(minWin, p);

    printf("%d %d\n", minWin, maxWin);

    return 0;
}
