#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int r, c;
char map[20][20];
bool visitMap[20][20];
bool visitAlpha[26];

int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};

int dfs(int y, int x, int cnt) {
    int alphaIndex = map[y][x] - 65;
    // dfs의 조건에 알파벳이 겹치지 않는 조건 추가
    if (visitMap[y][x] || visitAlpha[alphaIndex]) return cnt;

    visitMap[y][x] = true;
    visitAlpha[alphaIndex] = true;
    cnt++;
    int newCnt = cnt;

    for (int k = 0; k < 4; k++) {
        int newy = y + dy[k];
        int newx = x + dx[k];

        if (newy >= 0 && newy < r && newx >= 0 && newx < c && !visitMap[newy][newx]) {
            int newAlphaIndex = map[newy][newx] - 65;
            if (!visitAlpha[newAlphaIndex]) {
                // 여러 경로 중 최대값을 구해야 하므로
                newCnt = max(newCnt, dfs(newy, newx, cnt));
            }
        }
    }

    // 추후에 다른 경로를 통해 이곳에 방문할 수 있도록
    visitMap[y][x] = false;
    visitAlpha[alphaIndex] = false;

    return newCnt;
}

int main() {

    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            map[i][j] = s[j];
        }
    }

    printf("%d\n", dfs(0, 0, 0));

    return 0;
}
