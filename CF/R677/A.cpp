#include <cstdio>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int x;
        scanf("%d", &x);

        int temp = x;
        int digit;
        int answer = 1;

        while(temp != 0) {
            digit = temp % 10;
            temp /= 10;
        }

        answer = (digit - 1) * 10;

        int base = digit;
        while(base <= x) {
            if (base < 10) answer++;
            else if (base < 100) answer += 2;
            else if (base < 1000) answer += 3;
            else answer+= 4;
            
            base = base * 10 + digit;
        }

        printf("%d\n", answer);
    }

    return 0;
}
