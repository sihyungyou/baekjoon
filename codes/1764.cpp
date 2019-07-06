/*
문제
김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.
첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다.
이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다.
이름은 띄어쓰기 없이 영어 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, i, cnt;
  string str;
  vector<string> names, duplicated;

  cin >> n >> m;

  for (i = 0; i < n+m; i++){
    cin >> str;
    names.push_back(str);
  }

  sort(names.begin(), names.end());

  cnt = 0;
  for(i = 0; i < n+m; i++){
    if (!names[i].compare(names[i+1])) {
      duplicated.push_back(names[i]);
      i++;
      cnt++;
    }
  }

  cout << cnt << endl;
  for(vector<string>::iterator i = duplicated.begin(); i != duplicated.end(); i++){
    cout << *i << endl;
  }
  return 0;
}
