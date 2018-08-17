/*
N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

출력
각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.

시간제한 0.25초, 재귀함수로 풀 경우 시간초과!
*/
#include <iostream>
using namespace std;

int fibonacci(int n);
int memo[40] = {1,1,};

int main() {
  int N, T, i;

  cin >> T;

  for(i = 0; i < T; i++){
    cin >> N;
    if (N == 0) cout << "1 0\n";
    else if (N == 1) cout << "1 0\n";
    else {
      fibonacci(N);
      cout << memo[N-2] << " " << memo[N-1];
    }
  }

  return 0;
}

int fibonacci(int n) {
    if (n <= 1) memo[n];
    else if (!memo[n]) return memo[n];
    else{
      return memo[n] = fibonacci(n-1) + fibonacci(n-2);
    }
}
