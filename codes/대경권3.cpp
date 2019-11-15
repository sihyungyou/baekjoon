#include <iostream>
#include <climits>

using namespace std;
int get_min(int a, int b) { return a < b ? a : b; }

int main(void) {
    int n, i, j, temp, ans = 100000001;
    int arr[2][300000];
    scanf("%d", &n);
    // int arr[2][n];
    bool r = false;
    bool g = false;
    bool b = false;
    
    for (i = 0; i < n; i++) scanf("%d %d", &arr[0][i], &arr[1][i]);
    
    for (i = 0; i < n; i++) {
        printf("i\n");
        for (j = i; j < n; j++) {
            printf("j\n");
            if (arr[1][j] == 1) r = true;
            if (arr[1][j] == 2) g = true;
            if (arr[1][j] == 3) b = true;   
            
            if (r && g && b) {
                temp = arr[0][j]-arr[0][i];
                ans = get_min(ans, temp);
                r = false;
                g = false;
                b = false;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}