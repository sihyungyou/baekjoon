#include <cstdio>
#include <vector>
using namespace std;

int n, m, target, ans = 0;
pair<int, int> targetCoord;
pair<int, int> src;
pair<int, int> dest;
int map[15][15];
bool visit[15][15];
int dp[15][15];
int dy[2] = { 0, 1 };
int dx[2] = { 1, 0 };

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = false;
            dp[i][j] = 0;
        }
    }
    dp[dest.first][dest.second] = 1;
}

int dfs(int y, int x) {
    if (y == dest.first && x == dest.second) {
        return dp[y][x];
    }

    visit[y][x] = true;

    for (int k = 0; k < 2; k++) {
        int newy = y + dy[k];
        int newx = x + dx[k];
        if (newy >= 0 && newy < n && newx >= 0 && newx < m) {
            if (!visit[newy][newx]) {
                // visit 하지 않았다면 dfs
                dp[y][x] += dfs(newy, newx);
            } else {
               // 이미 visit 했다면 DP값으로 불필요한 dfs 하지 않도록
               dp[y][x] += dp[newy][newx];
           }
        }
    }

    return dp[y][x];
}

int calculate(pair<int, int> src, pair<int, int> setDest) {
    dest = setDest;
    init();
    dfs(src.first, src.second);
    return dp[src.first][src.second];
}


int main() {
    scanf("%d %d %d", &n, &m, &target);

    if (target != 0) {
        // 경유지가 있는 경우
        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp++;
                if (temp == target) {
                    targetCoord = make_pair(i, j);
                }
            }
        }
        printf("%d\n", calculate(make_pair(0, 0), targetCoord) * calculate(targetCoord, make_pair(n-1, m-1)));
    } else {
        // 경유지가 없는 경우
        printf("%d\n", calculate(make_pair(0, 0), make_pair(n-1, m-1)));
    }

    return 0;
}
