/*
어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 그 배추들 역시 해충으로부터 보호받을 수 있다.
(한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있다고 간주한다)

입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다.
그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50),
그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다.
그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다.

출력
각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.
*/

#include <cstdio>

using namespace std;

int N, M, cnt = 0;
int arr[50][50] = { 0, };
bool vi[50][50] = { false, };
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void init() {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      vi[i][j] = false;
      arr[i][j] = 0;
    }
  }
}

void dfs(int x, int y) {
  vi[x][y] = true;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
    if (arr[nx][ny] && !vi[nx][ny]){
      dfs(nx, ny);
    }
  }

}

int main() {

  int T, K, i, j, t, k, row, col;

  scanf("%d", &T);

  for (t = 0; t < T; t++) {
    cnt = 0;
    scanf("%d %d %d", &M, &N, &K);

    for (k = 0; k < K; k++) {
      scanf("%d %d", &row, &col);
      arr[col][row] = 1;
    }

    // dfs
    for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++) {
        if(arr[i][j] && !vi[i][j]) {
          dfs(i, j);
          cnt++;
        }
      }
    }
    printf("%d\n", cnt);
    init();
  }


  return 0;
}