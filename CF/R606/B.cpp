#include <cstdio>
#include <set>
using namespace std;

int main() {

    int t, n, i, j, temp, a, cnt = 0;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        set<int> s;
        cnt = 0;
        scanf("%d", &n);

        for (j = 0; j < n; j++) {
            scanf("%d", &temp);
            if (temp % 2 == 0) s.insert(temp);
        }

        set<int>::iterator k;
        while(!s.empty()) {
            k = s.end();
            k--;

            a = *k;
            while(a % 2 == 0) {
                s.erase(a);
                a /= 2;
                if (a % 2 == 0)s.insert(a);
                cnt++;
            }
        }

        printf("%d\n", cnt);
        
    }


    return 0;
}