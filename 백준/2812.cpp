/*
문제
N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ K < N ≤ 500,000)

둘째 줄에 N자리 숫자가 주어진다. 이 수는 0으로 시작하지 않는다.

출력
입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력한다.
*/

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main() {

    int n, k, i;
    char str[500001];
    deque<char> dq;

    scanf("%d %d", &n, &k);
    scanf("%s", str);

    for (i = 0; i < n; i++) {
        while(k && !dq.empty() && dq.back() < str[i]) {
            dq.pop_back();
            k--;
        }
        dq.push_back(str[i]);
    }

    for (i = 0; i < dq.size() - k; i++) {
        printf("%c", dq[i]);
    }

    printf("\n");

    return 0;
}