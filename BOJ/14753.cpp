#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, two, three, ans;
    vector<int> v;


    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), cmp);

    ans = v[0] * v[1];
    ans = max(ans, v[n-1] * v[n-2]);
    ans = max(ans, v[0] * v[1] * v[2]);
    ans = max(ans, v[0] * v[n-1] * v[n-2]);

    printf("%d\n", ans);

    return 0;
}
