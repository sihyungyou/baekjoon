#include <vector>
#include <array>
#include <iostream>

using namespace std;
int get_max(int a, int b) { return a > b ? a : b; }
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    array<int, 5> arr1 = { 1,2,3,4,5 };
    array<int, 8> arr2 = { 2,1,2,3,2,4,2,5 };
    array<int, 10> arr3 = { 3,3,1,1,2,2,4,4,5,5 };
    
    int i, j, k, m, max, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    
    j = 0, k = 0, m = 0;
    
    for (i = 0; i < answers.size(); i++) {
        if (j == arr1.size()) j = 0;
        if (k == arr2.size()) k = 0;
        if (m == arr3.size()) m = 0;
        
        if (arr1[j] == answers[i]) cnt1++;
        if (arr2[k] == answers[i]) cnt2++;
        if (arr3[m] == answers[i]) cnt3++;
        
        j++; k++; m++;
    }
    
    max = get_max(cnt1, cnt2);
    max = get_max(max, cnt3);
    
    if (max == cnt1) answer.push_back(1);
    if (max == cnt2) answer.push_back(2);
    if (max == cnt3) answer.push_back(3);
    
    return answer;
}