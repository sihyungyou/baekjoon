#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

struct Location {
    int y;
    int x;
    int d;
};

struct Fish {
    int y;
    int x;
    int size;
    int d;
};

struct Shark {
    int y;
    int x;
    int size;
    int count;
};

struct compare {
    bool operator()(Fish a, Fish b) {
        if (a.d == b.d) {
            if (a.y == b.y) {
                return a.x > b.x;
            }
            return a.y > b.y;
        }

        return a.d > b.d; // 내림차순이어야 함
    }
};

int main() {

    int n;
    scanf("%d", &n);

    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, 1, 0, -1 };
    int map[n][n];
    bool visit[n][n];
    int time = 0;
    int fishCount = 0;
    Shark shark = { 0, 0, 2, 0 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visit[i][j] = false;

            scanf("%d", &map[i][j]);

            if (map[i][j] == 9) {
                shark.y = i;
                shark.x = j;
            } else if (map[i][j] != 0) {
                fishCount++;
            }
        }
    }

    if (fishCount == 0) {
        printf("0\n");
        return 0;
    } else {
        // 물고기가 1마리 이상 있다면 모든 물고기를 현재 상어의 위치와 거리를 계산해 pq에 넣는다
        // 현재 상어위치로부터 가장 가까운 물고기의 위치를 알 수 있다 -> BFS
        priority_queue<Fish, vector<Fish>, compare> pq;
        queue<Location> q;
        Location loc = { shark.y, shark.x, 0 };
        q.push(loc);
        visit[loc.y][loc.x] = true;

        // 맵 전체를 보면서 모든 물고기에 대해 위치를 계산하여 pq에 넣는다
        while(!q.empty()) {
            Location cur = q.front();
            int cury = cur.y;
            int curx = cur.x;
            int curd = cur.d;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newy = cury + dy[k];
                int newx = curx + dx[k];
                int newd = curd + 1;

                if (newy >= 0 && newy < n && newx >= 0 && newx < n && !visit[newy][newx] && map[newy][newx] <= shark.size) {
                    // 지나갈 수 있는 공간 혹은 물고기
                    if (map[newy][newx] != 0 && map[newy][newx] < shark.size) {
                        // 먹을 수 있는 물고기라면 바로 거리 계산해서 pq에 넣음
                        Fish fish = { newy, newx, newd };
                        visit[newy][newx] = true;
                        pq.push(fish);
                    } else {
                        // 지나가기만 가능하다면
                        Location newLoc = { newy, newx, newd };
                        visit[newy][newx] = true;
                        q.push(newLoc);
                    }
                }
            }
        }

        // 모든 물고기 위치를 계산했으면
    }



    return 0;
}
