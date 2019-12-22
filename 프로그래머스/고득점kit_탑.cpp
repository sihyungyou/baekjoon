#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack <int> s;
    int len = heights.size()+1;
    int newh[len];
    newh[0] = 0;
    int i, j, flag;
    
    for (i = 0; i < len; i++) newh[i+1] = heights[i];
    
    for (i = len-1; i > 0; i--) {
        flag = 1;
        for (j = i-1; j >= 0; j--) {
            if (newh[i] < newh[j]) { s.push(j); flag = 0; break; }
        }
        if (flag) s.push(0);
    }
    
    while(!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    
    return answer;
}