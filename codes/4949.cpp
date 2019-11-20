#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    int flag;

    while(1) {
        char input[101];
        stack <char> small, big;
        cin.getline(input, 100);
        if (!strcmp(input, ".")) break;
        flag = 0;
        
        for (int i = 0; i < strlen(input); i++) {
            if (input[i] == '(') small.push('(');
            else if (input[i] == '[') big.push('[');
            else if (input[i] == ')') {
                if (!small.empty()) small.pop();
                else { cout << "NO\n"; flag = 1; break; }
            }
            else if (input[i] == ']') {
                if (!big.empty()) big.pop();
                else { cout << "NO\n"; flag = 1; break; }
            }
        }
        if (flag) continue;
        if (!small.empty() || !big.empty()) cout << "NO\n";
        else cout << "YES\n";
    }


    return 0;
}