/*
걍 몰랐다. 공부하자
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') return true;
    return false;
}

bool isHigherPriority(char a, char b) {
    if (a == '+' || a == '-') {
        if (b == '*' || b == '/' || b == '+' || b == '-') return true;
    } else if (a == '*' || a == '/') {
        if (b == '*' || b == '/') return true;
    }

    return false;
}

int main() {
    string str;

    cin >> str;

    int len = str.length();

    string answer = "";
    stack<char> s;

    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            // stack에 넣는다
            s.push(str[i]);
        } else if (str[i] == ')') {
            // 열린 괄호를 만날 때까지 모두 pop한다
            // 괄호도 pop한다
            while(!s.empty() && s.top() != '(') {
                answer += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(str[i])) {
            // 우선순위를 비교하여 스택에 넣는다
            while(!s.empty() && isHigherPriority(str[i], s.top())) {
                // true라는 것은 top의 우선순위가 str[i]과 같거나 더 높다는 뜻
                answer += s.top();
                s.pop();
            }
            s.push(str[i]);
        } else {
            // answer에 추가한다
            answer += str[i];
        }
    }

    while(!s.empty()) {
        answer += s.top();
        s.pop();
    }

    cout << answer << endl;

    return 0;
}
