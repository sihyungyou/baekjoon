#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    s += " ";
    int len = s.length();
    int mi = INT_MAX;
    int ma = INT_MIN;
    int i;

    for (i = 0; i < len; i++) {
        string temp;
        if (s[i] == '-') {
            // 음수 공백일때까지
            while(s[i] != ' ') {
                temp += s[i];
                i++;
            }
        }
        else if (isdigit(s[i])){
            // 음수 아닌 숫자
            while(s[i] != ' ') {
                temp += s[i];
                i++;
            }
        }

        int int_temp = stoi(temp);
        mi = min(mi, int_temp);
        ma = max(ma, int_temp);
    }

    answer += to_string(mi);
    answer += " ";
    answer += to_string(ma);

    return answer;
}
