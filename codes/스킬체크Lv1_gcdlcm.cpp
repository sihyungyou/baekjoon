#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm (int a, int b, int gcd) {
    return a * b / gcd;
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    int ans1 = gcd(n, m);
    int ans2 = lcm(n, m, ans1);

    answer.push_back(ans1);
    answer.push_back(ans2);
    return answer;
}