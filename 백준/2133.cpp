/*
문제
3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

입력
첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

출력
첫째 줄에 경우의 수를 출력한다.
*/

#include <cstdio>
using namespace std;

int main() {

    int n, i, j;
    int dp[31] = {1, 0, 3 };
    scanf("%d", &n);

    for (i = 4; i <= n; i += 2) {
        if (i % 2 != 0) dp[i] = 0;
        else {
            dp[i] = dp[i-2] * 3;
            for (j = 4; i-j >= 0; j += 2) {
                dp[i] += dp[i-j] * 2;
            }
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}