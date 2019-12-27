#include <cstdio>

using namespace std;

#define MOD 1000000000

int main() {

    int n, i, j;
    long long ans = 9;
    long long dp[2][12] = { 0, };

    for (i = 2; i < 11; i++) dp[1][i] = 1;

    scanf("%d", &n);

    for (i = 2; i <= n; i++) {
        ans = 0;
        for (j = 1; j < 11; j++) {
            dp[i%2][j] = (dp[(i-1)%2][j-1] + dp[(i-1)%2][j+1]) % MOD;
            ans = (ans + dp[i%2][j]) % MOD;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
