#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        // 테스트케이스별 입력
        int n, m, ans = 0;

        scanf("%d", &n);
        int coins[n];

        for (int i = 0; i < n; i++) scanf("%d", &coins[i]);

        scanf("%d", &m);
        int dp[n][m+1];

        // 데이터 셋업
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j == coins[i]) { dp[i][j] = 1; }
                else dp[i][j] = 0;
            }
        }

        // dp 수행
        for (int i = 0; i < n; i++) {
            int coin = coins[i];
            for (int j = coin + 1; j <= m; j++) {
                int cnt = 0;
                for (int k = 0; k <= i; k++) {
                    cnt += dp[k][j - coin];
                }
                dp[i][j] = cnt;
            }
        }

        // 최종 경우의 수 계산
        for (int i = 0; i < n; i++) {
            ans += dp[i][m];
        }

        printf("%d\n", ans);
    }


    return 0;
}
