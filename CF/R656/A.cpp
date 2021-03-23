#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int x, y, z, a, b, c;
        scanf("%d %d %d", &x, &y, &z);

        if ( (x != y && x != z && y != z) || (x == y && y < z) || (x == z && z < y) || (y == z && z < x)) {
            printf("NO\n");
            continue;
        }
        if (x == y && y == z) {
            printf("YES\n");
            printf("%d %d %d\n", x, y, z);
        } else {
            a = min(x, y);
            b = min(x, z);
            c = min(y, z);
            printf("YES\n");
            printf("%d %d %d\n", a, b, c);
        }
    }
    return 0;
}
