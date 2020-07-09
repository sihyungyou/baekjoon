/*
문제
세 정수 A, B, C가 주어진다. 이때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오. 

입력
첫째 줄에 세 정수 A, B, C가 공백으로 구분되어 주어진다. (1 ≤ A, B, C ≤ 100)

출력
두 번째로 큰 정수를 출력한다.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int arr[3];

    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    sort(arr, arr+3);

    printf("%d\n", arr[1]);

    return 0;
}