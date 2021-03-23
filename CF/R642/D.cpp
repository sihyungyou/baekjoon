#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

struct compare {
    bool operator()(pair<int ,int> a, pair<int, int> b) {
        // 길이 순, 그 다음으로 a.first 순
        int alen = a.second - a.first;
        int blen = b.second - b.first;

        if (alen == blen) {
            if (a.first == b.first) {
                return a.second > b.second;
            } else {
                return a.first > b.first;
            }
        } else {
            return alen < blen;
        }
    }
};

int main() {

    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int arr[n + 1];
        arr[0] = -1;
        for (int i = 1; i <= n; i++) arr[i] = 0;

        int left = 1;
        int right = n;

        priority_queue<pair<int, int>, vector<pair<int, int> >, compare> q;
        q.push(make_pair(left, right));

        for (int i = 1; i <= n; i++) {
            // q에서 top을 가져온다
            int l = q.top().first;
            int r = q.top().second;
            q.pop();
            // 문제에서 주어진 조건을 수행한다
            int segment = r - l + 1;
            int pos;
            if (segment % 2 == 0) {
                pos = (l + r - 1) / 2;
            } else {
                pos = (l + r) / 2;
            }

            arr[pos] = i;

            if (pos - 1 > 0 && arr[pos-1] == 0 && pos + 1 <= n && arr[pos+1] == 0) {
                // 좌, 우에 모두 0이 있다면
                q.push(make_pair(l, pos - 1));
                q.push(make_pair(pos + 1, r));
            } else if (pos - 1 > 0 && arr[pos-1] == 0) {
                // 좌에만 있다면
                q.push(make_pair(l, pos-1));
            } else if (pos + 1 <= n && arr[pos+1] == 0){
                // 우에만 있다면
                q.push(make_pair(pos+1, r));
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }


    return 0;
}
