#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

    int n, i, j, k, ans = 0;
    scanf("%d", &n);

    int inc[n];
    int dec[n];
    int arr[n];

    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (i = 0; i < n; i++) {
        k = n - i - 1;
        inc[i] = 1;
        dec[k] = 1;
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && inc[j] + 1 > inc[i]) inc[i] = inc[j] + 1;
        }
        for (j = n - 1; j > k; j--) {
            if (arr[k] > arr[j] && dec[j] + 1 > dec[k]) dec[k] = dec[j] + 1;
        }
    }

    for (i = 0; i < n; i++) {
        ans = max(ans, inc[i] + dec[i] - 1);
      }

    printf("%d\n", ans);
    return 0;
}
