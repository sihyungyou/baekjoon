/*
소요시간 : 45분
오래걸린 원인 : int nextx = j + dx[k]; 를 i + dx[k]로 잘못함
*/
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int map[100][100];
bool visit[100][100];
bool help[100][100];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {

    int count = 0;
    int answer = 0;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            visit[i][j] = false;
            help[i][j] = true;

            if (map[i][j] == 1) count++;
        }
    }

    int hour = 0;

    while(count > 0) {
        hour++;
        // 0, 0에서 bfs를 통해 공기가 찬 곳을 모두 help -> false로 바꾼다
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));
        visit[0][0] = true;
        help[0][0] = false;

        while(!q.empty()) {
            pair<int, int> cur = q.front();
            int y = cur.first;
            int x = cur.second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newy = y + dy[k];
                int newx = x + dx[k];

                if (newy >= 0 && newy < n && newx >= 0 && newx < m && !visit[newy][newx] && map[newy][newx] == 0) {
                    visit[newy][newx] = true;
                    help[newy][newx] = false;
                    q.push(make_pair(newy, newx));
                }
            }
        }

        vector<pair<int, int> > v;
        int removing = 0;
        // 0, 0부터 끝까지 보면서 1인 곳 중에 false랑 하나라도 인접해있으면 help를 false로 바꾸고 removing을 올리고 0으로 바꾼다
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visit[i][j] = false;
                if (map[i][j] == 1) {
                    // 인접한 곳 확인
                    for (int k = 0; k < 4; k++) {
                        int nexty = i + dy[k];
                        int nextx = j + dx[k];

                        if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < m && !help[nexty][nextx]) {
                            v.push_back(make_pair(i, j));
                            break;
                        }
                    }
                }
            }
        }

        removing = v.size();
        for (int r = 0; r < removing; r++) {
            int y = v[r].first;
            int x = v[r].second;
            help[y][x] = false;
            map[y][x] = 0;
        }

        // 전체 count에서 removing을 뺀다
        if (count - removing == 0) {
            answer = removing;
        }
        count -= removing;
    }


    printf("%d\n%d\n", hour, answer);
    return 0;
}
