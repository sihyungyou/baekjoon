#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int i, j;
    int row = board.size();
    int col = board[0].size();
    int map[row+1][col+1];

    for (i = 0; i <= row; i++) {
        for (j = 0; j <= col; j++) {
            if (i == 0 || j == 0) map[i][j] = 0;
            else map[i][j] = board[i-1][j-1];
        }
    }

    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            if (map[i][j] != 0) {
                int up = map[i-1][j];
                int left = map[i][j-1];
                int diag = map[i-1][j-1];

                if (up != 0 && left != 0 && diag != 0) {
                    int w = min(up, left);
                    w = min(w, diag);
                    w = sqrt(w);
                    map[i][j] = (w + 1) * (w + 1);
                }
            }
            answer = max(answer, map[i][j]);
        }
    }

    return answer;
}
