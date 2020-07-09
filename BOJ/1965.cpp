#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

    int n, i, j, ans = 0;
    scanf("%d", &n);

    int arr[n];
    int dp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = 0;
    }

    dp[0] = 1;
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
    
    return 0;
}
