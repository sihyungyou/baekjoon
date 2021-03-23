#include <cstdio>

using namespace std;

int main() {

    int a, b, n, w, x, y, sheep, goat, ans = 0;

    scanf("%d %d %d %d", &a, &b, &n, &w);

    for (x = 1; x < n; x++) {
        y = n - x;
        if ((a * x) + (b * y) == w) {
            sheep = x;
            goat = y;
            ans++;
        }
    }

    if (ans == 1) printf("%d %d\n", sheep, goat);
    else printf("-1\n");

    return 0;
}
