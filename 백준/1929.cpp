/*
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000)

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
*/

#include <cstdio>
#include <cmath>

using namespace std;

int main() {

    int M, N, i, j;
    bool arr[1000001];

    scanf("%d %d", &M, &N);

    for(i = 2; i <= N; i++) arr[i] = true;

    for (i = 2; i <= sqrt(N); i++) {
        if (arr[i]) {
            for (j = i+i; j <= N; j += i) {
                if (arr[j]) arr[j] = false;
            }
        }
    }
    
    for (i = M; i <= N; i++) {
        if (arr[i]) printf("%d\n", i);
    }

    return 0;
}