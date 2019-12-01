/*
문제
수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.
*/

#include <cstdio>

using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }
int main() {

    int N, i, j, ans = 0;

    scanf("%d", &N);

    int arr[N];
    int dp[N];

    for (i = 0; i < N; i++) scanf("%d", &arr[i]);
    
    for (i = 0; i < N; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if ( arr[i] < arr[j] && dp[i] < dp[j] + 1 ) dp[i] = dp[j] + 1;
        }
    }

    for (i = 0; i < N; i++) ans = get_max(ans, dp[i]);
    
    printf("%d\n", ans);

    return 0;
}