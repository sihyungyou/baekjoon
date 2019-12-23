#include <cstdio>

using namespace std;

int main() {

    int n, i;

    long long dp[1000001];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    scanf("%d", &n);
    for (i = 3; i <= n; i++) dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    printf("%lld\n", dp[n] % 15746);

    return 0;
}