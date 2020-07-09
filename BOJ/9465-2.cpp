#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {

    int T, t, n, i, j;

    scanf("%d", &T);
    for (t = 0; t < T; t++) {
        scanf("%d", &n);
        int ans = 0;
        int arr[2][n];
        int dp[2][n];
        for (i = 0; i < 2; i++) for (j = 0; j < n; j++) scanf("%d", &arr[i][j]);

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = arr[0][1] + arr[1][0];
        dp[1][1] = arr[1][1] + arr[0][0];

        for (i = 2; i < n; i++) {
            dp[0][i] = max(arr[0][i] + dp[1][i-1], arr[0][i] + dp[1][i-2]);
            dp[1][i] = max(arr[1][i] + dp[0][i-1], arr[1][i] + dp[0][i-2]);
        }

        for (i = 0; i < 2; i++) for (j = 0; j < n; j++) ans = max(ans, dp[i][j]);
        printf("%d\n", ans);
    }

    return 0;
}
