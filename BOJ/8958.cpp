#include <string>
#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        int ans = 0;
        int acc = 0;

        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'O') {
                acc++;
                ans += acc;
            } else {
                acc = 0;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
