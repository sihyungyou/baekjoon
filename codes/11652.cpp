/*
문제
준규는 숫자 카드 N장을 가지고 있다. 숫자 카드에는 정수가 하나 적혀있는데, 적혀있는 수는 -2^62보다 크거나 같고, 2^62보다 작거나 같다.
준규가 가지고 있는 카드가 주어졌을 때, 가장 많이 가지고 있는 정수를 구하는 프로그램을 작성하시오.
만약, 가장 많이 가지고 있는 정수가 여러 가지라면, 작은 것을 출력한다.

입력
첫째 줄에 준규가 가지고 있는 숫자 카드의 개수 N (1 <= N <= 1000000)이 주어진다.
둘째 줄부터 N개 줄에는 숫자 카드에 적혀있는 정수가 주어진다.

출력
첫째 줄에 준규가 가장 많이 가지고 있는 정수를 출력한다.
*/

#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    char flush;
    int N, i, temp, max;
    long long ans, input;
    vector <long long> v;

    scanf("%d", &N);
    max = 0;
    ans = __LONG_LONG_MAX__;


    for(i = 0; i < N; i++) {
        scanf("%lld", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    for(vector<long long>::iterator it = v.begin(); it != v.end(); it++) {
        if (ans == *it) continue;
        if (ans != *it) temp = count(v.begin(), v.end(), *it);
        if (temp > max) { 
            max = temp;
            ans = *it;
        }
        if (temp == max) {
            if (*it < ans) ans = *it;
        }
    }

    printf("%lld\n", ans);

    return 0;
}