#include <cstdio>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int main() {
    int arr[100000];
    int dp[100000];
    int n, i, ans = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    dp[0] = arr[0];

    for (i = 1; i < n; i++) dp[i] = max(dp[i-1] + arr[i], arr[i]);

    printf("%d\n", dp[n-1]);
    return 0;
}