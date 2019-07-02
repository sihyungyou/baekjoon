/*
문자열 N개가 주어진다. 이때, 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램을 작성하시오.

각 문자열은 알파벳 소문자, 대문자, 숫자, 공백으로만 이루어져 있다.

입력
첫째 줄부터 N번째 줄까지 문자열이 주어진다. (1 ≤ N ≤ 100) 문자열의 길이는 100을 넘지 않는다.

출력
첫째 줄부터 N번째 줄까지 각각의 문자열에 대해서 소문자, 대문자, 숫자, 공백의 개수를 공백으로 구분해 출력한다.
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main () {
    int N, i, lowers, uppers, numbers, spaces;
    string temp;
    vector<string> strings;

    scanf("%d ", &N);

    for(i = 0; i < N; i++) {
        getline(cin, temp);
        strings.push_back(temp);
    }

    while(strings.size()) {
        // init variables
        lowers = 0;
        uppers = 0;
        numbers = 0;
        spaces = 0;
        // for length of each string, go into loop
        if (strings[0].length() == 0) break;
        for (char c : strings[0]) {
            // check each character and decide it's type, accumulate them
            if (isupper(c)) uppers++;
            if (islower(c)) lowers++;
            if (isdigit(c)) numbers++;
            if (isspace(c)) spaces++;
        }
        // print lower, upper, number, whitespace
        printf("%d %d %d %d\n",lowers, uppers, numbers, spaces);
        // erase from vector so that size can decrease
        strings.erase(strings.begin() + 0);
        
    }

    return 0;
}

// cin 은 공백문자를 기준으로 입력을 끊어서 getline을 썼어야 함
