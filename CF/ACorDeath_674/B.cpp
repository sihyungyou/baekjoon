#include <bits/stdc++.h>
using namespace std;

typedef struct tile {
	int a, b, c, d;
} tile;

int main() {
	int t, n, m;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &m);
		vector<tile> tiles(n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d %d", &tiles[i].a, &tiles[i].b, &tiles[i].c, &tiles[i].d);
		}

		if (m % 2) {
			printf("NO\n");
			continue;
		}

		int check1 = 0, check2 = 0;

		for (int i = 0; i < n; i++) {
			if (tiles[i].b == tiles[i].c) check1 = 1;
		}

        if (check1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
