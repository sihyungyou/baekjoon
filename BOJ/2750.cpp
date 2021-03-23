/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#include <cstdio>

using namespace std;

#define MAXN 1000

int n;
int arr[MAXN];

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort() {
    // 인접한 두 수를 비교하여 swap 하는 과정 한 번을 할 때마다 가장 큰 수가 특정된다.
    // 그러므로 이 과정을 n번 반복하면 정렬이 완성된다.

    for (int i = 0; i < n; i++) {
        // 인접한 두 수를 0부터 끝까지 비교하며 위치를 바꾼다 (거품처럼 swapping이 일어날 것)
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
        }
    }
}

void selection_sort() {
    for (int i = 0; i < n; i++) {
        int idx = i;
        for (int j = i; j < n; j++) {
            // 가장 작은 수를 "선택"한다
            if (arr[j] < arr[idx]) {
                idx = j;
            }
        }
        // 선택한 가장 작은 수를 i자리(가장 앞 자리)에 갖다 놓는다
        swap(&arr[i], &arr[idx]);
    }
}

void insertion_sort() {
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print_arr() {
    for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // bubble_sort();
    // selection_sort();
    insertion_sort();

    print_arr();

    return 0;
}
