#include <cstdio>

using namespace std;

int main() {

    long long s;
    long long i = 1;
    int cnt = 0;
    scanf("%lld", &s);

    while(s >= 0) {
        s -= i++;
        cnt++;
    }

    printf("%d\n", cnt - 1);
    return 0;
}
