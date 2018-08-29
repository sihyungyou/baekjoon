/*
180807 1759 password
암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음과 최소 두 개의 자음으로 구성되어 있다고 알려져 있다.
또한 정렬된 문자열을 선호하는 조교들의 성향으로 미루어 보아 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다.
즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.
새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다.
C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.
첫째줄에 두 정수 L, C가 주어진다. (3≤L≤C≤15) 다음 줄에는 C개의 문자들이 공백으로 구분되어 주어진다. 주어지는 문자들은 알파벳 소문자이며, 중복되는 것은 없다.
˜*/

//over time!
#include <iostream>
#include <string>

using namespace std;

int L, C, cnt, vow, con;  //vow 모음, con 자음,
string result;
string a[16];
bool isvow(string s);
int main() {
  //L은 pwd의 length, C는 주어지는 가능성있는 알파벳들의 수
  cin >> L >> C;
  for(int i = 0; i < C; i++){
    cin >> a[i];
  }
  sort(a,a+C);



  return 0;
}

bool isvow(string s){
  if(s == "a" || s == "e" || s == "i" || s == "o" || s == "u") return true;
  else return false;
}
