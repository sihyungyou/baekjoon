#include <cstdio>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int bookshelf[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &bookshelf[i]);
        }

        int left, right;
        for (int i = 0; i < n; i++) {
            if (bookshelf[i] == 1) {
                left = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (bookshelf[i] == 1) {
                right = i;
                break;
            }
        }

        int answer = 0;
        for (int i = left; i <= right; i++) {
            if (bookshelf[i] == 0) answer++;
        }

        printf("%d\n", answer);
    }

    return 0;
}
