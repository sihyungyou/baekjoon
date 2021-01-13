#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define LEFT 0
#define RIGHT 1

int cache[2000][2000];
int cards[2000][2000];
int n;

int dfs(int leftIdx, int rightIdx) {
    if (leftIdx >= n || rightIdx >= n) return 0;

    int discardLeft = 0, discardRight = 0, discardBoth = 0;

    if (leftIdx + 1 < n && cache[leftIdx + 1][rightIdx] != -1) discardLeft = cache[leftIdx + 1][rightIdx];
    else discardLeft = dfs(leftIdx + 1, rightIdx);

    if (leftIdx + 1 < n && rightIdx + 1 < n && cache[leftIdx + 1][rightIdx + 1] != -1) discardBoth = cache[leftIdx + 1][rightIdx + 1];
    else discardBoth = dfs(leftIdx + 1, rightIdx + 1);

    if (cards[LEFT][leftIdx] > cards[RIGHT][rightIdx]) {
        // 오른쪽만 버려서 점수를 얻을 수 있는 경우
        if (rightIdx + 1 < n && cache[leftIdx][rightIdx + 1] != -1) discardRight = cache[leftIdx][rightIdx + 1] + cards[RIGHT][rightIdx];
        else discardRight = dfs(leftIdx, rightIdx + 1) + cards[RIGHT][rightIdx];
    }

    // 왼쪽만 버리는 경우, 오른쪽만 버리는 경우, 양쪽 모두 버리는 경우 중 가장 큰 값을 취한다
    // 여기서 discardRight + cards[RIGHT][rightIdx]로 비교하면 안됨! 오른쪽을 버릴 수 없는데도 버린 효과를 가져오기 때문!
     return cache[leftIdx][rightIdx] = max(discardRight, max(discardLeft, discardBoth));
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cache[i][j] = -1;

    for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) scanf("%d", &cards[i][j]);

    printf("%d\n", dfs(0, 0));

    return 0;
}
