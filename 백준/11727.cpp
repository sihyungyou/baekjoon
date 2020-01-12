/*
문제
2×n 직사각형을 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
아래 그림은 2×17 직사각형을 채운 한가지 예이다.

입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
*/

#include <cstdio>

using namespace std;

int dp(int n) {
    int d[n+1];
    d[1] = 1;
    d[2] = 3;

    for (int i = 3; i <= n; i++) d[i] = (d[i-1] + d[i-2] + d[i-2]) % 10007;
    return d[n];
}

int dfs(int n) {
    if (n <= 1) return 1;
    else return dfs(n-1) + dfs(n-2) + dfs(n-2);
}

int main () {

    int n;
    scanf("%d", &n);
    printf("%d\n", dfs(n));

    return 0;
}