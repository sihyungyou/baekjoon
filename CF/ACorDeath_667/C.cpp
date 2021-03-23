#include <cstdio>

using namespace std;

int main() {
	int x, y, n, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &x, &y);
		int d, start;
		for (d = 1; d <= (y - x); d++) {
			if ((y - x) % d == 0 && n >= (y - x) / d + 1) {
				break;
			}
		}

		start = x;
		while (start - d > 0 && (start - d) + d * (n - 1) >= y) start -= d;
		for (int i = 0; i < n; i++) {
			printf("%d ", start + (d * i));
		}
		puts("");
	}

	return 0;
}
