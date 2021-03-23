#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> origin;
vector<int> mixed;

bool isMagicSquare() {
    bool row = (mixed[0] + mixed[1] + mixed[2] == mixed[3] + mixed[4] + mixed[5]) &&
                (mixed[3] + mixed[4] + mixed[5] == mixed[6] + mixed[7] + mixed[8]);

    bool col = (mixed[0] + mixed[3] + mixed[6] == mixed[1] + mixed[4] + mixed[7]) &&
                (mixed[1] + mixed[4] + mixed[7] == mixed[2] + mixed[5] + mixed[8]);

    bool diag = mixed[0] + mixed[4] + mixed[8] == mixed[2] + mixed[4] + mixed[6];

    return row && col && diag;
}

int getDiff() {
    int diff = 0;
    for (int i = 0; i < 9; i++) diff += abs(origin[i] - mixed[i]);

    return diff;
}

int main() {
    int answer = INT_MAX;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num;
            scanf("%d", &num);
            origin.push_back(num);
        }
    }

    for (int i = 1; i <= 9; i++) mixed.push_back(i);

    do {
        // isMagicSquare 검사를 한다
        if (isMagicSquare()) {
            // origin - 현재 mixed와의 차이를 구하고 업데이트한다
            answer = min(answer, getDiff());
        }
    } while(next_permutation(mixed.begin(), mixed.end()));

    printf("%d\n", answer);
    return 0;
}
