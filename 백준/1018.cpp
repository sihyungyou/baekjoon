#include <cstdio>
#include <climits>

using namespace std;

int get_min(int a, int b) {return a < b ? a : b; }
int main() {

    char white[8][9] = {
        { "WBWBWBWB" },
        { "BWBWBWBW" }, 
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" }
    };

    char black[8][9] = {
        { "BWBWBWBW" }, 
        { "WBWBWBWB" },
        { "BWBWBWBW" }, 
        { "WBWBWBWB" },
        { "BWBWBWBW" }, 
        { "WBWBWBWB" },
        { "BWBWBWBW" }, 
        { "WBWBWBWB" }
    };

    int m, n, i, j, x, y, b, w, ans = INT_MAX;

    scanf("%d %d", &n, &m);
    char board[n][m];
    
    for (i = 0; i < n; i++) scanf("%s", board[i]);

    for (x = 0; x < n - 7; x++) {
        for ( y = 0; y < m - 7; y++) {
            b = 0;
            w = 0;
            for (i = x; i < x + 8; i++) {
                for (j = y; j < y + 8; j++) {
                    if (board[i][j] != black[i-x][j-y]) b++;
                    if (board[i][j] != white[i-x][j-y]) w++;
                }
            }
            int temp = get_min(b, w);
            ans = get_min(ans, temp);
        }
    }

    printf("%d\n", ans);

    return 0;
}