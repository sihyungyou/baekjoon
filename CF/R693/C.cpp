#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int arr[n + 1];
        int dp[n + 1];

        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            dp[i] = -1;
        }

        int answer = 0;
        for (int i = n; i >= 1; i--) {
            dp[i] = arr[i];

            if (i + arr[i] <= n && dp[i + arr[i]] != -1) {
                dp[i] += dp[i + arr[i]];
            }

            answer = max(answer, dp[i]);
        }

        printf("%d\n", answer);
    }

    return 0;
}
