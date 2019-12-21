/*
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
*/

#include <cstdio>
using namespace std;

bool grid[14][14] = { false, };
int ans = 0;
int N;

bool isValid(int i, int cnt) {
    int x, y;
    for (x = 0; x < cnt; x++) {
        if (grid[i][x]) return false;
    }

    for (x = cnt - 1, y = i - 1; y >= 0; x--, y--) {
        if (grid[y][x]) return false;
    }

    for (x = cnt - 1, y = i + 1; y < N; x--, y++) {
        if (grid[y][x]) return false;
    }
    
    return true;

}

void dfs(int cnt) {
    
    int i;

    // basecase
    if (cnt == N) {
        ans++;
        return;
    }

    for (i = 0; i < N; i++) {
        if (!grid[i][cnt] && isValid(i, cnt)) {
            // constraint satisfied
            grid[i][cnt] = true;
            dfs(cnt+1);
            grid[i][cnt] = false;
        }
    }

    
}

int main() {

    scanf("%d", &N);

    dfs(0);
    printf("%d\n", ans);

    return 0;
}