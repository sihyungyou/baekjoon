/*
180814 2667 apartment
1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다.
여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다.

입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
*/

#include <cstdio>
using namespace std;

int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};
int arr[26][26] = { 0, };
bool vi[26][26] = { false, };
int cnt;

void dfs(int i, int j) {
  cnt++;
  v[i][j] = true;

  int k; 
  
  for (k = 0; k < 4; k++) {

  }
}

int main() {
  int i, j, N;
  scanf("%d", &N);

  for (i = 1; i < N; i++) for (j = 1; j < N; j++) scanf("%d", &arr[i][j]);

  for (i = 1; i < N; i++) {
    for (j = 1; j < N; j++) {
      if (arr[i][j] && !vi[i][j]) {
        cnt = 0;
        dfs(i, j);
      }
    }
  }


  return 0;
}