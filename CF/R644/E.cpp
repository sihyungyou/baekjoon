#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<string> v;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            v.push_back(temp);
        }

        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(v[i][j] == '1') {
                    // 오른쪽과 아래가 모두 border, 1이 아니라면 즉시 NO
                    if ((i + 1 < n && v[i + 1][j] != '1') && (j + 1 < n && v[i][j + 1] != '1')) {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) break;
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}
