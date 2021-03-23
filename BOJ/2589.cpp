#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int answer = 0;
int r, c;
char map[50][50];
bool visit[50][50] = { false, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int bfs(int y, int x) {
    int count = 0;
    queue<pair<int, int> > q;
    int seg = 0, tempseg = 0;

    q.push(make_pair(y, x));

    tempseg = 1;
    seg = tempseg;

    while(!q.empty()) {
        count++;
        seg = tempseg;
        tempseg = 0;

        for (int i = 0; i < seg; i++) {
            pair<int, int> current = q.front();
            int currenty = current.first;
            int currentx = current.second;

            q.pop();
            visit[currenty][currentx] = true;

            for (int k = 0; k < 4; k++) {
                int newy = currenty + dy[k];
                int newx = currentx + dx[k];

                if (newy >= 0 && newy < r && newx >= 0 && newx < c && map[newy][newx] == 'L' && !visit[newy][newx]) {
                    visit[newy][newx] = true;
                    q.push(make_pair(newy, newx));
                    tempseg++;
                }
            }
        }
    }

    return count - 1;
}

void clearVisitMap() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            visit[i][j] = false;
        }
    }
}

int main() {

    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++) {
        char str[50];
        scanf("%s", str);
        for (int j = 0; j < c; j++) {
            map[i][j] = str[j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 'L') {
                clearVisitMap();
                answer = max(answer, bfs(i, j));
            }
        }
    }

    printf("%d\n", answer);
    return 0;
}
