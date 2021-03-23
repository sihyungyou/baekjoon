#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, m, answer = 0;
    scanf("%d", &n);
    scanf("%d", &m);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    sort(arr, arr + n);

    int l = 0, r = n - 1;
    while(l <= r) {
        // l번째 수와 r번째 수를 더해본다
        int sum = 0;
        if (l == r) sum = arr[l];
        else sum = arr[l] + arr[r];

        if (sum == m) {
            answer++;
            l++;
        }
        // sum이 m보다 작다면 l을 증가시키고 크다면 r을 감소시킨다 (정렬되어있으므로)
        else if (sum < m) l++;
        else if (sum > m) r--;
    }

    printf("%d\n", answer);

    return 0;
}
