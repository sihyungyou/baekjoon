#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int a, b;
        scanf("%d %d", &a, &b);

        int len = min(max(2 * b, a), max(2 * a, b));
        printf("%d\n", len * len);
    }

    return 0;
}
