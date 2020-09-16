// https://velog.io/@giraffelim/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%9C%84%EC%9E%A5 참고
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int i, j, len = clothes.size();
    map <string, int> m;
    map <string, int>::iterator it;

    // 옷의 종류별 개수 파악
    for (i = 0; i < len; i++) {
        string s = clothes[i][1];
        it = m.find(s);
        if (it != m.end()) {
            m[s]++;
        }
        else {
            m[s] = 1;
        }
    }


    for (it = m.begin(); it != m.end(); it++) {
        answer *= (it.second + 1);
    }

    return answer - 1;
}
