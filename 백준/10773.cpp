#include <cstdio>
#include <stack>
using namespace std;

int main() {

    stack <int> s;
    int N, i, temp, sum = 0;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &temp);
        if (temp == 0) s.pop();
        else s.push(temp);
    }

    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }

    printf("%d\n", sum);
    return 0;
}