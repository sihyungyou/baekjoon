#include <cstdio>

using namespace std;
int get_max(int a, int b) { return a > b ? a : b; }
int main() {

    int n, i, j, ans = 0;

    scanf("%d", &n);
    int dp[n];
    int arr[n];
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (i = 0; i < n; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (dp[j] + 1 > dp[i] && arr[j] < arr[i]) dp[i] = dp[j] + 1;
        }
        ans = get_max(ans, dp[i]);
    }

    printf("%d\n", ans);
    return 0;
}