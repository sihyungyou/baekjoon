#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int main() {

    int n, m, i, temp, ans = 0, left = 0, right = 0;
    queue<int> q;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d", &temp);
        q.push(temp);
    }

    while(!q.empty()) {
        temp = q.front();
        q.pop();

        temp += right;
        temp -= left;
        if (temp > n) temp = temp - n;
        if (temp < 1) temp = n - abs(temp);
        printf(">> %d\n", temp);

        if (temp <= n/2 + 1) {
            // left
            left += temp - 1;
            // ans += left;
        }
        else {
            // right
            right += n - temp + 1;
            // ans += right;
        }
    }

    printf("%d\n", right+left);

    return 0;
}