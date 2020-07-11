#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    vector<string> diff;
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    set_difference(participant.begin(), participant.end(), completion.begin(), completion.end(), inserter(diff, diff.begin()));

    answer = diff[0];
    return answer;
}
