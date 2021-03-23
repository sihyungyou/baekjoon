#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int count[n+1];
        int arr[n+1];

        memset(count, 0, sizeof(count));

        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            count[arr[i]]++;
        }

        int answer = -1;
        int prev = INT_MAX;

        for (int i = 1; i <= n; i++) {
            if (count[arr[i]] == 1 && arr[i] < prev) {
                // unique 하다면 min 검사
                prev = arr[i];
                answer = i;
            }
        }

        if (prev == INT_MAX) {
            printf("-1\n");
        } else {
            printf("%d\n", answer);
        }
    }

    return 0;
}
