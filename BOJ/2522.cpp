#include <cstdio>
using namespace std;

int main() {

    int n, i, j;
    scanf("%d", &n);
    int last = n * 2 - 1;
    int star = 1;
    int space = n - 1;
    bool star_down = false;
    bool space_up = false;

    for (i = 1; i <= last; i++) {
        for (j = 0; j < space; j++) printf(" ");
        for (j = 0; j < star; j++) printf("*");
        if (i == n) {
            star_down = true;
            space_up = true;
        }
        if (star_down) star--;
        else if (!star_down) star++;

        if (space_up) space++;
        else if (!space_up) space--;

        printf("\n");
    }


    return 0;
}
