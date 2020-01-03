#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int n, m, i, first, second, temp;

    vector<int> v[32001];
    queue<int> q;

    scanf("%d %d", &n, &m);
    int degree[n+1];

    for (i = 0; i <= n; i++) degree[i] = 0;

    for (i = 0; i < m; i++) {
        scanf("%d %d", &first, &second);
        degree[second]++;
        v[first].push_back(second);
    }


    for (i = 1; i <= n; i++) {
        if (!degree[i]) q.push(i);
    }

    while (!q.empty()) {
        temp = q.front();
        q.pop();
        printf("%d ", temp);

        for (i = 0; i < v[temp].size(); i++) {
            degree[v[temp][i]]--;
            if (!degree[v[temp][i]]) q.push(v[temp][i]);
        }
    }

    printf("\n");

    return 0;
}