#include <string>
#include <iostream>

using namespace std;

int main() {

    int n, k;
    string s, t;

    cin >> n >> k;
    cin >> s >> t;

    int i = 0;
    int j = n - 1;
    int ans = 0;

    while(1) {
        if (k == 0 || i == n || j < 0) break;

        int left = 0;
        int right = 0;

        // s[i] 왼쪽에 t[0] 개수
        for (int l = 0; l < i; l++) {
            if (s[l] == t[0]) left++;
        }
        // s[i] 오른쪽에 t[1] 개수
        for (int r = n - 1; r > i; r--) {
            if (s[r] == t[1]) right++;
        }

        if (left <= right) {
            if (s[i] != t[0]) {
                s[i] = t[0];
                k--;
            }
        } else {
            if (s[i] != t[1]) {
                s[i] = t[1];
                k--;
            }
        }
        i++;

        if (k == 0 || (i == n && j < 0)) break;

        left = 0;
        right = 0;

        // s[j] 왼쪽에 t[0]개수
        for (int l = 0; l < j; l++) {
            if (s[l] == t[0]) left++;
        }

        // s[j] 오른쪽에 t[1] 개수
        for (int r = n - 1; r > j; r--) {
            if (s[r] == t[1]) right++;
        }

        if (left < right) {
            if (s[j] != t[0]) {
                s[j] = t[0];
                k--;
            }
        } else {
            if (s[j] != t[1]) {
                s[j] = t[1];
                k--;
            }
        }
        j--;
    }

    // n <= 200
    int t1 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == t[1]) t1++;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == t[1]) {
            t1--;
        }
        if (s[i] == t[0]) {
            ans += t1;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (s[i] == t[0] && s[j] == t[1]) ans++;
    //     }
    // }

    cout << ans << endl;

    return 0;
}
