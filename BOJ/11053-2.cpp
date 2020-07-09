#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

    int n, i, j, ans = 0;
    scanf("%d", &n);

    int dp[n];
    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }
        ans = max(dp[i], ans);
    }

    printf("%d\n", ans);

    return 0;
}
