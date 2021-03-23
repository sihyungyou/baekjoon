#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int mustAtOdd = 0;
        int mustAtEven = 0;
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            if (num % 2 == 0 && i % 2 != 0) {
                mustAtEven++;
            } else if (num % 2 != 0 && i % 2 == 0) {
                mustAtOdd++;
            }
        }

        if (mustAtOdd != mustAtEven) printf("-1\n");
        else printf("%d\n", mustAtOdd);
    }

    return 0;
}
