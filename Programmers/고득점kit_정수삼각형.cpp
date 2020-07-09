#include <vector>
#include <cstdio>

using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }

int solution(vector<vector<int>> triangle) {
    long long answer = -1;
    int i, j, len;
    len = triangle.size();
    int dp[500][500];
    
    for (i = 1; i < len; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0) triangle[i][j] += triangle[i-1][j];
            else if (j == i) triangle[i][j] += triangle[i-1][j-1];
            else triangle[i][j] = get_max(triangle[i][j] + triangle[i-1][j-1], triangle[i][j] + triangle[i-1][j]);
            
            answer = get_max(answer, triangle[i][j]);
        }
    }
    
    
    return answer;
}