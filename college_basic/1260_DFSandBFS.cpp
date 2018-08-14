/*
180814 1260 dfs and bfs
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 한 간선이 여러 번 주어질 수도 있는데, 간선이 하나만 있는 것으로 생각하면 된다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
*/

#include <iostream>
#include <queue>

using namespace std;
void do_dfs(int a[][1000] , bool c[] , int v);
void do_bfs(int a[][1000], bool c[], int v);
int main() {
  int N, M, V, i, v1, v2;
  int map[1000][1000];
  bool check[1000] = { false };

  //stdin
  cin >> N >> M >> V;

  //check the edges
  for(i = 0; i < M; i++){
    cin >> v1 >> v2;
    map[v1][v2] = 1;
    map[v2][v1] = 1;
  }

  //dfs
  do_dfs(map, check, V);

  //re-initialize check array with false
  for(int i = 0; i < 1000; i++){
    check[i] = false;
  }

  cout << endl;

  //bfs
  do_bfs(map, check, V);


  return 0;
}

void do_dfs(int a[][1000], bool c[], int v){
  int n = sizeof a[0] / sizeof(int);        //get size (length) of map array
  c[v] = true;                              //mark true c[v] since calling dfs function means map[v] is checked
  cout << v << " ";                         //print which vertex is connected
  for(int i = 1; i < n; i++){
    if(a[v][i]==1 && !c[i]) {               //check a[v]'s all connected vertex
      do_dfs(a,c,i);                        //if find one && it hasn't been checked, do dfs again starting that vertex
    }
  }
}

void do_bfs(int a[][1000], bool c[], int v){
  queue<int> q;
  int n = sizeof a[0] / sizeof(int);
  c[v] = true;
  q.push(v);

  //check if a[v][i]==1, it it's 1 push to queue
  while(!q.empty()){
    v = q.front();                        //get one vertex which is one from queue
    q.pop();                              //get rid of that vertex from queue
    cout << v << " ";
    for(int i = 1; i < n; i++){           //check rest of array's elements if they are 1 and hasn't been checked
      if(a[v][i]==1 && !c[i]){
        q.push(i);                        //push to queue if both standards are satisfied
        c[i] = true;                      //don't forget to mark true in checking array
      }
    }
  }
}
