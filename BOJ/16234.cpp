#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int map[50][50];
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};
bool visit[50][50];
int answer = 0;
int n = 0;

void resetVisitMap() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visit[i][j] = false;
        }
    }
}

int main() {
    int l, r;
    bool didMovePopulation;

    scanf("%d %d %d", &n, &l, &r);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    while(1) {
        didMovePopulation = false;

        // 0, 0 부터 n-1, n-1까지 각 좌표에서 bfs를 수행하여 새로운 인구를 적용한다.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j]) {
                    queue<pair<int, int> > q;
                    queue<pair<int, int> > locations;
                    int sum = 0;
                    int count = 0;

                    locations.push(make_pair(i, j));
                    q.push(make_pair(i, j));

                    while(!q.empty()) {
                        int y = q.front().first;
                        int x = q.front().second;

                        visit[y][x] = true;
                        sum += map[y][x];
                        count++;

                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int newy = y + dy[k];
                            int newx = x + dx[k];
                            int diff = abs(map[newy][newx] - map[y][x]);
                            if (newy >= 0 && newy < n && newx >= 0 && newx < n && !visit[newy][newx] && diff >= l && diff <= r) {
                                visit[newy][newx] = true;
                                locations.push(make_pair(newy, newx));
                                q.push(make_pair(newy, newx));
                                // 인구이동을 했으면 flag를 바꾸어서 이번 loop에 인구이동을 했음을 명시한다.
                                didMovePopulation = true;
                            }
                        }
                    }

                    // 인구이동
                    int newPopulation = sum / count;
                    while(!locations.empty()) {
                        int y = locations.front().first;
                        int x = locations.front().second;
                        locations.pop();

                        map[y][x] = newPopulation;
                    }
                }
            }
        }

        if (!didMovePopulation) {
            // 만약 이번 loop에 인구이동이 안됐다면 break
            break;
        } else {
            // 인구이동이 있었다면 visit 배열을 초기화
            resetVisitMap();
            answer++;
        }
    }


    // 인구이동이 불가능하다면 answer를 print 후 return
    printf("%d\n", answer);

    return 0;
}
