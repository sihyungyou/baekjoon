#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	int t, a, b, x, y, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d %d", &a, &b, &x, &y, &n);
		int min_a = max(x, a - n);
		int min_b = max(y, b - n);
		int result_a, result_b;
		int rest;
		if (min_a < min_b) {
			result_a = min_a;

			rest = n - (a - result_a);
			result_b = max(y, b - rest);
		}
		else {
			result_b = min_b;

			rest = n - (b - result_b);
			result_a = max(x, a - rest);
		}
		long long ans = (long long)result_a * (long long)result_b;
		printf("%lld\n", ans);
	}

	return 0;
}
