/*
소요시간 : 40분
특이사항 : 틀왜맞?
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <climits>

using namespace std;

int main() {
    int n, m, k = 0, h = 0, answer = INT_MAX;
    scanf("%d %d", &n, &m);

    int map[n][n];
    vector<pair<int, int> > homes;
    vector<pair<int, int> > chickens;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                // 집
                h++;
                homes.push_back(make_pair(i, j));
            } else if (map[i][j] == 2) {
                // 치킨집
                k++;
                chickens.push_back(make_pair(i, j));
            }
        }
    }

    vector<int> ind;
    for (int i = 0; i < m; i++) ind.push_back(1);
    for (int i = 0; i < k - m; i++) ind.push_back(0);
    sort(ind.begin(), ind.end());

    // 치킨집을 permutation 돌린다
    do {
        // ind 벡터 중 1인 위치의 치킨 집들만 temp에 넣는다
        vector<pair<int, int> > temp;
        for (int i = 0; i < k; i++) {
            if (ind[i] == 1) {
                temp.push_back(chickens[i]);
            }
        }

        // temp에 들어간 치킨집들만 대상으로 치킨거리를 구한다
        int acc = 0;
        for (int i = 0; i < h; i++) {
            int cury = homes[i].first;
            int curx = homes[i].second;
            int d = INT_MAX;
            for (int j = 0; j < m; j++) {
                int newd = abs(temp[j].first - cury) + abs(temp[j].second - curx);
                d = min(d, newd);
            }

            acc += d;
        }

        answer = min(answer , acc);
    } while(next_permutation(ind.begin(), ind.end()));

    printf("%d\n", answer);

    return 0;
}
