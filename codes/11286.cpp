/*
문제
절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.

배열에 정수 x (x ≠ 0)를 넣는다.
배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.

입력
첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다.
만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 입력되는 정수는 -231보다 크고, 231보다 작다.

출력
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 절댓값이 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.
*/

#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int heapsize = 0;
int arr[100001];


void min_heapify(int i) {
	int l = i*2;
	int r = i*2 + 1;
	int min;
	int temp;
	if ( l <= heapsize && abs(arr[l]) < abs(arr[i])) min = l;
	else min = i;
	if ( r <= heapsize && abs(arr[r]) < abs(arr[min]) ) min = r;

	if (min != i) {
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		min_heapify(min);
	}
}

int extract_min() {
	int min;
	if (heapsize < 1) return 0;
	min = arr[1];
	arr[1] = arr[heapsize];
	heapsize--;
	min_heapify(1);
	return min;
}

void insert_to_heap(int val) {
    int parent, child, temp;

    heapsize++;
    arr[heapsize] = val;

    parent = heapsize / 2;
    child = heapsize;

    while(parent != 0) {
        if ( abs(arr[child]) < abs(arr[parent]) ) {
            temp = arr[parent];
            arr[parent] = arr[child];
            arr[child] = temp;
            child = parent;
            parent = parent / 2;
        }
        else if (abs(arr[child]) == abs(arr[parent]) ) {
            
        }
        else break;
    }
}

int main() {
    int N, temp, i, j;

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        scanf("%d", &temp);
        if (temp == 0) {
            // pop from heap and adjust
            // if arr length is 0, print 0
            printf("%d\n", extract_min());
        }
        else {
            // insert temp to arr
            insert_to_heap(temp);
        }
    }

    return 0;
}

        // else if (temp == 99) {
        //     printf("input is 99\n");
        //     for(j = 1; j <= heapsize; j++) printf("%d ", arr[j]);
        //     printf("\n");
        // }