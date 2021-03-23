#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n, m;
    int answer = 1;

    scanf("%d", &n);
    scanf("%d", &m);

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    int temp = 0;
    for (int i = 0; i < m; i++) {
        int vip;
        scanf("%d", &vip);
        answer *= dp[vip - temp - 1];
        temp = vip;
    }

    printf("%d\n", answer *= dp[n - temp]);

    return 0;
}
