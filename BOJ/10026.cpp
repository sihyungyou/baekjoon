#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, cnt;
char origMap[100][100];
char specialMap[100][100];
bool visit[100][100];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void clearInfo() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visit[i][j] = false;
        }
    }
}

int bfs(int flag) {
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            queue<pair<int, int> > q;
            if (!visit[i][j]) {
                q.push(make_pair(i, j));
                visit[i][j] = true;

                // bfs
                while(!q.empty()) {
                    pair<int, int> front = q.front();
                    q.pop();

                    int y = front.first;
                    int x = front.second;

                    for (int k = 0; k < 4; k++) {
                        int newy = y + dy[k];
                        int newx = x + dx[k];

                        if (flag == 0) {
                            if (newy >= 0 && newy < n && newx >= 0 && newx < n && !visit[newy][newx] && origMap[newy][newx] == origMap[y][x]) {
                                visit[newy][newx] = true;
                                q.push(make_pair(newy, newx));
                            }
                        }
                        else if (flag == 1) {
                            if (newy >= 0 && newy < n && newx >= 0 && newx < n && !visit[newy][newx] && specialMap[newy][newx] == specialMap[y][x]) {
                                visit[newy][newx] = true;
                                q.push(make_pair(newy, newx));
                            }
                        }
                    }
                }
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            origMap[i][j] = s[j];
            specialMap[i][j] = s[j];
            if (specialMap[i][j] == 'G') specialMap[i][j] = 'R';
            visit[i][j] = false;
        }
    }

    int normal = bfs(0);
    clearInfo();
    int special = bfs(1);

    printf("%d %d\n", normal, special);
    return 0;
}
