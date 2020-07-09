#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int dx[4] = { 0, -1, -1};
int dy[4] = { -1, -1, 0};

int main() {

    int n, m, i, j, w, ans = 0;
    bool sq;

    scanf("%d %d", &n, &m);
    int map[1001][1001] = { 0, };
    int dp[1001][1001] = { 0, };


    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 1) dp[i][j] = 1;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {

            if (map[i][j] == 1) {
                // 검사
                if (dp[i-1][j] != 0 && dp[i-1][j-1] != 0 && dp[i][j-1] != 0) {
                    // 하나라도 0이면 정사각형이 될 수 없음
                    if (dp[i-1][j] != 1 && dp[i-1][j-1] != 1 && dp[i][j-1] != 1) {
                        // 모두 1이 0도 아니고 1도 아니라면 더 큰 정사각형을 만들 수 있음
                        int size = min(dp[i-1][j], dp[i-1][j-1]);
                        size = min(size, dp[i][j-1]);
                        w = sqrt(size) + 1;
                        dp[i][j] = w * w;
                    }
                    else {
                        // 모두 0이 아니지만 1이 하나라도 있다면 더 큰 정사각형은 만들 수 없음
                        dp[i][j] = 4;
                    }
                }
                ans = max(ans, dp[i][j]);
            }

        }
    }

    printf("%d\n", ans);

    return 0;
}
