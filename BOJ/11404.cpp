#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX_DIST 10000000

int main() {
    int cities[101][101];
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cities[i][j] = MAX_DIST;
        }
    }

    for (int i = 0; i < m; i++) {
        int src, dest, distance;
        scanf("%d %d %d", &src, &dest, &distance);
        cities[src][dest] = min(cities[src][dest], distance);
    }

    // 플로이드 와샬 알고리즘
    for (int i = 1; i <= n; i++) {
        // i를 거쳐가는 경우
        for (int j = 1; j <= n; j++) {
            // j 노드들에 대해
            if (i != j) {
                for (int k = 1; k <= n; k++) {
                    if (j != k) {
                        // j -> k vs. j -> i -> k 중 min을 [j][k]에 대입
                        cities[j][k] = min(cities[j][k], cities[j][i] + cities[i][k]);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cities[i][j] == MAX_DIST) {
                cities[i][j] = 0;
            }
            printf("%d ", cities[i][j]);
        }
        printf("\n");
    }



    return 0;
}
