/*
소요시간 : 40분
오래걸린 원인 : y, x 거꾸로 입력받고 a, b 가로세로를 거꾸로 생각함
*/
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

struct Robot {
    int number;
    int y;
    int x;
    char facing;
};

int a, b;
int n, m;
vector<Robot> robots;

bool isCrashWall(int y, int x) {
    // y, x가 각각 a, b 범위를 넘어가는지 확인
    if (y < 1 || y > b || x < 1 || x > a) return true;
    return false;
}

pair<bool, int> isCrashRobot(int robotNum, int y, int x) {
    int len = robots.size();
    for (int i = 0; i < len; i++) {
        if (robots[i].number == robotNum) continue;
        else {
            // 자기 자신이 아니라면 비교한다
            if (robots[i].y == y && robots[i].x == x) {
                // 비교해서 만약 위치가 같다면 부딪힌 것
                return make_pair(true, robots[i].number);
            }
        }
    }

    return make_pair(false, 0);
}

int main() {

    scanf("%d %d", &a, &b);
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        // 로봇의 초기 위치, facing
        int y, x;
        char f;
        scanf("%d %d %c", &x, &y, &f);

        Robot robot = { i, y, x, f};
        robots.push_back(robot);
    }

    for (int i = 0; i < m; i++) {
        // m개의 명령
        int num;
        char op;
        int repeat;
        scanf("%d %c %d", &num, &op, &repeat);

        int len = robots.size();
        for (int r = 0; r < len; r++) {
            if (robots[r].number == num) {
                // 입력한 로봇의 번호와 일치하는 로봇에 대해
                for (int j = 0; j < repeat; j++) {
                    // 입력받은 명령 op릉 repeat번 수행한다
                    if (op == 'L') {
                        // 왼쪽으로 회전
                        if (robots[r].facing == 'E') {
                            robots[r].facing = 'N';
                        } else if (robots[r].facing == 'W') {
                            robots[r].facing = 'S';
                        } else if (robots[r].facing == 'S') {
                            robots[r].facing = 'E';
                        } else if (robots[r].facing == 'N') {
                            robots[r].facing = 'W';
                        }
                    } else if (op == 'R') {
                        // 오른쪽으로 회전
                        if (robots[r].facing == 'E') {
                            robots[r].facing = 'S';
                        } else if (robots[r].facing == 'W') {
                            robots[r].facing = 'N';
                        } else if (robots[r].facing == 'S') {
                            robots[r].facing = 'W';
                        } else if (robots[r].facing == 'N') {
                            robots[r].facing = 'E';
                        }
                    } else if (op == 'F') {
                        // 한칸 앞으로 움직인다
                        if (robots[r].facing == 'E') {
                            robots[r].x++;
                        } else if (robots[r].facing == 'W') {
                            robots[r].x--;
                        } else if (robots[r].facing == 'S') {
                            robots[r].y--;
                        } else if (robots[r].facing == 'N') {
                            robots[r].y++;
                        }

                        // robots[r].y, robots[r].x가 범위를 벗어나는가?
                        if (isCrashWall(robots[r].y, robots[r].x)) {
                            printf("Robot %d crashes into the wall\n", robots[r].number);
                            return 0;
                        }

                        // 다른 로봇과 부딪히는가?
                        pair<bool, int> result = isCrashRobot(robots[r].number, robots[r].y, robots[r].x);
                        if (result.first) {
                            printf("Robot %d crashes into robot %d\n", robots[r].number, result.second);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf("OK\n");

    return 0;
}
