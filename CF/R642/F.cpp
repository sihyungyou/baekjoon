#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
long long map[100][100];
bool visit[100][100];
int dy[4] = { 1, 0 };
int dx[4] = { 0, 1 };

long long dfs(int y, int x, long long count) {
    visit[y][x] = true;

    if (y == n - 1 && x == m - 1) {
        visit[y][x] = false;
        return count;
    }

    long long countfromhere = LONG_MAX;

    for (int k = 0; k < 2; k++) {
        int newy = y + dy[k];
        int newx = x + dx[k];

        if (newy >= 0 && newy < n && newx >= 0 && newx < m && !visit[newy][newx]) {
            if (map[newy][newx] == map[y][x] + 1) {
                // 바로 갈 수 있는 경우
                countfromhere = min(countfromhere, dfs(newy, newx, count));
            } else if (map[newy][newx] > map[y][x] + 1) {
                // 갈 수 없다면 얼마나 내려야하는지
                long long diff = map[newy][newx] - map[y][x] - 1;
                countfromhere = min(countfromhere, dfs(newy, newx, count + diff));
            }
        }
    }

    visit[y][x] = false;
    return count + countfromhere;
}

int main() {

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);

        // get map info
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%lld", &map[i][j]);
                visit[i][j] = false;
            }
        }

        // start dfs
        int answer = dfs(0, 0, 0);
        printf("%d\n", answer);
    }


    return 0;
}
