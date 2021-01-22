/*
소요시간 : 33분
특이사항 : map 재배치 시 반복이 아닌 한칸씩만 내렸던 것을 처음부터생각하지 못함, 입력을 string으로 받도록 중간에 변경
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string>

using namespace std;

vector<string> map;
bool visit[12][6];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool bfs() {
    // 현재 라운드에서 터뜨릴 수 있는 것들이 있는지 확인하고, 있으면 터뜨린다
    bool flag = false;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (map[i][j] != '.') {
                vector<pair<int, int> > v;
                queue<pair<int, int> > q;

                visit[i][j] = true;
                q.push(make_pair(i, j));
                v.push_back(make_pair(i, j));

                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    int y = cur.first;
                    int x = cur.second;

                    // 빈칸이 아니라면 자신과 이어진 것들 중 상하좌우로 bfs를 돌아 네 개 이상이면 터뜨린다
                    for (int k = 0; k < 4; k++) {
                        int newy = y + dy[k];
                        int newx = x + dx[k];

                        if (newy >= 0 && newy < 12 && newx >= 0 && newx < 6 && !visit[newy][newx] && map[newy][newx] == map[i][j]) {
                            visit[newy][newx] = true;
                            q.push(make_pair(newy, newx));
                            v.push_back(make_pair(newy, newx));
                        }
                    }
                }
                // 한 점에서 bfs를 돌았을 때 vector에 쌓인게 4개 이상이라면
                int num = v.size();
                if (num >= 4) {
                    flag = true;
                    // vector에 쌓인 모든 곳을 폭파시킨다 (.으로 바꾼다)
                    for (int i = 0; i < num; i++) {
                        pair<int, int> remove = v[i];
                        map[remove.first][remove.second] = '.';
                    }
                }
            }
        }
    }

    return flag;
}

void resetMap() {
    // 두번째로 아래줏부터 현재위치가 문자인데 자신보다 아래가 .이면 (떨어질 여지가 있으면) 자신을 .으로바꾸고 떨군다
    for (int i = 10; i >= 0; i--) {
        for (int j = 0; j < 6; j++) {
            // 모든 문자에 대해서 자기자신보다 한칸 아래가 더이상 .이 아니거나 out of range일 때 까지 반복
            if (map[i][j] != '.') {
                int cury = i;
                while(1) {
                    int nexty = cury + 1;
                    if (nexty == 12 || map[nexty][j] != '.') {
                        break;
                    } else {
                        map[nexty][j] = map[cury][j];
                        map[cury][j] = '.';
                        cury = nexty;
                    }
                }
            }
        }
    }
}

void clearVisit() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            visit[i][j] = false;
        }
    }
}

int main() {

    // 입력
    for (int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }

    int count = 0;
    while(1) {
        clearVisit();

        if (bfs()) {
            // 터뜨린 후 연쇄 카운트를 증가시킨다
            count++;
        } else {
            // 터뜨릴 수 있는게 없다면 break
            break;
        }

        // 맵을 재배치한다
        resetMap();
    }

    cout << count << endl;

    return 0;
}
