//180806 10819 difference 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int num, i, temp, max, calc;
  int cnt = 0;
  vector<int> nums;
  vector<int> sums;

  //ask user how many numbers to put in vector/array
  cout << "how many numbers? ";
  cin >> num;

  //get numbers from user
  for(i = 0; i < num; i++){
    cout << "type integer: ";
    cin >> temp;
    nums.push_back(temp);
  }

  //sort
  sort(nums.begin(), nums.end());

  //get sums of each cases of order sequence
  do {
    //display list
    for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
      cout << *i << " ";
    }
    //calculate sums
    temp = 0;
    for(i = 0; i < num-1; i++){
      calc = nums[i] - nums[i+1];
      if (calc< 0){
          temp += calc*-1;
      } else {
        temp += calc;
      }
    }

    //put sum into sums vector
    sums.push_back(temp);
    cout << temp << endl;
    cnt++;
  } while(next_permutation(nums.begin(), nums.end()));

  //find maximum number among sums vector
  max = sums[0];
  for(i = 0; i < cnt; i++){
    if(sums[i] > max){
      max = sums[i];
    }
  }

  cout << "there are " << cnt << " cases" << endl;
  cout << "max sum case is " << max << endl;
  return 0;
}
