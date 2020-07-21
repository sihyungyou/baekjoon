/*
문제
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 연산자가 주어진다. 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다. 연산자의 개수는 N-1보다 많을 수도 있다. 모든 수의 사이에는 연산자를 한 개 끼워넣어야 하며, 주어진 연산자를 모두 사용하지 않고 모든 수의 사이에 연산자를 끼워넣을 수도 있다.

우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.

예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 덧셈(+) 3개, 뺄셈(-) 2개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 250가지의 식을 만들 수 있다. 예를 들어, 아래와 같은 식을 만들 수 있다.

1+2+3-4×5÷6
1÷2+3+4-5×6
1+2÷3×4-5+6
1÷2×3-4+5+6
1+2+3+4-5-6
1+2+3-4-5×6
식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는 C++14의 기준을 따른다. 즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.

1+2+3-4×5÷6 = 1
1÷2+3+4-5×6 = 12
1+2÷3×4-5+6 = 5
1÷2×3-4+5+6 = 7
1+2+3+4-5-6 = -1
1+2+3-4-5×6 = -18
N개의 수와 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 셋째 줄에는 합이 N-1보다 크거나 같고, 4N보다 작거나 같은 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다.

출력
첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 둘째 줄에는 최솟값을 출력한다. 연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 또한, 앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.
*/

/*
수열로 풀면 시간초과
로또 문제처럼 0,1로만 이루어진 선택배열을 순열을 돌리면 시간초과는 안나겠지만 0, 1만으로는 +, -, *. / 라는 네 경우에 대해 올바르게 선택하여 순열을 만들 수 없음
재귀로 idx를 올려가면서 풀면 연산자의 순서를 뒤바꿀 수 없으므로 올바른 값이 나오지 않음
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n;
int mi = INT_MAX;
int ma = INT_MIN;
vector<int> num;

void dfs(int idx, int add, int sub, int mul, int div, int sum) {
  if (idx == n - 1) {
    mi = min(mi, sum);
    ma = max(ma, sum);
    return;
  }

  if (add != 0) dfs(idx + 1, add - 1, sub, mul, div, sum + num[idx+1]);
  if (sub != 0) dfs(idx + 1, add, sub - 1, mul, div, sum - num[idx+1]);
  if (mul != 0) dfs(idx + 1, add, sub, mul - 1, div, sum * num[idx+1]);
  if (div != 0) {
    if (sum < 0) {
        sum *= -1;
        sum /= num[idx+1];
        sum *= -1;
        dfs(idx + 1, add, sub, mul, div - 1, sum);
    }
    else dfs(idx + 1, add, sub, mul, div - 1, sum / num[idx+1]);
  }
}

int main() {

  int i, temp;
  vector<int> op;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &temp);
    num.push_back(temp);
  }
  for (i = 0; i < 4; i++) {
    scanf("%d", &temp);
    op.push_back(temp);
  }

  dfs(0, op[0], op[1], op[2], op[3], num[0]);
  printf("%d\n%d\n", ma, mi);

  return 0;
}