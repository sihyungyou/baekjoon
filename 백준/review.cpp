#include <cstdio>

using namespace std;
int get_max(int a, int b) { return a > b ? a : b; }

int main() {

    int i, j, n, t;
    long long ans = 0;
    long long dp[500][500];

    scanf("%d", &n);

    for (t = 0; t < n; t++) {
        for (i = 0; i <= t; i++) {
            scanf("%lld", &dp[t][i]);
        }
    }

    dp[1][0] += dp[0][0];
    dp[1][1] += dp[0][0];

    for (i = 2; i < n; i++) {
        dp[i][0] += dp[i-1][0];
        dp[i][i] += dp[i-1][i-1];
        for (j = 1; j < i; j++) {
            dp[i][j] += get_max(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    for (i = 0; i < n; i++) {
        ans = get_max(dp[n-1][i], ans);
    }

    printf("%lld\n", ans);

    return 0;
}