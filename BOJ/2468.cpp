#include <cstdio>
#include <algorithm>

using namespace std;

int map[100][100];
int origMap[100][100];
bool visit[100][100];
int cnt, n, rain;

// 상하좌우만 이어져있다고 간주
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void clearInfo() {
    cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            // clear 시, map을 0으로 초기화하는 실수를 하면 항상 강수량보다 적게 되므로 오류임
            // original map을 두고 초기화하자
            map[i][j] = origMap[i][j];
            visit[i][j] = false;
        }
    }
}

void dfs(int y, int x) {
    if (visit[y][x]) return;
    visit[y][x] = true;

    for (int k = 0; k < 4; k++) {
        int newy = y + dy[k];
        int newx = x + dx[k];

        if (newy >= 0 && newy < n && newx >= 0 && newx < n && !visit[newy][newx] && map[newy][newx] > rain) {
            dfs(newy, newx);
        }
    }
}

int main() {
    int lowest = 101;
    int highest = 0;
    // 어떤 지역도 잠기지 않으면 (가장 낮은 지역의높이 - 1만큼 비가 오면) 안전지대는 1이므로
    int ans = 1;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &origMap[i][j]);
            lowest = min(lowest, origMap[i][j]);
            highest = max(highest, origMap[i][j]);
        }
    }

    // 가장 낮은 지역 높이만큼 비가 오는 경우 ~ 가장 높은 지역높이 - 1만큼 비가 오는 경우에 대해서
    for (rain = lowest; rain < highest; rain++) {
        clearInfo();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && map[i][j] > rain) {
                    // dfs를 돌며 안전지대를 파악한다
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        ans = max(cnt, ans);
    }

    printf("%d\n", ans);

    return 0;
}
