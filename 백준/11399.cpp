//180806 11399 atm
//success

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int i, j, sum, num, c, min = 0;
  vector<int> v;
  cin >> num;
  for(i = 0; i < num; i++){
    cin >> c;
    v.push_back(c);
  }
  sort(v.begin(), v.end());
  
  for (i = 0; i < num; i++){
    sum = 0;
    for(j = 0; j <= i; j++){
      sum += v[j];
    }
    min += sum;
  }

  cout << min << endl;
  return 0;
}