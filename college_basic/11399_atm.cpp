//180806 11399 atm
//over time!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int i, j, sum = 0;
  vector<int> v;
  v.push_back(3);
  v.push_back(1);
  v.push_back(4);
  v.push_back(3);
  v.push_back(2);
  sort(v.begin(), v.end());

  for (i = 0; i < v.size(); i++){
    for(j = 0; j <= i; j++){
      sum += v[j];
    }
  }
  cout << "total: " << sum << endl;
  return 0;
}
