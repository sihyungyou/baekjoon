#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int cnt = 0;
    
    for (int i = 0; i < arrangement.length(); i++) {
        if (arrangement[i] == '(') {
            if (arrangement[i+1] == '(') {
                cnt++;
            }
            else if (arrangement[i+1] == ')') {
                answer += cnt;
                i++;
            }
        }
        else if (arrangement[i] == ')') {
            answer++;
            cnt--;
        }
    }
    
    return answer;
}