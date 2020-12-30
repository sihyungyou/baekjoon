#include <string>
#include <queue>

using namespace std;

int divideIntoTwoStrings(string str) {
    // 균형잡힌 두 문자열로 쪼갠다
    // 단, 하나는 더이상 쪼개질 수 없어야 하므로 균형잡힌 문자열의 최소조건을 만족하는 순간 그 다음 index부터 나머지 문자열이 v가된다
    int left = 0;
    int right = 0;
    int len = str.length();

    for (int i = 0; i < len; i++) {
        if (str[i] == '(') left++;
        else right++;
        if (left == right) return i + 1;
    }
}

bool isRightString(string str) {
    // 올바른 괄호 문자열인지 검사
    // 단순한 left, right 개수가 아니라 짝이 맞아야 함
    // 큐를 사용해서 검사
    queue<char> q;
    int len = str.length();

    q.push(str[0]);
    for (int i = 1; i < len; i++) {
        char currentFront = q.front();
        if (currentFront == '(' && str[i] == ')') {
            q.pop();
        } else {
            q.push(str[i]);
        }
    }

    if (q.empty()) return true;
    return false;
}

string solution(string p) {
    string answer = "";

    if (p == "") return answer;

    // 처음으로 나눠보고
    int idx = divideIntoTwoStrings(p);
    string u = p.substr(0, idx);
    string v = p.substr(idx /*, p.length() - idx */ );

    if (isRightString(u)) {
        // 처음 나눴는데 u가 올바른 괄호 문자열이면 v에 대해서 재귀적으로 수행한 후 뒤에 붙이기만 하면 됨
        answer = u + solution(v);
    }
    else {
        // u가 올바른 괄호 문자열이 아니라면 문제에서 주어진 알고리즘 흐름에 따라 진행
        answer += "(";
        answer += solution(v);
        answer += ")";
        for (int i = 1; i < u.length() - 1; i++) {
            if (u[i] == '(') answer += ")";
            else answer += "(";
        }
    }

    return answer;
}
