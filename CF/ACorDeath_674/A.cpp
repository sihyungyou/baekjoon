#include <cstdio>
using namespace std;

int main() {
    int n, x, t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &x);
        if (n == 1 || n == 2) {
            printf("%d\n", 1);
        } else {
            int answer;
            int floor = n - 2;
            if (floor % x == 0) answer = floor / x + 1;
            else answer = floor / x + 2;
            printf("%d\n", answer);
        }
    }

    return 0;
}
