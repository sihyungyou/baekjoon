/*
couldn't understand the grammer,

char s[101][101];
for (int i = 0; i < n; i++) scanf("%s", s[i]);
*/

#include <stdio.h>
int n, r, c;
char s[101][101];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            r += s[i][j] == '.'&&s[i][j + 1] == '.'&&s[i][j + 2] ^ '.',
            c += s[j][i] == '.'&&s[j + 1][i] == '.'&&s[j + 2][i] ^ '.';
    printf("%d %d", r, c);
    return 0;
}
