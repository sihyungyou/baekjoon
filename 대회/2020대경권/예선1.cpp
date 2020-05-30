/* 100 / 100 */
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> atmos) {
    int answer = 0;
    int len = atmos.size();
    bool reuse = false;
    int day = 0;

    for (int i = 0; i < len; i++) {
        if ( (atmos[i][0] >= 81 || atmos[i][1] >= 36) && !reuse) {
            // 하나라도 높은데 재사용중이 아니면 새것을 씀
            answer++;
            reuse = true;
        }
        if ( (atmos[i][0] >= 151 && atmos[i][1] >= 76)) {
            // 둘다 매우 나쁨이면 사용중이던 것을 폐기하므로 reuse = false;
            reuse = false;
            day = 0;
        }

        // 하나라도 높은데 재사용중 : day만 올림
        if (reuse) day++;

        // 3일째 쓰고있으면 폐기
        if (day == 3) {
            reuse = false;
            day = 0;
        }
    }

    return answer;
}
