#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int map[9][9];
vector<pair<int, int> > v;
bool flag = false;

bool isValid(int cnt) {
    // 현재 새로운 값을 넣어본 좌표가 속한 행, 렬, 사각형에 대해서만 valid check를 진행
    int y = v[cnt].first;
    int x = v[cnt].second;

    bool visit[10];

    // 가로 검사
    for (int k = 1; k <= 9; k++) visit[k] = false;
    for (int i = 0; i < 9; i++) {
        if (map[y][i] != 0) {
            if (visit[map[y][i]]) return false;
            visit[map[y][i]] = true;
        }
    }

    // 세로 검사
    for (int k = 1; k <= 9; k++) visit[k] = false;
    for (int i = 0; i < 9; i++) {
        if (map[i][x] != 0) {
            if (visit[map[i][x]]) return false;
            visit[map[i][x]] = true;
        }
    }

    int starty, startx;

    // 사각형 검사
    if (y < 3) starty = 0;
    else if (y < 7) starty = 3;
    else starty = 6;

    if (x < 3) startx = 0;
    else if (x < 7) startx = 3;
    else startx = 6;

    for (int k = 1; k <= 9; k++) visit[k] = false;
    for (int i = starty; i < starty + 3; i++) {
        for (int j = startx; j < startx + 3; j++) {
            if (map[i][j] != 0) {
                if (visit[map[i][j]]) return false;
                visit[map[i][j]] = true;
            }
        }
    }

    return true;
}

void printAnswer() {
    flag = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void dfs(int cnt) {
    // 이미 답을 구했다면 더이상 진행할 필요 없음 <- 하나의 답만 출력, 재귀가 너무 깊어지지 않도록
    if (flag) return;

    if (cnt == v.size()) {
        printAnswer();
        return;
    }

    int y = v[cnt].first;
    int x = v[cnt].second;

    for (int i = 1; i <= 9; i++) {
        if (flag) return;
        // 수를 넣어본다
        map[y][x] = i;

        if (isValid(cnt)) {
            // valid 하다면 다음 좌표로 넘어간다 => dfs(cnt + 1)
            dfs(cnt + 1);
        }
        // valid 하지 않다면 다른 수를 넣어본다 (다음 반복으로 넘어감)
    }

    // 모든 수를 넣었는데도 valid check을 만족하지 못한다면 값을 다시 0으로 돌려놓고 return
    map[y][x] = 0;
    return;
}

int main() {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0) {
                v.push_back(make_pair(i, j));
            }
        }
    }

    dfs(0);

    return 0;
}
