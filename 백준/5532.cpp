#include <cstdio>
using namespace std;

int main() {
    int arr[5];
    int i, l, a, b, c, d, day = 0;

    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    l = arr[0];
    a = arr[1];
    b = arr[2];
    c = arr[3];
    d = arr[4];

    while(1) {
        if (a <= 0 && b <= 0) break;
        else {
            a -= c;
            b -= d;
            day++;
        }
    }

    printf("%d\n", l - day);
    return 0;
}
