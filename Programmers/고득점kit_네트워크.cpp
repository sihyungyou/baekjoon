#include <string>
#include <vector>

using namespace std;

bool visit[200] = { false, };
vector<vector<int>> map;
int len;

void dfs(int v) {
    visit[v] = true;

    int i;
    for (i = 0; i < len; i++) {
        if (map[v][i] == 1 && !visit[i]) dfs(i);
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    len = n;

    for (int i = 0; i < n; i++) {
        map.push_back(computers[i]);
    }

    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            dfs(i);
            answer++;
        }
    }

    return answer;
}
