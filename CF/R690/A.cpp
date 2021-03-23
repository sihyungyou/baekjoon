#include <cstdio>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        int arr[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int left = 0;
        int right = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                printf("%d ", arr[i - left++]);
            } else {
                printf("%d ", arr[n - i + right++]);
            }
        }
        printf("\n");
    }

    return 0;
}
