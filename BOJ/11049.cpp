#include <cstdio>
#include <utility>

using namespace std;

long long answer = 0;
int n;
pair<int, int> matrix[500];
pair<int, int> cache[500][500];

void dfs(int from, int to, long long count) {
    printf("%d번째 행렬 ~ %d번째 행렬\n", from, to);

    pair<int, int> cached = cache[from][to];
    long long countTemp;

    if (cached.first == 0 && cached.second == 0) {
        cache[from][to] = make_pair(matrix[from].first, matrix[to].second);
    }

    if (from == 0 && to == n - 1) {
        return;
    }

    int newFrom = from - 1;
    int newTo = to + 1;

    if (newFrom >= 0) {
        dfs(newFrom, to);
    }
    if (newTo < n) {
        long long newCount = cache[from][to].first * cache[from][to].second * to.second;
        dfs(from, newTo, count + newCount);
    }
}

int main() {

    scanf("%d", &n);

    memset(cache, make_pair(0, 0), sizeof(cache));

    for (int i = 0; i < n; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        matrix[i] = make_pair(r, c);
    }

    for (int i = 0; i < n - 1; i++) {
        printf("new start\n");
        dfs(i, i + 1, 0);
    }

    printf("%lld\n", answer);

    return 0;
}
