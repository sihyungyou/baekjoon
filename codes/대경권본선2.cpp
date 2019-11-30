/*
문제 설명
직사각형 격자 형태의 지도에 여러 나라들이 표시되어 있습니다. 각각의 나라들은 알파벳 대문자로 구별되며, 빈 영토는 흰색으로 표시되어 있습니다. 한 나라는 한 덩어리로 붙어 있을 수도 있고, 여러 덩어리로 떨어져 있을 수도 있습니다.

세계대전3_1.png

좌측 지도 상에서 나타난 서로 다른 알파벳은 A, B, C, E, K, L, M, Q, T, X, Y 이며, 11개의 나라가 지도상에 존재함을 의미합니다. 세계대전이 발발하여, 한 덩어리로 붙어있는 나라들끼리 전쟁을 시작했습니다. 예를 들어, 좌측 지도에서 상.하.좌.우로 붙어있는 덩어리는 5개이며, 서로 다른 색으로 표시되어 있습니다.

보통 전쟁은 세력이 큰 나라가 승리하며, 세력은 영토의 크기에 비례합니다. 즉, 가장 영토가 넓은(알파벳 개수가 많은)나라가 전쟁에서 승리합니다. 만약 가장 영토가 넓은 나라가 여러 개라면, 그 중에서 알파벳 순서가 가장 뒤인 나라가 승리합니다. 승리한 나라는 자신보다 영토가 작은 나라들을 점령합니다. 좌측 지도가 전쟁이 일어나기 전 초기 상태이며, 전쟁이 종료된 후 각 나라가 차지하게 되는 영토를 표시한 것이 우측 지도입니다.

좌측 지도에서 파란색으로 표시된 구역을 살펴보겠습니다.

1-1. A는 6칸, B는 5칸, C는 3칸의 영토를 차지하고 있으므로, 전쟁에서 승리하는 국가는 A입니다.
1-2. 전쟁에 승리한 A는 자신보다 영토가 작은 B, C의 영토를 점령합니다.

좌측 지도에서 회색으로 표시된 구역을 살펴보겠습니다.

2-1. B, E, X가 모두 3칸의 영토를 차지하고 있습니다. 알파벳 순서로 가장 뒤인 X가 승리합니다.
2-1. 전쟁에 승리한 X는 자신보다 영토가 작은 Y, T, Q의 영토만 점령합니다. X와 영토의 크기가 동일한 B, E의 영토는 그대로 유지됨을 유의해야 합니다.

전쟁은 같은 덩어리로 붙어있는 구역에서 독립적으로 진행됩니다.

3-1. 좌측 지도에서 B가 차지하고 있는 영토는 총 8칸(파란색 구역 5칸, 회색 구역 3칸) 이고, A가 차지하고 있는 영토도 8칸(파란색 구역 6칸, 녹색 구역 1칸, 노란색 구역 1칸) 입니다. 지도 전체를 놓고 보면 A와 B가 동일한 영토를 차지하고 있습니다. 하지만 전쟁은 같은 덩어리에 속한 나라들끼리 독립적으로 진행되기 때문에, 파란색 구역의 승리국은 A가 됩니다.

전쟁이 일어나기 전 초기 상태의 지도가 주어질 때, 전쟁이 종료된 후 가장 많은 영토를 차지하는 나라의 넓이(격자 칸의 개수)를 구해주세요.

제한사항
입력 :

표준 입력을 사용해 데이터를 입력 받으세요.
테스트 케이스 첫째 줄에 지도의 세로 크기 n, 가로 크기 m이 순서대로 주어집니다.
n과 m은 모두 1 이상 1000 이하인 자연수입니다.
테스트 케이스 둘째 줄부터 n줄에 걸쳐 길이가 m인 문자열이 주어집니다.
문자열은 모두 알파벳 대문자와 ' . '로만 이루어져 있습니다.
알파벳 대문자는 각 나라를 표시하며, ' . '는 빈 영토를 의미합니다.
출력 :

표준 출력을 사용해 정답을 출력하세요.
첫째 줄에 전쟁이 종료된 후, 가장 많은 영토를 차지하게 되는 나라의 넓이(격자 칸의 개수)를 출력하세요.
입출력 예
입력 #1

7 8
AABCA.QA
AABC..QX
BBBC.Y..
.A...T.A
....EE..
.M.XXEXQ
KL.TBBBQ
출력 #1

15
입력 #2

4 4
XY..
YX..
..YX
.AXY
출력 #2

5
입출력 예 설명
입출력 예 #1
문제의 설명과 같습니다. A는 좌측 상단 파란색 모든 영토 14칸, 우측 중앙 노란색 영토 1칸을 차지하게 되어 총 15칸의 영토를 가지게 됩니다.

입출력 예#2
좌측 상단 구역에서는 X와 Y가 모두 2칸씩 같은 크기의 영토를 차지하고 있으므로, 전쟁에서 아무런 변화가 없습니다. 우측 하단 구역에서는 X와 Y가 모두 2칸씩 차지하지만, A는 1칸의 영토를 차지하고 있으므로 전쟁에서 승리한 Y가 A의 영토를 차지하게 됩니다. 따라서 Y는 원래의 영토 4칸에 점령한 A의 영토까지 더해서 5칸의 영토를 차지하게 됩니다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
vector<string> v;
bool vi[1000][1000] = {false, };
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};
int alpha[26] = {0,};
int n, m;
vector<pair<char, int> >ans;

void bfs(int i, int j) {
    int cnt = 0;
    // cout << "bfs\n";
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    cnt++;
    

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        vi[y][x] = true;   
        // printf("y : %d, x : %x -> %d, %c\n", y, x, v[y][x]-65, v[y][x]);
        alpha[v[y][x] - 65]++;

        for (int k = 0; k < 4; k++) {
            int newy = y + dy[k];
            int newx = x + dx[k];

            if (newx >= 0 && newx < m && newy >= 0 && newy < n && !vi[newy][newx] && v[newy][newx] != '.') {
                vi[newy][newx] = true;
                q.push(make_pair(newy, newx));
                cnt++;
                // printf("enque y : %d, x : %x -> %d, %c\n", newy, newx, v[newy][newx]-65, v[newy][newx]);
            }
        }
    }

    // check maximum value
    int maxv = 0; 
    char maxi;
    int dup = 0;

    for (int m = 0; m < 26; m++) {
        if (alpha[m] >= maxv) {
            maxv = alpha[m];
            maxi = m+65;
        }
        // if (alpha[m] == alpha[maxi-65]) {
        //     dup += alpha[m];
        // }
        // alpha[m] = 0;
    }
    for (int m = 0; m < 26; m++) {
        if (m != maxi-65 && alpha[m] == maxv) dup += alpha[m];
        alpha[m] = 0;
    }
    ans.push_back(make_pair(maxi, cnt-dup));

    // printf("maxv : %d, maxi : %c\n", cnt-dup, maxi);
}

int main(void) {
    int i, j;
    string temp;

    
    cin >> n >> m;
    
    for (i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (!vi[i][j] && v[i][j] != '.') {
                bfs(i, j);
            }
        }
    }
    
    int answer = 0;
    sort(ans.begin(), ans.end());
    for (i = 0; i < ans.size(); i++) {
        printf("%c %d\n", ans[i].first, ans[i].second);
        if (ans[i].first == ans[i+1].first) {
            ans[i+1].second += ans[i].second;
        }
        if (ans[i].second > answer) {
            answer = ans[i].second;
        }
    }
    printf("%d\n", answer);
    return 0;
}