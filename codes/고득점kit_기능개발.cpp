#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    printf("solution\n");
    vector<int> answer; 
    queue <int> q;
    
    int bound, rest, day, i, cnt = 0;
    
    for (i = 0; i < progresses.size(); i++) {
        rest = 100 - progresses[i];
        if (rest % speeds[i] == 0) day = rest/speeds[i];
        else day = rest/speeds[i] + 1;
        q.push(day);
    }
    
    bound = q.front();
    
    while(!q.empty()) {
        printf("queue : %d\n", q.front());
        if (q.front() <= bound) {
            cnt++;
            q.pop();
        }
        else {
            bound = q.front();
            answer.push_back(cnt);
            cnt = 0;
        }
    }
    
    return answer;
}

int main () {

    vector <int> a;
    a.push_back(93);
    a.push_back(30);
    a.push_back(55);
    vector <int> b;
    b.push_back(1);
    b.push_back(30);
    b.push_back(5);
    vector <int> c;
    c = solution(a, b);

    for(int i = 0; i < c.size(); i++) printf("%d ", c[i]);
    printf("\n");
    return 0;
}