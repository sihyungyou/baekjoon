/*
180813 1012 cabbage
어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 그 배추들 역시 해충으로부터 보호받을 수 있다.
(한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있다고 간주한다)

입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다.
그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50),
그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다.
그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다.

출력
각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

void dobfs(int x);

typedef struct cabbage {
  int x;
  int y;
}cabbage;

int cases, w, h, n, x, y, i, j, k, cnt = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<vector<int> > vec;
queue<cabbage> q;

int main() {

  //number of test cases
  cin >> cases;

  //initialize 2d vector
  for (i = 0; i < cases; i++){
    cin >> w >> h >> n;
    vec.resize(h, vector<int>(w, 0));
    for(j = 0; j < n; j++){
      cin >> x >> y;
      vec[x][y] = 1;
    }
  }
  cout << "initialize complete" << endl;

  //check every cabbage if it's 0 or 1
  for(i = 0; i < h; i++){
    dobfs(i);
  }
  cout << "bfs complete" << endl;

  //display vector
  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      cout << vec[i][j] << " ";
    }
    cout << endl;
  }
  cout << "display complete" << endl;
  return 0;
}

void dobfs(int x){
  //x goes up to height, so every x, need to check up to width value
  for(y = 0; y < w; i++){
    //make object
    cabbage cab = {x, y};
    //check if [x][y] == 1
    if(vec[cab.x][cab.y] == 1){
      //if it's 1, push to queue and check four way
      q.push(cab);
      //pop from queue (which means it's cabbage)
      while(!q.empty()){
        //pop from queue

        //check four ways and it it's 1, push to queue
        for(i = 0; i < 4; i++){
          cabbage temp = {x+dx[i], y+dy[i]};
          if (vec[temp.x][temp.y] == 1){
            q.push(temp);
          }
        }
      }
      cnt++;
    }
  }
}
