#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    
    int n, i, j, len, sum;
    int zero, even;
    bool three;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        char in[101];
        zero = 0;
        even = 0;
        three = false;
        sum = 0;

        scanf("%s", in);
        len = strlen(in);
        for (j = 0; j < len; j++) {
            int temp = in[j] - '0';

            if (temp == 0) zero++;
            else if (temp % 2 == 0) even++;
            sum += temp;
        }
        if (sum % 3 == 0) three = true;
        if ( (zero >= 2 && three) || (zero >= 1 && three && even >= 1)) printf("red\n");
        else printf("cyan\n");
    }
    
    return 0;
}