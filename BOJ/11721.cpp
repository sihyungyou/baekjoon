#include <iostream>
#include <string>
using namespace std;

int main() {

    int n;
    string s;
    cin >> s;

    n = s.length();
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i % 10 == 9) cout << endl;
    }

    cout << endl;

    return 0;
}
