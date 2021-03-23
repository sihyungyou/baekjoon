/*
소요시간 : 30분
특이사항 : 없음
*/

#include <cstdio>
#include <vector>

using namespace std;

int n, m;
int map[20][20];
vector<int> ops;

struct Dice {
    int y;
    int x;
    int front;
    int back;
    int top;
    int bottom;
    int west;
    int east;
};

bool isValid(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= m) return false;
    return true;
}

int main() {

    int x, y, k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    Dice dice = { x, y, 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < k; i++) {
        int num;
        scanf("%d", &num);

        ops.push_back(num);
    }

    for (int i = 0; i < k; i++) {
        int op = ops[i];

        int cury = dice.y;
        int curx = dice.x;

        int nexty = cury;
        int nextx = curx;
        // 현재 이동 명령에 따라 다음 위치를 구한다
        if (op == 1) {
            // 동
            nextx++;
            if (!isValid(nexty, nextx)) continue;
            int tempEast = dice.east;
            dice.east = dice.top;
            dice.top = dice.west;
            dice.west = dice.bottom;
            dice.bottom = tempEast;
        } else if (op == 2) {
            // 서
            nextx--;
            if (!isValid(nexty, nextx)) continue;
            int tempWest = dice.west;
            dice.west = dice.top;
            dice.top = dice.east;
            dice.east = dice.bottom;
            dice.bottom = tempWest;
        } else if (op == 3) {
            // 북
            nexty--;
            if (!isValid(nexty, nextx)) continue;
            int tempBack = dice.back;
            dice.back = dice.top;
            dice.top = dice.front;
            dice.front = dice.bottom;
            dice.bottom = tempBack;
        } else if (op == 4) {
            // 남
            nexty++;
            if (!isValid(nexty, nextx)) continue;
            int tempFront = dice.front;
            dice.front = dice.top;
            dice.top = dice.back;
            dice.back = dice.bottom;
            dice.bottom = tempFront;
        }

        printf("%d\n", dice.top);

        if (map[nexty][nextx] == 0) {
            map[nexty][nextx] = dice.bottom;
        } else {
            dice.bottom = map[nexty][nextx];
            map[nexty][nextx] = 0;
        }

        dice.y = nexty;
        dice.x = nextx;
    }

    return 0;
}
