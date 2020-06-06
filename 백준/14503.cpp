#include <cstdio>
#include <utility>

using namespace std;

int n, m;

void print_cord(int y, int x) {
    printf("%d, %d\n", y, x);
}

pair<int, int> go_forward(int y, int x, int d) {
    // printf("go_forward\n");
    pair<int, int> new_cord;
    if (d == 0) {
        // 북쪽 바라봄
        new_cord.first = y - 1;
        new_cord.second = x;
    }
    else if (d == 1) {
        // 동쪽 바라봄
        new_cord.first = y;
        new_cord.second = x + 1;
    }
    else if (d == 2) {
        // 남쪽 바라봄
        new_cord.first = y + 1;
        new_cord.second = x;
    }
    else if (d == 3) {
        // 서쪽 바라봄
        new_cord.first = y;
        new_cord.second = x - 1;
    }
    return new_cord;
}

pair<int, int> go_back(int y, int x, int d) {
    // printf("go_back\n");
    pair<int, int> new_cord;
    if (d == 0) {
        // 북쪽 바라봄
        new_cord.first = y + 1;
        new_cord.second = x;
    }
    else if (d == 1) {
        // 동쪽 바라봄
        new_cord.first = y;
        new_cord.second = x - 1;
    }
    else if (d == 2) {
        // 남쪽 바라봄
        new_cord.first = y - 1;
        new_cord.second = x;
    }
    else if (d == 3) {
        // 서쪽 바라봄
        new_cord.first = y;
        new_cord.second = x + 1;
    }
    return new_cord;
}

int turn_left(int d) {
    // printf("turn_left\n");
    int newd;
    if (d == 0) {
        // 북쪽 바라봄
        newd = 3;
    }
    else if (d == 1) {
        // 동쪽 바라봄
        newd = 0;
    }
    else if (d == 2) {
        // 남쪽 바라봄
        newd = 1;
    }
    else if (d == 3) {
        // 서쪽 바라봄
        newd = 2;
    }
    return newd;
}

pair<int, int> left_cord(int y, int x, int d) {
    // printf("left_cord\n");
    pair<int, int> new_cord;
    if (d == 0) {
        // 북쪽 바라봄
        new_cord.first = y;
        new_cord.second = x - 1;
    }
    else if (d == 1) {
        // 동쪽 바라봄
        new_cord.first = y - 1;
        new_cord.second = x;
    }
    else if (d == 2) {
        // 남쪽 바라봄
        new_cord.first = y;
        new_cord.second = x + 1;
    }
    else if (d == 3) {
        // 서쪽 바라봄
        new_cord.first = y + 1;
        new_cord.second = x;
    }
    return new_cord;
}

bool in_range(int y, int x) {
      if (y > 0 && y <= n && x > 0 && x <= m) return true;
      else return false;
}

int main() {

    int cnt = 0;
    int map[51][51] = { 1, };
    int r, c, d, i, j, k;

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    pair<int, int> now;
    pair<int, int> left;
    pair<int, int> back;

    now.first = r;
    now.second = c;


    while(1) {
        int sr = 0;

        // 빈 칸은 0, 벽은 1로 주어진다.
        // 현재 위치를 청소한다.
        if (map[now.first][now.second] == 0) {
            // 현재위치가 청소되어있지 않으면 청소한다
            map[now.first][now.second] = 2;
            cnt++;
        }

        // printf("now : %d %d, cnt : %d\n", now.first, now.second, cnt);
        // 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
        for (k = 0; k < 4; k++) {
            left = left_cord(now.first, now.second, d);

            if (map[left.first][left.second] == 0) {
                // 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
                d = turn_left(d);
                now = go_forward(now.first, now.second, d);
                break;
            } else {
                // 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
                d = turn_left(d);
                sr++;
            }
        } // for

        if (sr == 4) {
            // printf("sr == 4\n");

            // 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
            back = go_back(now.first, now.second, d);

            if (map[back.first][back.second] == 1) {
                break;
            } else {
                // 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
                now = go_back(now.first, now.second, d);
            }
        }

    } // while

    printf("%d\n", cnt);
    return 0;
}
