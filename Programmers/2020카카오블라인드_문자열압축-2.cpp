#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
    int len = s.length();
    int half = len / 2;
    int unit = 1;
    int answer = len;

    // 문자를 자르는 단위가 1부터 len/2까지 반복된다
    for (unit = 1; unit <= half; unit++) {
        string temp = "";
        string prev = "";
        int sequence = 0;

        // 문자를 자르는 단위가 결정되었으면, 처음부터 문자를 읽어나가면서 앞과 같은지 확인한다
        for(int pos = 0; pos < len; pos += unit) {
            string current = s.substr(pos, unit);

            // 첫 문자열이거나 previous 문자열과 같다면 sequence++
            if (prev == "" || current == prev) { sequence++; }
            else {
                // 다르다면 sequence를 문자로 변환하여 temp에 붙인다
                if (sequence > 1) {
                    // 이 때, 2이상일 때만 누적길이를 문자열로 변환하여 붙인다
                    string accLength = to_string(sequence);
                    temp += accLength;
                }
                // 그리고 현재까지 같았던 문자열 (prev)를 temp에 붙인다
                temp += prev;
                sequence = 1;
            }
            prev = current;
        }
        // 만약 length까지 모두 봤으면 마지막 prev에 대해서도 위와 동일하게 temp에 붙여준다
        if (sequence > 1) {
            temp += to_string(sequence);
        }
        temp += prev;

        // 완성된 temp의 길이를 구하고 min을 계산하여 업데이트한다
        answer = min(answer, (int)temp.length());
    }

    return answer;
}
