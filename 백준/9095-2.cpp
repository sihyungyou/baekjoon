#include <cstdio>
using namespace std;

int target;
int cnt;

void dfs(int x) {
    if (x == target) {
      cnt++;
      return;
    }
    else if (x > target) return;

    dfs(x + 1);
    dfs(x + 2);
    dfs(x + 3);
    return;
}

int main() {

    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &target);
        cnt = 0;
        dfs(0);
        printf(">> %d\n", cnt);
    }

    return 0;
}
