#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int dz[3] = { -1, 1};
    int dy[4] = { -1, 0, 1, 0};
    int dx[4] = { 0, 1, 0, -1};
    int m, n, h, seg, day = 0, yet = 0, cnt = 0, tempSeg = 0;
    queue<vector<int> > q;

    scanf("%d %d %d", &m, &n, &h);

    int map[h][n][m];
    bool visit[h][n][m];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &map[i][j][k]);
                visit[i][j][k] = false;
                if (map[i][j][k] == 1) {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                    q.push(v);
                    tempSeg++;
                }
                else if (map[i][j][k] == 0) yet++;
            }
        }
    }

    if (yet == 0) {
        // 이미 모두 익은 상태인 경우
        printf("0\n");
    }
    else {
        // bfs
        while(!q.empty()) {
            seg = tempSeg;
            tempSeg = 0;
            // 한 시점에 익은 토마토가 여러개일 수 있는데 이 여러개의 토마토가 다른 곳에 영향을 줄 때 마다 day를 증가시키면 안됨
            // 그래서 tempSeg 변수를 두고 하루 단위로 영향을 주는 여러 토마토가 몇 개인지 파악
            for (int a = 0; a < seg; a++) {
                vector<int> front = q.front();
                q.pop();
                int z = front[0];
                int y = front[1];
                int x = front[2];

                // 좌표에 대해 인접한 곳을 모두 검사

                // 1) 같은 판에서 앞, 뒤, 양옆의 토마토
                for (int k = 0; k < 4; k++) {
                    int newy = y + dy[k];
                    int newx = x + dx[k];

                    if (newy >= 0 && newy < n && newx >= 0 && newx < m && !visit[z][newy][newx] && map[z][newy][newx] == 0) {
                        visit[z][newy][newx] = true;
                        map[z][newy][newx] = 1;
                        vector<int> newv;
                        newv.push_back(z);
                        newv.push_back(newy);
                        newv.push_back(newx);
                        q.push(newv);
                        cnt++;
                        tempSeg++;
                    }
                }

                // 2) 같은 x, y 좌표인 위, 아래 판에 있는 토마토
                for (int k = 0; k < 2; k++) {
                    int newz = z + dz[k];

                    if (newz >= 0 && newz < h && !visit[newz][y][x] && map[newz][y][x] == 0) {
                        visit[newz][y][x] = true;
                        map[newz][y][x] = 1;
                        vector<int> newv;
                        newv.push_back(newz);
                        newv.push_back(y);
                        newv.push_back(x);
                        q.push(newv);
                        cnt++;
                        tempSeg++;
                    }
                }
            }
            day++;
        }

        if (cnt == yet) {
            printf("%d\n", day - 1);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
