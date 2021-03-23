#include <cstdio>

using namespace std;

int main() {

    int t;
    bool flag = true;
    scanf("%d", &t);

    char str[100];
    scanf("%s", str);

    char c = str[0];
    t--;

    while(t--) {
        scanf("%s", str);
        if (str[0] != c) {
            flag = false;
            break;
        }
    }

    if (flag) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
