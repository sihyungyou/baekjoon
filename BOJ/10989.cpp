/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#include <cstdio>

using namespace std;

#define MAXN 10000000

int counting[10001] = { 0, };

int main() {
    int n;
    scanf("%d", &n);

    int max = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);

        // 최대값을 미리 구하고,
        if (max < temp) max = temp;
        // 계수 카운트
        counting[temp]++;
    }

    for (int i = 0; i <= max; i++) {
        // 메모리 효율을 위해 배열을 선언하기보다 counting 개수만큼 출력
        for (int j = 0; j < counting[i]; j++) {
            printf("%d\n", i);
        }
    }

    return 0;
}
