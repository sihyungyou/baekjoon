/*
문제
nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n, m(0≤m≤n≤2,000,000,000, n!=0)이 들어온다.

출력
첫째 줄에 0의 개수를 출력한다.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

pair<long long, long long> zeros (long long n) {
    long long two = 0, five = 0, i = 0;
    for (i = 2; i <= n; i *= 2) two += n / i;
    for (i = 5; i <= n; i *= 5) five += n / i;
    return (pair <long long, long long> (two, five));
}

int main () {
    int n, r;
    pair<long long, long long> ansn, ansr, ansnr;
    long long t, f;

    
    scanf("%d %d", &n, &r);

    ansn = zeros(n);
    ansr = zeros(r);
    ansnr = zeros(n-r);

    t = ansn.first - ansr.first - ansnr.first;
    f = ansn.second - ansr.second - ansnr.second;

    printf("%lld\n", min(t,f));

    return 0;
}