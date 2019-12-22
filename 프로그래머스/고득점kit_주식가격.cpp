#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue <int> q;
    int i, j, cur, cnt = 0;
    
    for (i = 0; i < prices.size(); i++) q.push(prices[i]);
    
    i = 0;
    while(!q.empty()) {
        cnt = 0;
        cur = q.front();
        q.pop();
        for (j = i+1; j < prices.size(); j++) {
            if (cur > prices[j]) {
                cnt++;
                break;
            }
            cnt++;
        }
        answer.push_back(cnt);
        i++;
    }
    return answer;
}