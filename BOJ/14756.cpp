#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main() {

    int n, m, c1, c2, i, distance_y, ans = INT_MAX;
    vector<int> p;
    vector<int> q;
    map<int, vector<pair<int, int> > > dict;

    scanf("%d %d", &n, &m);
    scanf("%d %d", &c1, &c2);

    distance_y = abs(c1 -c2);

    for (i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        p.push_back(temp);
    }
    for (i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);
        q.push_back(temp);
    }

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    // p의 모든 점에대해 q와의 최소 distance를 파악
    for (i = 0; i < n; i++) {
        int min_distance = INT_MAX;
        int target = p[i];
        int targetq = 0;

        vector<int>::iterator low;
        low = lower_bound(q.begin(), q.end(), target);
        int lowidx = low - q.begin();

        if (lowidx > m - 1) {
            targetq = q[m - 1];
        } else if (lowidx == 0) {
            targetq = q[0];
        } else {
            if ( abs(target - q[lowidx]) > abs(target - q[lowidx - 1]) ) {
                targetq = q[lowidx - 1];
            } else {
                targetq = q[lowidx];
            }
        }

        min_distance = min(min_distance, abs(target - targetq));
        min_distance += distance_y;
        dict[min_distance].push_back(make_pair(target, targetq));

        ans = min(ans, min_distance);
    }

    // p의 모든 점에대해 q와의 최소 distance를 파악
    for (i = 0; i < m; i++) {
        int min_distance = INT_MAX;
        int target = q[i];
        int targetp;

        vector<int>::iterator low;
        low = lower_bound(p.begin(), p.end(), target);
        int lowidx = low - p.begin();

        if (lowidx > n - 1) {
            targetp = p[n - 1];
        } else if (lowidx == 0) {
            targetp = p[0];
        } else {
            if ( abs(target - p[lowidx]) > abs(target - p[lowidx - 1]) ) {
                targetp = p[lowidx - 1];
            } else {
                targetp = p[lowidx];
            }
        }

        min_distance = min(min_distance, abs(target - targetp));
        min_distance += distance_y;
        dict[min_distance].push_back(make_pair(targetp, target));

        ans = min(ans, min_distance);
    }

    sort(dict[ans].begin(), dict[ans].end());
    dict[ans].erase( unique(dict[ans].begin(), dict[ans].end()), dict[ans].end());
    printf("%d %lu\n", ans, dict[ans].size());

    return 0;
}
