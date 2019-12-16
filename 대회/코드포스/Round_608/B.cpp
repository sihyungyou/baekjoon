#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main() {

    int n, i, len, cnt = 0;
    vector<int> ans;
    char in[201];
    char tempin[201];

    scanf("%d", &n);
    scanf("%s", in);


    len = strlen(in);
    strncpy(tempin, in, len);
    tempin[len] = '\0';
    
    char compw[len];
    char compb[len];

    for (i = 0; i < len; i++) {
        compw[i] = 'W';
        compb[i] = 'B';
    }

    compw[len] = '\0';
    compb[len] = '\0';

    if (!strcmp(in, compw)) printf("0\n");          // all W
    else if (!strcmp(in, compb)) printf("0\n");     // all B
    else {                                          // needs to be changed

        // try all W
        for (i = 0; i < len - 1; i++) {

            if (tempin[i] == 'B') {
                tempin[i] = 'W';
                ans.push_back(i+1);
                cnt++;
                if (tempin[i+1] == 'B') {
                    tempin[i+1] = 'W';
                } else tempin[i+1] = 'B';
            }
        }

        if (!strcmp(tempin, compw)) {
            printf("%d\n", cnt);
            for (i = 0; i < cnt; i++) printf("%d ", ans[i]);
            printf("\n");
            return 0;
        }

        ans.clear();
        cnt = 0;
        // try all W
        for (i = 0; i < len - 1; i++) {
            if (in[i] == 'W') {
                in[i] = 'B';
                ans.push_back(i+1);
                cnt++;
                if (in[i+1] == 'W') {
                    in[i+1] = 'B';
                } else in[i+1] = 'W';
            }
        }

        if (!strcmp(in, compb)) {
            printf("%d\n", cnt);
            for (i = 0; i < cnt; i++) printf("%d ", ans[i]);
            printf("\n");
            return 0;
        }

        printf("-1\n");
    }

    return 0;
}