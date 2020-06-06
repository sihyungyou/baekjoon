#include <cstdio>
#include <utility>

using namespace std;

int n, m, cnt = 0;
int map[51][51] = { 1, };

bool in_range(int y, int x) {
      if (y > 0 && y <= n && x > 0 && x <= m) return true;
      else return false;
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

void dfs(int y, int x, int d) {
    int k;
    int sr = 0;

    cnt++;
    map[y][x] = 2;

    for (k = 0; k < 4; k++) {
        pair<int, int> left = left_cord(y, x, d);
        if (in_range(left.first, left.second) && map[left.first][left.second] == 0) {
            d = turn_left(d);
            dfs(left.first, left.second, d);
            return;
        }
        else {
            d = turn_left(d);
        }
    }

    pair<int, int> back = go_back(y, x, d);
    if (!in_range(back.first, back.second) || map[back.first][back.second] == 1) return;
    else dfs(back.first, back.second, d);

}

int main() {

    int r, c, d, i, j;

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    if (in_range(r, c)) dfs(r, c, d);

    printf("%d\n", cnt);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
