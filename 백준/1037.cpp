/*
문제
양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N의 진짜 약수의 개수가 주어진다. 이 개수는 50보다 작거나 같은 자연수이다. 둘째 줄에는 N의 진짜 약수가 주어진다. 1,000,000보다 작거나 같고, 2보다 크거나 같은 자연수이고, 중복되지 않는다.

출력
첫째 줄에 N을 출력한다. N은 항상 32비트 부호있는 정수로 표현할 수 있다.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int N, i; 
    long long ans;
    scanf("%d", &N);

    long long arr[N];

    for (i = 0; i < N; i++) scanf("%lld", &arr[i]);
    sort(arr, arr+N);
    // for (i = 0; i < N; i++) printf("%lld ", arr[i]);

    printf("%lld\n", arr[0] * arr[N-1]);
    return 0;
}