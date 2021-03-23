#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        long long a, b, n, m;
        scanf("%lld %lld %lld %lld", &a, &b, &n, &m);

        if (a + b < n + m || min(a, b) < m) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }

    return 0;
}
