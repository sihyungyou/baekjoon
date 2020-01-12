#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int get_min(int a, int b) { return a < b ? a : b; }
int gcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {

    int n, i, temp, min = INT_MAX, diff, ans = 0;

    scanf("%d", &n);
    int arr[n];
    int arr2[n-1];

    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (i = 1; i < n; i++) arr2[i-1] = arr[i] - arr[i-1];

    for (i = 1; i < n - 1; i++) {
        diff = gcd(arr2[i], arr2[i-1]);
        min = get_min(min, diff);
    }

    for (i = 0; i < n - 1; i++) {
        if (arr2[i] > min) {
            ans += arr2[i]/min - 1;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}