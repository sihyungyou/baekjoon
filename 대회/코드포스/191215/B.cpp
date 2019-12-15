#include <cstdio>
#include <cstring>
using namespace std;

int get_min(int a, int b) { return a < b ? a : b; }
int main() {

    int t, i, j, k, slen, clen, len, cnt;
    bool flag;
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        char s[5001];
        char c[5001];
        cnt = 0;
        flag = false;
        scanf("%s %s", s, c);
        slen = strlen(s);
        clen = strlen(c);
        len = get_min(slen, clen);

        for (j = 0; j < len; j++) {
            if (s[j] > c[j] && !flag) {
                for (k = j + 1; k < slen; k++) {
                    if (s[k] <= c[j]) {
                        char temp = s[k];
                        s[k] = s[j];
                        s[j] = temp;
                        flag = true;
                        break;
                    }
                }
            }
            if (s[j] == c[j]) cnt++;
            if (s[j] < c[j]) {
                if (cnt == j) {
                    printf("%s\n", s);
                    flag = true;
                    break;
                }
            }
        }
        
        if (slen < clen && cnt == len) printf("%s\n", s);
        if (!flag || strcmp(s, c) >= 0) printf("---\n");

    }

    return 0;
}