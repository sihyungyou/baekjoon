#include <cstdio>
#include <algorithm>
using namespace std;

int main() {


    int n, i;
    scanf("%d", &n);
    int arr[n+3];
    int dp[n+3];

    for (i = 0; i < 3; i++) {
        dp[i] = 0;
        arr[i] = 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i+3]);
    }

    for (i = 3; i < n + 3; i++) {
        dp[i] = max(arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3]);
        dp[i] = max(dp[i], dp[i-1]);
    }

    printf("%d\n", dp[n+2]);
    return 0;
}
