#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 1;
    int i, w = 0;
    sort(people.begin(), people.end());
    
    for (i = 0; i < people.size()-1; i++) {
        if (w + people[i] <= limit) {
            w += people[i];
        }
        else {
            answer++;
            w = people[i];
        }
    }
    
    return answer;
}