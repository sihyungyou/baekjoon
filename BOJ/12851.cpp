/*
소요시간 : 40분
특이사항 : 알고리즘을 짜는 것은 쉬웠는데 더하기와 곱하기의 경우가 같다는 반례를 질문 검색을 통해서야 알게 되었다. 어렵다 ㅜㅜ
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>
#include <map>
#include <climits>

using namespace std;

#define MAXNUM 100000

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    bool visit[MAXNUM + 1];
    memset(visit, false, sizeof(visit));

    int answer_time = -1;
    int answer = 0;

    // bfs
    map<int, int> m;
    queue<pair<int, int> > q;
    q.push(make_pair(n, 0));
    visit[n] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int location = cur.first;
        int time = cur.second;

        // 여기서 visit true를 해주는 이유는 1 -> 2로 가는 경우가 1 + 1, 1 * 2가 있기 때문이다
        // 큐에 push 할 때 visit 검사를 하기 때문에 push하기 직전이 아니라 실제로 방문 했을 때 true로 해주어야 다른 경로로 카운트 가능하다
        visit[location] = true;

        if (location == k) {
            if (answer_time == -1) {
                // 처음으로 k를 방문한 경우
                answer_time = time;
                answer++;
            } else if (answer_time == time) {
                // 이미 다른 경로를 통해 k를 방문했기 때문에 최소시간과 동일한지 추가적으로 검사
                answer++;
            }

            visit[k] = false;
            continue;
        }

        int left = location - 1;
        int right = location + 1;
        int jump = location * 2;

        if (jump <= MAXNUM && !visit[jump]) {
            q.push(make_pair(jump, time + 1));
        }
        if (left >= 0 && !visit[left]) {
            q.push(make_pair(left, time + 1));
        }
        if (right <= MAXNUM && !visit[right]) {
            q.push(make_pair(right, time + 1));
        }
    }

    printf("%d\n%d\n", answer_time, answer);
    return 0;
}
