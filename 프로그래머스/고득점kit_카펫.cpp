#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int i;
    int yh, yw, bh, bw;

    for (i = 1; i <= sqrt(yellow); i++) {
        if (yellow % i == 0) {
            yh = i;
            bh = yh + 2;
            yw = yellow / i;
            bw = yw + 2;
            if (bw * bh - yellow == brown) {
                answer.push_back(bw);
                answer.push_back(bh);
                break;
            }
        }
    }

    return answer;
}
