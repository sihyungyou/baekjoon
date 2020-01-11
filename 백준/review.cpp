#include <cstdio>
#include <utility>

using namespace std;

pair<long long, long long> cal(long long r) {
    long long two = 0, five = 0, i;
    for (i = 2; i <= r; i *= 2) two += r/i;
    for (i = 5; i <= r; i *= 5) five += r/i;
    return pair<long long, long long> (two, five);
}

long long get_min(long long a, long long b) { return a < b ? a : b; }

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    pair<long long, long long> ansn;
    pair<long long, long long> ansm;
    pair<long long, long long> ansnm;

    ansn = cal(n);
    ansm = cal(m);
    ansnm = cal(n-m);

    long long t = ansn.first - ansm.first - ansnm.first;
    long long f = ansn.second - ansm.second - ansnm.second;
    printf("%lld\n", get_min(t, f));

    return 0;
}