#include <cstdio>

using namespace std;

int main() {

    long long dp[101] = {0, };
    int t, i, n;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for (i = 6; i < 101; i++) dp[i] = dp[i-1] + dp[i-5];

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }

    return 0;
}