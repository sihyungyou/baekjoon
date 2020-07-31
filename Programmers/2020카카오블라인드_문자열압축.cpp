#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    int fraction = 0;
    int i = 0;
    string cur;
    string prev;

    answer = len;

    for (fraction = 1; fraction <= len/2; fraction++) {
        string temp;
        int pos = 0;
        int cnt = 0;
        prev = "";
        while(pos < len) {
            cur = "";
            // fraction 길이 만큼 문자열을 만든다
            for (i = 0; i < fraction; i++) if (pos + i < len) cur += s[pos + i];

            // 완전 처음 시작이거나 이전의 문자열과 같다면 cnt를 올린다
            if (cur == prev || prev == "") {
                cnt++;
            }

            // 처음시작이 아니고 이전의 문자열과 다르다면 이전까지의 문자열을 저장하고 cnt를 처음으로 낮춘다
            else {
                if (cnt != 1) temp += to_string(cnt);
                temp += prev;
                cnt = 1;
            }

            // 비교가 끝난 후에는 추후 비교를 위해 이전 문자열에 현재 문자열을 담아놓는다
            prev = cur;

            // 그리고 문자열에서의 포지션을 옮긴다
            pos += fraction;
        }

        // 포지션이 fraction만큼 옮겨갔는데 len을 넘었을 경우, 즉 끝났을 경우 남아있는 문자열을 그대로 붙인다
        if (cnt != 1) temp += to_string(cnt);
        temp += cur;

        // 길이를 비교하여 답을 업데이트한다
        int l = temp.length();
        answer = min(answer, l);
    }

    return answer;
}
