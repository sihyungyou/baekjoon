#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n, m, i, j, maxValue = -1;
    long long ans = 0;
    scanf("%d %d", &n, &m);

    int boxes[n][m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &boxes[i][j]);
        }
    }

    vector<pair<int, int> > col;
    vector<pair<int, int> > row;

    // 열 기준 max 값들 위치 파악
    for (j = 0; j < m; j++) {
        maxValue = -1;
        pair<int, int> tempCoordinate;
        for (i = 0; i < n; i++) {
            if (maxValue < boxes[i][j]) {
                maxValue = boxes[i][j];
                tempCoordinate.first = i;
                tempCoordinate.second = j;
            }
        }
        col.push_back(tempCoordinate);
    }

    // 행 기준 max 값들 위치 파악
    for (i = 0; i < n; i++) {
        maxValue = -1;
        pair<int, int> tempCoordinate;
        for (j = 0; j < m; j++) {
            if (maxValue < boxes[i][j]) {
                maxValue = boxes[i][j];
                tempCoordinate.first = i;
                tempCoordinate.second = j;
            }
        }
        row.push_back(tempCoordinate);
    }

    // 열 기준 max 값들 0으로 처리
    for (i = 0; i < col.size(); i++) {
        int y = col[i].first;
        int x = col[i].second;
        boxes[y][x] = 0;
    }

    // 행 기준 max 값들 0으로 처리
    for (i = 0; i < row.size(); i++) {
        int y = row[i].first;
        int x = row[i].second;
        boxes[y][x] = 0;
    }

    // 모든 값 누적
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            ans += boxes[i][j];
        }
    }

    printf("%llu\n", ans);

    return 0;
}
