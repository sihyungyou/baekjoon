/*
문제
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
2. X가 2로 나누어 떨어지면, 2로 나눈다.
3. 1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
*/

/* dp로 풀자
주어진 수를 2나 3으로 나누었을 때 몫이 2나 3으로 나누어지는 게 가장 좋다
만약 그 몫이 2나 3으로 나누어지는 경우가 아니라면 그냥 1을 빼는게 낫다
위를 반복한다.
즉, 10의 경우 10/2 = 5다. 하지만 5는 2로도, 3으로도 나누어지지 않는다
그래서 10-1을 한다. 
9/3 = 3이며, 3은 2나 3으로 나눌 수 있다. 그러므로 9/3을 한다.
3/3 = 1이며 계산이 끝난다.
즉, 10 -> 9 -> 3 -> 1 의 경우로 1을빼기, 3으로나누기, 3으로 나누기 총 세 번의 연산으로 주어진 N을 1로 만들 수 있다.

1. 먼저 10^6 (1000001개) 만큼의 boolean type 배열을 만들고 false로 초기화한다.
2. 2, 3, 6의 배수에 해당하는 index는 모두 true로 바꿔준다.
3. 주어진 N에 대해서 2로나눈 수를 index로 삼아서 그 배열값이 true라면 실행하고 false라면 1을 뺀다.
4. N이 1이 될 때 까지 과정3을 반복한다.
5. cnt변수로 연산의 횟수를 계산한다.
*/

#include <cstdio>

using namespace std;

int main() {

    int arr[1000001] = {0, };
    int i, cnt, N, two, three;
    cnt = 0;

    scanf("%d", &N);
    arr[1] = 1;
    for(i = 2; i <= N; i++) {
        if ( (i % 2 == 0) || (i % 3 == 0) ) arr[i] = 1;
    }
    
    while(N != 1) {

        if (N % 2 == 0) {
            two = N/2;
        } else {
            two = 0;
        }

        if (N % 3 == 0) {
            three = N/3;
        } else {
            three = 0;
        }
        // printf("two : %d three : %d\n", two, three);

        if(two != 0 && arr[two]) {
            // N을 2로 나누고 몫이 2나 3로 나눠질 수 있는 경우
            N /= 2;
            // printf("2, N : %d\n", N);
        }
        else if (three != 0 && arr[three]) {
            // N을 3으로 나누고 몫이 2나 3로 나눠질 수 있는 경우
            N /= 3;
            // printf("3, N : %d\n", N);
        }
        else {
            // N을 2나 3으로 나누었지만 몫이 2나 3으로 나눠질 수 없는 경우
            N -= 1;
            // printf("else, N : %d\n", N);
        }
        cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}