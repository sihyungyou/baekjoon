#include <cstdio>

using namespace std;

long long money, coins;

void buy(int price) {
    coins += money/price;
    money %= price;
}

void sell(int price) {
    money += coins*price;
    coins -= coins;
}

int main() {

    int n, i;
    long long w;
    
    scanf("%d %lld", &n, &w);

    int arr[n+1];

    money = w;
    coins = 0;

    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    arr[n] = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] < arr[i+1]) buy(arr[i]);
        else if (arr[i] > arr[i+1]) sell(arr[i]);
    }
    
    printf("%lld\n", money);
    return 0;
}