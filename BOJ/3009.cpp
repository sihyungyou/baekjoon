/*
문제
세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.

입력
세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

출력
직사각형의 네 번째 점의 좌표를 출력한다.
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compx(pair<int, int> &a, pair<int, int> &b) {
    return a.first > b.first;
}

bool compy(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

int main() {

    vector<pair<int, int> > v;
    int x, y;

    for(int i = 0; i < 3; i++) {
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), compx);
    if (v[0].first == v[1].first) x = v[2].first;
    else x = v[0].first;

    sort(v.begin(), v.end(), compy);
    if (v[0].second == v[1].second) y = v[2].second;
    else y = v[0].second;


    printf("%d %d\n", x, y);
    
    return 0;
}