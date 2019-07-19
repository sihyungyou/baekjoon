/*
문제
양의 정수 N이 주어졌을 때, 이 수를 소인수분해 한 결과를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 수가 주어진다. 각 테스트 케이스마다 양의 정수 N (2 ≤ N ≤ 100,000)이 주어진다.

출력
각 테스트 케이스마다 각 인수와 그 인수가 곱해진 횟수를 한 줄씩 출력한다. 출력 순서는 인수가 증가하는 순으로 한다.
*/

#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int N, i, j, k, num, orig;
    int arr[100001] = {0, };
    
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &num);
        orig = num;
        for (j = 2; j <= sqrt(num); j++) {
            while (num%j == 0) {
                arr[j]++;
                num /= j;
            }
        }
        if (num != 1) arr[num]++;

        for (j = 2; j <= orig; j++) {
            if (arr[j] > 0) { 
                printf("%d %d\n", j, arr[j]);
                arr[j] = 0;
            }
        }
    }

    return 0;
}
