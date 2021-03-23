#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int map[500][500];
bool visit[500][500];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int dfs(int y, int x) {
    visit[y][x] = true;

    int count = 0;
    for (int k = 0; k < 4; k++) {
        int newy = y + dy[k];
        int newx = x + dx[k];

        if (newy >= 0 && newy < n && newx >= 0 && newx < m && !visit[newy][newx] && map[newy][newx] == 1) {
            count += dfs(newy, newx);
        }
    }

    return count + 1;
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            visit[i][j] = false;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j] && map[i][j] == 1) {
                area = max(area, dfs(i, j));
                count++;
            }
        }
    }

    printf("%d\n%d\n", count, area);

    return 0;
}
