#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, m;
int arr[8];
int printarr[8];
set<vector<int> > s;

void dfs(int cnt) {

    if (cnt == m) {
        // 개수가 모두 찼다면 m개 출력
        vector<int> temp;
        for (int i = 0; i < m; i++) temp.push_back(printarr[i]);

        if (s.insert(temp).second) {
            for (int i = 0; i < m; i++) printf("%d ", temp[i]);
            printf("\n");
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        // i는 방문하려는 노드의 인덱스인데, 중복가능 + 비내림차순 미적용
        printarr[cnt] = arr[i];
        dfs(cnt + 1);
    }
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    dfs(0);

    return 0;
}
