#include <cstdio>
#include <cmath>
using namespace std;

int main() {

    int n, i, temp, ans = 0, cnt = 0, nine = 9;
    int dp[9];
    scanf("%d", &n);

    for (i = 1; i <= 8; i++) {
        dp[i] = nine * i;
        nine *= 10;
    }

    temp = n;
    while(temp != 0) {
        temp /= 10;
        cnt++;
    }

    for (i = 1; i < cnt; i++) {
        ans += dp[i];
    }

    ans += (n - pow(10, cnt-1) + 1) * cnt;

    printf("%d\n", ans);


    return 0;
}
