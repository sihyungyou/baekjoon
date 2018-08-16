//180806 1026 treasure
//in progress
#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b);
int main() {
  //find max index of B array and put A's min number to the index
  vector<int> arr_A;
  vector<int> arr_B;
  // vector<int> arr_C;
  int arr[50] = { 0 };
  int arr2[50] = { 0 };
  int N;

  int c, num, maxidx, minidx;
  int max, sum = 0;
  int min = 100;
  int i, j = 0;

  cin >> N;
  for(i = 0; i < N; i++){
    cin >> arr[i];
  }

  for(i = 0; i < N; i++){
    cin >> arr2[i];
  }

  // for (i = 0; i < num; i++){
  //   cin >> c;
  //   arr_A.push_back(c);
  // }

  // for (i = 0; i < num; i++){
  //   cin >> c;
  //   arr_B.push_back(c);
  //   arr_C.push_back(c);
  // }

  while(j < num){
    //find B's max
    for (i = 0; i < num; i++){
      if (arr_B[i] >= max) {
        max = arr_B[i];
      }
    }
    //get index of B's max
    for (i = 0; i < num; i++){
      if (max == arr_B[i]){
        maxidx = i;
        break;
      }
    }
    arr_B[maxidx] = -1;
    //find A's min
    for (i = 0; i < num; i++){
      if (arr_A[i] <= min) {
        min = arr_A[i];
      }
    }
    //get index of A's min
    for (i = 0; i < num; i++){
      if (min == arr_A[i]){
        minidx = i;
        break;
      }
    }
    //swap A's min and B's max index element
    swap(arr_A[minidx], arr_A[maxidx]);
    j++;
  }

  //display
  for(i = 0; i < num; i++){
    cout << arr_A[i] << " ";
  }
  cout << endl;
  for(i = 0; i < num; i++){
    cout << arr_B[i] << " ";
  }

  for (i = 0; i < num; i++){
    sum += arr_A[i]*arr_C[i];
  }
  cout << sum << endl;
  return 0;
}

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}
