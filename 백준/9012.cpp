#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int main() {

    int N, i, j, flag;

    scanf("%d", &N);
    char arr[N][51];

    for (i = 0; i < N; i++) scanf("%s", arr[i]);

    for (i = 0; i < N; i++) {
        stack <char> s;
        flag = 0;
        for (j = 0; j < strlen(arr[i]); j++) {
            if (arr[i][j] == '(') s.push('(');
            else {
                if (!s.empty()) s.pop();
                else { printf("NO\n"); flag = 1; break; }
            }
        }
        if (flag) continue;
        if (!s.empty()) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}