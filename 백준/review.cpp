#include <cstdio>
#include <cmath>

using namespace std;

int main() {

    int n, n2, cnt, i, j;
    bool prime[246913];

    while(1) {
        cnt = 0;
        scanf("%d", &n);
        if (n == 0) break;

        n2 = n * 2;

        for (i = 2; i <= n2; i++) prime[i] = true;

        for (i = 2; i <= sqrt(n2); i++) {
            if (prime[i]) {
                for (j = i+i; j <= n2; j+=i) {
                    prime[j] = false;
                }
            }
        }

        for (i = n + 1; i <= n2; i++) if (prime[i]) cnt++;

        printf("%d\n", cnt);
    }

    return 0;
}