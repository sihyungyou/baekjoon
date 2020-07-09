#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    string afirst = a + b;
    string bfirst = b + a;
    return afirst > bfirst;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    int len = numbers.size();
    int i;

    // convert int -> string
    for (i = 0; i < len; i++) {
        string temp = to_string(numbers[i]);
        v.push_back(temp);
    }

    // sort
    sort(v.begin(), v.end(), compare);

    // concat all strings
    for (i = 0; i < len; i++) {
        answer += v[i];
    }

    if (answer[0] == '0') return "0";
    else return answer;
}
