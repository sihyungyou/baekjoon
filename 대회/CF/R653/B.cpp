#include <cstdio>
using namespace std;

#define MAX 1000000000

int main () {
    int t, i, n, ans;

    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d", &n);

        ans = 0;
        while(1) {
            if (n == 1) {
                break;
            }
            else if (n > MAX) {
                ans = -1;
                break;
            }
            else if (n % 6 == 0) {
                n /= 6;
                ans++;
            }
            else {
                n *= 2;
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
