#include <vector>
#include <algorithm>

using namespace std;

int M;
int N;
int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};
bool visited[101][101];
int map[101][101];
int dp[101][101];

int dfs(int y, int x, int num) {
    // dfs를 왔다는 것은 현재 위치가 영역으로 인정된다는 것이므로 넓이를 1로 설정한다
    dp[y][x] = 1;
    visited[y][x] = true;

    int k = 0;
    for (k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny >= 0 && ny <= M && nx >= 0 && nx <= N && map[ny][nx] != 0 && !visited[ny][nx] && map[ny][nx] == num) {
            // 현재 위치로부터 인접한 영역들
            dp[y][x] += dfs(ny, nx, num);
        }
    }

    return dp[y][x];
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    int i = 0;
    int j = 0;
    int area = 0;
    int max_area = 0;
    M = m;
    N = n;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            map[i][j] = picture[i-1][j-1];
            dp[i][j] = 0;
            visited[i][j] = false;
        }
    }

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (map[i][j] != 0 && !visited[i][j]) {
                max_area = max(max_area, dfs(i, j, map[i][j]));
                area++;
                printf("area : %d, max : %d\n", area, max_area);
            }
        }
    }

    vector<int> answer;
    answer.push_back(area);
    answer.push_back(max_area);
    return answer;
}
