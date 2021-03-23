/*
소요시간 : 1시간
오래걸린 원인 : 문제 이해를 잘못함. 뱀이 길이를 늘려 머리를 두었을 때 valid 체크를해야했음. (이동을 완료하고 하는 것이 아니라)
*/
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

struct Snake {
    vector<pair<int, int> > body;
    char facing;
};

int main() {
    vector<pair<int, int> > v;
    v.push_back(make_pair(1, 1));
    Snake snake = { v, 'E' };

    int n, k, l;
    scanf("%d", &n);
    scanf("%d", &k);

    int map[101][101];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            map[i][j] = 0; // 비어있는곳 0
        }
    }

    // 사과
    for (int i = 0; i < k; i++) {
        int y, x;
        scanf("%d %d", &y, &x);
        map[y][x] = 1; // 사과는 1
    }

    // 방향 변환 정보
    vector<pair<int, char> > ops;

    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        ops.push_back(make_pair(x, c));
    }

    int second = 0;
    while(1) {
        // 현재 게임 시간에 방향을 바꿔야하는지 확인하고, 바꿔야한다면 바꾼다
        for (int i = 0; i < l; i++) {
            if (ops[i].first == second) {
                // 현재 시간초에 방향변환이 있다면
                if (ops[i].second == 'L') {
                    // 왼쪽
                    if (snake.facing == 'E') {
                        snake.facing = 'N';
                    } else if (snake.facing == 'W') {
                        snake.facing = 'S';
                    } else if (snake.facing == 'S') {
                        snake.facing = 'E';
                    } else if (snake.facing == 'N') {
                        snake.facing = 'W';
                    }
                } else if (ops[i].second == 'D') {
                    // 오른쪽
                    if (snake.facing == 'E') {
                        snake.facing = 'S';
                    } else if (snake.facing == 'W') {
                        snake.facing = 'N';
                    } else if (snake.facing == 'S') {
                        snake.facing = 'W';
                    } else if (snake.facing == 'N') {
                        snake.facing = 'E';
                    }
                }
            }
        }

        // 다음 위치가 이동할 수 있는 위치인지 확인한다
        pair<int, int> head = snake.body[0];
        int heady = head.first;
        int headx = head.second;
        // printf("head : [%d, %d]\n", heady, headx);

        pair<int, int> next;
        if (snake.facing == 'E') {
            next = make_pair(heady, headx + 1);
        } else if (snake.facing == 'W') {
            next = make_pair(heady, headx - 1);
        } else if (snake.facing == 'S') {
            next = make_pair(heady + 1, headx);
        } else if (snake.facing == 'N') {
            next = make_pair(heady - 1, headx);
        }

        int nexty = next.first;
        int nextx = next.second;

        // next가 out of range라면 바로 break
        if (nexty < 1 || nexty > n || nextx < 1 || nextx > n) {
            second++;
            break;
        }

        // 몸을 늘려 이동하려는 곳이 현재 몸과 닿지 않는지 확인한다 <- 이동을 완료하고 검사했던 것이 틀렸던 원인
        int len = snake.body.size();
        bool flag = true;
        for (int i = 0; i < len; i++) {
            if (snake.body[i].first == nexty && snake.body[i].second == nextx) {
                flag = false;
                break;
            }
        }

        if (!flag) {
            second++;
            break;
        }

        // 그렇지 않다면, 이동해본다. 이 때 next에 사과가 있으면 vector 맨 앞에 next만 추가하고, 없다면 한칸씩 모두 옮겨야 한다
        if (map[nexty][nextx] == 1) {
            // 사과가 있다면 사과를 먹고
            map[nexty][nextx] = 0;

            // snake body vector 맨 앞에 next만 insert 한다
            snake.body.insert(snake.body.begin(), next);
        } else {
            // 사과가 없다면 snake body를 한칸씩 땡긴다
            snake.body.insert(snake.body.begin(), next);
            snake.body.pop_back();
        }

        second++;
    }

    printf("%d\n", second);
    return 0;
}
