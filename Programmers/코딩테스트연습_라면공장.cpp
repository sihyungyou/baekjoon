// 공급 가능일자가 되면 반드시 supplies[i]에 있는 밀가루만큼 공급받아야 한다는 의미가 아니라 이후에 언제든 해당 밀가루만큼 공급받을 수 있다는 의미로 이해해야 한다. <- 띠용탁!?

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int i = 0, j = 0;
    int len = dates.size();
    priority_queue <int, vector<int> > pq;

    for (i = 0; i < k; i++) {

        if (j < len && dates[j] == i) {
            pq.push(supplies[j++]);
        }

        if (stock == 0) {
            stock += pq.top();
            pq.pop();
            answer++;
        }
        stock--;
    }

    return answer;
}
