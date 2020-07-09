#include <cstdio>
using namespace std;

#define MOD 1000000000

int main () {

    int n, k, i, j;

    scanf("%d %d", &n, &k);
    int dp[n + 1][k + 1];

    for (i = 1; i <= k; i++) dp[1][i] = i;
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= k; j++) {
            if (j == 1) dp[i][j] = 1;
            else dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
        }
    }

    printf("%d\n", dp[n][k]);
    return 0;
}
