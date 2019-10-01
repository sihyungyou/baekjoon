/*
문제
n개의 정수로 이루어진 임의의 수열이 주어진다.  
우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.  
예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.  

입력  
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.  

출력  
첫째 줄에 답을 출력한다.  
*/

// #include <cstdio>
// #include <algorithm>

// using namespace std;

// int main() {
//     int n, i;
//     long long ans = 0;

//     scanf("%d", &n);
//     long long arr[n];
//     long long dp[n];

//     for (i = 0; i < n; i++) scanf("%lld", &arr[i]);
    
//     dp[0] = arr[0];
//     ans = dp[0];

//     for (i = 1; i < n; i++) {
//         dp[i] = max(dp[i-1] + arr[i], arr[i]);
//         ans = max(ans, dp[i]);
//     }
    
//     printf("%lld", ans);

//     return 0;
// }

#include <cstdio>

using namespace std;
int max(long long a, long long b) { return a > b ? a : b; }

int main() {

    long long dp[100000] = { 0 };
    int arr[100000];
    long long ans = 0;
    int i, n;

    scanf("%d", &n);


    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    dp[0] = arr[0];

    for (i = 1; i < n; i++) {
        if (dp[i-1] > arr[i]) dp[i] = arr[i] + dp[i-1];
        else dp[i] = arr[i];
    }


    for (i = 0; i < n; i++) {
        printf("%lld ", dp[i]);
        ans = max(ans, dp[i]);
    }
    printf("\n%lld\n", ans);

    return 0;
}