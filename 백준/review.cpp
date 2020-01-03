#include <cstdio>
#include <climits>

using namespace std;

int get_min(int a, int b) { return a < b ? a : b; }

int main() {

    int n, k, i, j;

    scanf("%d %d", &n, &k);

    int dp[100001];
    int coins[100];

    dp[0] = 0;
    for (i = 1; i <= k; i++) dp[i] = INT_MAX;

    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
        dp[coins[i]] = 1;
    }

    for (i = 1; i <= k; i++) {
        for (j = 0; j < n; j++) {
            if (dp[i] == 1) break;
            else if (i - coins[j] < 0 || dp[i - coins[j]] == INT_MAX) continue;
            else dp[i] = get_min(dp[i], 1 + dp[i - coins[j]]);
        }
    }

    if (dp[k] == INT_MAX) printf("-1\n");
    else printf("%d\n", dp[k]);
    return 0;
}