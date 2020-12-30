#include <vector>
#include <climits>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int n = routes.size();

    sort(routes.begin(), routes.end(), cmp);

    for (int i = 0; i < n - 1; i++) {
        vector<int> cur = routes[i];
        vector<int> next = routes[i + 1];

        if (next[0] <= cur[1] && next[0] > cur[0]) answer++;
    }

    return answer;
}
