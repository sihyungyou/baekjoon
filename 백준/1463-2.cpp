#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 1000001

int main() {

    int n, i;
    int dp[MAX];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    scanf("%d", &n);
    for (i = 4; i <= n; i++) {
        if (i % 2 != 0 && i % 3 != 0) {
            // 2, 3 모두 안나눠지면 1을 뺄 수 밖에 없음
            dp[i] = dp[i-1] + 1;
        }
        else if (i % 2 != 0 && i % 3 == 0) {
            // 3으로만 나눠지면 3으로 나누거나 1을 뺄 수 있음
            dp[i] = min(dp[i/3] + 1 , dp[i-1] + 1);
        }
        else if (i % 2 == 0 && i % 3 != 0) {
            // 2로만 나눠지면 2로 나누거나 1을 뺄 수 있음
            dp[i] = min(dp[i/2] + 1 , dp[i-1] + 1);
        }
        else if (i % 2 == 0 && i % 3 == 0) {
            // 둘다 나눠지면 2로 나누거나 3으로 나누거나 1을 뺄 수 있음
            dp[i] = min(dp[i/2] + 1 , dp[i/3] + 1);
            dp[i] = min(dp[i-1] + 1 , dp[i]);
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}
