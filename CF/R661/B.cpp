#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        long long ans = 0;
        scanf("%d", &n);
        int a[n];
        int adiff[n];
        int b[n];
        int bdiff[n];
        int amin = INT_MAX;
        int bmin = INT_MAX;

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            amin = min(amin, a[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            bmin = min(bmin, b[i]);
        }

        for (int i = 0; i < n; i++) {
            adiff[i] = a[i] - amin;
            bdiff[i] = b[i] - bmin;
            ans += min(adiff[i], bdiff[i]) + abs(adiff[i] - bdiff[i]);
        }

        printf("%lld\n", ans);

    }

    return 0;
}
