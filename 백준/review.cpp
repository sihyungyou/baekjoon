#include <cstdio>

using namespace std;

int main() {

    int n, i, j;
    scanf("%d", &n);

    i = 2;
    
    while(n != 1) {
        if (n % i == 0) {
            printf("%d\n", i);
            n /= i;
            i = 2;
        }
        else i++;
    }

    return 0;
}