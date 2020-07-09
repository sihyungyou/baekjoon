/*
문제
N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다.

출력
첫째 줄부터 N!개의 줄에 걸쳐서 모든 순열을 사전순으로 출력한다.
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

  int n, i;
  int arr[8];
  scanf("%d", &n);

  for (i = 1; i <= n; i++) arr[i-1] = i;

  do {
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
  } while(next_permutation(arr, arr+n));

  return 0;
}
