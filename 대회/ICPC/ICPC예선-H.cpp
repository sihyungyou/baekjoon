#include <cstdio>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int main() {

    int N, i, j;
    int dp[100001] = { 0 };
    int a[317] = { 0 };
    scanf("%d", &N);

    for (i = 0; i <= N; i++) a[i] = i*i;

    for (i = 0; i <= N; i++) dp[i] = __INT_MAX__;
    
    dp[0] = 0;
    for (i = 1; i*i <= N; i++) {
        for (j = a[i]; j <= N; j++) {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }

    printf("%d\n", dp[N]);

    return 0;
}