#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

int main() {

    int N, i, temp, cnt = 0;
    vector <int> v;
    v.push_back(INT_MIN);

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &temp);
        if (v.back() < temp) { cnt++; v.push_back(temp);
        } else {
            vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
            *low = temp;
        }
    }

    printf("%d\n", cnt);
    return 0;
}