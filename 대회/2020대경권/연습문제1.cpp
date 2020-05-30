#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortbyx(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    int x;
    int y;

    sort(v.begin(), v.end(), sortbyx);

    if (v[0][0] == v[1][0]) {
        x = v[2][0];
    } else {
        x = v[0][0];
    }

    if (v[0][1] == v[1][1]) {
        y = v[2][1];
    } else if (v[0][1] == v[2][1]){
        y = v[1][1];
    } else {
        y = v[0][1];
    }
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}
