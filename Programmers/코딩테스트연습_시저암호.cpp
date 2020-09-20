#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int i = 0;
    int len = s.length();

    for (i = 0; i < len; i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            // upper letter
            if (s[i] + n > 90) {
                s[i] = s[i] + n - 26;
            }
            else {
                s[i] += n;
            }
        }
        else if (s[i] >= 97 && s[i] <= 122) {
            // lower letter
            if (s[i] + n > 122) {
                s[i] = s[i] + n - 26;
            }
            else {
                s[i] += n;
            }
        }
        // space
        answer += s[i];
    }

    return answer;
}

// s[i] += n을 해놓고 그게 122를 넘어가는지 검사하면 안됨.
// 왜냐면 아예 ASCII를 넘어가서 이상한 값이 들어가버릴 수 있기 때문 (단순히 int계산이 아니므로)
