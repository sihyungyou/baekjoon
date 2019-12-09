#include <cstdio>
#include <cmath>

using namespace std;

#define MOD 16769023

int main() {
    long n, ans = 1;
    scanf("%ld", &n);

    for (int i = 1; i <= n/2; i++) { ans *= 2; ans %= MOD; }
    if (n % 2 != 0) ans *= 2;
    
    printf("%ld\n", ans%MOD);
    return 0;
}