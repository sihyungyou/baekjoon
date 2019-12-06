/*
문제
0과 1로만 이루어진 행렬 A와 행렬 B가 있다. 이때, 행렬 A를 행렬 B로 바꾸는데 필요한 연산의 횟수의 최솟값을 구하는 프로그램을 작성하시오.

행렬을 변환하는 연산은 어떤 3*3크기의 부분 행렬에 있는 모든 원소를 뒤집는 것이다. (0 -> 1, 1 -> 0)

입력
첫째 줄에 행렬의 크기 N M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 행렬 A가 주어지고, 그 다음줄부터 N개의 줄에는 행렬 B가 주어진다.

출력
첫째 줄에 문제의 정답을 출력한다. 만약 A를 B로 바꿀 수 없다면 -1을 출력한다.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m, cnt = 0;
vector<string> a;
vector<string> b;

void flip(int x, int y) {
    cnt++;
    // cout << "flip\n";
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if(a[x+i][y+j] == '0') a[x+i][y+j] = '1';
            else a[x+i][y+j] = '0';
        }
    }
}

int main() {    

    int i, j;
    bool flag = true;
    string s;

    cin >> n >> m;

    for (i = 0; i < n; i++) {
        cin >> s;
        a.push_back(s);
    }

    for (i = 0; i < n; i++) {
        cin >> s;
        b.push_back(s);
    }

    for (i = 0; i < n-2; i++) {
        for (j = 0; j < m-2; j++) {
            if (a[i][j] != b[i][j]) {
                flip(i, j);
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (flag) {
            for (j = 0; j < m; j++) {
                if (a[i][j] != b[i][j]) {
                    cout << "-1\n";
                    flag = false;
                    break;
                }
            }
        }
    }
    
    if(flag) cout << cnt << endl;
    
    return 0;
}