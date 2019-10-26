#include <cstdio>
using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }
int main() {

    int T[16] = { 0, };
    int P[16] = { 0, };
    int dp[17] = { 0, };
    int N, i, day;

    scanf("%d", &N);

    for(i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
        if (T[i] + i > N + 1) dp[i] = 0;
        else dp[i] = P[i];
    }

    for (i = N; i > 0; i--) {
        day = i + T[i];
        if ( day > N + 1) dp[i] = dp[i+1];
        else dp[i] = get_max(P[i] + dp[day], dp[i+1]);

    }

    printf("%d\n", dp[1]);

    return 0;
}