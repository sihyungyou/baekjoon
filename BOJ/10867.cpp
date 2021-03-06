/*
180829 10867 sort without duplicated elements
문제
N개의 정수가 주어진다. 이 때, N개의 정수를 오름차순으로 정렬하는 프로그램을 작성하시오. 같은 정수는 한 번만 출력한다.

입력
첫째 줄에 수의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째에는 숫자가 주어진다. 이 수는 절대값이 1,000보다 작거나 같은 정수이다.

출력
첫째 줄에 수를 오름차순으로 정렬한 결과를 출력한다. 이 때, 같은 수는 한 번만 출력한다.
*/
//success
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int N, i, n;
  vector<int> vec;

  cin >> N;
  for(i = 0; i < N; i++){
    cin >> n;
    vec.push_back(n);
  }
  //sort
  sort(vec.begin(), vec.end());

  //eliminate duplicated elements
  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  //display
  for(vector<int>::iterator i = vec.begin(); i != vec.end(); i++){
    cout << *i << " ";
  }
  cout << endl;
  return 0;
}
