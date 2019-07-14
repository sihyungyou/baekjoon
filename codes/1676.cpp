/*
문제
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.
*/

#include <cstdio>

using namespace std;

int main() {
    int two, five, N, i;

    scanf("%d", &N);

    two = N / 2;
    for (i = 4; i <= N; i *= 2) {
        two += N/i;
    }
    five = N / 5;
        for (i = 25; i <= N; i *= 5) {
        five += N/i;
    }

    two < five ? printf("%d\n", two) : printf("%d\n", five);

    return 0;
}