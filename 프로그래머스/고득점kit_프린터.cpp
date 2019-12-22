#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int i, j, temp, flag, order = 0;
    
    queue<int> q;
    for (i = 0; i < priorities.size(); i++) q.push(priorities[i]);
    
    int idx = 0;
    
    while(!q.empty()) {
        flag = 1;
        temp = q.front();
        q.pop();
        for (j = idx + 1; j < priorities.size(); j++) {
            if (temp < priorities[j]) {
                q.push(temp);
                priorities.push_back(temp);
                flag = 0;
                break;
            }   
        }
        if (idx == location) {
            if (!flag) location += q.size();
            else { order++; break; }
        } else {
            if (flag) order++;
        }
        
        idx++;
    }
    
    return order;
}