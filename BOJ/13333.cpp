#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, qidx, maxk = -1;

    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        maxk = max(maxk, arr[i]);
    }

    // n^2로 풀어도 TLE 안뜨는 크기
    for (qidx = 0; qidx <= maxk; qidx++) {
        int over = 0;
        int below = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= qidx) over++;     // qidx번 이상 인용된 논문 수
            if (arr[i] <= qidx) below++;    // qidx번 이하 인용된 논문 수
        }
        // qidx번 이상 인용된 논문 수가 qidx개 이상이고, qidx번 이하 인용된 논문 수가 n-qidx 이상이면 조건 만족
        if (over >= qidx && below >= n - qidx) {
            break;
        }
    }

    printf("%d\n", qidx);

    return 0;
}
