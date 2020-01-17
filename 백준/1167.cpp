/*
문제
트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.

입력
트리가 입력으로 주어진다. 먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2≤V≤100,000)둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. (정점 번호는 1부터 V까지 매겨져 있다고 생각한다)

먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 하나는 정점번호, 다른 하나는 그 정점까지의 거리이다. 예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고, 정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 각 줄의 마지막에는 -1이 입력으로 주어진다. 주어지는 거리는 모두 10,000 이하의 자연수이다.

출력
첫째 줄에 트리의 지름을 출력한다.
*/

#include <cstdio>
using namespace std;

int V;
int dist;
int farnode;
int tree[100001][100001];
bool visited[100001] = { false, };

void dfs(int src, int cost) {

    visited[src] = true;

    if (dist < cost) {
        dist = cost;
        farnode = src;
    }

    for (int k = 1; k <= V; k++) {
        if (!visited[src] && tree[src][k] > 0) dfs(k, cost + tree[src][k]);
    }
}

int main() {
    
    int i, s, d, dist;

    scanf("%d", &V);

    for (i = 0; i < V; i++) {
        scanf("%d", &s);
        while(1) {
            scanf("%d", &d);
            if (d != -1) {
                scanf("%d", &dist);
                tree[s][d] = dist;
            }
            else break;
        }
    }

    dfs(1, 0);
    for (i = 0; i <= V; i++) visited[i] = false;
    
    printf("farthest node : %d\ndistance : %d\n", farnode, dist);

    dist = 0;
    dfs(farnode, 0);
    
    printf("%d\n", dist);

    return 0;
}