#include <cstdio>
using namespace std;

int main() {

    bool arr[31] = { false, };
    int i, n;

    for (i = 0; i < 28; i++) {
        scanf("%d", &n);
        arr[n] = true;
    }

    for (i = 1; i < 31; i++) {
        if (!arr[i]) printf("%d\n", i);
    }


    return 0;
}
