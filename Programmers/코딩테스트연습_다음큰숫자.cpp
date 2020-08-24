#include <string>
#include <vector>

using namespace std;

int convert_binary(int n) {
    int i = 0;
    while(n != 0) {
        if (n % 2 == 1) {
            i++;
        }
        n /= 2;
    }
    return i;
}

int solution(int n) {
    int answer = 0;
    answer = n + 1;
    int ones = convert_binary(n);

    while(1) {
        int temp = convert_binary(answer);
        if (temp == ones) break;
        answer++;
    }

    return answer;
}
