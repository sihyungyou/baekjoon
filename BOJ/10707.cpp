#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int a, b, c, d, p, ans, x, y;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &p);

    x = p * a;
    if (p <= c) {
        y = b;
    } else {
        y = b + d * (p-c);
    }

    ans = min(x, y);
    printf("%d\n", ans);

    return 0;
}
