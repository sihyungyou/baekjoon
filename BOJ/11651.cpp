/*
문제
2차원 평면 위의 점 N개가 주어진다. 
좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
*/

#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>

using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second == b.second) return (a.first < b.first);
    return (a.second < b.second); 
} 

int main() {
    int N, i, j, k;
    vector< pair<int, int> > v;

    // cin >> N;
    scanf("%d ", &N);

    for(i = 0; i < N; i++) {
        // cin >> j >> k;
        scanf("%d %d", &j, &k);
        v.push_back(pair<int, int>(j, k));
    }
    sort(v.begin(), v.end(), sortbysec);

    for(i = 0; i < N; i++) {
        // cout << v[i].first << " " << v[i].second << endl;
        printf("%d %d\n", v[i].first, v[i].second);
    }

    return 0;
}
