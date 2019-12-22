#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    int i, j, start, end, k, t;
    
    for (i = 0; i < commands.size(); i++) {
        temp.clear();
        start = commands[i][0];
        end = commands[i][1];
        k = commands[i][2];
        
        for (j = start-1; j < end; j++) temp.push_back(array[j]);
        sort(temp.begin(), temp.begin()+temp.size());
        answer.push_back(temp[k-1]);
    }
    return answer;
}