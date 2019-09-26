/*
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다.
(1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다.
(1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.
*/

#include <cstdio>
using namespace std;

int N, M, cnt = 0;
int arr[1001][1001] = { 0, };
bool vi[1001] = { false, };

void dfs(int s) {

  int i = 0;
  vi[s] = true;
  for(i = 1; i <= N; i++) if (arr[s][i] && !vi[i]) dfs(i);
  if (i == N) return;
}

int main() {
  int i, j, src, dest;

  scanf("%d %d", &N, &M);

  for (i = 1; i <= M; i++) {
    scanf("%d %d", &src, &dest);
    arr[src][dest] = 1;
    arr[dest][src] = 1;
  }

  for (i = 1; i <= N; i++) {
    if (!vi[i]) {
      dfs(i);
      cnt++;
    }
  }

  printf("%d\n", cnt);

  return 0;
}