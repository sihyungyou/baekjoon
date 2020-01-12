/*
문제  
자연수 N과 정수 K가 주어졌을 때 이항 계수를 10007로 나눈 나머지를 구하는 프로그램을 작성하시오.  

입력  
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 1000, 0 ≤  K ≤ N)  

출력  
nCk를 10007로 나눈 나머지를 출력한다.   
*/

#include <cstdio>

using namespace std;

#define MOD 10007

int main() {

    int N, K, i, j;

    scanf("%d %d", &N, &K);
    int dp[N+1][K+1];

    for (i = 0; i <= N; i++) {
        for (j = 0; j <= K; j++) {
            if (i == j || j == 0) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j-1] % MOD) + (dp[i-1][j] % MOD);
                dp[i][j] %= MOD;
            }
        }
    }

    printf("%d\n", dp[N][K]);

    return 0;
}