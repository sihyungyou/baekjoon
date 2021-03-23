#include <cstdio>
#include <queue>

using namespace std;

struct compare {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    // 기본이 max heap
    priority_queue<int, vector<int>, compare> q;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);

        if (op == 0) {
            if (q.empty()) {
                // if empty -> print 0
                printf("0\n");
            } else {
                // else, pop
                int top = q.top();
                printf("%d\n", top);
                q.pop();
            }
        } else {
            // push op
            q.push(op);
        }
    }


    return 0;
}
