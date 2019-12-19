#include <cstdio>

using namespace std;

int main() {

    int i = 666, n, cnt = 0;
    bool flag;
    scanf("%d", &n);

    while(cnt != n) {
        int temp = i;
        flag = false;
        
        while(temp != 0) {
            if (temp % 1000 == 666) {
                flag = true;
                break;
            }
            temp /= 10;
        }

        if (flag) cnt++;
        i++;
    }

    printf("%d\n", i-1);


    return 0;
}