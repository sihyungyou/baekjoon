#include <cstdio>
#include <cstring>
using namespace std;

int main() {

    int n, k, i, j, cnt = 0;
    char str[500001];

    scanf("%d %d", &n, &k);
    scanf("%s", str);

    for (i = 0; i < n; i++) {
        if (str[i] <= str[i+1] && cnt < k) {
            str[i] = '-';
            cnt++;
        }
        else if (n - i <= k - cnt) { 
            str[i] = '-';
            cnt++;
        }
        else {
            for (j = 0; j < k - cnt; j++) {
                if (str[i] < str[j]) {
                    str[i] = '-';
                    cnt++;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (str[i] != '-') printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}