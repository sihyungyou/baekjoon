#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    while(n != 0) {
        int temp = n % 3;
        n /= 3;
        if (temp == 0) {
            n--;
            temp = 4;
        }
        answer.insert(0, to_string(temp));
    }

    return answer;
}
