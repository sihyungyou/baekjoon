#include <cstdio>
#include <cstdlib>

using namespace std;

#define MOD 16769023

int n;
// int cnt = 0;

void dfs(int zeros, int ones, int len) {
    // dfs는 시간초과 + 메모리 범위 넘어감
    int diff = abs(zeros - ones);

    if (diff > 1) return;
    else if (len == n) {
        cnt++;
        return;
    }

    dfs(zeros + 1, ones, len + 1);
    dfs(zeros, ones + 1, len + 1);

}

int main() {
    scanf("%d", &n);

    /*
    규칙
    n = 1 -> 2
    n = 2 -> 2
    n = 3 -> 4
    n = 3 -> 4
    n = 4 -> 8
    ...
    */
    int arr[n + 1];
    arr[1] = 2;
    arr[2] = 2;

    for (int i = 3; i <= n; i += 2) {
        int temp = arr[i - 1] * 2 % MOD;
        arr[i] = temp;
        arr[i + 1] = temp;
    }

    printf("%d\n", arr[n]);
    return 0;
}
