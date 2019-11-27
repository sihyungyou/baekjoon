/*
문제
N×M크기의 배열로 표현되는 미로가 있다.  

1	0	1	1	1	1  
1	0	1	0	1	0  
1	0	1	0	1	1  
1	1	1	0	1	1  

미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.  

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.  

입력  
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.  

출력  
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.  
*/

#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int N, M;
int check[100][100] = { 0, };
bool v[100][100] = { false, };
string arr[100];
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

void bfs(int i, int j) {
    v[i][j] = true;
    
    queue<pair<int, int> > q;
    q.push(make_pair(i,j));

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();

        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if (0 <= newX && newX < M && 0 <= newY && newY < N && arr[newY][newX] == '1' && !v[newY][newX] && check[newY][newX] == 0) {
                check[newY][newX] = check[y][x] + 1;
                v[newY][newX] = true;
                q.push(make_pair(newY, newX));
            }
        }
    }

}

int main() {

    int i;

    cin >> N >> M;
    for (i = 0; i < N; i++) cin >> arr[i];

    bfs(0, 0);
    printf("%d\n", check[N-1][M-1]+1);

    return 0;
}