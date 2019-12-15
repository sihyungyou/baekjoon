#include <cstdio>
#include <cstring>

using namespace std;

int main() {

    int t, i, j, k, len, first, cnt = 0;
    bool flag;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        char in[11];
        scanf("%s", in);
        len = strlen(in);
        cnt = 0;
        first = in[0] - '0';
        flag = true;


        if (len == 1) {
            cnt += first;
        }
        else {
            cnt += (len-1) * 9;

            for (j = 1; j < len; j++) {
                if (in[j] < in[0]) {
                    for (k = 1; k < j; k++) {
                        if (in[k] > in[0]) break;
                    }
                    if (k == j) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                cnt += first;
            } else {
                cnt += first - 1;
            }
        }

        printf("%d\n", cnt);
    }



    return 0;
}