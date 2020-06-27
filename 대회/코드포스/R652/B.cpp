/*
B. AccurateLee
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Lee was cleaning his house for the party when he found a messy string under the carpets. Now he'd like to make it clean accurately and in a stylish way...

The string 𝑠 he found is a binary string of length 𝑛 (i. e. string consists only of 0-s and 1-s).

In one move he can choose two consecutive characters 𝑠𝑖 and 𝑠𝑖+1, and if 𝑠𝑖 is 1 and 𝑠𝑖+1 is 0, he can erase exactly one of them (he can choose which one to erase but he can't erase both characters simultaneously). The string shrinks after erasing.

Lee can make an arbitrary number of moves (possibly zero) and he'd like to make the string 𝑠 as clean as possible. He thinks for two different strings 𝑥 and 𝑦, the shorter string is cleaner, and if they are the same length, then the lexicographically smaller string is cleaner.

Now you should answer 𝑡 test cases: for the 𝑖-th test case, print the cleanest possible string that Lee can get by doing some number of moves.

Small reminder: if we have two strings 𝑥 and 𝑦 of the same length then 𝑥 is lexicographically smaller than 𝑦 if there is a position 𝑖 such that 𝑥1=𝑦1, 𝑥2=𝑦2,..., 𝑥𝑖−1=𝑦𝑖−1 and 𝑥𝑖<𝑦𝑖.

Input
The first line contains the integer 𝑡 (1≤𝑡≤104) — the number of test cases.

Next 2𝑡 lines contain test cases — one per two lines.

The first line of each test case contains the integer 𝑛 (1≤𝑛≤105) — the length of the string 𝑠.

The second line contains the binary string 𝑠. The string 𝑠 is a string of length 𝑛 which consists only of zeroes and ones.

It's guaranteed that sum of 𝑛 over test cases doesn't exceed 105.

Output
Print 𝑡 answers — one per test case.

The answer to the 𝑖-th test case is the cleanest string Lee can get after doing some number of moves (possibly zero).

Example
inputCopy
5
10
0001111111
4
0101
8
11001101
10
1110000000
1
1
outputCopy
0001111111
001
01
0
1
*/

#include <iostream>
#include <string>
using namespace std;

string compare;

bool comp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

void dfs(string s, int len) {

    if (comp(s, compare)) {
        compare = s;
    }

    // cout << "compare : " << compare << endl;

    int i;
    string str;

    for (i = 0; i < len - 1; i++) {
      str = s;
        if (s[i] == '1' && s[i+1] == '0') {
            if (i + 2 < len && s[i+2] == '0') {
                dfs(str.erase(i + 1, 1), len - 1);
            }
            else if (i + 2 < len && s[i+2] == '1') {
                dfs(str.erase(i, 1), len - 1);
            }
            else if (i - 1 >= 0 && s[i-1] == '0') {
                dfs(str.erase(i + 1, 1), len - 1);
            }
            else if (i - 1 >= 0 && s[i-1] == '1') {
                dfs(str.erase(i, 1), len - 1);
            }
            else {
                dfs(str.erase(i + 1, 1), len - 1);
                str = s;
                dfs(str.erase(i, 1), len - 1);
            }
            i++;
        }
    }

}

int main() {

    int t, i, n;

    cin >> t;

    for (i = 0; i < t; i++) {
        string temp;
        cin >> n;
        cin >> temp;
        compare = temp;
        dfs(temp, n);
        cout << compare << endl;
    }

    return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string compare;

bool comp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

void dfs(string s, int len) {

    if (comp(s, compare)) {
        compare = s;
    }
    // cout << "compare : " << compare << endl;

    int i;
    string str;

    for (i = 0; i < len - 1; i++) {
      str = s;
        if (s[i] == '1' && s[i+1] == '0') {
            // dfs erasing 1
            dfs(str.erase(i, 1), len - 1);

            str = s;
            // dfs erasing 0
            dfs(str.erase(i + 1, 1), len - 1);
        }
    }


}

int main() {

    int t, i, n;

    cin >> t;

    for (i = 0; i < t; i++) {
        string temp;
        cin >> n;
        cin >> temp;
        compare = temp;
        dfs(temp, n);
        cout << compare << endl;
    }

    return 0;
}

*/
