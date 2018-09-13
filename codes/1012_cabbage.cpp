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

//run time error
//fix global variables to local
#include <iostream>
#include <vector>
#define SIZE 2500

using namespace std;

typedef struct cabbage {
  int x;
  int y;
} cabbage;

void dobfs(int x);
bool check(cabbage c);
void init();
void qpush(cabbage in);
cabbage qpop();
bool qempty();
bool qfull();


int T, M, N, K, front, rear, cnt = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
cabbage queue[SIZE];
int vec[50][50];
vector<int> cnts;

int main() {

  cin >> T;                         //number of test cases
  for(int t = 0; t < T; t++){
    init();                         //initialize each cases
    cnt = 0;
    for(int k = 0; k < N; k++){
      dobfs(k);                     //do bfs for each case
    }
    cnts.push_back(cnt);
  }
  for(vector<int>::iterator c = cnts.begin(); c != cnts.end(); c++){
    cout << *c << endl;
  }
  return 0;
}

void init(){
  int x, y;
  //initialize 2d vector
    cin >> M >> N >> K;
    for(int j = 0; j < K; j++){
      cin >> x >> y;
      vec[y][x] = 1;
    }
}

bool check(cabbage c){
  if (vec[c.y][c.x] == 0) return false;                              //check if vec[c.x][c.y] == 0 or 1
  if (c.y < 0 || c.y >= N || c.x < 0 || c.x >= M) return false;      //check range of M and N
  vec[c.y][c.x] = 0;            //put 0 after check
  return true;
}
void qpush(cabbage in){
  if(qfull()==true) {
    printf("queue full error!\n");
  }  else {
      queue[rear] = in;
      rear = (rear+1)%SIZE;
  }
}
cabbage qpop(){
  cabbage t;
  t = queue[front];
  front++;
  return t;
}
bool qempty(){
  if (rear == front)
      return true;
  else
      return false;
}
bool qfull(){
  if ((rear+1)%SIZE==front)
      return true;
  else
      return false;
}

void dobfs(int x){
  //x goes up to height, so every x, need to check up to width value
  for(int y = 0; y < M; y++){
    //make object
    cabbage cab = {x, y};
    //check if [x][y] == 1
    if(check(cab)){
      //if it's 1, push to queue and check four way
      qpush(cab);
      //pop from queue (which means it's cabbage)
      while(!qempty()){
        //pop from queue
        cab = qpop();
        //check four ways and it it's 1, push to queue
        for(int i = 0; i < 4; i++){
          cabbage temp = {cab.x+dx[i], cab.y+dy[i]};
          if (check(temp)){
            qpush(temp);
          }
        }
      }
      cnt++;
    }
  }
}
