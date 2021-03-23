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
        int even = 0;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] % 2 == 0) even++;
            else odd++;
        }

        bool flag = false;
        if ((odd > 0 && odd % 2 == 0) || (even > 0 && even % 2 == 0)) {
            flag = true;
        } else {
            sort(arr, arr + n);
            for (int i = 0; i < n - 1; i++) {
                int diff = arr[i + 1] - arr[i];
                if (diff == 1) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
