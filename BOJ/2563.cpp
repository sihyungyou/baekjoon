#include <cstdio>

using namespace std;

int main() {

    int i, n, x, y, j, k, sum = 0;
    int map[101][101]  = { 0, };

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);

        for (j = x + 1; j <= x + 10; j++) {
            for (k = 100 - y; k > 100 - y - 10; k--) {
                if (map[k][j] == 0) sum++;
                map[k][j]++;
            }
        }
    }

    printf("%d\n", sum);

    return 0;
}
