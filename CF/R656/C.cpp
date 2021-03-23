#include <cstdio>
#include <cstring>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int arr[n + 1];
        memset(arr, 0, sizeof(arr));

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        if (n <= 2) {
            printf("0\n");
            continue;
        } else {
            int answer = 0;
            bool didDecrease = false;
            for (int i = n - 1; i >= 0; i--) {
                if (didDecrease && i - 1 >= 0 && arr[i-1] > arr[i]) {
                    answer = i;
                    break;
                }
                if (i - 1 >= 0 && arr[i-1] < arr[i]) {
                    didDecrease = true;
                }
            }
            printf("%d\n", answer);
        }
    }

    return 0;
}
