/*
문제
강남역에서 붕어빵 장사를 하고 있는 해빈이는 지금 붕어빵이 N개 남았다.
해빈이는 적절히 붕어빵 세트 메뉴를 구성해서 붕어빵을 팔아서 얻을 수 있는 수익을 최대로 만드려고 한다.
붕어빵 세트 메뉴는 붕어빵을 묶어서 파는 것을 의미하고, 세트 메뉴의 가격은 이미 정해져 있다.

붕어빵 i개로 이루어진 세트 메뉴의 가격은 Pi 원이다.
붕어빵이 4개 남아 있고, 1개 팔 때의 가격이 1, 2개는 5, 3개는 6, 4개는 7인 경우에 해빈이가 얻을 수 있는 최대 수익은 10원이다. 2개, 2개로 붕어빵을 팔면 되기 때문이다.
1개 팔 때의 가격이 5, 2개는 2, 3개는 8, 4개는 10 인 경우에는 20이 된다. 1개, 1개, 1개, 1개로 붕어빵을 팔면 되기 때문이다.
마지막으로, 1개 팔 때의 가격이 3, 2개는 5, 3개는 15, 4개는 16인 경우에는 정답은 18이다. 붕어빵을 3개, 1개로 팔면 되기 때문이다.
세트 메뉴의 가격이 주어졌을 때, 해빈이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 해빈이가 가지고 있는 붕어빵의 개수 N이 주어진다. (1 ≤ N ≤ 1,000)
둘째 줄에는 Pi가 P1부터 PN까지 순서대로 주어진다. (1 ≤ Pi ≤ 10,000)

출력
해빈이가 얻을 수 있는 최대 수익을 출력한다.
*/
//DP problem

#include <iostream>
#include <algorithm>
using namespace std;
// int comp(int x, int y);

int N, fish[1001], sum[1001] = { 0, };

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++){
    scanf("%d", &fish[i]);
  }
  sum[1] = fish[1];
  /*
  sum[1] = fish[1]
  sum[2] = fish[2] vs. sum[1] + fish[1]
  sum[3] = fish[3] vs. sum[2] + fish[1] vs. sum[1] + fish[2]
  sum[4] = fish[4] vs. sum[3] + fish[1] vs. sum[2] + fish[2] vs. sum[1] + fish[3]
  ...
  sum[N] = compare(fish[N], sum[N-j] + fish[j]);
  */
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= i; j++){
      sum[i] = max(fish[i], sum[i-j] + fish[j]);
    }
  }
  cout << sum[N] << endl;

  return 0;
}
// int comp(int x, int y){
//   if (x >= y) return x;
//   else return y;
// }
