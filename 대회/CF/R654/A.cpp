#include <cstdio>
using namespace std;

int main() {

    int n, i, t, j;

    scanf("%d", &t);
    for (j = 0; j < t; j++) {
        scanf("%d", &n);

        if (n % 2 == 0) printf("%d\n", n/2);
        else printf("%d\n", n/2 + 1);

    }


    return 0;
}
