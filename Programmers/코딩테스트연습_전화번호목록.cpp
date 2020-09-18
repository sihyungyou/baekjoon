// O(N^2)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int i = 0;
    int j = 0;
    int len = phone_book.size();
    sort(phone_book.begin(), phone_book.end());

    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (phone_book[j].find(phone_book[i]) != string::npos) {
                answer = false;
                break;
            }
        }
    }
    return answer;
}

// O(N)
#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int i, j, len = phone_book.size();
    map <string, int> m;

    // map에 모든 전화번호들의 모든 substr을 넣는다 -> O(N * 20)
    for (i = 0; i < len; i++) {
        int length = phone_book[i].length();
        for (j = 1; j < length; j++) {
            string temp = phone_book[i].substr(0, j);
            m[temp] = 1;
        }
    }

    // map에서 전화번호를 O(1)로 찾고 있다면 다른 전화번호의 substr이라는 뜻이므로 false, break -> O(N)
    for (i = 0; i < len; i++) {
        map <string, int>::iterator it = m.find(phone_book[i]);
        if (it != m.end()) {
            answer = false;
            break;
        }
    }

    return answer;
}
