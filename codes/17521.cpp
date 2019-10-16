/*
문제
국제자본부동산회사(ICPC)는 바이트 코인(Byte Coin)에 자금을 투자하고 있다. 바이트 코인은 김박사가 만든 가상 화폐이다. 실제로는 바이트 코인 가격을 예상할 수 없지만 이 문제에서는 바이트 코인 가격 등락을 미리 정확히 예측할 수 있다고 가정하자.

우리는 1일부터 n일까지 n일 동안 그림 1과 같이 바이트 코인의 등락을 미리 알 수 있으며 우리에게는 초기 현금 W가 주어져 있다. 그림 1의 빨간색 네모는 해당 일자의 바이트 코인 가격을 나타낸다. 매일 바이트 코인을 매수하거나 매도할 수 있다고 하자. 다만 바이트 코인 하나를 나누어 매도하거나 매수할 수는 없다. 우리는 n일 날 보유하고 있는 모든 코인을 매도할 때 가지고 있는 현금을 최대화하고 싶다. 

그림 1. 10 일간 바이트 코인 가격 등락 그래프

예를 들어, 그림 1과 같은 바이트 코인 등락 그래프를 첫날 미리 알 수 있다고 하고 우리에게 주어진 초기 현금이 24라고 하자. 수익을 최대한 높이려면 다음과 같이 바이트 코인을 매수, 매도할 수 있다. 첫 날 현금 20을 써서 4개의 코인을 산다. 둘째 날 모든 코인을 매도해서 현금 28을 얻고 모두 32의 현금을 갖게 된다. 5일째 되는 날 현금 32를 써서 16개의 코인을 매수한다. 7일째 되는 날 모든 코인을 매도해서 모두 128의 현금을 갖게 된다. 9일째 되는 날 현금 126을 써서 42개의 코인을 사고 10일 날 모든 코인을 매도한다. 그러면 10일 날 현금이 170이 되고 이것이 최대이다.

요일 수 n, 초기 현금 W, 1일부터 n일까지 각 요일의 바이트 코인 가격이 주어질 때, n일 날 보유하고 있는 모든 코인을 매도할 때 보유하게 될 최종 현금의 최댓값을 출력하는 프로그램을 작성하시오.

입력
입력은 표준입력을 사용한다. 첫 번째 줄에 요일 수를 나타내는 양의 정수 n과 초기 현금 W(1 ≤ n ≤ 15, 1 ≤ W ≤ 100,000)가 주어진다. 다음 n 개의 줄에서, i번째 줄은 i일의 바이트 코인 가격을 나타내는 정수 si가 주어진다(1 ≤ si ≤ 50).

출력
출력은 표준출력을 사용한다. n일 날 보유하고 있는 모든 코인을 매도할 때 가지고 있는 현금의 최댓값을 한 행에 출력한다. 비록 초기 현금 W는 그렇게 크지 않지만 최종 현금은 매우 커질 수 있음에 주의하자.
*/

#include <cstdio>

using namespace std;

long long money;
int coins;

void buy(int price) {
    if (money >= coins*price) {
        coins += money/price;
        money -= coins*price;
    }
    // printf("price : %d, buy, money : %lld\n", price, money);
}

void sell(int price) {
    money += coins*price;
    coins -= coins;
    // printf("price : %d, sell, money : %lld\n", price, money);
}

int main() {

    int n, i, w;
    
    scanf("%d %d", &n, &w);

    int arr[n];

    money = w;
    coins = 0;

    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    // if (arr[0] < arr[1]) buy(arr[0]);
    
    for (i = 0; i < n-1; i++) {
        if (arr[i] < arr[i+1]) buy(arr[i]);
        else if (arr[i] > arr[i+1]) sell(arr[i]);
        // if (arr[i-1] >= arr[i] && arr[i] < arr[i+1]) buy(arr[i]);
        // else if (arr[i-1] <= arr[i] && arr[i] > arr[i+1]) sell(arr[i]);
    }

    sell(arr[n-1]);

    printf("%lld\n", money);
    return 0;
}