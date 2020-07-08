#include <cstdio>
using namespace std;

int main() {

    int n, i, j;
    scanf("%d", &n);

    int star = 1;

    for (i = 1; i <= n; i++) {
        for (j = 0; j < star; j++) printf("*");
        printf("\n");
        star++;
    }

    return 0;
}
