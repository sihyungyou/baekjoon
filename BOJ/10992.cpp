#include <cstdio>
using namespace std;

int main() {

    int n, i, j;
    scanf("%d", &n);

    int arr[101][200] = { 0, };
    int last = n * 2 - 1;
    int plus = 0;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= last; j++) {
            if (i == n) {
                arr[i][j] = 1;
            }
            else {
                arr[i][n+plus] = 1;
                arr[i][n-plus] = 1;
                plus++;
                break;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        int cnt = 0;
        for (j = 1; j <= last; j++) {
            if (i == 1) {
                if (arr[i][j] == 1) {
                    printf("*");
                    break;
                }
                else {
                  printf(" ");
                }
            }
            else if (i == n) {
                printf("*");
            }
            else {
                if (arr[i][j] == 1) {
                    printf("*");
                    cnt++;
                }
                else if (arr[i][j] == 0 && cnt < 2) printf(" ");
                else if (arr[i][j] == 0 && cnt >= 2) {
                  break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
