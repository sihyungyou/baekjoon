#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int i, sum = 0, cnt = 0, answer = 0;
    queue <int> wait;
    queue <int> moving;
    
    for (i = 0; i < truck_weights.size(); i++) wait.push(truck_weights[i]);
    for (i = 0; i < bridge_length; i++) moving.push(0);
    
    while(!(wait.empty() && sum == 0)) {
        answer++;
        sum -= moving.front();
        moving.pop();
        if ( !wait.empty() && sum + wait.front() <= weight) {
            sum += wait.front();
            moving.push(wait.front());
            wait.pop();
        } else {
            moving.push(0);
        }
    }
    
    return answer;
}