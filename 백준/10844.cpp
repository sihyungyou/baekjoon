/*
문제
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
*/


// #include <cstdio>

// using namespace std;

// int main() {
//     int ans = 0;
//     int N, i, j;
//     int dp[100][12] = { 0 };
//     scanf("%d", &N);

//     for (i = 2; i < 11; i++) dp[0][i] = 1;

//     for (i = 1; i < N; i++) {
//         dp[i][0] = 0;
//         dp[i][11] = 0;
//         for (j = 1; j < 11; j++) {
//             dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
//         }
//     }

//     for (i = 1; i < 11; i++) {
//         ans = (ans + dp[N-1][i]) % 1000000000;
//     }

//     printf("%d\n", ans);

//     return 0;
// }

#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

int a[2][12];

int main() {
    int n, ans = 9;
    
    scanf("%d", &n);
    
    for(int i = 2; i < 11; i++)
        a[1][i] = 1;
    
    for(int i = 2; i <= n; i++) {
        ans = 0;
        for(int j = 1; j < 11; j++) {
            a[i%2][j] = (a[(i-1)%2][j-1] + a[(i-1)%2][j+1]) % MOD;
            ans = (ans + a[i%2][j]) % MOD;
        }
    }
    
    printf("%d", ans);
    
    return 0;
}