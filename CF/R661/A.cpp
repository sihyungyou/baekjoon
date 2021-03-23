#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            v.push_back(temp);
        }

        // sort
        sort(v.begin(), v.end());

        // try erase elements
        bool flag = true;
        if (n > 1) {
            while(v.size() > 0) {
                if (abs(v[0] - v[1]) <= 1) {
                    v.erase(v.begin() + 0);
                } else {
                    flag = false;
                    break;
                }
            }    
        }

        flag ? printf("YES\n") : printf("NO\n");
    }


    return 0;
}
