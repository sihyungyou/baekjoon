#include <cstdio>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int temp6 = a * b;

    int temp5 = b/100;
    b%=100;
    int temp4 = b/10;
    b%=10;
    int temp3 = b;

    printf("%d\n%d\n%d\n%d\n", temp3*a, temp4*a, temp5*a, temp6);

    return 0;
}