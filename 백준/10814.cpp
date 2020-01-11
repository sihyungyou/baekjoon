#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool sortby(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

int main() {

    vector<pair<int, int> > v1;
    string arr[100000];

    int n, i;
    cin >> n;

    for (i = 0; i < n; i++) {
        string temp_name;
        int temp_age;
        cin >> temp_age >> temp_name;
        v1.push_back(make_pair(temp_age, i));
        arr[i] = temp_name;
    }

    sort(v1.begin(), v1.end(), sortby);

    for (vector<pair <int, int> >::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << it->first << " " << arr[(it->second)] << "\n";
    }

    return 0;
}