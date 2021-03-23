/*
소요시간 : 40분
특이사항 : 문제 해결 컨셉을 잡는 것은 오래걸리지 않았으나 가중치가 동일하지 않은 상태에서 BFS를 한다는 것을 고려하지 못하여 오답. 결국 질문 검색을 통해 해결
*/

#include <cstdio>
#include <cstring>
#include <utility>
#include <deque>

using namespace std;

#define MAXNUM 100000

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    bool visit[MAXNUM + 1];
    memset(visit, false, sizeof(visit));

    // bfs
    deque<pair<int, int> > dq;
    dq.push_front(make_pair(n, 0));
    visit[n] = true;

    while(!dq.empty()) {
        pair<int, int> cur = dq.front();
        int location = cur.first;
        int time = cur.second;
        dq.pop_front();

        visit[location] = true;

        if (location == k) {
            // 찾음
            printf("%d\n", time);
            return 0;
        }

        int left = location - 1;
        int right = location + 1;
        int jump = location * 2;

        if (jump <= MAXNUM && !visit[jump]) {
            dq.push_front(make_pair(jump, time));
        }
        if (left >= 0 && !visit[left]) {
            dq.push_back(make_pair(left, time + 1));
        }
        if (right <= MAXNUM && !visit[right]) {
            dq.push_back(make_pair(right, time + 1));
        }
    }

    return 0;
}
