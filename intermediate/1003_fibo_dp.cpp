/*
N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

출력
각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.

시간제한 0.25초, 재귀함수로 풀 경우 시간초과!
dynamic programming
*/

#include <iostream>
using namespace std;

int fibonacci(int n);
int memo[40] = {1,1,};
int one = 0;
int zero = 1;

int main() {
  int T, i;
  int N[40];

  cin >> T;
  for(i = 0; i < T; i++){
    cin >> N[i];
  }

  for(i = 0; i < T; i++){
    if (N[i] == 0) cout << "1 0\n";
    else if (N[i] == 1) cout << "0 1\n";
    else {
      fibonacci(N[i]);
      // cout << fibonacci(N[i]-2) << " " << fibonacci(N[i]-1);  //normal fibonacci, not counting 0s and 1s
      cout << zero << " " << one << endl;
    }
  }

  return 0;
}

int fibonacci(int n) {
    if (n == 0) {
      zero++;
      return 0;
    }
    if (n == 1 || n == 2) {
      one++;
      return 1;
    }
    if (memo[n] > 0) return memo[n];
    return memo[n] = fibonacci(n-1) + fibonacci(n-2);
}
