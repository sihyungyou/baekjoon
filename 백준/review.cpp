#include <cstdio>

using namespace std;
int get_min(int a, int b) { return a < b ? a : b; }
int main() {

    int i, j, n, ans;

    int dp[1000][3];

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);

    for (i = 1; i < n; i++) {
        dp[i][0] += get_min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += get_min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += get_min(dp[i-1][1], dp[i-1][0]);
    }
    
    ans = get_min(dp[n-1][0], dp[n-1][1]);
    ans = get_min(ans, dp[n-1][2]);

    printf("%d\n", ans);

    return 0;
}