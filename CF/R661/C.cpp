#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int w[101] = { 0, };
        vector<int> p;
        bool visit[n];
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            p.push_back(temp);
            visit[i] = false;
        }

        // 나올 수 있는 모든 weight 가지수 기록
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sumWeight = p[i] + p[j];
                w[sumWeight]++;
            }
        }

        // 모든 가능한 s를 만드는 쌍 개수 계산
        int ans = 0;
        int tempAns = 0;
        for (int k = 2; k <= 100; k++) {
            if (w[k] > 0) {
                for (int v = 0; v < n; v++) visit[v] = false;
                int s = k;
                tempAns = 0;
                for (int i = 0; i < n; i++) {
                    if (!visit[i]) {
                        for (int j = 0; j < n; j++) {
                            if (i != j && !visit[j]) {
                                int tryS = p[i] + p[j];
                                if (tryS == s) {
                                    visit[i] = true;
                                    visit[j] = true;
                                    tempAns++;
                                    break;
                                }
                            }
                        }
                    }
                }
                ans = max(ans, tempAns);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
