#include <cstdio>

using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }
int main() {

    int n, i, ans = 0;

    int arr[10003] = { 0, };
    int dp[10003] = { 0, };
    scanf("%d", &n);

    for (i = 3; i < n + 3; i++) scanf("%d", &arr[i]);


    for (i = 3; i < n + 3; i++) {
        dp[i] = get_max(arr[i-1] + arr[i] + dp[i-3], arr[i] + dp[i-2]);
        dp[i] = get_max(dp[i], dp[i-1]);
        ans = get_max(ans, dp[i]);
    }
    
    printf("%d\n", ans);    

    return 0;
}