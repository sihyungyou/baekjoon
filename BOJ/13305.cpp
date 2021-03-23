#include <cstdio>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    long long answer = 0;
    long long distance[n - 1];
    long long price[n];

    for (int i = 0; i < n - 1; i++) scanf("%lld", &distance[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &price[i]);

    for (int i = 0; i < n - 1; i++) {
        answer += distance[i] * price[i];
        int next = i + 1;
        while(next < n - 1 && price[i] < price[next]) {
            answer += distance[next] * price[i];
            next++;
        }
        i = next - 1;
    }

    printf("%lld\n", answer);

    return 0;
}
