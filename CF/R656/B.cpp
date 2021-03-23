#include <cstdio>
#include <cstring>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        bool visit[n + 1];
        int a[2 * n];
        int p[n];

        memset(visit, false, sizeof(visit));
        for (int i = 0; i < 2*n; i++) {
            scanf("%d", &a[i]);
        }

        int j = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (!visit[a[i]]) {
                p[j++] = a[i];
                visit[a[i]] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%d ", p[i]);
        }
        printf("\n");
    }
    
    return 0;
}
