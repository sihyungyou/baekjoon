#include <cstdio>

using namespace std;

int n, s;
int sequence[20];
int answer = 0;

void dfs(int idx, int sum) {
    if (idx == n) return;
    if (sequence[idx] + sum == s) answer++;

    dfs(idx + 1, sum);
    dfs(idx + 1, sequence[idx] + sum);

    return;
}

int main() {
    scanf("%d %d", &n, &s);

    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    dfs(0, 0);

    printf("%d\n", answer);
    return 0;
}
