/*
문제
한수는 지금 (x, y)에 있다. 직사각형의 왼쪽 아래 꼭짓점은 (0, 0)에 있고, 오른쪽 위 꼭짓점은 (w, h)에 있다. 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 x y w h가 주어진다. w와 h는 1,000보다 작거나 같은 자연수이고, x는 1보다 크거나 같고, w-1보다 작거나 같은 자연수이고, y는 1보다 크거나 같고, h-1보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제의 정답을 출력한다.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int arr[4];
    scanf("%d %d %d %d", &x, &y, &w, &h);

    arr[0] = x;
    arr[1] = y;
    arr[2] = h-y;
    arr[3] = w-x;

    sort(arr, arr+4);

    printf("%d\n", arr[0]);

    return 0;
}