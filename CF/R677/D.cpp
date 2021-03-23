#include <cstdio>
#include <vector>

using namespace std;

int n;
int gangs[5001];
bool connected[5001];
vector<pair<int, int> > roads;

void dfs(int src, int dest) {
    connected[src] = true;
    connected[dest] = true;

    roads.push_back(make_pair(src, dest));

    for (int i = 1; i <= n; i++) {
        if (dest != i && !connected[i] && gangs[dest] != gangs[i]) {
            dfs(dest, i);
        }
    }
}

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        roads.clear();

        for (int i = 1; i <= n; i++) {
            scanf("%d", &gangs[i]);
            connected[i] = false;
        }

        for (int i = 1; i <= n; i++) {
            if (!connected[i]) {
                for (int j = 1; j <= n; j++) {
                    if (i != j && !connected[j] && gangs[i] != gangs[j]) {
                        dfs(i, j);
                    }
                }
            }
        }

        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (!connected[i]) {
                flag = false;
                break;
            }
        }

        if (!flag) {
            printf("NO\n");
        } else if (roads.size() == n - 1) {
            printf("YES\n");
            int len = roads.size();
            for (int i = 0; i < len; i++) {
                printf("%d %d\n", roads[i].first, roads[i].second);
            }
        }
    }

    return 0;
}
