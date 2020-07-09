#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int main() {

    int n, i, ans = INT_MIN;
    scanf("%d", &n);

    int arr[n + 1];
    int dp[n + 1];
    dp[0] = 0;

    for (i = 1; i <= n; i++) scanf("%d", &arr[i]);

    for (i = 1; i <= n; i++) {
        dp[i] = max(arr[i] + dp[i-1], arr[i]);
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
    return 0;
}
