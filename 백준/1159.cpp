#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, i, cnt = 1;
    string temp;
    bool flag = false;
    vector <string> v;

    cin >> n;


    for (i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n - 1; i++) {
        if (v[i][0] == v[i+1][0]) {
            cnt++;
        }
        else {
            cnt = 1;
        }

        if (cnt == 5) {
            flag = true;
            cout << v[i][0];
        }
    }

    if (!flag) cout << "PREDAJA\n";
    else cout << "\n";

    return 0;
}
