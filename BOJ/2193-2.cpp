#include <cstdio>
using namespace std;

int main()  {

    int n, i;
    scanf("%d", &n);

    long long dp[n + 1];
    dp[1] = 1;
    dp[2] = 1;

    for (i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
    printf("%lld\n", dp[n]);

    return 0;
}

// #include <cstdio>
// using namespace std;
//
// int n;
// long long ans = 1;
//
// void dfs(int x, int len) {
//     if (len == n) {
//         return;
//     }
//     if (x == 1) {
//         dfs(0, len + 1);
//     }
//     else if (x == 0) {
//         ans += 1;
//         dfs(0, len + 1);
//         dfs(1, len + 1);
//
//     }
// }
//
// int main()  {
//
//     scanf("%d", &n);
//     dfs(1, 1);
//     printf("%lld\n", ans);
//
//
//     return 0;
// }
