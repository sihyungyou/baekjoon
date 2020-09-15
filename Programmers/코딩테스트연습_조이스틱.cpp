#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int num[len];
    int i, j, left, right, lidx, ridx, change = 0;

    for (i = 0; i < len; i++) {
        char target = name[i];
        num[i] = min(target - 'A', 'Z' - target + 1);
        if (num[i] != 0) change++;
        answer += num[i];
    }

    i = 0;
    int pos = 0;

    if (num[i] != 0) {
        num[i] = 0;
        change--;
    }

    while(change > 0) {

        // 오른쪽 계산
        for (i = pos+1; i < len; i++) {
            if (num[i] != 0) {
                break;
            }
        }

        right = i - pos;
        ridx = i;

        // 왼쪽 계산
        for (i = pos-1; i >= 0; i--) {
            if (num[i] != 0) break;
        }
        if (i < 0) {
            for (j = len-1; j > pos; j--) if (num[j] != 0) break;
            left = pos + (len - j);
            lidx = j;
        } else {
            left = pos - i;
            lidx = i;
        }

        // 이동
        if (left > right) {
            // go right
            answer += right;
            num[ridx] = 0;
            pos = ridx;
        }
        else {
            // go left
            answer += left;
            num[lidx] = 0;
            pos = lidx;
        }

        change--;
    }

    return answer;
}
