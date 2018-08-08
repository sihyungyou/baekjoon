//180806 1026 treasure
#include <iostream>
#include <array>

using namespace std;
void swap(int &a, int &b);
int main() {
  //find max index of B array and put A's min number to the index
  array <int, 5> arr_A = {1,1,1,6,0};
  array <int, 5> arr_B = {2,7,8,3,6};
  int maxidx, minidx;
  int max = 0;
  int min = 100;
  int i, j = 0;

  while(j < arr_A.size()){
    //find B's max
    for (i = 0; i < arr_B.size(); i++){
      if (arr_B[i] >= max) {
        max = arr_B[i];
      }
    }
    //get index of B's max
    for (i = 0; i < arr_B.size(); i++){
      if (max == arr_B[i]){
        maxidx = i;
        break;
      }
    }
    //find A's min
    for (i = 0; i < arr_A.size(); i++){
      if (arr_A[i] <= min) {
        min = arr_A[i];
      }
    }
    //get index of A's min
    for (i = 0; i < arr_A.size(); i++){
      if (min == arr_A[i]){
        minidx = i;
        break;
      }
    }
    //swap A's min and B's max index element
    swap(arr_A[minidx], arr_A[maxidx]);
    j++;
  }

  for(i = 0; i < arr_A.size(); i++){
    cout << arr_A[i] << " ";
  }
  cout << endl;
  for(i = 0; i < arr_B.size(); i++){
    cout << arr_B[i] << " ";
  }
  return 0;
}

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}
