#include <cstdio>
using namespace std;

int main() {

    int n, i, j;

    scanf("%d", &n);
    int last = n * 2 - 1;
    int space = 0;
    int star = last;

    bool star_up = false;
    bool space_down = false;

    for (i = 0; i < last; i++) {
        for (j = 0; j < space; j++) printf(" ");
        for (j = 0; j < star; j++) printf("*");
        if (i == n-1) {
            star_up = true;
            space_down = true;
        }
        if(!star_up) {
            star -= 2;
        }
        else if (star_up) {
            star += 2;
        }
        if (!space_down) {
            space++;
        }
        else if (space_down) {
            space--;
        }
        printf("\n");
    }



    return 0;
}
