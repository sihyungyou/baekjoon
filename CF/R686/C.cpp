#include <cstdio>
#include <climits>
#include <map>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int arr[n];
        map<int, int> m;
        int answer = INT_MAX;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            m.insert(make_pair(arr[i], 1));
        }

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && arr[i] != arr[i + 1]) {
                m[arr[i]]++;
            }
        }
        m[arr[0]]--;

        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            answer = min(answer, it -> second);
        }

        printf("%d\n", answer);
    }


    return 0;
}
