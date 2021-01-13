#include <cstdio>

using namespace std;

int arr[1001];
bool visit[1001];

bool find_cycle(int from) {
    visit[from] = true;

    if (visit[arr[from]]) return true;
    return find_cycle(arr[from]);
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);


        for (int i = 1; i <= n; i++) {
            int num;
            scanf("%d", &num);

            arr[i] = num;
            visit[i] = false;
        }

        int answer = 0;
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                // find cycle
                if (find_cycle(i)) answer++;
            }
        }

        printf("%d\n", answer);

    }

    return 0;
}
