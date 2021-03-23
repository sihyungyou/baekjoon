#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, cnt;
int map[100][100] = { 0, };
bool visit[100][100] = { false, };
int dy[4] = { -1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void initMap() {
    cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            map[i][j] = 0;
            visit[i][j] = false;
        }
    }
}

int dfs(int y, int x, int cnt) {
    if (visit[y][x]) return cnt;
    cnt++;
    visit[y][x] = true;

    for (int k = 0; k < 4; k++) {
        int newy = y + dy[k];
        int newx = x + dx[k];

        if (newy >= 0 && newy < m && newx >= 0 && newx < n && !visit[newy][newx] && map[newy][newx] != 1) {
            cnt = dfs(newy, newx, cnt);
        }
    }
    return cnt;
}

int main() {
    int k;
    vector<int> v;

    initMap();

    scanf("%d %d %d", &m, &n, &k);

    for (int i = 0; i < k; i++) {
        int leftx, lefty, rightx, righty;
        scanf("%d %d %d %d", &leftx, &lefty, &rightx, &righty);

        // 좌표계 변환
        rightx--;
        righty--;
        int lefty_converted = m - 1 - lefty;
        int leftx_converted = leftx;
        int righty_converted = m - 1 - righty;
        int rightx_converted = rightx;

        // 사각형 영역에 대해 1로 표시
        for (int a = righty_converted; a <= lefty_converted; a++) {
            for (int b = leftx_converted; b <= rightx_converted; b++) {
                map[a][b] = 1;
            }
        }
    }

    // 연결된 영역의 넓이 파악하여 벡터에 push
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j] && map[i][j] != 1) {
                int cnt = dfs(i, j, 0);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());

    printf("%lu\n", v.size());
    for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
    printf("\n");


    return 0;
}
