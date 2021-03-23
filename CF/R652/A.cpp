#include <cstdio>
using namespace std;

int main() {

    int t, i, temp;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d", &temp);
        if (temp % 4 == 0) printf("YES\n");
        else printf("NO\n");
    }


    return 0;
}
