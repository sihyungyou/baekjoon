#include <cstdio>
using namespace std;

#define MOD 10007

int main() {

    int n, i, j, sum = 0;
    int dp[1001][10];

    scanf("%d", &n);

    for (i = 0; i <= 9; i++) dp[1][i] = 1;

    for (i = 1; i <= n; i++) {
        dp[i][9] = 1;
        for (j = 8; j >= 0; j--) {
            dp[i][j] = (dp[i][j+1] + dp[i-1][j]) % MOD;
        }
    }

    for (i = 0; i <= 9; i++) sum = (sum + dp[n][i]) % MOD;
    printf("%d\n", sum);

    return 0;
}
