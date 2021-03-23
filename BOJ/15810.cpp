#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXNUM 1000001

int n, m, mintime = MAXNUM;
vector<int> staff;

long long binary_search(long long s, long long e) {
    if (s > e) return -1;

    long long mid = (s + e) / 2;

    // mid분에 스태프들이 최소 m개의 풍선을 실제로 만들 수 있는지 검사
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mid / staff[i];
    }

    if (sum >= m) {
        // mid분에 스태프들이 m개 이상 만들 수 있다면 그 이전 시간에 대해서도 검사
        long long candidtae = binary_search(s, mid - 1);
        if (candidtae != -1 && candidtae < mid) {
            return candidtae;
        } else {
            return mid;
        }
    }

    // m개의 풍선을 만들 수 없다면 시간이 더 필요하므로 다시 binary search 수행
    return binary_search(mid + 1, e);
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        // 각 스태프가 풍선을 부는데 걸리는 시간 입력
        int time;
        scanf("%d", &time);

        // 가장 빨리 부는 사람이 혼자 풍선을 다 부는 경우가 최대 시간일 것이므로
        if (mintime > time) mintime = time;
        staff.push_back(time);
    }

    // 가장 적게 걸리는 사람의 시간으로 upper bound를 정하고 binary search 시작
    long long upper_bound = (long long)mintime * (long long)m;
    long long answer = binary_search(0, upper_bound);

    printf("%lld\n", answer);

    return 0;
}
