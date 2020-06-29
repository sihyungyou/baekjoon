#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.first > b.first;
}

int main() {

    vector < pair <int, int> > v;
    vector <int> p;

    int i, score, total = 0;

    for (i = 0; i < 8; i++) {
        scanf("%d", &score);
        v.push_back(make_pair(score, i + 1));
    }

    sort(v.begin(), v.end(), cmp);

    for (i = 0; i < 5; i++) {
        total += v[i].first;
        p.push_back(v[i].second);
    }

    sort(p.begin(), p.end());

    printf("%d\n", total);
    for (i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }

    printf("\n");

    return 0;
}
