//180806 1026 treasure
//success
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> arr_A;
  vector<int> arr_B;

  int i, N, c, sum = 0;

  cin >> N;                         //get numbers
  for(i = 0; i < N; i++){           //arr 1 inputs
    cin >> c;
    arr_A.push_back(c);
  }

  for(i = 0; i < N; i++){           //arr 2 inputs
    cin >> c;
    arr_B.push_back(c);
  }
  sort(arr_A.begin(), arr_A.end());
  sort(arr_B.begin(), arr_B.end());
  for(i = 0; i < N; i++){
    sum += arr_A[i]*arr_B[N-i-1];
  }
  cout << sum << endl;

  return 0;
}
