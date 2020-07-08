#include <cstdio>
using namespace std;

int main() {
    int n, i, j, k = 1;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (i == n) {
            for (j = 0; j < n; j++) printf("* ");
        }
        else {
            for (j = 0; j < n - k; j++) printf(" ");
            printf("*");
            for (j = 0; j < i - 1; j++) printf(" *");
            k++;
        }
        printf("\n");
    }

    return 0;
}
