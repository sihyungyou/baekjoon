/*
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.
*/

#include <cstdio>
#include <cstring>
using namespace std;

int get_max (int a, int b) { return a > b ? a : b; }
int get_min (int a, int b) { return a < b ? a : b; }

int main() {
    char arr1[1001];
    char arr2[1001];
    // int dp1[1001];
    // int dp2[1001];

    int i, j, len, ans = 0;
    len = __INT_MAX__;

    scanf("%s", arr1);
    scanf("%s", arr2);

    len = get_min(strlen(arr1), strlen(arr2));
    dp1[len];
    dp2[len];

    for (i = 0; i < len; i++) {
        dp1[i] = 1;
        for (j = 0; j <= i; j++) {
            dp2[i] = 0;
            if (arr1[i] == arr2[j] && dp1[j] + 1 > dp1[j] && dp2[j] < dp2[i]) {
                dp1[i] = dp1[j] + 1;
                dp2[i] = j;
            }
        }
    }

    for (i = 0; i < len; i++) ans = get_max(ans, dp1[i]);
    printf("%d\n", ans);

    return 0;
}