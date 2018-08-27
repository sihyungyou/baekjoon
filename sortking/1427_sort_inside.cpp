/*
180826 1427 sort inside
문제
배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.

입력
첫째 줄에 정렬하고자하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.
ex) 2143 -> 4321
*/
//success
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, n, i;
  vector<int> num;
  cin >> N;

  while(1){
    if(N == 0) break;
    n = N%10;
    N /= 10;
    num.push_back(n);
  }

  sort(num.begin(), num.end(), greater<int>());

  for(vector<int>::iterator i = num.begin(); i != num.end(); i++){
    cout << *i;
  }
  cout << endl;
  return 0;
}
