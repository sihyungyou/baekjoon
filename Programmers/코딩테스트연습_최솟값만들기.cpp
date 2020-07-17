#include <algorithm>
#include <vector>

using namespace std;

bool dec (int a, int b) {
    return a > b;
}

bool inc (int a, int b) {
    return a < b;
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int i = 0;
    int len = A.size();

    sort(A.begin(), A.end(), inc);
    sort(B.begin(), B.end(), dec);

    for (i = 0; i < len; i++) {
        answer += A[i] * B[i];
    }

    return answer;
}
