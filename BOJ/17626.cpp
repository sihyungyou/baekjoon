#include <cstdio>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    vector<int> ones;
    int arr[n + 1];

    // 모든 수에 대해 필요한 제곱수 개수를 max값으로 초기화
    for (int i = 0; i <= n; i++) arr[i] = INT_MAX;

    for (int i = 1; i <= sqrt(n); i++) {
        // 하나의 제곱수로 표현 가능한 수들 : 1, 4, 9, 16, 25 ... 은 따로 모아놓고 1로 표시
        ones.push_back(i * i);
        arr[i * i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < ones.size(); j++) {
            // 모든 수 i에 대해서 하나의 제곱수로 표현 가능한 수와 조합했을 때 제곱수가 총 몇개 필요한지 검사
            if (ones[j] < i) {
                arr[i] = min(arr[i], arr[ones[j]] + arr[i - ones[j]]);
            } else {
                break;
            }
        }
    }

    printf("%d\n", arr[n]);
    return 0;
}
