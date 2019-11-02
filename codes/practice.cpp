#include <cstdio>
using namespace std;
 
long long get_max (long long a, long long b) { return a > b ? a : b; }

int main() {

    int n, i;
    long long ans = 0;
    
    scanf("%d", &n);
    long long arr[n];
    long long dp[n];

    for (i = 0; i < n; i++) scanf("%lld", &arr[i]);
    dp[0] = arr[0];
    ans = dp[0];

    for (i = 1; i < n; i++) {
        dp[i] = get_max(arr[i], dp[i-1] + arr[i]);
        ans = get_max(ans, dp[i]);
    }

    printf("%lld\n", ans);

    return 0;
}