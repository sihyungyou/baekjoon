/*
180810 1652 hotel
똑바로 연속해서 2칸 이상의 빈 칸이 존재하면 그 곳에 몸을 양 옆으로 쭉 뻗으면서 누울 수 있다.
가로로 누울 수도 있고 세로로 누울 수도 있다.
누울 때는 무조건 몸을 쭉 뻗기 때문에 반드시 벽이나 짐에 닿게 된다. (중간에 어정쩡하게 눕는 경우가 없다.)
첫째 줄에 방의 크기 N이 주어진다. N은 1이상 100이하의 정수이다.
그 다음 N줄에 걸쳐 N개의 문자가 들어오는데 '.'은 아무것도 없는 곳을 의미하고, 'X'는 짐이 있는 곳을 의미한다.
*/
//run time error
#include <iostream>
#include <array>

using namespace std;

int main() {
  int num, i, j;
  int hor, ver = 0;
  char temp;

  cin >> num;

  //create two dimensional array for the map
  char ** arr = new char*[num];
  for (i = 0; i < num; i++){
    arr[i] = new char[num];
  }

  //stdin
  for(i = 0; i < num; i++){
    for(j = 0; j < num; j++){
      cin >> arr[i][j];
    }
  }

  //find horizental way
  for(i = 0; i < num; i++){
    for(j = 0; j < num-1; j++){
      if (arr[i][j] == '.' && arr[i][j+1] == '.' && arr[i][j+2] != '.') hor++;
      if (arr[j][i] == '.' && arr[j+1][i] == '.' && arr[j+2][i] != '.') ver++;
      }
    }

  cout << hor << " " << ver << endl;
  //return memory
  for (i = 0; i < num; i++){
    delete [] arr[i];
  }
  delete [] arr;
  return 0;
}
