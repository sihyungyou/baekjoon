#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool used[10000] = { false, };
vector<vector<string> > t;
vector<string> answer;
int len;

void dfs(int idx) {
    cout << "visiting " << t[idx][0] << endl;
    int i;
    bool flag = false;

    used[idx] = true;
    answer.push_back(t[idx][0]);

    for (i = 0; i < len; i++) {
        if (t[i][0].compare(t[idx][1]) == 0 && !used[i]) {
            cout << "going to " << t[i][0] << endl;
            flag = true;
            dfs(i);
        }
    }
    if (!flag) {
      answer.push_back(t[idx][1]);
    }
    return;
}

bool cmp(vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> tickets) {

    len = tickets.size();
    int i;

    // second string 기준으로 정렬
    sort(tickets.begin(), tickets.end(), cmp);

    // ICN만 뽑아서 먼저 t에 넣음
    for (i = 0; i < len; i++) {
        if (tickets[i][0].compare("ICN") == 0) t.push_back(tickets[i]);
    }

    // ICN을 제외한 나머지들도 t에 넣음
    for (i = 0; i < len; i++) {
        if (tickets[i][0].compare("ICN") != 0) t.push_back(tickets[i]);
    }

    // 0 -> t.size() dfs 시작
    for (i = 0; i < len; i++) {
        if (!used[i]) dfs(i);
    }

    return answer;
}
