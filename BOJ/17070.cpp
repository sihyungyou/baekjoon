#include <cstdio>
#include <utility>

using namespace std;

int n = 0;
int map[16][16];
int dp[16][16];
int answer = 0;

int getCurrentShape(pair<int, int> start, pair<int, int> end) {
    if (start.first == end.first && start.second + 1 == end.second) {
        // start와 end의 y가 같고 x가 다르다면 가로 - 0
        return 0;
    } else if (start.first + 1 == end.first && start.second == end.second) {
        // start와 end의 y가 다르고 x가 같다면 세로 - 1
        return 1;
    } else if (start.first + 1 == end.first && start.second + 1 == end.second) {
        // src와 dest의 x, y모두 차이가 난다면 대각 - 2
        return 2;
    } else {
        // 그 외의 상황일 경우
        return -1;
    }
}

bool isValid(pair<int, int> nextEnd) {
    if (nextEnd.first >= 0 && nextEnd.first < n && nextEnd.second >= 0 && nextEnd.second < n && map[nextEnd.first][nextEnd.second] != 1) {
        return true;
    }

    return false;
}

pair<int, int> getNextEnd(pair<int, int> start, int currentShape) {
    if (currentShape == 0) {
        return make_pair(start.first, start.second + 1);
    } else if (currentShape == 1) {
        return make_pair(start.first + 1, start.second);
    }

    return make_pair(start.first + 1, start.second + 1);
}

int dfs(pair<int, int> start, pair<int, int> end) {

    // end가 끝에 도달했다면 answer++, return
    if (end.first == n - 1 && end.second == n - 1) {
        if (dp[start.first][start.second] == -1) {
            dp[start.first][start.second] = 1;
        } else {
            dp[start.first][start.second]++;
        }

        return dp[start.first][start.second];
    }

    // 아직 끝에 도달하지 못했다면

    // 현재 놓여진 상태가 가로/세로/대각 확인
    int currentShape = getCurrentShape(start, end);

    pair<int, int> newStart = end;
    pair<int, int> newEndhorizontal = getNextEnd(end, 0);
    pair<int, int> newEndVertical = getNextEnd(end, 1);
    pair<int, int> newEndDiagonal = getNextEnd(end, 2);

    switch (currentShape) {
        case 0:
            printf("가로\n");
            // 가로일 때 -> 가로, 대각으로 dfs
            if (isValid(newEndhorizontal)) {
                if (dp[newStart.first][newStart.second] == -1) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dfs(newStart, newEndhorizontal);
                    } else {
                        dp[start.first][start.second] += dfs(newStart, newEndhorizontal);
                    }
                } else if (dp[newStart.first][newStart.second] >= 0) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dp[newStart.first][newStart.second];
                    } else {
                        dp[start.first][start.second] += dp[newStart.first][newStart.second];
                    }
                }
            }

            if (isValid(newEndDiagonal)) {
                if (dp[newStart.first][newStart.second] == -1) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dfs(newStart, newEndDiagonal);
                    } else {
                        dp[start.first][start.second] += dfs(newStart, newEndDiagonal);
                    }
                } else if (dp[newStart.first][newStart.second] >= 0) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dp[newStart.first][newStart.second];
                    } else {
                        dp[start.first][start.second] += dp[newStart.first][newStart.second];
                    }
                }
            }
            break;

        case 1:
            printf("세로\n");
            // 세로일 때 -> 세로, 대각으로 dfs
            if (isValid(newEndVertical)) {
                if (dp[newStart.first][newStart.second] == -1) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dfs(newStart, newEndVertical);
                    } else {
                        dp[start.first][start.second] += dfs(newStart, newEndVertical);
                    }
                } else if (dp[newStart.first][newStart.second] >= 0) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dp[newStart.first][newStart.second];
                    } else {
                        dp[start.first][start.second] += dp[newStart.first][newStart.second];
                    }
                }
            }

            if (isValid(newEndDiagonal)) {
                if (dp[newStart.first][newStart.second] == -1) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dfs(newStart, newEndDiagonal);
                    } else {
                        dp[start.first][start.second] += dfs(newStart, newEndDiagonal);
                    }
                } else if (dp[newStart.first][newStart.second] >= 0) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dp[newStart.first][newStart.second];
                    } else {
                        dp[start.first][start.second] += dp[newStart.first][newStart.second];
                    }
                }
            }
            break;

        case 2:
            printf("대각\n");
            // 대각일 때 -> 가로, 세로, 대각으로 dfs
            if (isValid(newEndhorizontal)) {
                if (dp[newStart.first][newStart.second] == -1) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dfs(newStart, newEndhorizontal);
                    } else {
                        dp[start.first][start.second] += dfs(newStart, newEndhorizontal);
                    }
                } else if (dp[newStart.first][newStart.second] >= 0) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dp[newStart.first][newStart.second];
                    } else {
                        dp[start.first][start.second] += dp[newStart.first][newStart.second];
                    }
                }
            }

            if (isValid(newEndVertical)) {
                if (dp[newStart.first][newStart.second] == -1) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dfs(newStart, newEndVertical);
                    } else {
                        dp[start.first][start.second] += dfs(newStart, newEndVertical);
                    }
                } else if (dp[newStart.first][newStart.second] >= 0) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dp[newStart.first][newStart.second];
                    } else {
                        dp[start.first][start.second] += dp[newStart.first][newStart.second];
                    }
                }
            }

            if (isValid(newEndDiagonal)) {
                if (dp[newStart.first][newStart.second] == -1) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dfs(newStart, newEndDiagonal);
                    } else {
                        dp[start.first][start.second] += dfs(newStart, newEndDiagonal);
                    }
                } else if (dp[newStart.first][newStart.second] >= 0) {
                    if (dp[start.first][start.second] == -1) {
                        dp[start.first][start.second] = dp[newStart.first][newStart.second];
                    } else {
                        dp[start.first][start.second] += dp[newStart.first][newStart.second];
                    }
                }
            }
            break;

        default:
            printf("오류\n");
            break;
    }

    return dp[start.first][start.second];
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 1;
    int answer = dfs(make_pair(0, 0), make_pair(0, 1));

    printf("%d\n", answer);

    return 0;
}
