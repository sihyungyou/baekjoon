/*
문제
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.

출력
첫째 줄에 N!을 출력한다.
*/

#include <cstdio>

using namespace std;

int fact(int a) {
    if (a == 0) return 1;
    else return a * fact(a-1);
}

int main() {

    int n;
    scanf("%d", &n);
    printf("%d\n", fact(n));

    return 0;
}