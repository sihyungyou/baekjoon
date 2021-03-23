#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, k;
        int answer = INT_MAX;
        scanf("%d %d", &n, &k);

        if (n <= k) {
            answer = 1;
        } else {
            vector<int> v;
            // 1 이상, k 이하인 n의 모든 약수를 구하고 그 중 min값이 답
            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    int another = n / i;
                    if (i <= k) v.push_back(i);
                    if (another <= k) v.push_back(another);
                }
            }

            int len = v.size();
            for (int i = 0; i < len; i++) {
                answer = min(answer, n / v[i]);
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}
