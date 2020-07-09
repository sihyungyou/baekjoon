/*
문제
n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

출력
첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.
*/

#include <cstdio>
#include <climits>

using namespace std;

int get_min(int a, int b) { return a < b ? a : b; }

int main() {

    int n, k, i, j;

    scanf("%d %d", &n, &k);

    int dp[100001];
    int coins[100];

    dp[0] = 0;
    for (i = 1; i <= k; i++) dp[i] = INT_MAX;

    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
        dp[coins[i]] = 1;
    }

    for (i = 1; i <= k; i++) {
        for (j = 0; j < n; j++) {
            if (dp[i] == 1) break;
            else if (i - coins[j] < 0 || dp[i - coins[j]] == INT_MAX) continue;
            else dp[i] = get_min(dp[i], 1 + dp[i - coins[j]]);
        }
    }

    if (dp[k] == INT_MAX) printf("-1\n");
    else printf("%d\n", dp[k]);
    return 0;
}