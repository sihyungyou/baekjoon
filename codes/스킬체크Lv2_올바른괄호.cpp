#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    bool flag = true;
    int cnt = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') cnt++;
        else if (s[i] == ')' && cnt != 0) cnt--;
        else if (s[i] == ')' && cnt == 0) flag = false;
    }

    if (flag && !cnt) answer = true;
    else answer = false;

    return answer;
}