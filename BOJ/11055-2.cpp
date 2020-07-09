#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

    int n, i, j, ans = 0;
    scanf("%d", &n);

    int dp[n];
    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        dp[i] = arr[i];
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[j] + arr[i] > dp[i]) dp[i] = dp[j] + arr[i];
        }
        ans = max(dp[i], ans);
    }


    printf("%d\n", ans);

    return 0;
}

// dp[j] + arr[i] > dp[i] 조건을 생각하지 못했다..
