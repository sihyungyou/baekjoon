#include <cstdio>

using namespace std;

int get_min(int a, int b) { return a < b ? a : b; }

int main() {

    int n, i;
    int dp[1000001] = { 0, };

    dp[2] = 1;
    dp[3] = 1;

    scanf("%d", &n);

    for (i = 4; i <= n; i++) {
        if (i % 2 == 0 && i % 3 == 0) {
            dp[i] = get_min(dp[i/2], dp[i/3]) + 1;
        }
        else if (i % 2 == 0) {
            dp[i] = get_min(dp[i/2], dp[i-1]) + 1;
        }
        else if (i % 3 == 0) {
            dp[i] = get_min(dp[i/3], dp[i-1]) + 1;
        }
        else {
            dp[i] = dp[i-1] + 1;
        }
    }
    
    printf("%d\n", dp[n]);
    
    return 0;
}