#include <iostream>
#include <string>

using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string b;

        cin >> b;
        int len = b.length();

        string a = "";
        a += b[0];
        a += b[1];
        for (int k = 3; k < len; k+=2) {
            a += b[k];
        }

        cout << a << endl;
    }

    return 0;
}
