#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

bool arr[100001];

void checkArray(int starting) {
    if (starting > 10000) return;

    int newnum = starting;
    string str = to_string(starting);

    for (int i = 0; i < str.length(); i++) {
        newnum += str[i] - '0';
    }

    if (newnum > 10000) return;

    arr[newnum] = false;
    checkArray(newnum);

}

int main() {

    for (int i = 0; i <= 10000; i++) arr[i] = true;

    for (int i = 1; i <= 10000; i++) {
        checkArray(i);
    }

    for (int i = 1; i <= 10000; i++) {
        if (arr[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}
