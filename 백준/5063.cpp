#include <cstdio>
using namespace std;

int main() {

    int i, t, r, e, c;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d %d %d", &r, &e, &c);
        if (e - c > r) {
            printf("advertise\n");
        }
        else if (e - c == r) {
            printf("does not matter\n");
        }
        else {
            printf("do not advertise\n");
        }
    }

    return 0;
}
