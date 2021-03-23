#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int integers[n];
        for (int i = 0; i < n; i++) scanf("%d", &integers[i]);
        sort(integers, integers + n);

        int numbers[k];
        int arr[k];
        for (int i = 0; i < k; i++) {
            scanf("%d", &numbers[i]);
            arr[i] = 0;
        }
        sort(numbers, numbers + k, cmp);

        long long answer = 0;
        int pos = k - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (numbers[pos] > 0) {
                // 아직 받을 수 있으면
                
            }
        }

        printf("%lld\n", answer);
    }


    return 0;
}
