// https://programmers.co.kr/learn/courses/30/lessons/42889
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int , double> a, pair<int, double> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double> > v;
    int i = 0;
    long double users = stages.size();

    for (i = 1; i <= N; i++) {
        int num = count(stages.begin(), stages.end(), i);
        long double fail = 0;
        // divide by zero 에러 방지가 핵심
        if (users != 0) fail = num / users;
        v.push_back(make_pair(i, fail));
        users -= num;
    }

    sort(v.begin(), v.end(), cmp);
    for (i = 0; i < N; i++) {
        answer.push_back(v[i].first);
    }

    return answer;
}
