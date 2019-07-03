/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

// void printarr(int * arr, int len) {
//     int i = 0;
//     for(i = 0; i < len; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
int C[10001] = {0, };
int main () {

    int N, i, j, k, temp, range, max;
    int * ptr;
    vector <int> v;  

    scanf("%d", &N);

    // int A[N];
    // int B[N];
    max = 10001;
    for(i = 0; i < N; i++) {
        scanf("%d", &temp);
        // A[i] = temp;
        C[temp]++;
        if (temp > max) max = temp;
    }
    // printf("A : ");
    // printarr(A, 20);
    
    // ptr = max_element(A, A+N);
    // range = *ptr;

    // int C[range+1];

    // for (i = 0; i <= range; i++) {
    //     C[i] = 0;
    // }

    // printf("C : ");
    // printarr(C, range+1);

    // for (j = 0; j < N; j++) {
    //     C[A[j]] = C[A[j]]+1;
    // }

    // printf("C2 : ");
    // printarr(C, range+1);

    // for (i = 1; i <= range; i++) {
    //     C[i] = C[i] + C[i-1];
    // }
    for (i = 1; i <= max; i++) {
        C[i] = C[i] + C[i-1];
    }
    // printf("C3 : ");
    // printarr(C, range+1);

    for (j = N; j >= 0; j--) {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    for (i = 0; i < N; i++) {
        printf("%d\n", B[i]);
    }

    printf("\n");
    return 0;
}