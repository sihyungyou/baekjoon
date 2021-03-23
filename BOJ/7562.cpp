#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int main() {

    int tc, n, srcy, srcx, desty, destx, seg;
    bool flag = false;
    int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

    scanf("%d", &tc);

    for (int t = 0; t < tc; t++) {
        // 입력
        scanf("%d", &n);

        int ans = 0;
        bool visit[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visit[i][j] = false;
            }
        }

        scanf("%d %d", &srcy, &srcx);
        scanf("%d %d", &desty, &destx);

        // 시작점과 목적지가 같으면 0
        if (srcx == destx && srcy == desty) {
            printf("%d\n", ans);
            continue;
        }

        // starting point queue에 넣기
        queue<pair<int, int> > q;
        q.push(make_pair(srcy, srcx));
        ans++;

        int tempSeg = 1;

        // start bfs
        while(!q.empty()) {
            seg = tempSeg;
            tempSeg = 0;
            for (int i = 0; i < seg; i++) {
                pair<int, int> front = q.front();
                q.pop();

                int y = front.first;
                int x = front.second;

                for (int k = 0; k < 8; k++) {
                    int newy = y + dy[k];
                    int newx = x + dx[k];

                    if (newy == desty && newx == destx) {
                        // dest 도달
                        printf("%d\n", ans);
                        flag = true;
                        break;
                    }

                    if (newy >= 0 && newy < n && newx >= 0 && newx < n && !visit[newy][newx]) {
                        visit[newy][newx] = true;
                        q.push(make_pair(newy, newx));
                        tempSeg++;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
            ans++;
        }
        flag = false;
    }

    return 0;
}
