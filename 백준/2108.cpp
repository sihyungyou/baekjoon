/*
문제
수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

출력
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.
*/

#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>

using namespace std;

bool sortbysec(pair <int, int> &a, pair <int, int> &b) {
    return a.second > b.second;
}

int main() {

    int n, i, temp, a, b, c, d;
    float sum = 0;
    map<int, int> m;
    vector<int> v;
    vector<pair<int, int> > v2;

    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        v.push_back(temp);
        m[temp]++;
        sum += temp;
    }

    sort(v.begin(), v.end());

    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        v2.push_back(make_pair(it->first, it->second));
    }

    sort(v2.begin(), v2.end(), sortbysec);
    if (v2[0].second == v2[1].second) {
        c = v2[1].first;
    } else {
        c = v2[0].first;
    }

    a = sum / n;
    if (a < 0) a = int(a - 0.5);
    else a = int(a + 0.5);
    b = v[n/2];
    d = v[n-1] - v[0];

    printf("%d\n%d\n%d\n%d\n", a, b, c, d);


    return 0;
}