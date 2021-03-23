#include <cstdio>
#include <set>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        set<double> s;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = arr[j] - arr[i];
                s.insert(diff * 0.5);
            }
        }

        printf("%lu\n", s.size());
    }


    return 0;
}
