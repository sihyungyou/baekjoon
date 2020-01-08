#include <cstdio>
#include <map>

using namespace std;

int main() {

    int t, T, n, i;

    scanf("%d", &T);

    for (t = 0; t < T; t++) {
        scanf("%d", &n);
        map<int, int> m;

        i = 2;
        while(n != 1) {
            if (n % i == 0) {
                m[i]++;
                n /= i;
                i = 2;
            }
            else i++;
        }

        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++) printf("%d %d\n", it->first, it->second);

    }

    return 0;
}