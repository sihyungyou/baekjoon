#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {

    int n, i, ans = 0;

    scanf("%d", &n);
    n += 3;
    int arr[n];
    int dp[n];

    for (i = 0; i < 3; i++) {
        dp[i] = 0;
        arr[i] = 0;
    }

    for (i = 3; i < n; i++) scanf("%d", &arr[i]);

    for (i = 3; i < n; i++) {
        dp[i] = max(arr[i] + arr[i-1] + dp[i-3], arr[i] + dp[i-2]);
    }

    printf("%d\n", dp[n-1]);
    return 0;
}

// 마지막 계단을 밟아야 하는데 ans를 매번 update하고 있었다. 마지막 계단은 반드시 선택하므로 그냥 dp[n-1]을 출력하면 됨
