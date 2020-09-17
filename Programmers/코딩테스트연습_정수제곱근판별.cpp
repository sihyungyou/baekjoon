#include <string>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long i = 0;
    long long max_num = sqrt(n);

    for (i = 1; i <= max_num; i++) {
        if (i * i == n) {
            answer = (i + 1) * (i + 1);
            break;
        }
    }

    if (i > max_num) answer = -1;
    return answer;

}
