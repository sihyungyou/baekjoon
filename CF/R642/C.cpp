#include <cstdio>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        long long multiplier = 1;
        long long answer = 0;
        for (long long width = 3; width <= n; width += 2) {
            long long area = width * width;
            long long subarea = (width - 2) * (width - 2);
            answer += (area - subarea) * multiplier++;
        }

        printf("%lld\n", answer);
    }

    return 0;
}
