#include <cstdio>
using namespace std;

#define MOD 1000000000

int main() {

    int i, j, N, ans = 9;
    int dp[2][12] = { 0, };

    for (i = 2; i <= 10; i++) dp[1][i] = 1;

    scanf("%d", &N);

    for (i = 2; i <= N; i++) {
        ans = 0;
        for (j = 1; j < 11; j++) {
            dp[i%2][j] = (dp[(i-1)%2][j-1] + dp[(i-1)%2][j+1]) % MOD;
            ans = (ans + dp[i%2][j]) % MOD;
        }
    }

    printf("%d\n", ans);

    return 0;
}