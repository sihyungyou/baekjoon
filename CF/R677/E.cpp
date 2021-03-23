#include <cstdio>
#include <cstring>

using namespace std;

long long comb[21][21];

long long calculateComb(int n, int r) {
    if (comb[n][r] != 0) return comb[n][r];
    if (n == r || r == 0) return 1;

    return comb[n][r] = calculateComb(n-1, r-1) + calculateComb(n-1, r);
}

int main() {
    memset(comb, 0, sizeof(comb));

    int n;
    scanf("%d", &n);

    printf("%lld\n", calculateComb(n, n/2)/2);

    return 0;
}
