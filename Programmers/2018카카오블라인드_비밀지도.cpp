// https://programmers.co.kr/learn/courses/30/lessons/17681
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string map1[n][n];
    string map2[n][n];
    int len = arr1.size();
    int i = 0;
    int j = 0;

    for (i = 0; i < len; i++) {
        int num = arr1[i];
        int cnt = 0;
        while(num != 0) {
            int r = num % 2;
            if (r == 0) {
                map1[i][n-cnt-1] = " ";
            } else {
                map1[i][n-cnt-1] = "#";
            }
            num /= 2;
            cnt++;
        }
        if (cnt < n) {
            for (int k = 0; k < n - cnt; k++) {
                map1[i][k] = " ";
            }
        }
    }

    for (i = 0; i < len; i++) {
        int num = arr2[i];
        int cnt = 0;
        while(num != 0) {
            int r = num % 2;
            if (r == 0) {
                map2[i][n-cnt-1] = " ";
            } else {
                map2[i][n-cnt-1] = "#";
            }
            num /= 2;
            cnt++;
        }
        if (cnt < n) {
            for (int k = 0; k < n - cnt; k++) {
                map2[i][k] = " ";
            }
        }
    }

    for (i = 0; i < len; i++) {
        string temp = "";
        for (j = 0; j < len; j++) {
            if (map1[i][j] == "#" || map2[i][j] == "#") temp += "#";
            if (map1[i][j] == " " && map2[i][j] == " ") temp += " ";
        }
        answer.push_back(temp);
    }

    return answer;
}
