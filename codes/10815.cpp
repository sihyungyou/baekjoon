/*
문제
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이가 주어진다.
둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다.
숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다.
넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다.
이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다

출력
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.
*/

#include <algorithm>
#include <cstdio>

using namespace std;

int a1[500001];
int a2[500001];

int bsearch(int l, int r, int val) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (a1[mid] == val) return mid;
        else if (a1[mid] < val) return bsearch(mid + 1, r, val);
        else if (a1[mid] > val) return bsearch(l, mid - 1, val);
    }
    return -1;
}

int main () {
    int N, M, i, temp, result;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &temp);
        a1[i] = temp;
    }

    scanf("%d", &M);
    for (i = 0; i < M; i++) {
        scanf("%d", &temp);
        a2[i] = temp;
    }

    sort(a1, a1 + N);

    for (i = 0; i < M; i++) {
        result = bsearch(0, N-1, a2[i]);
        result == -1 ? printf("0 ") : printf("1 ");
    }

    printf("\n");

    return 0;
}