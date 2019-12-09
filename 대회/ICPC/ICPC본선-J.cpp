#include <cstdio>
using namespace std;

int main() {

    int n, i;
    scanf("%d", &n);
    
    long long dp[n+1];
    dp[3] = 0;
    dp[4] = 1;
    dp[5] = 2;
    dp[6] = 2;

    for(i = 7; i <= n; i++) {
        if (i%2 != 0) dp[i] = dp[(i/2)+1] + 2;
        else { dp[i] = dp[i/2] + 2; }
    }

    printf("%lld\n", dp[n]);

    return 0;
}