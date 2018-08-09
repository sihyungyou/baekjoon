/*
180807 1759 password
암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음과 최소 두 개의 자음으로 구성되어 있다고 알려져 있다.
또한 정렬된 문자열을 선호하는 조교들의 성향으로 미루어 보아 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다.
즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.
새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다.
C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.
첫째줄에 두 정수 L, C가 주어진다. (3≤L≤C≤15) 다음 줄에는 C개의 문자들이 공백으로 구분되어 주어진다. 주어지는 문자들은 알파벳 소문자이며, 중복되는 것은 없다.
*/

//시간초과!
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
  int length, num, i, flag;
  char c;
  string str;
  vector<char> pwd;
  vector<string> keys;

  //get alphabets
  //L is password length, C is number of possible alphabets for password
  cin >> length >> num;

  for (i = 0; i < num; i++){
    cin >> c;
    pwd.push_back(c);
  }

  //sort and permutate the sequence
  sort(pwd.begin(), pwd.end());

  do {
    flag = 1;
    str="";
    //check if it's in alphabetical order. if not, don't display
    for(i = 0; i < length-1; i++){
      if(pwd[i] > pwd[i+1]){
        flag = 0;
      }
    }
    //put all qualified possibilities in string vector
    if (flag == 1){
      for(i = 0; i < length; i++){
        str += pwd[i];
      }
      keys.push_back(str);
    }

  } while(next_permutation(pwd.begin(), pwd.end()));

  //erase duplicated passwords
  keys.erase(unique(keys.begin(), keys.end()), keys.end());

  //if all the requirements are satisfied, that is a possible password. display
  for(vector<string>::iterator i = keys.begin(); i != keys.end(); i++){
    cout << *i << endl;
  }

  return 0;
}
