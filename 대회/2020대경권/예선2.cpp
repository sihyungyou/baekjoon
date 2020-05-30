/* 81 / 100 */
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int solution(int n, int m, vector<vector<int>> dusts, vector<vector<int>> walls, vector<string> winds) {
  vector< vector<int> > temp;
    int answer = 0;
    int i, j;
    int dustlen = dusts.size();
    int walllen = walls.size();
    int windlen = winds.size();

    // 맵 초기화
    int map[501][501] = { 0, };

    // dust = 1, wall = 2로 설정
    for (i = 0; i < dustlen; i++) {
        map[dusts[i][0]][dusts[i][1]] = 1;
    }
    for (i = 0; i < walllen; i++) {
        map[walls[i][0]][walls[i][1]] = 2;
    }

    // 바람 traverse하면서 옮기면 됨

    for (i = 0; i < windlen; i++) {
        int nx = 0;
        int ny = 0;
        if (winds[i] == "E") nx = -1;
        else if (winds[i] == "W") nx = 1;
        else if (winds[i] == "S") ny = -1;
        else if (winds[i] == "N") ny = 1;

        // dusts <- temp
        for (j = 0; j < temp.size(); j++) {
            dusts.push_back(temp[j]);
        }

        temp.clear();
        
        int newdustlen = dusts.size();
        for (j = 0; j < newdustlen; j++) {
            // 현재 있는 먼지들에 대해 움직일 수 있는 것들에 대해서만 움직이고 answer++

            int newy = dusts[j][0] + ny;
            int newx = dusts[j][1] + nx;

            if (newx > 0 && newx <= m && newy > 0 && newy <= n && map[newy][newx] == 0) {
                map[newy][newx] = 1;
                vector<int> nv;
                nv.push_back(newy);
                nv.push_back(newx);
                temp.push_back(nv);
                answer++;
            }
        }
    }

    return answer + dustlen;
}
