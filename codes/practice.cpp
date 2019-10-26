#include <cstdio>
using namespace std;

int main() {
    int k, n, i, j;
    scanf("%d %d", &k, &n);

    int coins[k];
    int dp[n+1];

    dp[0] = 1;
    for (i = 1; i <= n; i++) dp[i] = 0;
    for (i = 0; i < k; i++) scanf("%d", &coins[i]);

    for (i = 0; i < k; i++) {
        for (j = coins[i]; j <= n; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}