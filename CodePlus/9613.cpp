/*
문제
양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있다. 각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고, 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1,000,000을 넘지 않는다.

출력
각 테스트 케이스마다 가능한 모든 쌍의 GCD의 합을 출력한다.
*/

#include <cstdio>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  else {
    return gcd(b, a%b);
  }
}

int main() {

  int k, t, n, i, j, l, temp;
  long long sum = 0;
  vector<int> v;

  // testcase
  scanf("%d", &t);

  for (k = 0; k < t; k++) {
    // how many nums in each testcase
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
      // scanf n numbers, push it to vector
      scanf("%d", &temp);
      v.push_back(temp);
    }

    // iterate vector
    for (i = 0; i < n; i++) {
      for (j = i+1; j < n; j++) {
        sum += gcd(v[i], v[j]);
      }
    }

    printf("%lld\n", sum);
    sum = 0;
    v.clear();
  }

  return 0;
}
