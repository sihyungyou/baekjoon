// O(N) 코드
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    int i, j, k;
    int len = people.size();
    deque <int> dq;

    sort(people.begin(), people.end(), cmp);
    for (i = 0; i < len; i++) dq.push_back(people[i]);

    while(!dq.empty()) {
        int front = dq.front();
        dq.pop_front();
        int temp = front;
        while(!dq.empty()) {
            int back = dq.back();
            if (temp + back <= limit) {
                temp += back;
                dq.pop_back();
            }
            else break;
        }
        answer++;
    }

    return answer;
}


// O(N^2) 코드 (효율성 실패)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    int i, j, k;
    int len = people.size();

    sort(people.begin(), people.end(), cmp);

    for (i = 0; i < len; i++) {
        if (people[i] == -1) continue;
        int temp = people[i];
        people[i] = -1;
        for (j = len - 1; j > i; j--) {
            if (temp + people[j] <= limit && people[j] != -1) {
                temp += people[j];
                people[j] = -1;
            }
        }
        answer++;
    }

    return answer;
}
