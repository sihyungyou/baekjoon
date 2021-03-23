#include <cstdio>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int ones = 0;
        int twos = 0;
        for (int i = 0; i < n; i++) {
            int w;
            scanf("%d", &w);

            if (w == 1) ones++;
            else if (w == 2) twos++;
        }

        if ((twos % 2 == 0 && ones % 2 == 0) || (twos % 2 != 0 && ones > 0 && ones % 2 == 0)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }


    return 0;
}
