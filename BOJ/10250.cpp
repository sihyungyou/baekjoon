#include <cstdio>
using namespace std;

int main() {

    int h, w, n, t, i, H, W;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d %d %d", &h, &w, &n);
        if (n % h == 0) W = n/h;
        else W = n/h + 1;
        H = n - (h * (W-1));
        printf("%d%02d\n", H, W);
    }

    return 0;
}