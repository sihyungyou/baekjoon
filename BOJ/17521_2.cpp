#include <cstdio>
using namespace std;

int main() {

    int n;
    // 현금과 코인 개수는 int범위를 넘어갈 수 있음
    long long w, coin = 0;
    scanf("%d %lld", &n, &w);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            // 다음날 오르면 지금 바로 매수
            // newcoin이 int면 WA -> long long / int 계산 결과가 int에 담기지 않을 수 있으므로
            long long newcoin = w / arr[i];
            coin += newcoin;
            w -= newcoin * arr[i];
        }
        else if (arr[i] > arr[i + 1]) {
            // 다음날 떨어지면 지금 바로 매도
            w += coin * arr[i];
            coin = 0;
        }
    }

    w += arr[n - 1] * coin;
    printf("%lld\n", w);
    return 0;
}
