/*
문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.
*/

#include <cstdio>
#include <cmath>
using namespace std;

int main() {

  int i, j, n ,temp, cnt = 0;
  bool check[1001];

  // 에라토스테네스의 체로 소수를 미리 걸러놓음
  for (i = 1; i <= 1001; i++) check[i] = true;
  check[1] = false;

  for (i = 2; i <= sqrt(1000); i++) {
    for (j = i+i; j <= 1000; j += i) {
      check[j] = false;
    }
  }

  // n개의 수를 받으면서 check array만 확인하고 바로 결과를 출력
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &temp);
    if (check[temp] == true) cnt++;
  }

  printf("%d\n", cnt);

  return 0;
}
