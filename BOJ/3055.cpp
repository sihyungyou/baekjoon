#include <cstdio>
#include <utility>

using namespace std;

int r, c;
char map[50][50];
pair<int, int> dest;
pair<int, int> src;

int main() {

    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%c", &map[i][j]);
            if (map[i][j] == 'S') {
                src = make_pair(i, j);
            } else if (map[i][j] == 'D') {
                dest = make_pair(i, j);
            }
        }
    }


    return 0;
}
