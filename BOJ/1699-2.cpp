// 이해가 왜 안되냐 
#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int main() {

    int n, i, j;
    scanf("%d", &n);

    int sq[n + 1];
    int dp[n + 1];

    for (i = 0; i <= n; i++) dp[i] = INT_MAX;
    for (i = 1; i <= sqrt(n); i++) sq[i] = i * i;

    for (i = 1; i <= sqrt(n); i++) {
        for (j = sq[i]; j <= n; j++) dp[j] = min(dp[j], dp[j-sq[i]] + 1);
    }

    printf("%d\n", dp[n]);

    return 0;
}
