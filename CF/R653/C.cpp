#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        char str[n];
        scanf("%s", str);

        int opening = 0;
        for (int i = 0; i < n; i++) {
            char cur = str[i];
            if (cur == '(') opening++;
            else if (cur == ')' && opening > 0) opening--;
        }

        printf("%d\n", opening);
    }

    return 0;
}
