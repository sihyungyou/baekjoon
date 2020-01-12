/*
문제
수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.
*/

#include <cstdio>
using namespace std;

int get_max (int a, int b) { return a > b ? a : b; }

int main() {

    int N, i, j, ans = 0;

    scanf("%d", &N);

    int arr[N];
    int dp1[N];
    int dp2[N];
    
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        dp2[i] = arr[i];
    }
    
    ans = dp2[0];

    for (i = 0; i < N; i++) {
        dp1[i] = 1;
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp1[j]+1 > dp1[i]) {
                dp1[i] = dp1[j] + 1;
                dp2[i] = get_max(dp2[i], dp2[j] + arr[i]);
            }
            ans = get_max(ans, dp2[i]);
        }
    }

    printf("%d\n", ans);

    return 0;
}