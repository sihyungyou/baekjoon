#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct heapcmp {
    // min heap을 만들기 위한 custom
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int v, e, k;
int d[20001];
// 인접행렬을 사용할 경우 메모리초과 -> 인접리스트로 변경
vector<pair<int, int> > edges[20001];

void printDarray() {
    for (int i = 1; i <= v; i++) {
        if (d[i] == INT_MAX) printf("INF\n");
        else printf("%d\n", d[i]);
    }
}

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, heapcmp> heap;

    // 시작점에서 시작점으로는 거리가 0이므로
    d[start] = 0;
    // 시작점을 heap에 넣어야 시작할 수 있다
    heap.push(make_pair(start, d[start]));

    // heap이 비어있지 않을 동안
    while(!heap.empty()) {
        // 현재 노드 (현재 시점에서 가장 d배열의 값이 작은 노드)
        int currentIdx = heap.top().first;
        int currentDistance = heap.top().second;
        heap.pop();

        int adjNodes = edges[currentIdx].size();
        // 현재 노드와 인접한 모든 노드에 대해
        for (int i = 0; i < adjNodes; i++) {
            int destIdx = edges[currentIdx][i].first;
            int destDistance = edges[currentIdx][i].second + d[currentIdx];

            // 현재 노드를 거쳐서 가는 거리가 인접한 노드의 현재 거리값보다 작다면 업데이트하고 heap에 다시 넣어서 다른 경로도 업데이트할 수 있도록한다
            if (d[destIdx] > destDistance) {
                d[destIdx] = destDistance;
                heap.push(make_pair(destIdx, destDistance));
            }
        }
    }
}

int main() {
    scanf("%d %d", &v, &e);
    scanf("%d", &k);

    // d배열은 초기에 모두 최대값이고, 시작점만 0으로 설정된다
    for (int i = 1; i <= v; i++) d[i] = INT_MAX;

    while(e--) {
        int u, v, dist;
        scanf("%d %d %d", &u, &v, &dist);
        edges[u].push_back(make_pair(v, dist));
    }

    dijkstra(k);
    printDarray();
    return 0;
}
