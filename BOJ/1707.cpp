#include <cstdio>
#include <vector>
using namespace std;

vector<int> graph[20001];
bool visit[20001] = { false, };
bool colors[20001] = { false, };
bool isCycle = false;

void init() {
    isCycle = false;
    for (int i = 0; i <= 20000; i++) {
        graph[i].clear();
        visit[i] = false;
        colors[i] = false;
    }
}

void dfs(int from) {
    visit[from] = true;

    int len = graph[from].size();
    for (int i = 0; i < len; i++) {
        int node = graph[from][i];
        if (!visit[node]) {
            // 방문을 안했다면 나와 다른 컬러로 지정
            colors[node] = !colors[from];
            dfs(node);
        } else if (colors[node] == colors[from]) {
            // 방문을 했다면 나와 컬러가 달라야함
            isCycle = true;
            return;
        }
    }
}

int main() {
    int k;
    scanf("%d", &k);

    while(k--) {
        int v, e;
        scanf("%d %d", &v, &e);

        init();
        while(e--) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // 하.. 연결그래프가 아닐 수도 있다니; 당연히 연결그래프라고 생각하고 1번 정점에서만 탐색을 했었다.
        for (int i = 1; i <= v; i++) if (!visit[i]) dfs(i);

        isCycle ? printf("NO\n") : printf("YES\n");
    }

    return 0;
}
