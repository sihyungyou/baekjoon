#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int len = dartResult.length();
    int i = 0;
    int score_cnt = 0;
    int bonus_cnt = 0;

    int scores[3];
    int acc[3];
    char bonuses[3];
    char options[3];


    // 점수, 보너스, 옵션을 분리
    for (i = 0; i < len; i++) {
        char now = dartResult[i];
        if (isdigit(now)) {
            if (now == '1') {
                if (dartResult[i+1] == '0') {
                    scores[score_cnt++] = 10;
                    i++;
                }
                else scores[score_cnt++] = 1;
            }
            else {
                scores[score_cnt++] = now - '0';
            }
        }
        else if (isalpha(now)) {
            bonuses[bonus_cnt++] = now;
        }
        else {
            if (i == 2) {
                options[0] = now;
            }
            else if (i == 4 || i == 5) {
                options[1] = now;
            }
            else {
                options[2] = now;
            }
        }
    }

    for (i = 0; i < 3; i++) {
        int score = scores[i];
        int bonus = bonuses[i];
        int option = options[i];

        // 현재 score에 bonus를 적용하여 계산
        if (bonus == 'D') score *= score;
        else if (bonus == 'T') score = score * score * score;

        // option을 보고, option 해당사항이 있다면,
        if (option == '*') {
            score *= 2;
            acc[i-1] *= 2;
        }
        else if (option == '#') {
            score *= -1;
        }

        acc[i] = score;
    }

    for(i = 0; i < 3; i++) answer += acc[i];

    return answer;
}
