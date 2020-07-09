#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main() {

    int dp[101][10001];
    int a, b, i, j, k, w, h;

    scanf("%d %d", &a, &b);

    if (a > b) {
        w = a;
        h = b;
    } else {
        w = b;
        h = a;
    }

    for (i = 1; i <= h; i++) {
        for (j = 1; j <= w; j++) {
            dp[i][j] = 0;
        }
    }

    for (i = 1; i <= h; i++) {
        for (j = i; j <= w; j++) {
            if (i == 1) dp[i][j] = j;
            else if (i == j) dp[i][j] = 1;
            else {
                for (k = 0; k < i; k++) {
                    if (dp[i][j] == 0) dp[i][j] = INT_MAX;
                    int n = i - k;
                    int val = dp[n][n] + dp[i][j-n] + dp[i-n][j] - dp[i-n][j-n];
                    printf("[i : %d, j : %d, n : %d] %d = %d + %d + %d - %d\n", i, j, n, val, dp[n][n] , dp[i][j-n] , dp[i-n][j] , dp[i-n][j-n]);
                    printf("val : %d\n", val);
                    // printf("dp[%d][%d] : %d\n", i, j, dp[i][j]);
                    dp[i][j] = min(dp[i][j], val);
                    printf("dp[%d][%d] : %d\n", i, j, dp[i][j]);
                }
            }

        }
    }

    for (i = 1; i <= h; i++) {
        for (j = 1; j <= w; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    printf("%d\n", dp[h][w]);
    return 0;
}
