#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int n;

    while(1) {
        char str[5];
        scanf("%s", str);

        int n = strlen(str);

        if (strcmp("0", str) == 0) break;

        bool flag = true;
        for (int j = 0; j < n / 2; j++) {
            if (str[j] != str[n-j-1]) {
                flag = false;
                break;
            }
        }

        if (flag) printf("yes\n");
        else printf("no\n");
    }


    return 0;
}
