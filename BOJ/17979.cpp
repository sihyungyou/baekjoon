#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] > b[0];
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int tp[m + 1];
    for (int i = 1; i <= m; i++) {
        scanf("%d", &tp[i]);
    }

    vector<vector<int> > table;
    long long dp[15000] = { 0, };
    bool visit[10000] = { false, };
    int maxTime = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int s, e, t;
        scanf("%d %d %d", &s, &e, &t);
        vector<int> v;
        v.push_back(s);
        v.push_back(e);
        v.push_back(t);
        table.push_back(v);

        maxTime = max(maxTime, e);
    }

    sort(table.begin(), table.end(), cmp);

    int pos = 0;
    int tableSize = table.size();

    for (int i = maxTime - 1; i >= 0; i--) {
        dp[i] = max(dp[i], dp[i+1]);

        for (pos = 0; pos < tableSize; pos++) {
            if (!visit[pos] && table[pos][0] == i) {
                int s = table[pos][0];
                int e = table[pos][1];
                int t = table[pos][2];
                int p = tp[t];
                int income = (e - s) * p;

                dp[i] = max(dp[i], income + dp[e]);
                ans = max(ans, dp[i]);
                visit[pos] = true;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}
