/*
180810 2606 virus
신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다.
한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자.
1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다.
하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.
어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다.
컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 컴퓨터의 수가 주어진다.
컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다.
둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다.
이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다

출력
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
*/

//run time error
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
int main() {

  int i, k, coms, sets, a, b, cnt;
  vector<int> infected;
  vector<int> temp;
  cin >> coms >> sets;

  //initialize array of vector<int> with the sets of connected computers
  vector<int>* com_array = new vector<int>[coms];
  for (i = 0; i < sets; i++){
    cin >> a >> b;
    com_array[a].push_back(b);
  }

  //since number 1 computer is infected fist, put connected computer to 1 into infected vector
  infected.push_back(1);
  for(i = 0; i < com_array[1].size(); i++){
    infected.push_back(com_array[1][i]);
  }

  //put the infected computer into infected vector. before putting it in, check if there is same number.
  for(i = 0; i < infected.size(); i++){
      for (k = 0; k < com_array[infected[i]].size(); k++){
        temp.push_back(com_array[infected[i]][k]);
      }
  }

  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());

  cout << temp.size() << endl;
  return 0;
}
