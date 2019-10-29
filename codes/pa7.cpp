#include <cstdio>
using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }

int main() {

    int i, j, k, n, temp, ans = 0;

    scanf("%d", &n);
    int arr[n+2][n+2];
    int dp[n+1][n+1];
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};


    for (i = 0; i <= n+1; i++) for (j = 0; j <= n+1; j++) arr[i][j] = __INT_MAX__;
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) { scanf("%d", &arr[i][j]); dp[i][j] = 0; }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 0; k < 4; k++) {
                temp = arr[i][j]-arr[i+dx[k]][j+dy[k]];
                if (temp <= 0) temp = 0;
                dp[i][j] = get_max(dp[i][j], temp);
            }
            // printf("%d ", dp[i][j]);
        }
        // printf("\n");
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 0; k < 4; k++) {
                temp = arr[i][j]-arr[i+dx[k]][j+dy[k]];
                if (temp > 0) {
                    dp[i][j] = get_max(dp[i][j], temp + dp[i+dx[k]][j+dy[k]]);
                    ans = get_max(ans, dp[i][j]);
                }
            }
            // printf("%d ", dp[i][j]);
        }
        // printf("\n");
    }

    printf("%d\n", ans);

    return 0;
}