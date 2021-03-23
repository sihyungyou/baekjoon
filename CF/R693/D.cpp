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
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        sort(arr, arr + n, cmp);

        long long alice = 0;
        long long bob = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && arr[i] % 2 == 0) {
                // alice turn, alice can get point
                alice += arr[i];
            } else if (i % 2 != 0 && arr[i] % 2 != 0) {
                // bob turn, bob can get point
                bob += arr[i];
            }
        }

        if (alice == bob) printf("Tie\n");
        else if (alice > bob) printf("Alice\n");
        else if (alice < bob) printf("Bob\n");
    }

    return 0;
}
