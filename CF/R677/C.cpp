#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int arr[n];
        int maxSize = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            maxSize = max(maxSize, arr[i]);
        }

        int answer = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == maxSize && ((i - 1 >= 0 && arr[i-1] < arr[i]) || (i + 1 < n && arr[i+1] < arr[i]))) {
                answer = i + 1;
                break;
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}
