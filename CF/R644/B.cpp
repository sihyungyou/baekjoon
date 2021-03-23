#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int arr[n + 1];
        for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
        arr[0] = 0;

        sort(arr, arr + n + 1);

        int answer = INT_MAX;
        for (int i = 1; i < n; i++) {
            int diff = arr[i + 1] - arr[i];
            answer = min(answer, diff);
        }

        printf("%d\n", answer);
    }

    return 0;
}
