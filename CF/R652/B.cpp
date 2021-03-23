#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {

    int i, j, t, zero, one, onezero, len;
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        string s;
        int left, right;

        cin >> len;
        cin >> s;

        // find leftmost 1
        for (j = 0; j < len; j++) {
            if (s[j] == '1') break;
        }
        left = j;
        // find rightmost 0
        for (j = len - 1; j >= 0; j--) {
            if (s[j] == '0') break;
        }
        right = j;

        if (left > right) cout << s;
        else {
            for (j = 0; j < left; j++) printf("%c", s[j]);
            for (j = right; j < len; j++) printf("%c", s[j]);
        }
        printf("\n");

      }

    return 0;
}
