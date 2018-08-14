/*
180814 2667 apartment
1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다.
여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다.

입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int N, cnt;
int map[25][25];

int main() {
  //input
  cin >> N;
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      scanf("%1d", &map[i][j]);   //get one digit input
    }
  }

  //algorithm for BFS
  solution(N);

  //sort

  //print

  return 0;
}

void solution(int n){
  int i, j = 0;
  //apartment
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(map[i][j]==1){
        do_bfs(i,j,cnt+2);
        cnt++;
      }
    }
  }
  //house
}
void do_bfs(int x, int y, int mark){

  queue<pair<int><int>> q;
  q.push(pair<int,int> (x,y));
  map[x][y] = mark;
  while(!q.qempty()){
    pair<int, int> p;
    int y = p.first = q.front().first;
    int x = p.second = q.front().second;
    q.pop();
  }
}
