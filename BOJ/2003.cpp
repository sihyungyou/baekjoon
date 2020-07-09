/*
문제
N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 이 수열의 i번째 수부터 j번째 수까지의 합 A[i]+A[i+1]+…+A[j-1]+A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1≤N≤10,000), M(1≤M≤300,000,000)이 주어진다. 다음 줄에는 A[1], A[2], …, A[N]이 공백으로 분리되어 주어진다. 각각의 A[x]는 30,000을 넘지 않는 자연수이다.

출력
첫째 줄에 경우의 수를 출력한다.
*/

#include <cstdio>
using namespace std;

int main() {
    int N, M, i;
    int l = 0, h = 0, cnt = 0, sum = 0;
    int arr[10000];

    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++) {
        scanf(" %d", &arr[i]);
    }

    while(1) {
        if (sum >= M) sum -= arr[l++];
        else if (h == N) break;
        else sum += arr[h++];
        
        if (sum == M) cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}