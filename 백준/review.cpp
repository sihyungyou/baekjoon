#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

bool desc(string a, string b) {
    return a > b;
}

int main() {

    map<string, bool> m;
    vector<string> v;

    int n, i;
    cin >> n;

    for (i = 0; i < n; i++) {
        string name;
        string status;
        cin >> name >> status;
        if (status == "enter") {
            if (m.find(name) == m.end()) m.insert(make_pair(name, true));
            else m[name] = true;
        }
        else m[name] = false;
    }

    for (map<string, bool>::iterator it = m.begin(); it != m.end(); it++) if (it->second) v.push_back(it->first);

    sort(v.begin(), v.end(), desc);
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++) cout << *it << "\n";
    return 0;
}