#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

bool cmp(string a, string b) {
    return a.length() < b.length();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> strings;
    set<int> numbers;

    // {} 를 기준으로 문자열들을 나눈다
    // "{ {2},{2,1},{2,1,3},{2,1,3,4} }"
    int i = 0, j = 0;
    int len = s.length();

    for (i = 1; i < len - 1; i++) {
        string temp;
        if (s[i] == '{') {
            i++;
            while(s[i] != '}') {
                temp += s[i];
                i++;
            }
        }
        if (temp.length() != 0 ) strings.push_back(temp);
    }

    // 그것들을 문자열의 길이 기준으로 오름차순 정렬한다
    sort(strings.begin(), strings.end(), cmp);
    int strings_len = strings.size();

    // 그러므로 문자열들을 탐색하면서 하나씩 없는 원소를 추가해가면 tuple이 완성된다
    for (i = 0; i < strings_len; i++) {
        string cur = strings[i];
        int curlen = cur.length();
        string num = "";
        cout << "cur : " << cur << " cur length : " << cur.length() << endl;
        for (j = 0; j < curlen; j++) {
            if (cur[j] == ',' || j == curlen - 1) {
                cout << "inserting " << num << endl;
                numbers.insert(stoi(num));
                num = "";
            }
            else {
                num += cur[j];
            }
        }
    }

    return answer;
}
