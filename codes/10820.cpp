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
#include <string>

using namespace std;

int main () {
    int N, i, j, lowers, uppers, numbers, spaces;
    char c, dump;
    cin >> N >> dump;

    for(j = 0; j < N; j++) {
        string temp;
        lowers = 0;
        uppers = 0;
        numbers = 0;
        spaces = 0;
        
        getline(cin, temp);
        if (temp.length() == 0) break;

        for(i = 0; i < temp.length(); i++) {
            if(temp[i] == ' ') spaces++;
            else if ('A' <= temp[i] && temp[i] <= 'Z') uppers++;
            else if ('a' <= temp[i] && temp[i] <= 'z') lowers++;
            else if ('0' <= temp[i] && temp[i] <= '9') numbers++;
        }
        printf("%d %d %d %d\n",lowers, uppers, numbers, spaces);
    }
    return 0;
}

