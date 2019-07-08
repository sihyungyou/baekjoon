/*
문제
nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n, m(0≤m≤n≤2,000,000,000, n!=0)이 들어온다.

출력
첫째 줄에 0의 개수를 출력한다.
*/

#include <cstdio>

using namespace std;

// int comb(int n, int k) {
// 	if( n == k || k == 0) return 1;
// 	else return comb(n-1, k-1) + comb(n-1, k);
// }

long comb_dp(int n, int k) {
	long arr[n+1][k+1];
	int i, j = 0;

	for(i = 0; i < n; i++)
		for(j = 0; j < k; j++)
			arr[i][j] = 0;

	for(i = 0; i <= n; i++) {
		for(j = 0; j <= k; j++) {
			if ( i == j || j == 0) arr[i][j] = 1;
			else arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
		}
	}

	return arr[n][k];
}

int main () {
    
    int n, r, ans, cnt, remainder = 0; 
    cnt = 0;
    
    scanf("%d %d", &n, &r);
    ans = comb_dp(n, r);

    while(!remainder) {
        cnt++;
        // printf("remainder : %d\n", remainder);
        remainder = ans%10;
        ans /= 10;
    }
    printf("%d\n", cnt-1);

    return 0;
}