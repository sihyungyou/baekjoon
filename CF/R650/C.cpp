#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        vector<int> v;
        string s;
        int n, k, answer = 0;

        cin >> n >> k;
        cin >> s;

        vector<int> pos;
        for (int i = 0; i < n; i++) if (s[i] == '1') pos.push_back(i);

        int len = pos.size();

        // no one at all
        if (len == 0) {
            answer = (n + k) / (k + 1);
            cout << answer << endl;
            continue;
        }

        // first
        answer += (pos[0] - k + k) / (k + 1);

        // last
        answer += (n - 1 - pos.back() - k + k) / (k + 1);

        // middle
        for (int i = 1; i < len; i++) {
            int count = pos[i] - pos[i - 1] - 1;
            answer += (count - (2 * k) + k) / (k + 1);
        }

        cout << answer << endl;
    }

    return 0;
}
