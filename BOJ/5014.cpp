#include <cstdio>
#include <queue>

using namespace std;

int f, s, g, u, d;
long long answer = 0;
bool visit[1000001] = { false, };
bool arrived = false;

int bfs() {
    if (s == g) {
        arrived = true;
        return 0;
    }

    int count = 0;
    int seg = 1;
    int nextSeg = 1;

    queue<int> q;
    q.push(s);
    visit[s] = true;

    while (seg != 0) {
        seg = nextSeg;
        nextSeg = 0;
        count++;

        for (int i = 0; i < seg; i++) {
            int cur = q.front();
            if (cur == g) {
                arrived = true;
                return count - 1;
            }

            int up = cur + u;
            int down = cur - d;

            q.pop();

            if (up <= f && !visit[up]) {
                visit[up] = true;
                q.push(up);
                nextSeg++;
            }
            if (down > 0 && !visit[down]) {
                visit[down] = true;
                q.push(down);
                nextSeg++;
            }
        }
    }

    return count - 1;
}

int main() {

    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    answer = bfs();
    if (arrived) printf("%lld\n", answer);
    else printf("use the stairs\n");

    return 0;
}
