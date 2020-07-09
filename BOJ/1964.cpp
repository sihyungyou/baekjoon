/*
문제
오각형의 각 변에 아래 그림과 같이 점을 찍어 나간다. N단계에서 점의 개수는 모두 몇 개일까?

입력
첫째 줄에 N(1≤N≤10,000,000)이 주어진다.

출력
첫째 줄에 N단계에서 점의 개수를 45678로 나눈 나머지를 출력한다.
*/

#include <cstdio>
using namespace std;

int main() {

    long long N, i, ans = 5;
    scanf("%lld", &N);

    for (i = 1; i < N; i++) ans += (7 + ((i-1)*3)) % 45678;
    printf("%lld\n", ans%45678);

    return 0;
}