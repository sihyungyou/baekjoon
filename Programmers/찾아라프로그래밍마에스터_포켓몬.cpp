#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int len = nums.size();
    int half = len / 2;
    int i = 0;
    int prev = 0;

    sort(nums.begin(), nums.end());

    for (i = 0; i < len; i++) {
        if (answer == half) break;
        if (nums[i] != prev) {
            answer++;
            prev = nums[i];
        }
    }
    return answer;
}
