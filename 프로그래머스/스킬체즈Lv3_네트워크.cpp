#include <string>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int i, j;
    queue<int> q;
    bool visit[200];

    for (i = 0; i < 200; i++) { visit[i] = false; }

    for (i = 0; i < n; i++) {
        if (!visit[i]) {
            q.push(i);
            while(!q.empty()) {
                int temp = q.front();
                q.pop();
                visit[temp] = true;
                for (j = 0; j < n; j++) {
                    if (temp != j && computers[temp][j] == 1 && !visit[j]) {
                        q.push(j);
                    }
                }
            }
            answer++;
        }
    }

    return answer;
}
