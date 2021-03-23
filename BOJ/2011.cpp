#include <iostream>
#include <string>
using namespace std;

#define MOD 1000000

int main() {
    string s;
    cin >> s;

    bool flag = true;
    int len = s.length();
    long long dp[len + 1];

    dp[len] = 1;
    if (s[0] == '0') {
        // 첫 문자가 0이면 올바르지 않은 암호
        flag = false;
    } else {
        if (s[len-1] == '0') {
            dp[len-1] = 0;
        } else {
            dp[len-1] = 1;
        }

        for (int i = len - 2; i >= 0; i--) {
            if (s[i] == '0') {
                // 현재 위치의 숫자가 0이라면 해석될 수 있는 여지는 없으므로 0
                // 하지만 다음 위치의 수(s[i-1])와 조합해서 10, 20 등의 암호를 만들어 낼 수 있으므로 break 하지 않음
                dp[i] = 0;
            } else {
                // 현재 위치의 숫자가 0이 아니라면 1개 단위로 잘랐을 때 이전까지의 암호를 해석할 수 있는 가짓수와 동일
                dp[i] = dp[i + 1] % MOD;

                int temp = ((s[i] - '0') * 10) + (s[i + 1] - '0');
                // 2자리를 조합했봄으로써 더 해석될 수 있는 여지가 있는지 검사
                if (temp >= 10 && temp <= 26) {
                    // 만약 10~26 사이의 수라면 s[i], s[i+1]을 하나의 알파벳으로 해석하고 s[i+2]까지 해석된 가짓수를 더함
                    dp[i] += dp[i + 2] % MOD;
                } else if (s[i+1] == '0') {
                    // 30, 40같은 수는 두자리수는 만들어지지만 알파벳으로 해석할 수 없으므로 올바르지 않은 암호
                    flag = false;
                    break;
                }
            }
        }
    }


    flag ? printf("%lld\n", dp[0] % MOD) : printf("0\n");

    return 0;
}
