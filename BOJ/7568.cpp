#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main() {

    int i, j, n, h, w, k;
    vector<int> ans;
    vector<pair <int, int> >v;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &w, &h);
        v.push_back(make_pair(w, h));
    }

    for (i = 0; i < n; i++) {
        k = 0;
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            else if (v[i].first < v[j].first && v[i].second < v[j].second) k++;
        }
        ans.push_back(k + 1);
    }

    for (i = 0; i < n; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}