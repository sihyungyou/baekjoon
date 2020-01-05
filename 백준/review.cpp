#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;

int main() {

    priority_queue<pair <int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;    
    int n, i, temp;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp == 0) {
            if (pq.empty()) printf("0\n");
            else {
                printf("%d\n", pq.top().second);
                pq.pop();
            }
        }
        else pq.push(make_pair(abs(temp), temp));
        
    }

    return 0;
}