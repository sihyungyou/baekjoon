#include <cstdio>
#include <set>
using namespace std;

int main() {
    int n, answer = 0;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    set<long long> s;
    s.insert(0);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        // 새로운 값을 더한 결과가 이미 set에 있다는 것은, 새로 더한 값과 기존의 값 사이에 합이 0인 sequence가 있음을 의미함
        if (s.find(sum) != s.end()) {
            answer++;
            s.clear();
            s.insert(0);
            sum = arr[i];
        }
        s.insert(sum);
    }

    printf("%d\n", answer);
    return 0;
}
