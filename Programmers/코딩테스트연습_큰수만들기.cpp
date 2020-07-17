#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length();
    int return_len = len - k;
    int i = 0;
    int idx = 0;
    char num;

    while(return_len > 0) {
        num = '0';
        for (i = idx; i < len - return_len + 1; i++) {
            if (number[i] > num) {
                idx = i+1;
                num = number[i];
            }
        }
        return_len--;
        answer += num;
    }

    return answer;
}
