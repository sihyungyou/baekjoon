#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int t, w, answer = 0, count = 0;
    int fruit[1001][3];
    int dp[1001][3][31];

    memset(fruit, 0, sizeof(fruit));
    memset(dp, 0, sizeof(dp));

    scanf("%d %d", &t, &w);

    for (int i = 1; i <= t; i++) {
        int location;
        scanf("%d", &location);

        fruit[i][location] = 1;
    }

    dp[1][1][0] = fruit[1][1];
    dp[1][2][1] = fruit[1][2];

    for (int i = 2; i <= t; i++) {
        for (int k = 0; k <= w; k++) {
            dp[i][1][k] = max(dp[i-1][1][k], k > 0 ? dp[i-1][2][k-1] : 0) + fruit[i][1];
            dp[i][2][k] = max(dp[i-1][2][k], k > 0 ? dp[i-1][1][k-1] : 0) + fruit[i][2];
        }
    }

    if (w > 0) {
        for (int k = 0; k <= w; k++) {
            answer = max(answer, max(dp[t][1][k], dp[t][2][k]));
        }
    } else {
        answer = dp[t][1][0];
    }

    printf("%d\n", answer);

    return 0;
}
