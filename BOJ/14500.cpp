#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int map[500][500];
int answer = 0;
int n, m;
vector<vector<int> > dys;
vector<vector<int> > dxs;

void init() {
    vector<int> dy1, dx1;
    dy1.push_back(0);
    dy1.push_back(0);
    dy1.push_back(0);
    dx1.push_back(1);
    dx1.push_back(2);
    dx1.push_back(3);
    dys.push_back(dy1);
    dxs.push_back(dx1);

    vector<int> dy2, dx2;
    dy2.push_back(0);
    dy2.push_back(1);
    dy2.push_back(1);
    dx2.push_back(1);
    dx2.push_back(0);
    dx2.push_back(1);
    dys.push_back(dy2);
    dxs.push_back(dx2);

    vector<int> dy3, dx3;
    dy3.push_back(1);
    dy3.push_back(2);
    dy3.push_back(2);
    dx3.push_back(0);
    dx3.push_back(0);
    dx3.push_back(1);
    dys.push_back(dy3);
    dxs.push_back(dx3);

    vector<int> dy4, dx4;
    dy4.push_back(1);
    dy4.push_back(1);
    dy4.push_back(2);
    dx4.push_back(0);
    dx4.push_back(1);
    dx4.push_back(1);
    dys.push_back(dy4);
    dxs.push_back(dx4);

    vector<int> dy5, dx5;
    dy5.push_back(0);
    dy5.push_back(0);
    dy5.push_back(1);
    dx5.push_back(1);
    dx5.push_back(2);
    dx5.push_back(1);
    dys.push_back(dy5);
    dxs.push_back(dx5);
}

void calculate(vector<int> dy, vector<int> dx) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pair<int, int> a = make_pair(i + dy[0], j + dx[0]);
            pair<int, int> b = make_pair(i + dy[1], j + dx[1]);
            pair<int, int> c = make_pair(i + dy[2], j + dx[2]);
            if (a.first >= 0 && a.first < n &&
                a.second >= 0 && a.second < m &&
                b.first >= 0 && b.first < n &&
                b.second >= 0 && b.second < m &&
                c.first >= 0 && c.first < n &&
                c.second >= 0 && c.second < m) {
                    answer = max(answer, map[i][j] + map[a.first][a.second] + map[b.first][b.second] + map[c.first][c.second]);
                }
        }
    }
}

vector<vector<int> > rotate(vector<int> currentdy, vector<int> currentdx, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < 3; j++) {
            // rotate
            int tempdx[3];
            for (int k = 0; k < 3; k++) {
                tempdx[k] = currentdy[k];
                currentdy[k] = currentdx[k] * -1;
                currentdx[k] = tempdx[k];
            }
            calculate(currentdy, currentdx);
        }
    }

    vector<vector<int> > v;
    v.push_back(currentdy);
    v.push_back(currentdx);
    return v;
}

vector<vector<int> > symmetric(vector<int> currentdy, vector<int> currentdx, int num) {
    if (num == 0) {
        // y 대칭
        for (int i = 0; i < 3; i++) currentdy[i] = currentdy[i] * -1;
    }
    else {
        // x 대칭
        for (int i = 0; i < 3; i++) currentdx[i] = currentdx[i] * -1;
    }

    vector<vector<int> > v;
    v.push_back(currentdy);
    v.push_back(currentdx);
    return v;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // 모든 도형 꼭지점 기준으로 나머지 세 지점의 좌표 설정
    init();

    for (int i = 0; i < 5; i++) {
        // 각각의 도형에 대해
        vector<int> currentdy = dys[i];
        vector<int> currentdx = dxs[i];

        for (int j = 0; j <= 3; j++) {
            // 0번~3번 rotate
            vector<vector<int> > rotated = rotate(currentdy, currentdx, j);
            calculate(rotated[0], rotated[1]);
            // rotate한 결과에 대해 대칭한 것도 계산해야 하므로
            vector<vector<int> > symmetricalY = symmetric(rotated[0], rotated[1], 0);
            calculate(symmetricalY[0], symmetricalY[1]);

            vector<vector<int> > symmetricalX = symmetric(rotated[0], rotated[1], 1);
            calculate(symmetricalX[0], symmetricalX[1]);
        }
    }

    printf("%d\n", answer);
    return 0;
}
