#include <cstdio>
#include <cmath>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int w, h, n;
        scanf("%d %d %d", &w, &h, &n);

        if (n == 1) {
            printf("YES\n");
        } else {
            int fold = 0;
            while(w % 2 == 0) {
                w /= 2;
                fold++;
            }
            while(h % 2 == 0) {
                h /= 2;
                fold++;
            }

            int num = 2;
            int count = 1;
            while (num < n) {
                num *= 2;
                count++;
            }

            if (count <= fold) {
                printf("YES\n");
            } else if (count > fold) {
                printf("NO\n");
            }
        }

    }


    return 0;
}
