#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int i, j, k;
    int row = land.size();
    int dp[row][4];

    for (i = 0; i < row; i++) for (j = 0; j < 4; j++) dp[i][j] = land[i][j];

    for (i = row - 1; i > 0; i--) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (k != j) {
                    dp[i-1][k] = max(land[i-1][k] + dp[i][j], dp[i-1][k]);
                    answer = max(answer, dp[i-1][k]);
                }
            }
        }
    }

    return answer;
}
