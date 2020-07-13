// https://programmers.co.kr/learn/courses/30/lessons/67256
#include <string>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int keypad[5][4];

pair<int, int> find_coord(int n) {
    int i = 0;
    int j = 0;
    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 3; j++) {
            if (keypad[i][j] == n) return make_pair(i, j);
        }
    }
}
string solution(vector<int> numbers, string hand) {
    int i = 0;
    int j = 0;
    int len = numbers.size();
    string answer = "";
    pair<int, int> left = make_pair(4, 1);
    pair<int, int> right = make_pair(4, 3);


    int num = 1;
    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 3; j++) {
            if (num == 10) num = -1;
            else if (num == 11) num = 0;
            else if (num == 12) num = -2;
            keypad[i][j] = num++;
        }
    }

    for (i = 0; i < len; i++) {
        int press = numbers[i];
        if (press == 1 || press == 4 || press == 7) {
            // 1, 4, 7이면 바로 L을 넣고 왼손 위치를 업데이트
            answer += "L";
            left = find_coord(press);
        }
        else if (press == 3 || press == 6 || press == 9) {
            // 3, 6, 9면 바로 R을 넣고 오른손 위치를 업데이트
            answer += "R";
            right = find_coord(press);
        }
        else {
            // 2, 5, 8, 0이면 왼손으로부터의 거리, 오른손으로부터의 거리를 계산 후, 가까운 쪽을 넣고 위치를 업데이트
            // 만약 거리가 같다면 Hand에 따라 L/R를 넣고 위치를 업데이트
            int lefty = left.first;
            int leftx = left.second;
            int righty = right.first;
            int rightx = right.second;
            pair<int, int> cur = find_coord(press);
            int cury = cur.first;
            int curx = cur.second;
            int left_dist = abs(cury - lefty) + abs(curx - leftx);
            int right_dist = abs(cury - righty) + abs(curx - rightx);

            if (left_dist > right_dist) {
                answer += "R";
                right = cur;
            }
            else if (left_dist < right_dist) {
                answer += "L";
                left = cur;
            }
            else {
                // 거리가 같다
                if (hand == "right") {
                    answer += "R";
                    right = cur;
                }
                else {
                    answer += "L";
                    left = cur;
                }
            }
        }
    }

    return answer;
}
