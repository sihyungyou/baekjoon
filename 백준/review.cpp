#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;
#define MAX 10000

int main() {

    int n, t, T, i, j, diff, ans, ans2;
    bool prime[MAX+1];


    for (i = 2; i <= MAX; i++) prime[i] = true;

    for (i = 2; i <= sqrt(MAX); i++) {
        if (prime[i]) {
            for (j = i+i; j <= MAX; j+=i) {
                prime[j] = false;
            }
        }
    }
    
    scanf("%d", &T);
    
    for (t = 0; t < T; t++) {
        diff = INT_MAX;
        scanf("%d", &n);

        for (i = 2; i <= n/2; i++) {
            if (prime[i] && prime[n-i]) {
                int temp = (n - i) - i;
                if (temp < diff) {
                    ans = i;
                    ans2 = n - i;
                }
            }
        }

        printf("%d %d\n", ans, ans2);

    }

    return 0;
}