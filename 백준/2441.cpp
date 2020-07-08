#include <cstdio>
using namespace std;

int main() {

    int n, i, j;
    scanf("%d", &n);

    int star = n;
    int space = 0;

    for (i = 1; i <= n; i++) {
        for (j = 0; j < space; j++) printf(" ");
        for (j = 0; j < star; j++) printf("*");
        printf("\n");

        star--;
        space++;
    }



    return 0;
}
