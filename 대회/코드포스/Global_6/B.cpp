#include <cstdio>

using namespace std;

int main() {

    int n, i, j;
    long long num;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%lld", &num);

        for (j = 1; j < 7; j++) {
            if ( (num > 14) && ((num - j) % 14) == 0 ) {
                printf("YES\n");
                break;
            }
        }
        if (j == 7) printf("NO\n");
    }

    return 0;
}