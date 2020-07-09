#include <cstdio>
using namespace std;

int n;
int map[100][100];
long long dp[100][100];

long long dfs(int y, int x) {

    if (y == n - 1 && x == n - 1) {
        // dest
        return 1;
    }
    else if (dp[y][x] == -1) {
        // not dest, but first time
        dp[y][x] = 0;

        // right
        int righty = y;
        int rightx = x + map[y][x];
        if (righty >= 0 && righty < n && rightx >= 0 && rightx < n) {
            dp[y][x] += dfs(righty, rightx);
        }

        // down
        int downy = y + map[y][x];
        int downx = x;
        if (downy >= 0 && downy < n && downx >= 0 && downx < n) {
            dp[y][x] += dfs(downy, downx);
        }

    }

    return dp[y][x];

}

int main() {

    int i, j;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }

    printf("%lld\n", dfs(0,0));

    return 0;
}
