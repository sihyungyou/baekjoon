#include <cstdio>

using namespace std;

#define MAXP 10000

int main() {
    long long dp[MAXP + 1];
    int t, p, q, x = 1;

    dp[1] = 1;
    dp[2] = 1;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &p, &q);
        for (int i = 3; i <= p; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) % q;
        }

        printf("Case #%d: %lld\n", x++, dp[p] % q); // 여기서 % q를 추가적으로 해주지 않으면 틀림
    }

    return 0;
}
