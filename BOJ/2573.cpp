#include <cstdio>
using namespace std;

int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};
int orig[300][300] = { 0, };
int melt[300][300] = { 0, };
bool visit[300][300] = { false, };
int n, m, cnt, dfscnt, year;

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = false;
            melt[i][j] = 0;
        }
    }
}

void meltfunc() {
    int i, j, k;
    // 내년에 녹을 높이 계산
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (orig[i][j] != 0) {
                // 빙하이므로 내년에 녹을 것을 계산해서 melt 배열에 저장
                for (k = 0; k < 4; k++) {
                    int newy = i + dy[k];
                    int newx = j + dx[k];
                    // 상하좌우가 0 (바다라면)
                    if (newy >= 0 && newy < n && newx >= 0 && newx < m && orig[newy][newx] == 0) {
                        // 내년에 녹을 높이 증가
                        melt[i][j]++;
                    }
                }
            }
        }
    }

    // 실제로 녹이기
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            // 녹아야 하는 빙하라면
            if (orig[i][j] != 0) {
                if (orig[i][j] - melt[i][j] <= 0) {
                    orig[i][j] = 0;
                    // 해당 빙하가 높이만큼 모두 녹았으면 녹여야 할 빙하 개수 감소
                    cnt--;
                }
                else orig[i][j] -= melt[i][j];
            }
        }
    }

}

void dfs(int y, int x) {
    visit[y][x] = true;

    for (int k = 0; k < 4; k++) {
        // 문제를 잘못읽어 빙하가 인접한 경우에는 대각선도 포함된다고 착각하여 고생했던 부분
        int newy = y + dy[k];
        int newx = x + dx[k];

        if (newy >= 0 && newy < n && newx >= 0 && newx < m && !visit[newy][newx] && orig[newy][newx] != 0) {
            // 인접한데 방문하지 않은 빙하가 있다면 dfs
            dfs(newy, newx);
        }
    }
}

int main() {

    year = 0;
    cnt = 0;

    // 입력
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &orig[i][j]);
            if (orig[i][j] != 0) cnt++;
        }
    }

    while(1) {
        init();
        dfscnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (orig[i][j] != 0 && !visit[i][j]) {
                    // 빙하라면 거기서 dfs 시작
                    dfs(i, j);
                    dfscnt++;
                }
            }
        }

        // 만약 1덩어리이하인데 더이상 녹을 빙하가 없다면 0을 출력
        if (dfscnt < 2 && cnt == 0)  {
            printf("0\n");
            break;
        }
        // 2덩어리 이상으로 쪼개지면 year를 출력
        if (dfscnt >= 2) {
            printf("%d\n", year);
            break;
        }

        // 쪼개지지도 않았고 여전히 녹을 빙산이 있다면 빙산을 녹이는 과정 반복
        meltfunc();
        year++;
    }


    return 0;
}
