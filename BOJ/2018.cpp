#include <cstdio>
using namespace std;

int main() {
    int n, l = 1, r = 1, answer = 0, sum = l;
    scanf("%d", &n);

    while(r <= n && l <= n) {
        if (sum == n) {
            answer++;
            sum -= l;
            l++;
        } else if (sum > n) {
            sum -= l;
            l++;
        } else if (sum < n) {
            r++;
            sum += r;
        }
    }

    printf("%d\n", answer);

    return 0;
}
