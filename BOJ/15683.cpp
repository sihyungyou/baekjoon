/*
소요시간 : 55분
특이사항 : 구현에 오래걸림 (코드 가독성이나 효율을 전혀 고려하지 않음), type 1, facing 1일 때 x를 증가시켜야하는데 감소시켜서 50분 내에 풀지못함
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int originMap[8][8];
int map[8][8];
int n, m;
int k = 0;
int answer = 100;

struct CCTV {
    int y;
    int x;
    int type;
    int facing;
};

vector<CCTV> cctvs;

void resetMap() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = originMap[i][j];
        }
    }
}

void printMap() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void watch(int y, int x, int type, int facing) {
    // 0 북 / 1 동 / 2 남 / 3 서
    if (type == 1) {
        if (facing == 0) {
            while(y >= 0 && map[y][x] != 6) {
                map[y--][x] = 9;
            }
        } else if (facing == 1) {
            while(x < m && map[y][x] != 6) {
                map[y][x++] = 9;
            }
        } else if (facing == 2) {
            while(y < n && map[y][x] != 6) {
                map[y++][x] = 9;
            }
        } else if (facing == 3) {
            while(x >= 0 && map[y][x] != 6) {
                map[y][x--] = 9;
            }
        }
    } else if (type == 2) {
        if (facing == 0 || facing == 2) {
            int tempx = x;
            while(tempx < m && map[y][tempx] != 6) {
                map[y][tempx++] = 9;
            }
            tempx = x;
            while(tempx >= 0 && map[y][tempx] != 6) {
                map[y][tempx--] = 9;
            }
        } else if (facing == 1 || facing == 3) {
            int tempy = y;
            while(tempy < n && map[tempy][x] != 6) {
                map[tempy++][x] = 9;
            }
            tempy = y;
            while(tempy >= 0 && map[tempy][x] != 6) {
                map[tempy--][x] = 9;
            }
        }
    } else if (type == 3) {
        if (facing == 0) {
            int tempy = y;
            while(tempy >= 0 && map[tempy][x] != 6) {
                map[tempy--][x] = 9;
            }
            while(x < m && map[y][x] != 6) {
                map[y][x++] = 9;
            }
        } else if (facing == 1) {
            int tempx = x;
            while(tempx < m && map[y][tempx] != 6) {
                map[y][tempx++] = 9;
            }
            while(y < n && map[y][x] != 6) {
                map[y++][x] = 9;
            }
        } else if (facing == 2) {
            int tempy = y;
            while(tempy < n && map[tempy][x] != 6) {
                map[tempy++][x] = 9;
            }
            while(x >= 0 && map[y][x] != 6) {
                map[y][x--] = 9;
            }
        } else if (facing == 3) {
            int tempx = x;
            while(tempx >= 0 && map[y][tempx] != 6) {
                map[y][tempx--] = 9;
            }
            while(y >= 0 && map[y][x] != 6) {
                map[y--][x] = 9;
            }
        }
    } else if (type == 4) {
        if (facing == 0) {
            int tempy = y;
            while(tempy >= 0 && map[tempy][x] != 6) {
                map[tempy--][x] = 9;
            }
            int left = x - 1;
            while(left >= 0 && map[y][left] != 6) {
                map[y][left--] = 9;
            }
            int right = x + 1;
            while (right < m && map[y][right] != 6) {
                map[y][right++] = 9;
            }
        } else if (facing == 1) {
            int tempx = x;
            while(tempx < m && map[y][tempx] != 6) {
                map[y][tempx++] = 9;
            }
            int up = y - 1;
            while(up >= 0 && map[up][x] != 6) {
                map[up--][x] = 9;
            }
            int down = y + 1;
            while(down < n && map[down][x] != 6) {
                map[down++][x] = 9;
            }
        } else if (facing == 2) {
            int tempy = y;
            while(tempy < m && map[tempy][x] != 6) {
                map[tempy++][x] = 9;
            }
            int left = x - 1;
            while(left >= 0 && map[y][left] != 6) {
                map[y][left--] = 9;
            }
            int right = x + 1;
            while (right < m && map[y][right] != 6) {
                map[y][right++] = 9;
            }
        } else if (facing == 3) {
            int tempx = x;
            while(tempx >= 0 && map[y][tempx] != 6) {
                map[y][tempx--] = 9;
            }
            int up = y - 1;
            while(up >= 0 && map[up][x] != 6) {
                map[up--][x] = 9;
            }
            int down = y + 1;
            while(down < n && map[down][x] != 6) {
                map[down++][x] = 9;
            }
        }
    } else if (type == 5) {
        int left = x - 1;
        while(left >= 0 && map[y][left] != 6) {
            map[y][left--] = 9;
        }
        int right = x + 1;
        while (right < m && map[y][right] != 6) {
            map[y][right++] = 9;
        }
        int up = y - 1;
        while(up >= 0 && map[up][x] != 6) {
            map[up--][x] = 9;
        }
        int down = y + 1;
        while(down < n && map[down][x] != 6) {
            map[down++][x] = 9;
        }
    }
}

int countSpace() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                count++;
            }
        }
    }

    return count;
}

void dfs(int idx) {
    // idx가 k - 1개까지 왔다면
    if (idx == k) {
        // 모든 cctv를 한번에 작동시킨다
        for (int i = 0; i < idx; i++) {
            watch(cctvs[i].y, cctvs[i].x, cctvs[i].type, cctvs[i].facing);
        }

        // 그리고 사각지대의 개수를 센다
        answer = min(answer, countSpace());

        // 맵을 초기화시키고 return
        resetMap();
        return;
    }

    // 현재 idx cctv에 대해서 4가지 경우를 모두 따진다
    // 0 북 / 1 동 / 2 남 / 3 서
    for (int i = 0; i < 4; i++) {
        cctvs[idx].facing = i;
        for (int j = idx + 1; j <= k; j++) {
            dfs(j);
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            originMap[i][j] = map[i][j];

            if (map[i][j] != 0 && map[i][j] != 6) {
                // cctv라면 추가
                k++;
                CCTV temp = { i, j, map[i][j], 0 };
                cctvs.push_back(temp);
            }
        }
    }

    dfs(0);

    printf("%d\n", answer);

    return 0;
}
