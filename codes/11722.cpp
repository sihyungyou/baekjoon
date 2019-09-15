/*
문제
수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.
*/

#include <cstdio>

using namespace std;

int get_max(int a, int b) {
    return a > b ? a : b;
}

int main() {

    int N, i, max = 0;
    int arr[1001] = {0, };
    int memo[1001] = {0, };

    scanf("%d", &N);

    for (i = 0; i < N; i++) scanf("%d", &arr[i]);
    
    memo[0] = 1;
    
    for (i = 1; i < N; i++) {
        if (arr[i] < arr[i-1]) memo[i] = memo[i-1] + 1;
        else memo[i] = memo[i-1];
    }

    for (i = 0; i < N; i++) printf("%d ", memo[i]);
    printf("\n");
    // printf("%d\n", max);

    return 0;
}