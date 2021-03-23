#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int x;
        scanf("%d", &x);

        int sum = 0, last = 9;
        vector<int> v;
        while(sum < x && last > 0) {
            v.push_back(min(last, x - sum));
            sum += last;
            last--;
        }

        if (sum < x) printf("-1\n");
        else {
            int len = v.size();
            for (int i = len - 1; i >= 0; i--) printf("%d", v[i]);
            printf("\n");
        }
    }

    return 0;
}
