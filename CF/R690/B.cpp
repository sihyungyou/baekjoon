#include <iostream>
#include <string>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string str;
        cin >> str;


        bool flag = false;
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (j - i != n - 4) continue;
                // delete from i ~ j
                string tempstr = str;
                tempstr.erase(tempstr.begin() + i, tempstr.begin() + j);
                // cout << "i : " << i << " j : " << j << endl;
                // cout << tempstr << endl;
                if (tempstr == "2020") {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}
