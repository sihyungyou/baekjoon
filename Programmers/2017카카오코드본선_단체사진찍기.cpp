#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    int i = 0;
    vector <char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector <char>::iterator it;

    sort(friends.begin(), friends.end());

    do {
        bool flag = true;
        for (i = 0; i < n; i++) {
            // 만들어진 수열로 모든 조건을 만족하는지 검사
            string condition = data[i];
            char a = condition[0];
            char b = condition[2];
            char op = condition[3];
            int space = condition[4] - '0';

            // 현재 만들어진 수열에서 캐릭터 간 실제 거리 계산
            it = find(friends.begin(), friends.end(), a);
            int aidx = distance(friends.begin(), it);

            it = find(friends.begin(), friends.end(), b);
            int bidx = distance(friends.begin(), it);

            // 실제 거리와 희망하는 거리 비교, 원하는 조건을 만족하지 않으면 flag를 false로 바꾸고 다음 수열 검사
            int real_space = aidx > bidx ? aidx - bidx - 1 : bidx - aidx - 1;

            if ( (op == '=' && real_space != space) || (op == '>' && real_space <= space) || (op == '<' && real_space >= space) ) {
                flag = false;
                // 여기에 break 추가하면 효율성 테스트 통과!
                break;
            }
        }

        if (flag) answer++;
    } while(next_permutation(friends.begin(), friends.end()));


    return answer;
}
