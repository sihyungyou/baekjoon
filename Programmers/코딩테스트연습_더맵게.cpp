#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int i = 0;
    int len = scoville.size();
    int least = 0;
    int second_least = 0;
    int new_spicy = 0;

    priority_queue <int, vector<int>, greater<int> > pq;
    for (i = 0; i < len; i++) pq.push(scoville[i]);

    while(!pq.empty()) {
        if (!pq.empty()) {
          least = pq.top();
          if (least < K) {
              pq.pop();
              if (!pq.empty()) {
                second_least = pq.top();
                pq.pop();
                new_spicy = least + (second_least * 2);
                pq.push(new_spicy);
                answer++;
              }
              else {
                answer = -1;
                break;
              }
          } else {
              break;
          }
        }
    }

    return answer;
}
