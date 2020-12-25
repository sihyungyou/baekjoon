#include <cstdio>

using namespace std;

int t, n, cycle = 0;
bool map[1001][1001] = { false, };
bool visit[1001] = { false, };

void cleanMap() {
    for (int i = 0; i < 1001; i++) {
        visit[i] = false;
        for (int j = 0; j < 1001; j++) {
            map[i][j] = false;
        }
    }
}

void dfs(int dest) {
    visit[dest] = true;
    for (int i = 1; i <= n; i++) {
        if (map[dest][i]) {
            if (visit[i]) {
                // cycle 발견
                cycle++;
            } else {
                dfs(i);
            }
        }
    }
}

void getNumOfCycle() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] && !visit[i]) {
                visit[i] = true;
                dfs(j);
            }
        }
    }
}

int main() {

    scanf("%d", &t);

    while(t--) {
        cycle = 0;
        cleanMap();

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int pi;
            scanf("%d", &pi);
            map[i][pi] = true;
        }

        // get cycle
        getNumOfCycle();

        printf("%d\n", cycle);
    }


    return 0;
}
