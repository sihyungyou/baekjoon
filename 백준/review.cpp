#include <cstdio>

using namespace std;
int get_max(int a, int b) { return a > b ? a : b; }
int main() {

    int n, i, j, ans = 0;

    scanf("%d", &n);
    int dp[n];
    int dp2[n];
    int arr[n];
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (i = 0; i < n; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) if (dp[j] + 1 > dp[i] && arr[j] < arr[i]) dp[i] = dp[j] + 1;
    }

    for (i = n-1; i >= 0; i--) {
        dp2[i] = 1;
        for (j = n-1; j > i; j--) if(dp2[j] + 1 > dp2[i] && arr[j] < arr[i]) dp2[i] = dp2[j] + 1;
    }

    for (i = 0; i < n; i++) {
        ans = get_max(ans, dp[i] + dp2[i]);
    }

    printf("%d\n", ans-1);
    return 0;
}