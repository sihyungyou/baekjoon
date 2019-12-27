#include <cstdio>

using namespace std;

#define MOD 1000000000

int main() {

    int n, i, j;
    long long ans = 0;
    long long dp[2][11];
    
    scanf("%d", &n);

    for(i = 0; i < 10; i++) dp[0][i] = 1;
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[0][10] = 0;
    dp[1][10] = 0;

    for (i = 1; i < n; i++) {
        ans = 0;
        for (j = 1; j < 10; j++) {
            dp[i%2][j] = (dp[(i+1)%2][j-1] + dp[(i+1)%2][j+1]) % MOD;
            ans += dp[i%2][j] % MOD;
            // printf("%lld ", dp[i%2][j]);
        }
        // printf("\n");
    }

    for (i = 1; i < 10; i++) ans += dp[(n-1)%2][i] % MOD;
    printf("%lld\n", ans);

    return 0;
}