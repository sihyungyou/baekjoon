#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int blen = baseball.size();
    int i, j;

    for (i = 123; i <= 987; i++) {
        int one = i % 10;
        int ten = (i / 10) % 10;
        int hun = (i / 100) % 10;

        if (one != 0 && ten != 0 && hun != 0 && one != ten && one != hun && ten != hun) {

            for (j = 0; j < blen; j++)  {
              int strike = 0;
              int ball = 0;
              int b = baseball[j][0];
              int bone = b % 10;
              int bten = (b / 10) % 10;
              int bhun = (b / 100) % 10;

              if (one == bone) strike++;
              if (ten == bten) strike++;
              if (hun == bhun) strike++;
              if (one == bhun || one == bten) ball++;
              if (ten == bhun || ten == bone) ball++;
              if (hun == bone || hun == bten) ball++;
              if (strike != baseball[j][1] || ball != baseball[j][2]) break;
            }

            if (j == blen) answer++;
        }
    }

    return answer;
}
