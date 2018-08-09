//180806 11399 atm
//in progress

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int i, j, sum, num, c = 0;
  vector<int> v;
  cin >> num;
  for(i = 0; i < num; i++){
    cin >> c;
    v.push_back(c);
  }
  sort(v.begin(), v.end());
  //3 1 4 3 2
  //1 2 3 3 4
  /*
  1
  1+2
  1+2+3
  1+2+3+3
  1+2+3+3+4
  */
  for (i = 0; i < num; i++){
    for(j = 0; j <= i; j++){
      sum += v[j];
    }
  }
  cout << sum << endl;
  return 0;
}
