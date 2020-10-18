#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int dp[n];
    int minval;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = 0;
    }

    for (int i = n-2; i >= 0; i--) {
        if (arr[i] == 0) {
            // 0인경우
            dp[i] = INT_MAX;
        } else {
            // 0이 아닌경우 중
            if (i + arr[i] >= n - 1) {
                // 한번에 끝까지 점프가 가능한 경우
                dp[i] = 1;
            } else {
                // 한번에 가지 못해서 arr[i] 이하의 다음 arr 값을 봐야하는 경우
                minval = INT_MAX;
                for (int j = 1; j <= arr[i]; j++) {
                    minval = min(minval, dp[i + j]);
                }
                if (minval == INT_MAX) {
                    dp[i] = minval;
                } else {
                    dp[i] = minval + 1;
                }
            }
        }
    }

    dp[0] == INT_MAX ? printf("-1\n") : printf("%d\n", dp[0]);

    return 0;
}
