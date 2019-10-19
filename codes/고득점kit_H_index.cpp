#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }

int solution(vector<int> citations) {
    int i, j, high = 0, low = 0, answer = 0;
    int len = citations.size();
    
    sort(citations.begin(), citations.end());
    
    for (i = 0; i < len; i++) {
        high = 0;
        low = 0;
        
        for (j = 0; j < len; j++) {
            if (citations[i] >= citations[j]) high++;
            else low++;
        }
        printf("high : %d, low : %d\n", high, low);
        if ((high >= citations[i]) && (low < citations[i]) ) answer = citations[i];
        
    }
    
    return answer;
}