#include <string>
#include <vector>
#include <cstdio>

using namespace std;
int answer = 0;
int n = 0;
int tar;
vector<int> num;

void dfs(int x, int idx) {
    if (x == tar && idx == n) {
        answer++;
        return;
    } else if (x != tar && idx == n) {
        return;
    } else {
        dfs(x + num[idx], idx + 1);
        dfs(x - num[idx], idx + 1);
    }
}

int solution(vector<int> numbers, int target) {
    tar = target;
    n = numbers.size();
    for(int i = 0; i < n; i++) num.push_back(numbers[i]);

    dfs(0 + num[0], 1);
    dfs(0 - num[0], 1);

    return answer;
}
