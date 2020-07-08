#include <cstdio>
using namespace std;

int main() {

    int i, j, x, t, n, r;
    long long ans;
    long long temp;

    scanf("%d", &t);
    for (x = 0; x < t; x++) {
        scanf("%d %d", &n, &r);
        ans = 0;
        if (r < n) {
            temp = r - 1;
            if (temp % 2 == 0) {
                ans += r * (temp / 2);
            }
            else {
                ans += r * (temp / 2) + (temp / 2 + 1);
            }
            ans += r;
        }
        else {
          temp = n - 1;
          if (temp % 2 == 0) {
              ans += (temp + 1) * (temp / 2);
          }
          else {
              ans += (temp + 1) * (temp / 2) + (temp / 2 + 1);
          }
          ans++;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
