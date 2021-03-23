#include <cstdio>

using namespace std;

#define ULL unsigned long long
int main() {

    ULL n, chunk = 1, total = 1;
    scanf("%llu", &n);

    while(total < n) {
        total += total + 1;
        chunk++;
        printf("total : %llu, chunk : %llu\n", total, chunk);
    }

    // printf("%llu\n", chunk/2);
    return 0;
}
