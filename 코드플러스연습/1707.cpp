/*
문제
그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K(2≤K≤5)가 주어진다. 각 테스트 케이스의 첫째 줄에는 그래프의 정점의 개수 V(1≤V≤20,000)와 간선의 개수 E(1≤E≤200,000)가 빈 칸을 사이에 두고 순서대로 주어진다. 각 정점에는 1부터 V까지 차례로 번호가 붙어 있다. 이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데, 각 줄에 인접한 두 정점의 번호가 빈 칸을 사이에 두고 주어진다.

출력
K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.
*/

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[20001];
bool visit[20001] = { false, };
bool color[20001] = { false, };
bool flag = true;

void dfs(int start, bool c) {
  visit[start] = true;
  color[start] = c;

  for (int i = 0; i < graph[start].size(); i++) {
    
    if (visit[graph[start][i]] == false) dfs(graph[start][i]);
  }
}

void data_clear() {
  for (int i = 0; i < 20001; i++) {
    color[i] = false;
    visit[i] = false;
    flag = true;
    graph[i].clear();
  }
}

// void print_graph(int v) {
//   for(int a = 1; a <= v; a++)  {
//     printf("%d -> ", a);
//     for (int b = 0; b < graph[a].size(); b++) {
//       printf("%d ", graph[a][b]);
//     }
//     printf("\n");
//   }
// }

int main() {

  int t, e, v, i, j, src, dest;

  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    scanf("%d %d", &v, &e);

    // clear
    data_clear();

    // init graph
    for (j = 0; j < e; j++) {
      scanf("%d %d", &src, &dest);
      graph[src].push_back(dest);
      graph[dest].push_back(src);
      // if (color[src] != 0 && color[dest] != 0) continue;
      // else {
      //   if (color[src] == 0 && color[dest] != 0) {
      //     color[src] = color[dest] * -1;
      //   }
      //   else if (color[src] != 0 && color[dest] == 0) {
      //     color[dest] = color[src] * -1;
      //   }
      //   else if (color[src] == 0 && color[dest] == 0) {
      //     color[src] = 1;
      //     color[dest] = -1;
      //   }
      // }
    }

    // start dfs
    dfs(1, true);
    if(flag) printf("YES\n");
    else printf("NO\n");
  }

  return 0;
}
