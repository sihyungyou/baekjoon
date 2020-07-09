#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

    int i;
    int a[10];
    int b[10];
    int A = 0, B = 0, D = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 10; i++) {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < 10; i++) {
        if (a[i] == b[i]) D++;
        else if (a[i] > b[i]) A++;
        else B++;
    }

    if (A == B) printf("D\n");
    else if (A > B) printf("A\n");
    else printf("B\n");

    return 0;
}
