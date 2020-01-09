#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int n, b;
    stack<int> s;

    scanf("%d %d", &n, &b);

    while(n != 0) {
        s.push(n % b);
        n /= b;
    }

    while(!s.empty()) {
        if (s.top() > 9) printf("%c", s.top() + 55);
        else printf("%d", s.top());
        s.pop();
    }
    
    printf("\n");

    return 0;
}