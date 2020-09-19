#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int i = 0;
    int len = s.length();
    stack <char> st;

    st.push(s[0]);
    for (i = 1; i < len; i++) {
        if (!st.empty()) {
            char temp = st.top();
            if (temp == '(' && s[i] == ')') st.pop();
            else st.push(s[i]);
        }
        else st.push(s[i]);
    }

    if (!st.empty()) answer = false;
    return answer;
}
