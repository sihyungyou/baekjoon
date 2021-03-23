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

        int a[n];
        int b[n];

        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }

        sort(a, a + n);
        sort(b, b + n, cmp);

        int pos = 0;
        while(k > 0) {
            // a[i]는 a의 min일 것이고 b[i]는 b의 max일 것.
            int mina = a[pos];
            int maxb = b[pos];

            if (mina < maxb) {
                // a min이 b max보다 크다면 swap
                sum -= mina;
                sum += maxb;
                // swap 했다면 k--
                k--;

                // pos 옮기기
                pos++;
            } else {
                break;
            }
            // k가 아직 0보다 크더라도 바꿀 게 없이 pos가 n을 넘어가면 break
        }

        printf("%d\n", sum);
    }

    return 0;
}
