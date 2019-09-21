#include <cstdio>

using namespace std;

int main() {
    long double N, sum = 0;
    int i, temp, cnt = 0;

    scanf("%Lf", &N);

    while (sum < N) {
        sum = 0;
        cnt++;
        temp = cnt + 1;
        for(i = 0; i <= cnt; i++) {
            sum += temp;
            temp *= 2;
        }
        sum += cnt;
    }

    printf("%d\n", cnt);

    return 0;
}