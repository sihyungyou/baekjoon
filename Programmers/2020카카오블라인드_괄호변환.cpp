#include <string>
#include <vector>
#include <stack>

using namespace std;

// 재귀적으로 서로 콜을 하므로 함수선언
bool is_correct(string);
string step1(string);
string step2(string);
pair<string, string> divide_uv(string);
string solution(string);

// 함수 정의
bool is_correct(string p) {
    stack <char> s;
    int i = 0;
    int len = p.length();
    char temp;

    s.push(p[0]);
    for (i = 1; i < len; i++) {
        if (!s.empty()) {
            temp = s.top();
            if (temp == '(' && p[i] == ')') {
                s.pop();
            }
            else {
                s.push(p[i]);
            }
        }
        else {
            s.push(p[i]);
        }
    }

    if (s.empty()) return true;
    else return false;
}

pair<string, string> divide_uv(string p) {
    pair <string, string> temp;
    int right = 0;
    int left = 0;
    int len = p.length();
    int i = 0;
    int j = 0;

    for (i = 0; i < len; i++) {
        if (p[i] == '(') left++;
        else right++;

        if (left == right) break;
    }

    for (j = 0; j <= i; j++) temp.first += p[j];
    for (j = i + 1; j < len; j++) temp.second += p[j];

    return temp;
}

string step1(string p) {
    if (p.length() == 0) return "";
    else if (is_correct(p)) return p;
    else {
        string ans = step2(p);
        return ans;
    }
}

string step2(string p) {
    pair<string, string> div = divide_uv(p);
    string u = div.first;
    string v = div.second;
    int i = 0;
    int ulen = u.length();
    if (is_correct(u)) {
        // step 3
        return u + step1(v);
    }
    else {
        // spte 4
        string newstr = "(";
        newstr += step1(v);
        newstr += ")";
        for (i = 1; i < ulen - 1; i++) {
            if (u[i] == '(') newstr += ")";
            else newstr += "(";
        }
        return newstr;
    }
}

string solution(string p) {
    string answer = "";

    answer = step1(p);

    return answer;
}
