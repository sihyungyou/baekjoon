#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n, w, l, time = 0, weight = 0;
    queue<int> waiting;
    queue<int> moving;


    scanf("%d %d %d", &n, &w, &l);

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        waiting.push(temp);
    }

    for (int i = 0; i < w; i++) moving.push(0);

    // 아직 건너야 할 트럭이 남았거나 건너고 있는 트럭이 있을 경우 (무게가 0이 아닐 경우)
    while(!waiting.empty() || weight != 0) {
        // 어떤 액션을 취하든 시간은 흐름
        time++;
        // 현재 다리에 새로운 트럭이 들어오든 들어오지 않든 시간이 지나면 반드시 트럭은 한칸씩 움직인다
        // 다리를 실제로 트럭이 올라와있지 않더라도 무게가 0인 트럭으로 채웠다고 생각한다면 매 시간 다리에서 트럭이 pop 되는 것과 동일하다
        weight -= moving.front();
        moving.pop();

        // 아직 옮겨야할 트럭이 있고 가장 앞의 트럭을 올려도 무게를 견딜 수 있다면
        if (!waiting.empty() && waiting.front() + weight <= l) {
            // 다리로 트럭을 올린다
            moving.push(waiting.front());
            weight += waiting.front();
            waiting.pop();
        } else {
            // 새로운 트럭이 다리로 못 온다고 해도 다리 내부는 한 칸씩 움직여야 한다
            moving.push(0);
        }
    }

    printf("%d\n", time);
    return 0;
}
