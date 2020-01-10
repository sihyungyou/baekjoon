#include <cstdio>

using namespace std;

int get_min(int a, int b) { return a < b ? a : b; }

int main() {

    int n, i, j, two, five;

    scanf("%d", &n);

    i = n/2;
    j = n/5;

    two += i;
    five += j;

    while(i != 0) {
        two += i/2;
        i/=2;
    }
    while(j != 0) {
        five += j/5;
        j/=5;
    }
    
    printf("%d\n", get_min(two, five));
    

    return 0;
}