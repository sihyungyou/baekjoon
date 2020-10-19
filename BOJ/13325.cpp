#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int k;
int maxValue = 0;
vector<int> maxPaths;
vector<long long> paths;

int main() {

    int i, j, cnt = 0;
    scanf("%d", &k);

    // paths.push_back(0); // 첫 인덱스 사용x

    i = 1;
    while(i <= k) {
        for (j = 0; j < pow(2, i); j++) cnt++;
        i++;
    }

    int orig[i + 1];
    // int [i + 1];
    for (i = 1; i <= cnt; i++) {
        scanf("%d", &orig[i]);
    }

    for (i = cnt; i > 0; i -= 2) {
        int parent = i / 2;
        int parentValue = orig[parent];
        parentValue = max(parentValue + orig[i], parentValue + orig[i-1]);
        maxValue = max(maxValue, parentValue);
    }

    printf("max : %d\n", maxValue);

    return 0;
}
